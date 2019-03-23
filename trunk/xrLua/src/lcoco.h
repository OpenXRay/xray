/*
** Lua/Coco glue.
** Copyright (C) 2004-2005 Mike Pall. See copyright notice in lcoco.c
*/

#ifndef lcoco_h
#define lcoco_h

#define LUA_HASCOCO		1

/* Exported C API to add a C stack to a coroutine. */
LUA_API lua_State *LUA_CC lua_newcthread(lua_State *L, int cstacksize);

/* Entry point for coroutine replacement library. */
LUALIB_API int LUA_CC luaopen_coco(lua_State *L); 

/* Internal support routines. */
LUAI_FUNC void luaCOCO_free(lua_State *L);
LUAI_FUNC int luaCOCO_resume(lua_State *L, int nargs);
LUAI_FUNC int luaCOCO_yield(lua_State *L, int nresults);
LUAI_FUNC int luaCOCO_cstacksize(int cstacksize);

/* Forward declaration. */
typedef struct coco_State coco_State;

/* These are redefined below. */
#undef LUAI_EXTRASPACE
#undef luai_userstateopen
#undef luai_userstatefree
#undef luai_userstateresume
#undef luai_userstateyield

/* Use Windows Fibers (Win98+). */
#if defined(_WIN32)

/* Fibers allocate their own stack. The whole Coco state is in front of L. */
struct coco_State {
  void *fib;			/* Own fiber (if any). */
  void *back;			/* Fiber to switch back to. */
  int nargs;			/* Number of arguments to pass. */
  int dummy_align;
};

#define LUAI_EXTRASPACE		sizeof(coco_State)
#define L2COCO(L)		(&((coco_State *)(L))[-1])
#define LHASCOCO(L)		(L2COCO(L)->fib)

#define luai_userstateopen(L)	L2COCO(L)->fib = NULL
#define luai_userstatefree(L)	if (LHASCOCO(L)) luaCOCO_free(L)
#define luai_userstateresume(L, nargs) \
  if (LHASCOCO(L)) return luaCOCO_resume(L, nargs)
#define luai_userstateyield(L, nresults) \
  if (LHASCOCO(L)) return luaCOCO_yield(L, nresults)

#define COCO_USE_FIBERS

#else

/* The Coco state depends on the context switch method used. See lcoco.c. */
/* It's stored at the end of the stack. Only need a pointer in front of L. */
#define L2COCO(L)		(((coco_State **)(L))[-1])
#define LHASCOCO(L)		(L2COCO(L))
/* This wastes some space on 32 bit systems, but gets better alignment. */
#define LUAI_EXTRASPACE		sizeof(LUAI_USER_ALIGNMENT_T)

#define luai_userstateopen(L)	L2COCO(L) = NULL
#define luai_userstatefree(L)	if (LHASCOCO(L)) luaCOCO_free(L)
#define luai_userstateresume(L, nargs) \
  if (LHASCOCO(L)) return luaCOCO_resume(L, nargs)
#define luai_userstateyield(L, nresults) \
  if (LHASCOCO(L)) return luaCOCO_yield(L, nresults)

#endif

#endif
