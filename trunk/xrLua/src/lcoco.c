/*
** Copyright (C) 2004-2005 Mike Pall. All rights reserved.
**
** Permission is hereby granted, free of charge, to any person obtaining
** a copy of this software and associated documentation files (the
** "Software"), to deal in the Software without restriction, including
** without limitation the rights to use, copy, modify, merge, publish,
** distribute, sublicense, and/or sell copies of the Software, and to
** permit persons to whom the Software is furnished to do so, subject to
** the following conditions:
**
** The above copyright notice and this permission notice shall be
** included in all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
** EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
** MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
** IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
** CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
** TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
** SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
**
** [ MIT license: http://www.opensource.org/licenses/mit-license.php ]
*/

/* Coco -- True C coroutines for Lua. http://luajit.luaforge.net/coco.html */
#ifndef COCO_DISABLE

#define lcoco_c
#define LUA_CORE

#include "lua.h"

#include "lobject.h"
#include "lstate.h"
#include "ldo.h"
#include "lvm.h"
#include "lgc.h"


/* ------------------------------------------------------------------------ */

/* Use Windows Fibers. */
#if defined(COCO_USE_FIBERS)

#define _WIN32_WINNT 0x0501
#include <windows.h>

#define COCO_MAIN_DECL		CALLBACK

typedef LPFIBER_START_ROUTINE coco_MainFunc;

// start of code replacement
/**
#define COCO_NEW(OL, NL, cstacksize, mainfunc) \
  if (GetCurrentFiber() == NULL) ConvertThreadToFiber(NULL); \
  if ((L2COCO(NL)->fib = CreateFiber(cstacksize, mainfunc, NL)) == NULL) \
    luaD_throw(OL, LUA_ERRMEM);
/**/

#define COCO_NEW(OL, NL, cstacksize, mainfunc) \
{ void *cur = GetCurrentFiber(); \
    if (cur == NULL || cur == (void *)0x1e00) ConvertThreadToFiber(NULL); } \
  if ((L2COCO(NL)->fib = CreateFiber(cstacksize, mainfunc, NL)) == NULL) \
    luaD_throw(OL, LUA_ERRMEM);
// end of code replacement

#define COCO_FREE(L) \
  DeleteFiber(L2COCO(L)->fib);

#define COCO_JUMPIN(coco) \
  coco->back = GetCurrentFiber(); \
  SwitchToFiber(coco->fib);

#define COCO_JUMPOUT(coco) \
  SwitchToFiber(coco->back);

/* CreateFiber() defaults to STACKSIZE from the Windows module .def file. */
#define COCO_DEFAULT_CSTACKSIZE		0

/* ------------------------------------------------------------------------ */

#else /* !COCO_USE_FIBERS */

/* Try to find a setjmp method unless ucontext is forced. */
#ifndef COCO_USE_UCONTEXT

#include <setjmp.h>

/* Check for supported CPU+OS combinations. */
#if defined(i386) || defined(__i386__) || defined(_M_IX86)

#define COCO_STATE_HEAD		size_t arg0;
#define COCO_SETJMP_X86(coco, stack, a0) \
  stack[COCO_STACKADJUST-1] = 0xdeadc0c0;  /* Dummy return address. */ \
  coco->arg0 = (size_t)(a0);

#if defined(JB_SP) && defined(JB_PC)		/* x86-linux-glibc2 */
#define SETJMP_PATCH(coco, buf, func, stack, a0) \
  buf->__jmpbuf[JB_PC] = (int)(func); \
  buf->__jmpbuf[JB_SP] = (int)(stack); \
  buf->__jmpbuf[JB_BP] = 0; \
  COCO_SETJMP_X86(coco, stack, a0)
#elif defined(_I386_JMP_BUF_H)			/* x86-linux-libc5 */
#define SETJMP_PATCH(coco, buf, func, stack, a0) \
  buf->__sp = (stack); \
  buf->__pc = (func); \
  buf->__bp = NULL; \
  COCO_SETJMP_X86(coco, stack, a0)
#elif defined(__FreeBSD__)			/* x86-FreeBSD */
#define SETJMP_PATCH(coco, buf, func, stack, a0) \
  buf->_jb[2] = (long)(stack); \
  buf->_jb[0] = (long)(func); \
  buf->_jb[3] = 0; /* ebp */ \
  COCO_SETJMP_X86(coco, stack, a0)
#define COCO_STACKADJUST	2
#elif defined(__NetBSD__) || defined(__OpenBSD__) /* x86-NetBSD, x86-OpenBSD */
#define SETJMP_PATCH(coco, buf, func, stack, a0) \
  buf[2] = (long)(stack); \
  buf[0] = (long)(func); \
  buf[3] = 0; /* ebp */ \
  COCO_SETJMP_X86(coco, stack, a0)
