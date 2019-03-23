/*
** Lua library for the JIT engine.
** Copyright (C) 2005 Mike Pall. See Copyright Notice in luajit.h
*/

#include <stdio.h>

#define ljitlib_c
#define LUA_LIB

#include "lua.h"
#include "lauxlib.h"
#include "luajit.h"
#include "lualib.h"
#ifndef COCO_DISABLE
#include "lcoco.h"
#endif

/* This file is not a pure C API user. Some internals are required. */
#include "lobject.h"
#include "lstate.h"
#include "lstring.h"
#include "ltable.h"
#include "lfunc.h"
#include "lgc.h"
#include "lopcodes.h"

#include "ljit.h"
#include "ljit_hints.h"

#define STRING_HINTS
#include "ljit_hints.h"

/* ------------------------------------------------------------------------ */

/* Static pointer addresses used as registry keys. */
static const int regkey_frontend = 1;
static const int regkey_comthread = 1;

/* Check that the first argument is a Lua function and return its closure. */
static Closure *check_LCL(lua_State *L)
{
  StkId o = L->base;
  switch (lua_type(L, 1)) {
  case LUA_TBOOLEAN:
    o = (L->ci-1)->func;
  case LUA_TFUNCTION:
    if (isLfunction(o))
      return clvalue(o);
    break;
  }
  luaL_argerror(L, 1, "Lua function expected");
  return NULL;
}

/* Create a new closure from a prototype. */
/* Note: upvalues are assumed to be after first two slots. */
static void push_LCL(lua_State *L, Proto *pt, Table *env)
{
  Closure *cl;
  int i, nup = pt->nups;
  /* Adjust the number of stack slots to the number of upvalues. */
  luaL_checkstack(L, nup, "too many upvalues");
  lua_settop(L, 2+nup);
  /* Create a closure from the subroutine prototype. */
  cl = luaF_newLclosure(L, nup, env);
  cl->l.p = pt;
  /* Allocate new upvalues and close them. */
  for (i = 0; i < nup; i++)
    cl->l.upvals[i] = luaF_findupval(L, L->base + (2+i));
  luaF_close(L, L->base + 2);
  lua_settop(L, 2);  /* Remove upvalues. */
  setclvalue(L, L->top++, cl);  /* Return closure on top of stack. */
  luaC_checkGC(L);
}

/* ------------------------------------------------------------------------ */

/* Set JIT mode for the engine or a closure and/or its subroutines. */
static int setmode(lua_State *L, int mode)
{
  int idx = 0;
  switch (lua_type(L, 1)) {
  case LUA_TNONE:	/* jit.on/off() */
  case LUA_TNIL:	/* jit.on/off(nil) */
    luaJIT_setmode(L, 0, mode | LUAJIT_MODE_ENGINE);
    break;
  case LUA_TFUNCTION:	/* jit.on/off(func, nil|true|false) */
    idx = 1;
  case LUA_TBOOLEAN:	/* jit.on/off(true, nil|true|false) (parent frame) */
    if (lua_isboolean(L, 2))
      mode |= lua_toboolean(L, 2)?LUAJIT_MODE_ALLFUNC:LUAJIT_MODE_ALLSUBFUNC;
    else
      mode |= LUAJIT_MODE_FUNC;
    if (luaJIT_setmode(L, idx, mode) == 1)  /* Ok? */
      break;
  default:
    luaL_argerror(L, 1, "Lua function expected");
    break;
  }
  return 0;
}

/* Set JIT mode to on: (re-)enable compilation. */
static int j_on(lua_State *L)
{
  return setmode(L, LUAJIT_MODE_ON);
}

/* Set JIT mode to off: disable compilation. */
static int j_off(lua_State *L)
{
  return setmode(L, LUAJIT_MODE_OFF);
}

/* Set JIT debug level. Defaults to maximum level for use with -j. */
static int j_debug(lua_State *L)
{
  luaJIT_setmode(L, luaL_optinteger(L, 1, 100), LUAJIT_MODE_DEBUG);
  return 0;
}

/* ------------------------------------------------------------------------ */

/* Report the compilation status. */
static int compstatus(lua_State *L, int status)
{
  if (status == -1)
    return luaL_argerror(L, 1, "Lua function expected");
  else if (status == JIT_S_OK)
    return 0;
  else {
    lua_pushinteger(L, status);
    return 1;
  }
}

