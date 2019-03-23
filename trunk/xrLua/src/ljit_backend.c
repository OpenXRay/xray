/*
** LuaJIT wrapper for architecture-specific compiler backend.
** Copyright (C) 2005 Mike Pall. See Copyright Notice in luajit.h
*/

#include <math.h>
#include <string.h>

#define ljit_backend_c
#define LUA_CORE

#include "lua.h"

#include "lobject.h"
#include "lstate.h"
#include "ldo.h"
#include "lfunc.h"
#include "lgc.h"
#include "lstring.h"
#include "ltable.h"
#include "ltm.h"
#include "lvm.h"
#include "lopcodes.h"
#include "ldebug.h"

#include "ljit.h"
#include "ljit_hints.h"
#include "ljit_dasm.h"

/* ------------------------------------------------------------------------ */

/* Include pre-processed architecture-specific backend. */
#if defined(__i386) || defined(__i386__) || defined(_M_IX86)
#include "ljit_x86.h"
#else
#error "No support for this architecture (yet)"
#endif

/* ------------------------------------------------------------------------ */

#define jit_next_jmp(J) \
  (jit_assert(GET_OPCODE(*J->nextins)==OP_JMP), \
   (++J->nextpc) + GETARG_sBx(*J->nextins++))

/* Compile prototype. */
static int jit_compile_proto(jit_State *J)
{
  int status, lastpc;

  J->nextpc = 1;
  J->nextins = J->pt->code;
  lastpc = J->pt->sizecode;
  dasm_setup(Dst, jit_actionlist, lastpc+PCADDR_EXTRA);

  jit_prologue(J);

  while (J->nextpc <= lastpc) {
    Instruction ins = *J->nextins++;
    OpCode op = GET_OPCODE(ins);
    int ra = GETARG_A(ins);
    int rb = GETARG_B(ins);
    int rc = GETARG_C(ins);
    int rbx = GETARG_Bx(ins);

    jit_ins_start(J);
    J->nextpc++;

    if (hint_isset(J, DEAD))
      continue;

    if (J->flags & JIT_F_DEBUG_INS)
      jit_ins_debug(J, luaG_checkopenop(ins));

    switch (op) {
    case OP_MOVE: jit_op_move(J, ra, rb); break;
    case OP_LOADK: jit_op_loadk(J, ra, rbx); break;
    case OP_LOADBOOL: jit_op_loadbool(J, ra, rb, rc); break;
    case OP_LOADNIL: jit_op_loadnil(J, ra, rb); break;

    case OP_GETUPVAL: jit_op_getupval(J, ra, rb); break;
    case OP_SETUPVAL: jit_op_setupval(J, ra, rb); break;

    case OP_GETGLOBAL: jit_op_getglobal(J, ra, rbx); break;
    case OP_SETGLOBAL: jit_op_setglobal(J, ra, rbx); break;

    case OP_NEWTABLE: jit_op_newtable(J, ra, rb, rc); break;
    case OP_GETTABLE: jit_op_gettable(J, ra, rb, rc); break;
    case OP_SETTABLE: jit_op_settable(J, ra, rb, rc); break;
    case OP_SELF: jit_op_self(J, ra, rb, rc); break;
    case OP_SETLIST: jit_op_setlist(J, ra, rb, rc); break;

    case OP_ADD: jit_op_arith(J, ra, rb, rc, TM_ADD, 0); break;
    case OP_SUB: jit_op_arith(J, ra, rb, rc, TM_SUB, 0); break;
    case OP_MUL: jit_op_arith(J, ra, rb, rc, TM_MUL, 0); break;
    case OP_DIV: jit_op_arith(J, ra, rb, rc, TM_DIV, 0); break;
    case OP_MOD: jit_op_arith(J, ra, rb, rc, TM_MOD, 0); break;
    case OP_POW: jit_op_arith(J, ra, rb, rc, TM_POW, 0); break;

    case OP_UNM: jit_op_unm(J, ra, rb); break;
    case OP_LEN: jit_op_len(J, ra, rb); break;
    case OP_NOT: jit_op_not(J, ra, rb); break;

    case OP_CONCAT: jit_op_concat(J, ra, rb, rc); break;

    case OP_EQ: jit_op_eq(J, ra, rb, rc, jit_next_jmp(J)); break;
    case OP_LT: jit_op_arith(J, ra, rb, rc, TM_LT, jit_next_jmp(J)); break;
    case OP_LE: jit_op_arith(J, ra, rb, rc, TM_LE, jit_next_jmp(J)); break;

    case OP_TEST: jit_op_test(J, rc, ra, ra, jit_next_jmp(J)); break;
    case OP_TESTSET: jit_op_test(J, rc, ra, rb, jit_next_jmp(J)); break;

    case OP_JMP: jit_op_jmp(J, J->nextpc + rbx-MAXARG_sBx); break;

    case OP_CALL: jit_op_call(J, ra, rb-1, rc-1); break;
    case OP_TAILCALL: jit_op_tailcall(J, ra, rb-1); break;
    case OP_RETURN: jit_op_return(J, ra, rb-1); break;

    case OP_FORLOOP: jit_op_forloop(J, ra, J->nextpc + rbx-MAXARG_sBx); break;
    case OP_FORPREP: jit_op_forprep(J, ra, J->nextpc + rbx-MAXARG_sBx); break;

    case OP_TFORLOOP: jit_op_tforloop(J, ra, rc, jit_next_jmp(J)); break;

    case OP_CLOSE: jit_op_close(J, ra); break;
    case OP_CLOSURE: jit_op_closure(J, ra, rbx); break;

    case OP_VARARG: jit_op_vararg(J, ra, rb-1); break;

    default: jit_assert(0); break;
    }

    /* Convention: all opcodes start and end with the .code section. */
    if (dasm_checkstep(Dst, DASM_SECTION_CODE)) { J->nextpc--; goto asmerr; }
  }
  jit_ins_last(J);

asmerr:
  status = luaJIT_link(J, &J->pt->jit_mcode, &J->pt->jit_sizemcode);
  if (status != JIT_S_OK)
    return status;

  J->pt->jit_pcaddr = luaM_newvector(J->L, lastpc+PCADDR_EXTRA, void *);
  dasm_getlabels(Dst, J->pt->jit_mcode, J->pt->jit_pcaddr);

  return JIT_S_OK;
}

