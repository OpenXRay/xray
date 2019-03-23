/*
** Interface to JIT engine.
** Copyright (C) 2005 Mike Pall. See Copyright Notice in luajit.h
*/

#define ljit_core_c
#define LUA_CORE

#include "lua.h"

#include "lobject.h"
#include "lstate.h"
#include "ldo.h"

#include "ljit.h"
#include "luajit.h"


/* ------------------------------------------------------------------------ */

/* Initialize JIT engine state. */
void luaJIT_initstate(lua_State *L)
{
  jit_State *J = luaM_new(L, jit_State);
  G(L)->jit_state = J;
  /* Clear JIT engine fields. */
  J->frontwrap = NULL;  /* Filled in by ljitlib before enabling the engine. */
  J->flags = 0;  /* Disable the JIT engine by default. */
  /* Try to initialize the backend. */
  if (luaJIT_initbackend(L) != JIT_S_OK)
    J->flags = JIT_F_INIT_FAILED;
  J->L = NULL;  /* No compiler thread allocated, yet. */
}

/* Free JIT engine state. */
void luaJIT_freestate(lua_State *L)
{
  jit_State *J = G(L)->jit_state;
  if (J == NULL) return;
  luaJIT_freebackend(L);
  luaM_free(L, J);
  G(L)->jit_state = NULL;
}

/* ------------------------------------------------------------------------ */

/* Find relative PC for a bytecode pointer or a JIT mcode address. */
int luaJIT_currentpc(lua_State *L, Proto *pt, const Instruction *savedpc)
{
  ptrdiff_t pc = savedpc - pt->code;
  if (pc >= 0 && pc <= pt->sizecode) { /* Bytecode pointer? */
    return (int)pc-1;
  } else {  /* Else translate JIT mcode address to PC. */
    /* TODO: can assume monotonic addresses (with NULLs). Use binary search? */
    char *addr = (char *)savedpc;
    for (pc = pt->sizecode; pc > 0; pc--) {
      char *a = (char *)pt->jit_pcaddr[pc];
      if (a && addr > a) return (int)pc;
    }
    return 0;
  }
}

/* ------------------------------------------------------------------------ */

/* Compile a prototype. */
/* Note: func pointer may be invalidated because of stack reallocation. */
static int jit_compile(lua_State *L, StkId func, int nargs, int force)
{
  jit_State *J = G(L)->jit_state;
  Closure *cl = clvalue(func);
  Proto *pt = cl->l.p;
  int status;

  /* Check if JIT engine is enabled and prevent recursive invocation. */
  if ((J->flags & JIT_F_INIT_FAILED) ||
      (!force && !(J->flags & JIT_F_ON)) ||
      !J->frontwrap) {
    status = JIT_S_ENGINE_OFF;
  } else if (J->flags & JIT_F_COMPILING) {
    status = JIT_S_DELAYED;
  } else if (pt->jit_sizemcode != 0) {  /* Prevent recompilation. */
    status = JIT_S_OK;
  } else {
    /* Call frontend wrapper. */
    J->flags |= JIT_F_COMPILING;
    lua_unlock(L);
    status = J->frontwrap(L, nargs);
    lua_lock(L);
    J->flags &= ~JIT_F_COMPILING;
  }

  /* Better sanity check what the frontend returns. */
  if ((status == JIT_S_OK && pt->jit_sizemcode == 0) || status == JIT_S_NONE)
    status = JIT_S_COMPILER_ERROR;

  /* Update closure callgate and prototype status. */
  cl->l.jit_gate = (status == JIT_S_OK) ? (lua_CFunction)pt->jit_mcode :
					  G(L)->jit_gateJL;
  pt->jit_status = status;
  return status;
}

/* ------------------------------------------------------------------------ */