/* Compile a function. Pass typical args to help the analyzer. */
static int j_compile(lua_State *L)
{
  int nargs = lua_gettop(L) - 1;
  return compstatus(L, nargs >= 0 ? luaJIT_compile(L, nargs) : -1);
}

/* Recursively compile all subroutine prototypes. */
static int rec_compile(lua_State *L, Proto *pt, Table *env, int stoponerror)
{
  int rstatus = JIT_S_OK;
  int i;
  for (i = 0; i < pt->sizep; i++) {
    Proto *pti = pt->p[i];
    int status;
    push_LCL(L, pti, env);  /* Assumes stack is at 2 (no upvalues). */
    status = luaJIT_compile(L, 0);
    lua_settop(L, 2);  /* Clear stack */
    if (status != JIT_S_OK) {
      rstatus = status;
      if (stoponerror) break;
    }
    status = rec_compile(L, pti, env, stoponerror);
    if (status != JIT_S_OK) {
      rstatus = status;
      if (stoponerror) break;
    }
  }
  return rstatus;
}

/* Compile all subroutines of a function. */
/* Note: the function itself is _not_ compiled (use jit.compile()). */
static int j_compilesub(lua_State *L)
{
  Closure *cl = check_LCL(L);
  int stoponerror = lua_toboolean(L, 2);  /* Stop on first error? */
  lua_settop(L, 2);
  return compstatus(L, rec_compile(L, cl->l.p, cl->l.env, stoponerror));
}

/* jit.* functions. */
static const luaL_Reg jitlib[] = {
  { "on",		j_on },
  { "off",		j_off },
  { "debug",		j_debug },
  { "compile",		j_compile },
  { "compilesub",	j_compilesub },
  /* j_attach is added below. */
  { NULL, NULL }
};

/* ------------------------------------------------------------------------ */

/* Get the compiler pipeline table from an upvalue (j_attach, j_frontend). */
#define COMPIPE		lua_upvalueindex(1)

/* Attach/detach handler to/from compiler pipeline. */
static int j_attach(lua_State *L)
{
  int pipesz;
  luaL_checktype(L, 1, LUA_TFUNCTION);
  pipesz = lua_objlen(L, COMPIPE);
  if (lua_isnoneornil(L, 2)) {  /* Detach if no priority given. */
    int i;
    for (i = 1; i <= pipesz; i += 2) {
      lua_rawgeti(L, COMPIPE, i);
      if (lua_rawequal(L, 1, -1)) {  /* Found: delete from pipeline. */
	for (; i+2 <= pipesz; i++) {  /* Shift down. */
	  lua_rawgeti(L, COMPIPE, i+2);
	  lua_rawseti(L, COMPIPE, i);
	}
	/* Clear last two elements. */
	lua_pushnil(L); lua_rawseti(L, COMPIPE, i);
	lua_pushnil(L); lua_rawseti(L, COMPIPE, i+1);
	return 0;
      }
      lua_pop(L, 1);
    }
    return 0;  /* Not found: ignore detach request. */
  } else {  /* Attach if priority given. */
    int prio = luaL_checkint(L, 2);
    int pos, i;
    for (pos = 2; pos <= pipesz; pos += 2) {
      lua_rawgeti(L, COMPIPE, pos);
      if (prio > (int)lua_tointeger(L, -1)) break; /* Insertion point found. */
      lua_pop(L, 1);
    }
    for (i = pipesz+2; i > pos; i--) {  /* Shift up. */
      lua_rawgeti(L, COMPIPE, i-2);
      lua_rawseti(L, COMPIPE, i);
    }
    /* Set handler and priority. */
    lua_pushvalue(L, 1); lua_rawseti(L, COMPIPE, i-1);
    lua_pushvalue(L, 2); lua_rawseti(L, COMPIPE, i);
    return 0;
  }
}