#define COCO_STACKADJUST	2
#endif

#elif defined(__x86_64__) || defined(__x86_64)

#define COCO_STATE_HEAD		size_t arg0;

#if defined(JB_RSP) && defined(JB_PC)		/* x64-linux-glibc2 */
#define SETJMP_PATCH(coco, buf, func, stack, a0) \
  buf->__jmpbuf[JB_RSP] = (long)(stack); \
  buf->__jmpbuf[JB_PC] = (long)(func); \
  stack[0] = 0xdeadc0c0;  /* Dummy return address. */ \
  coco->arg0 = (size_t)(a0);
#define COCO_MAIN_PARAM \
  int _a, int _b, int _c, int _d, int _e, int _f, lua_State *L
#endif

#elif defined(PPC) || defined(__ppc__) || defined(__PPC__) || \
      defined(__powerpc__) || defined(__POWERPC__) || defined(_ARCH_PPC)

#define COCO_STACKADJUST	16

#if defined(__MACH__) && defined(_BSD_PPC_SETJMP_H_)	/* ppc32-osx */
#define SETJMP_PATCH(coco, buf, func, stack, a0) \
  buf[0] = (int)(stack); \
  buf[21] = (int)(func); \
  stack[6+8] = (size_t)(a0);
#define COCO_MAIN_PARAM \
  int _a, int _b, int _c, int _d, int _e, int _f, int _g, int _h, lua_State *L
#endif

#endif  /* arch check */

#endif /* !COCO_USE_UCONTEXT */

/* ------------------------------------------------------------------------ */

/* Use setjmp if available. */
#ifdef SETJMP_PATCH

struct coco_State {
#ifdef COCO_STATE_HEAD
  COCO_STATE_HEAD
#endif
  jmp_buf jmp;			/* Own context. */
  jmp_buf back;			/* Context to switch back to. */
  void *allocptr;		/* Pointer to allocated memory. */
  int allocsize;		/* Size of allocated memory. */
  int nargs;			/* Number of arguments to pass. */
};

#ifndef COCO_STACKADJUST
#define COCO_STACKADJUST	1
#endif

#define COCO_FILL(coco, NL, mainfunc) \
{ /* Include the return address to get proper stack alignment. */ \
  size_t *stackptr = &((size_t *)coco)[-COCO_STACKADJUST]; \
  _setjmp(coco->jmp); \
  SETJMP_PATCH(coco, coco->jmp, mainfunc, stackptr, NL) \
}

#define COCO_JUMPIN(coco) \
  if (_setjmp(coco->back) == 0) _longjmp(coco->jmp, 1);

#define COCO_JUMPOUT(coco) \
  if (_setjmp(coco->jmp) == 0) _longjmp(coco->back, 1);

/* ------------------------------------------------------------------------ */

/* Fallback to ucontext. Slower, because it saves/restores signals. */
#else

#include <ucontext.h>

struct coco_State {
  ucontext_t ctx;		/* Own context. */
  ucontext_t back;		/* Context to switch back to. */
  void *allocptr;		/* Pointer to allocated memory. */
  int allocsize;		/* Size of allocated memory. */
  int nargs;			/* Number of arguments to pass. */
};

/* Ugly workaround for makecontext() deficiencies on 64 bit CPUs. */
/* Note that WIN64 (which is LLP64) never comes here. See above. */
#if defined(__LP64__) || defined(_LP64) || INT_MAX != LONG_MAX
/* 64 bit CPU: split the pointer into two 32 bit ints. */
#define COCO_MAIN_PARAM		unsigned int lo, unsigned int hi
#define COCO_MAIN_GETL \
  lua_State *L = (lua_State *)((((unsigned long)hi)<<32)+(unsigned long)lo);
#define COCO_MAKECONTEXT(coco, NL, mainfunc) \
  makecontext(&coco->ctx, mainfunc, 2, \
    (int)(ptrdiff_t)NL, (int)((ptrdiff_t)NL>>32));
#else
/* 32 bit CPU: a pointer fits into an int. */
#define COCO_MAKECONTEXT(coco, NL, mainfunc) \
  makecontext(&coco->ctx, mainfunc, 1, (int)NL);
#endif

#define COCO_FILL(coco, NL, mainfunc) \
  getcontext(&coco->ctx); \
  coco->ctx.uc_link = NULL;  /* We never exit from coco_main. */ \
  coco->ctx.uc_stack.ss_sp = coco->allocptr; \
  coco->ctx.uc_stack.ss_size = (char *)coco - (char *)(coco->allocptr); \
  COCO_MAKECONTEXT(coco, NL, mainfunc)

#define COCO_JUMPIN(coco) \
  swapcontext(&coco->back, &coco->ctx);