/* Compile and run a function. To be used by luaD_precall() only. */
int luaJIT_run(lua_State *L, StkId func, int nresults)
{
  ptrdiff_t funcr = savestack(L, func);
  int status = jit_compile(L, func, L->top-func-1, 0);  /* Compile function. */
  func = restorestack(L, funcr);

  /* Run the compiled function on success. Fallback to bytecode on failure. */
  if (status == JIT_S_OK)
    return G(L)->jit_gateLJ(L, func, nresults);
  else
    return luaD_precall(L, func, nresults);
  /* Note: We are called from luaD_precall and we call it again. */
  /* So jit_compile makes sure pt->jit_status != JIT_S_NONE. */
}

/* ------------------------------------------------------------------------ */

/* API function: Compile a Lua function. Pass arguments as hints. */
int luaJIT_compile(lua_State *L, int nargs)
{
  StkId func;
  int status;
  lua_lock(L);
  api_check(L, (nargs+1) <= (L->top - L->base));
  func = L->top - (nargs+1);
  status = isLfunction(func) ? jit_compile(L, func, nargs, 1) : -1;
  lua_unlock(L);
  return status;
}

/* Recursively set the mode for all subroutines. */
static void rec_setmode(Proto *pt, int on)
{
  int i;
  for (i = 0; i < pt->sizep; i++) {
    Proto *pti = pt->p[i];
    pti->jit_status = on ? (pti->jit_sizemcode?JIT_S_OK:JIT_S_NONE) : JIT_S_OFF;
    rec_setmode(pti, on);  /* Recurse into proto. */
  }
}

/* API function: Set the JIT mode for the whole engine or a function+subs. */
int luaJIT_setmode(lua_State *L, int idx, int mode)
{
  jit_State *J = G(L)->jit_state;
  int mm = mode & LUAJIT_MODE_MASK;
  if (J->flags & JIT_F_INIT_FAILED) return -1;  /* Init failed. */
  switch (mm) {
  case LUAJIT_MODE_ENGINE:		/* Set mode for JIT engine. */
    if (mode & LUAJIT_MODE_ON)
      J->flags |= JIT_F_ON;
    else
      J->flags &= ~JIT_F_ON;
    break;
  case LUAJIT_MODE_DEBUG: {		/* Set debug mode. */
    int dbg;
    switch (idx) {
    case 0: dbg = 0; break;
    case 1: dbg = JIT_F_DEBUG_CALL; break;
    case 2: default: dbg = JIT_F_DEBUG_CALL | JIT_F_DEBUG_INS; break;
    }
    J->flags = (J->flags & ~JIT_F_DEBUG) | dbg;
    luaJIT_debugnotify(J);
    break;
  }
  case LUAJIT_MODE_FUNC:		/* Set mode for function. */
  case LUAJIT_MODE_ALLFUNC:		/* Set mode for function + subfuncs. */
  case LUAJIT_MODE_ALLSUBFUNC: {	/* Set mode for subfunctions. */
    StkId func;
    lua_lock(L);
    func = idx == 0 ? (L->ci-1)->func :
	   (idx > 0 ? L->base + (idx-1) : L->top + idx);
    if (isLfunction(func)) {
      Closure *cl = clvalue(func);
      Proto *pt = cl->l.p;
      if (mm != LUAJIT_MODE_ALLSUBFUNC) {
	if (mode & LUAJIT_MODE_ON) {
	  if (pt->jit_sizemcode) {  /* Already compiled? */
	    cl->l.jit_gate = pt->jit_mcode;  /* Restore callgate. */
	    pt->jit_status = JIT_S_OK;
	  } else {
	    pt->jit_status = JIT_S_NONE;  /* (Re-)enable proto compilation */
	  }
	} else {
	  cl->l.jit_gate = G(L)->jit_gateJL;  /* Default callgate. */
	  pt->jit_status = JIT_S_OFF;  /* Disable proto compilation. */
	  /* Note: compiled code must be retained for suspended threads. */
	}
      }
      if (mm != LUAJIT_MODE_FUNC)
	rec_setmode(pt, mode & LUAJIT_MODE_ON);
      lua_unlock(L);
    } else {
      lua_unlock(L);
      return 0;  /* Failed. */
    }
    break;
  }
  default:
    return 0;  /* Failed. */
  }
  return 1;  /* OK. */
}

/* ------------------------------------------------------------------------ */