/* Compiler frontend. Runs in the compiler thread. */
/* First and only arg is the compiler state table. */
static int j_frontend(lua_State *L)
{
  int status = JIT_S_OK;
  int pos;
  /* Loop through all handlers in the compiler pipeline. */
  for (pos = 1; ; pos += 2) {
    if (status != JIT_S_OK) {  /* Pending failure? */
      int prio;
      lua_rawgeti(L, COMPIPE, pos+1);  /* Must check for odd/even priority. */
      if (lua_isnil(L, -1)) break;  /* End of pipeline. */
      prio = (int)lua_tointeger(L, -1);
      lua_pop(L, 1);
      if ((prio & 1) == 0) continue;  /* Skip handlers with even priority. */
    }
    /* Call handler with compiler state table and optional failure status. */
    lua_rawgeti(L, COMPIPE, pos);
    if (lua_isnil(L, -1)) break;  /* End of pipeline. */
    lua_pushvalue(L, 1);
    if (status != JIT_S_OK)
      lua_pushinteger(L, status);
    lua_call(L, status ? 2 : 1, 1);
    if (!lua_isnil(L, -1))  /* Remember failure status. */
      status = (int)lua_tointeger(L, -1);
    lua_pop(L, 1);
  }
  lua_pushinteger(L, status);
  return 1;
}

/* Preallocation for the hash part of the compiler state table. */
#define COMSTATE_PREALLOC	128

/* Helper function to efficiently fill the state table. */
static void createstate(lua_State *L, StkId func, int nargs)
{
  Table *t;
  int i;
  /* Create compiler state table. */
  lua_createtable(L, nargs, COMSTATE_PREALLOC);
  lua_lock(L);
  t = hvalue(L->top-1);
  /* Copy function and args (from different stack). */
  setobj2t(L, luaH_setstr(L, t, luaS_newliteral(L, "func")), func);
  for (i = 1; i <= nargs; i++)
    setobj2t(L, luaH_setnum(L, t, i), func+i);
  lua_unlock(L);
}

/* Compiler frontend wrapper. */
static int frontwrap(lua_State *L, int nargs)
{
  jit_State *J = G(L)->jit_state;
  lua_State *JL;
  int status;

  /* Allocate compiler thread on demand. */
  if (J->L == NULL) {
    if (!lua_checkstack(L, 2)) return JIT_S_COMPILER_ERROR;
    lua_pushlightuserdata(L, (void *)&regkey_comthread);
#if !defined(COCO_DISABLE) && defined(LUAJIT_COMPILER_CSTACK)
    J->L = lua_newcthread(L, LUAJIT_COMPILER_CSTACK);  /* Ensure C stack. */ 
#else
    J->L = lua_newthread(L);
#endif
    lua_rawset(L, LUA_REGISTRYINDEX);
  }
  JL = J->L;

  /* Initialize compiler thread stack with frontend and state table. */
  lua_settop(JL, 0);
  lua_pushlightuserdata(JL, (void *)&regkey_frontend);
  lua_rawget(JL, LUA_REGISTRYINDEX);
  createstate(JL, L->top - (nargs+1), nargs);

  /* Start the frontend by resuming the compiler thread. */
  if (lua_resume(JL, 1) != 0) {  /* Failed? */
    /* Note: LUA_YIELD is treated like any other error. */
    J->L = NULL;  /* Get a new thread next time. */
    fprintf(stderr, "[LuaJIT frontend failed: %s]\n",
      lua_isstring(JL, -1) ? lua_tostring(JL, -1) : "(unknown error)");
    return JIT_S_COMPILER_ERROR;
  }

  /* Get status from terminated thread. */
  status = (int)lua_tointeger(JL, -1);
  lua_settop(JL, 0);  /* Help the GC. */
  return status;
}

/* Create the compiler pipeline and register it. */
static void makepipeline(lua_State *L)
{
  lua_createtable(L, 20, 0);  /* 10 handlers+priorities should be enough. */
  lua_pushcfunction(L, luaJIT_backend);
  lua_rawseti(L, -2, 1);
  lua_pushinteger(L, 0);  /* Fill in the backend at prio 0. */
  lua_rawseti(L, -2, 2);

  /* Store the compiler frontend in the registry. */
  lua_pushlightuserdata(L, (void *)&regkey_frontend);
  lua_pushvalue(L, -2);  /* Pipeline table as upvalue. */
  lua_pushcclosure(L, j_frontend, 1);
  lua_rawset(L, LUA_REGISTRYINDEX);

  /* Register the frontend wrapper. */
  G(L)->jit_state->frontwrap = frontwrap;

  /* Add jit.attach with the pipeline table as upvalue. */
  lua_pushcclosure(L, j_attach, 1);
  lua_setfield(L, -2, "attach");  /* "jit" table must be below. */
}

/* ------------------------------------------------------------------------ */

#define setintfield(name, i) \
  do { lua_pushinteger(L, i); lua_setfield(L, -2, name); } while (0)

