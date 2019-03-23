/*
** Wrapper for architecture-specific DynASM encoder.
** Copyright (C) 2005 Mike Pall. See Copyright Notice in luajit.h
*/

#define ljit_dasm_c
#define LUA_CORE


#include "lua.h"

#include "ljit.h"
#include "ljit_dasm.h"
#include "lmem.h"


/* Glue functions for DynASM memory allocation. */
static void dasm_m_grow(Dst_DECL, void **pp, size_t *szp, int need)
{
  size_t sz = *szp;
  if (sz > (size_t)need) return;
  if (sz < 16) sz = 16;
  while (sz < (size_t)need) sz += sz;
  *pp = luaM_realloc_(J->L, *pp, *szp, sz);
  *szp = sz;
}

static void dasm_m_free(Dst_DECL, void *p, size_t sz)
{
  luaM_freemem(J->L, p, sz);
}


/* Embed architecture-specific DynASM encoder. */
#if defined(__i386) || defined(__i386__) || defined(_M_IX86)
#include "dasm_x86.h"
#else
#error "No support for this architecture (yet)"
#endif


