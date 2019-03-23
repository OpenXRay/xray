/*
** Interface to JIT engine.
** Copyright (C) 2005 Mike Pall. See Copyright Notice in luajit.h
*/

#ifndef ljit_h
#define ljit_h

#include "lobject.h"


/* Define this to enable assertions when debugging LuaJIT. */
#ifdef LUAJIT_ASSERT
#include <assert.h>
#define jit_assert(x)	assert(x)
#define DASM_CHECKS
#else
/* A better idea is to enable lua_assert() in luaconf.h. */
#define jit_assert(x)	lua_assert(x)
#endif

/* Define this to set the C stack size for the compiler thread. */
/* The compiler runs on the callers C stack otherwise. */
#undef LUAJIT_COMPILER_CSTACK

/* Hardcoded limits for the backend to avoid useless work. */
/* Note: mind you, these are very generous limits. Check jit.opt, too. */
#define LUAJIT_LIM_BYTECODE	3000	/* Max. # of bytecodes. */
#define LUAJIT_LIM_MCODE	128000	/* Max. mcode size of a function. */

/* Global JIT engine flags. */
#define JIT_F_ON		0x0001	/* JIT engine is on. */
#define JIT_F_COMPILING		0x0002	/* Currently compiling. */
#define JIT_F_INIT_FAILED	0x0004	/* Initialization failed. */

#define JIT_F_CPU_CMOV		0x0010	/* CPU has conditional move support. */

#define JIT_F_DEBUG_CALL	0x0100	/* Compile with call hooks. */
#define JIT_F_DEBUG_INS		0x0200	/* Compile with instruction hooks. */
#define JIT_F_DEBUG		0x0f00	/* Union of all debug flags. */

/* JIT engine status codes for prototypes (grep "ORDER JIT_S"). */
enum {
  JIT_S_OK,		/* OK, code has been compiled. */
  JIT_S_NONE,		/* Nothing analyzed or compiled, yet (default). */

  JIT_S_OFF,		/* Compilation for this prototype disabled. */
  JIT_S_ENGINE_OFF,	/* JIT engine is turned off. */
  JIT_S_DELAYED,	/* Compilation delayed (recursive invocation). */

  JIT_S_TOOLARGE,	/* Bytecode or machine code is too large. */
  JIT_S_COMPILER_ERROR,	/* Error from compiler frontend. */
  JIT_S_DASM_ERROR,	/* Error from DynASM engine. */

  JIT_S_MAX
};

/* Extra slots in pcaddr: [0] = currently unused, [lastpc+1] = .tail. */
#define PCADDR_EXTRA	2


/* Forward declaration for DynASM state. */
struct dasm_State;

/* Frontend wrapper. */
typedef int (*jit_FrontWrap)(lua_State *L, int nargs);

/* Global JIT state. */
typedef struct jit_State {
  /* Permanent backend environment: */
  struct dasm_State *D;	/* DynASM state. Keep this as the first field. */
  void **jsub;		/* Addresses of JIT subroutines. */
  void *jsubmcode;	/* Base address of JSUB mcode. */
  size_t sizejsubmcode;	/* Size of JSUB mcode. */
  void *mcodeheap;	/* Private heap to allocate executable memory from. */

  /* Temporary backend environment (valid only while running): */
  lua_State *L;		/* Compiler thread. */
  Table *comstate;	/* Compiler state table. */
  Proto *pt;		/* Currently compiled prototype. */
  const Instruction *nextins;	/* Pointer to next instruction. */
  int nextpc;		/* Next PC. */
  int dasmstatus;	/* DynASM status code. */

  /* JIT engine fields: */
  jit_FrontWrap frontwrap; /* Compiler frontend wrapper. */
  unsigned int flags;	/* Global JIT engine flags. */
} jit_State;


/* --- ljit_core.c */

/* Initialize and free JIT engine state. */
LUAI_FUNC void luaJIT_initstate(lua_State *L);
LUAI_FUNC void luaJIT_freestate(lua_State *L);

/* Compile and run a function. */
LUAI_FUNC int luaJIT_run(lua_State *L, StkId func, int nresults);

/* Find relative PC for a bytecode pointer or a JIT mcode address. */
LUAI_FUNC int luaJIT_currentpc(lua_State *L, Proto *pt,
                               const Instruction *savedpc);

/* --- ljit_backend.c */

/* Initialize and free compiler backend. */
LUAI_FUNC int luaJIT_initbackend(lua_State *L);
LUAI_FUNC void luaJIT_freebackend(lua_State *L);
/* Compiler backend. */
LUAI_FUNC int luaJIT_backend(lua_State *L);
/* Notify backend that the debug mode may have changed. */
LUAI_FUNC void luaJIT_debugnotify(jit_State *J);


/* ---- ljit_mem.c */

/* Free the mcode heap. */
LUAI_FUNC void luaJIT_freemcodeheap(jit_State *J);
/* Free JIT structures in function prototype. */
LUAI_FUNC void luaJIT_freeproto(lua_State *L, Proto *pt);
/* Link generated code. */
LUAI_FUNC int luaJIT_link(jit_State *J, void **mcodep, size_t *szp);


#endif