/* local stats = jit.util.stats(func) */
static int ju_stats(lua_State *L)
{
  if (!(L->top > L->base))
    luaL_argerror(L, 1, "Lua function expected");
  if (isLfunction(L->base)) {
    Proto *pt = clvalue(L->base)->l.p;
    lua_createtable(L, 0, 11);
    setintfield("status", pt->jit_status);
    setintfield("stackslots", pt->maxstacksize);
    setintfield("params", pt->numparams);
    setintfield("bytecodes", pt->sizecode);
    setintfield("consts", pt->sizek);
    setintfield("upvalues", pt->nups);
    setintfield("subs", pt->sizep);
    lua_pushboolean(L, pt->is_vararg);
    lua_setfield(L, -2, "isvararg");
    lua_getfenv(L, 1);
    lua_setfield(L, -2, "env");
    if (pt->jit_sizemcode != 0) {
      setintfield("mcodesize", pt->jit_sizemcode);
      lua_pushnumber(L, (lua_Number)(size_t)pt->jit_mcode);
      lua_setfield(L, -2, "mcodeaddr");
    }
    return 1;
  } else {
    return 0;  /* Don't throw an error like the other util functions. */
  }
}

/* local op, a, b, c, test = jit.util.bytecode(func, pc) */
static int ju_bytecode(lua_State *L)
{
  Proto *pt = check_LCL(L)->l.p;
  int pc = luaL_checkint(L, 2);
  if (pc >= 1 && pc <= pt->sizecode) {
    Instruction ins = pt->code[pc-1];
    OpCode op = GET_OPCODE(ins);
    /* Just in case we accidentally decode a count following OP_SETLIST. */
    if (op >= NUM_OPCODES) return 0;
    lua_pushstring(L, luaP_opnames[op]);
    lua_pushinteger(L, GETARG_A(ins));
    switch (getOpMode(op)) {
    case iABC: {
      int b = GETARG_B(ins), c = GETARG_C(ins);
      if (getBMode(op) == OpArgN) lua_pushnil(L);
      else lua_pushinteger(L, ISK(b) ? (-1-INDEXK(b)) : b);
      if (getCMode(op) == OpArgN) lua_pushnil(L);
      else lua_pushinteger(L, ISK(c) ? (-1-INDEXK(c)) : c);
      lua_pushboolean(L, testTMode(op));
      return 5;
    }
    case iABx: {
      int bx = GETARG_Bx(ins);
      lua_pushinteger(L, getBMode(op) == OpArgK ? -1-bx : bx);
      return 3;
    }
    case iAsBx:
      lua_pushinteger(L, GETARG_sBx(ins));
      return 3;
    }
  }
  return 0;
}

/* local const, ok = jit.util.const(func, idx) */
static int ju_const(lua_State *L)
{
  Proto *pt = check_LCL(L)->l.p;
  int idx = luaL_checkint(L, 2);
  if (idx < 0) idx = -idx;  /* Handle both positive and negative indices. */
  if (idx >= 1 && idx <= pt->sizek) {
    setobj2s(L, L->top-1, &pt->k[idx-1]);
    lua_pushboolean(L, 1);
    return 2;
  }
  lua_pushnil(L);
  lua_pushboolean(L, 0);
  return 2;
}

/* local upvalue, ok = jit.util.upvalue(func, idx) */
static int ju_upvalue(lua_State *L)
{
  Closure *cl = check_LCL(L);
  Proto *pt = cl->l.p;
  int idx = luaL_checkint(L, 2);
  if (idx >= 0 && idx < pt->nups) {
    setobj2s(L, L->top-1, cl->l.upvals[idx]->v);
    lua_pushboolean(L, 1);
    return 2;
  }
  lua_pushnil(L);
  lua_pushboolean(L, 0);
  return 2;
}

/* local subfunc = jit.util.closure(func, idx, upvalues...) */
static int ju_closure(lua_State *L)
{
  Closure *cl = check_LCL(L);
  Proto *pt = cl->l.p;
  int idx = luaL_checkint(L, 2);
  if (idx >= 0 && idx < pt->sizep) {
    push_LCL(L, pt->p[idx], cl->l.env);
    return 1;
  }
  return 0;
}

/* local nup = jit.util.closurenup(func, idx) */
static int ju_closurenup(lua_State *L)
{
  Closure *cl = check_LCL(L);
  Proto *pt = cl->l.p;
  int idx = luaL_checkint(L, 2);
  if (idx >= 0 && idx < pt->sizep) {
    lua_pushinteger(L, pt->p[idx]->nups);
    return 1;
  }
  return 0;
}