#define COCO_JUMPOUT(coco) \
  swapcontext(&coco->ctx, &coco->back);

#endif


/* Common code for setjmp/ucontext to allocate/free the stack. */

typedef void (*coco_MainFunc)(void);

/* Put the Coco state at the end and align it downwards. */
#define ALIGNED_END(p, s, t) \
  ((t *)(((char *)0) + ((((char *)(p)-(char *)0)+(s)-sizeof(t)) & -16)))

/* TODO: use mmap. */
#define COCO_NEW(OL, L, cstacksize, mainfunc) \
{ \
  void *ptr = luaM_malloc(OL, cstacksize); \
  coco_State *coco = ALIGNED_END(ptr, cstacksize, coco_State); \
  coco->allocptr = ptr; \
  coco->allocsize = cstacksize; \
  COCO_FILL(coco, NL, mainfunc) \
  L2COCO(NL) = coco; \
}

#define COCO_FREE(L) \
  luaM_freemem(L, L2COCO(L)->allocptr, L2COCO(L)->allocsize);

#endif /* !COCO_USE_FIBERS */

/* ------------------------------------------------------------------------ */

#ifndef COCO_MIN_CSTACKSIZE
#define COCO_MIN_CSTACKSIZE		4096
#endif

/* Don't use multiples of 64K to avoid aliasing problems. */
#ifndef COCO_DEFAULT_CSTACKSIZE
#define COCO_DEFAULT_CSTACKSIZE		(65536-4096)
#endif

static int defaultcstacksize = COCO_DEFAULT_CSTACKSIZE;

/* Start the Lua or C function. */
static void coco_start(lua_State *L, void *ud)
{
  if (luaD_precall(L, (StkId)ud, LUA_MULTRET) == PCRLUA)
    luaV_execute(L, L->ci - L->base_ci);
}

#ifndef COCO_MAIN_PARAM
#define COCO_MAIN_PARAM		lua_State *L
#endif

#ifndef COCO_MAIN_DECL
#define COCO_MAIN_DECL
#endif

/* Toplevel function for the new coroutine stack. Never exits. */
static void COCO_MAIN_DECL coco_main(COCO_MAIN_PARAM)
{
#ifdef COCO_MAIN_GETL
  COCO_MAIN_GETL
#endif
  coco_State *coco = L2COCO(L);
  for (;;) {
    L->status = luaD_rawrunprotected(L, coco_start, L->top - (coco->nargs+1));
    if (L->status != 0) luaD_seterrorobj(L, L->status, L->top);
    COCO_JUMPOUT(coco)
  }
}

/* Add a C stack to a coroutine. */
lua_State *lua_newcthread(lua_State *OL, int cstacksize)
{
  lua_State *NL = lua_newthread(OL);

  if (cstacksize < 0)
    return NL;
  if (cstacksize == 0)
    cstacksize = defaultcstacksize;
  else if (cstacksize < COCO_MIN_CSTACKSIZE)
    cstacksize = COCO_MIN_CSTACKSIZE;
  cstacksize &= -16;

  COCO_NEW(OL, NL, cstacksize, ((coco_MainFunc)(coco_main)))

  return NL;
}

/* Free the C stack of a coroutine. Called from lstate.c. */
void luaCOCO_free(lua_State *L)
{
  COCO_FREE(L)
}

/* Resume a coroutine with a C stack. Called from ldo.c. */
int luaCOCO_resume(lua_State *L, int nargs)
{
  coco_State *coco = L2COCO(L);
  coco->nargs = nargs;
  COCO_JUMPIN(coco)
  return L->status;
}

/* Yield from a coroutine with a C stack. Called from ldo.c. */
int luaCOCO_yield(lua_State *L, int nresults)
{
  coco_State *coco = L2COCO(L);
  L->base = L->top - nresults;  /* Protect stack slots below. */
  L->status = LUA_YIELD;
  COCO_JUMPOUT(coco)
  L->status = 0;
  {
    StkId base = L->top - coco->nargs;
    StkId rbase = L->base;
    if (rbase < base) {  /* Need to move args down? */
      while (base < L->top)
	setobjs2s(L, rbase++, base++); 
      L->top = rbase;
    }
  }
  L->base = L->ci->base;  /* Restore invariant. */
  return coco->nargs;
}

/* Get/set the default C stack size. */
int luaCOCO_cstacksize(int cstacksize)
{
  int oldsz = defaultcstacksize;
  if (cstacksize >= 0) {
    if (cstacksize == 0)
      cstacksize = COCO_DEFAULT_CSTACKSIZE;
    else if (cstacksize < COCO_MIN_CSTACKSIZE)
      cstacksize = COCO_MIN_CSTACKSIZE;
    defaultcstacksize = cstacksize;
  }
  return oldsz;
}

#endif