/* ------------------------------------------------------------------------ */

/* Compiler backend. */
int luaJIT_backend(lua_State *L)
{
  jit_State *J = G(L)->jit_state;
  const TValue *cl;
  int status = JIT_S_COMPILER_ERROR;
  lua_lock(L);
  /* Remember compiler state table. */
  jit_assert(L->top > L->base && ttistable(L->top-1));
  J->comstate = hvalue(L->top-1);
  /* Fetch prototoype. Better check this in case some handler screwed up. */
  cl = luaH_getstr(J->comstate, luaS_newliteral(L, "func"));
  if (isLfunction(cl)) {
    J->pt = clvalue(cl)->l.p;
    if (J->pt->sizecode > LUAJIT_LIM_BYTECODE) {  /* Hard backend limit. */
      status = JIT_S_TOOLARGE;
    } else if (J->pt->jit_sizemcode != 0) {  /* Prevent recompilation. */
      status = JIT_S_OK;
    } else {  /* Compile prototype. */
      status = jit_compile_proto(J);
    }
  }
  lua_unlock(L);
  J->comstate = NULL;  /* Just in case. */
  J->pt = NULL;
  if (status == JIT_S_OK) {
    return 0;
  } else {
    if (status == JIT_S_DASM_ERROR) {
      lua_pushinteger(L, J->nextpc);
      lua_setfield(L, 1, "dasm_pc");
      lua_pushinteger(L, J->dasmstatus);
      lua_setfield(L, 1, "dasm_err");
    }
    lua_pushinteger(L, status);
    return 1;
  }
}

/* Initialize compiler backend. */
int luaJIT_initbackend(lua_State *L)
{
  jit_State *J = G(L)->jit_state;
  J->L = L;
  J->pt = NULL;  /* Not in use. */
  J->jsub = NULL;
  J->jsubmcode = NULL;
  J->sizejsubmcode = 0;
  J->mcodeheap = NULL;
  J->D = NULL;
  dasm_init(Dst, DASM_MAXSECTION);
  J->jsub = luaM_newvector(J->L, JSUB_MAX, void *);
  return jit_compile_jsub(J);
}

/* Free compiler backend. */
void luaJIT_freebackend(lua_State *L)
{
  jit_State *J = G(L)->jit_state;
  J->L = L;
  if (J->jsub) luaM_freearray(L, J->jsub, JSUB_MAX, void *);
  luaJIT_freemcodeheap(J);  /* Frees JSUB mcode, too. */
  dasm_free(Dst);
}

/* ------------------------------------------------------------------------ */