/* local mcode, addr = jit.util.mcode(func) */
static int ju_mcode(lua_State *L)
{
  Proto *pt = check_LCL(L)->l.p;
  if (pt->jit_sizemcode == 0) { /* Not compiled (yet): return nil, status. */
    lua_pushnil(L);
    lua_pushinteger(L, pt->jit_status);
    return 2;
  } else {
    lua_pushlstring(L, (const char *)pt->jit_mcode, pt->jit_sizemcode);
    lua_pushnumber(L, (lua_Number)(size_t)pt->jit_mcode);
    return 2;
  }
}

/* local addr = jit.util.mcodeaddr(func, pc) */
static int ju_mcodeaddr(lua_State *L)
{
  Proto *pt = check_LCL(L)->l.p;
  int idx = luaL_checkint(L, 2);
  /* Allow for PC 0 (currently unused), PC last+1 (.tail) and maybe more. */
  if (pt->jit_pcaddr != NULL && idx >= 0 && idx < pt->sizecode+PCADDR_EXTRA) {
    lua_pushnumber(L, (lua_Number)(size_t)pt->jit_pcaddr[idx]);
    return 1;
  }
  return 0;
}

/* local mcode, base = jit.util.jsubmcode() */
static int ju_jsubmcode(lua_State *L)
{
  jit_State *J = G(L)->jit_state;
  lua_pushlstring(L, (const char *)J->jsubmcode, J->sizejsubmcode);
  lua_pushnumber(L, (lua_Number)(size_t)J->jsubmcode);
  return 2;
}

/* jit.util.* functions. */
static const luaL_Reg jitutillib[] = {
  {"stats",		ju_stats },
  {"bytecode",		ju_bytecode },
  {"const",		ju_const },
  {"upvalue",		ju_upvalue },
  {"closure",		ju_closure },
  {"closurenup",	ju_closurenup },
  {"mcode",		ju_mcode },
  {"mcodeaddr",		ju_mcodeaddr },
  {"jsubmcode",		ju_jsubmcode },
  { NULL, NULL }
};

/* Make hint name to hint number map. */
static void makehints(lua_State *L, const char *const *t, int tmax,
		      const char *name)
{
  int i;
  lua_createtable(L, 0, tmax);
  for (i = 1; i < tmax; i++) {
    lua_pushinteger(L, JIT_H2NUM(i));
    lua_setfield(L, -2, t[i-1]);
  }
  lua_setfield(L, -2, name);
}

/* CHECK: This must match with ljit.h (grep "ORDER JIT_S"). */
static const char *const status_list[] = {
  "OK",
  "NONE",
  "OFF",
  "ENGINE_OFF",
  "DELAYED",
  "TOOLARGE",
  "COMPILER_ERROR",
  "DASM_ERROR"
};

/* Make bidirectional status name to status number map. */
static void makestatus(lua_State *L, const char *name)
{
  int i;
  lua_createtable(L, JIT_S_MAX, JIT_S_MAX);
  for (i = 0; i < JIT_S_MAX; i++) {
    lua_pushstring(L, status_list[i]);
    lua_pushinteger(L, i);
    lua_pushvalue(L, -2);
    lua_rawseti(L, -4, i);
    lua_rawset(L, -3);
  }
  lua_setfield(L, -2, name);
}

/* ------------------------------------------------------------------------ */

/*
** Open JIT library
*/
LUALIB_API int LUA_CC luaopen_jit(lua_State *L)
{
  /* Add the core JIT library. */
  luaL_register(L, LUA_JITLIBNAME, jitlib);
  makepipeline(L);

  /* Add the utility JIT library. */
  luaL_register(L, LUA_JITLIBNAME ".util", jitutillib);
  makestatus(L, "status");
  makehints(L, hints_H, JIT_H_MAX, "hints");
  makehints(L, hints_HF, JIT_HF_MAX, "fhints");
  lua_pop(L, 1);

  /* Everything ok, so turn the JIT engine on. Vroooom! */
  if (luaJIT_setmode(L, 0, LUAJIT_MODE_ENGINE|LUAJIT_MODE_ON) <= 0)
    /* Ouch. Someone screwed up DynASM or the JSUBs. Probably me. */
    return luaL_error(L, "JIT engine init failed (%08x)",
	G(L)->jit_state->dasmstatus);

  return 1;
}

