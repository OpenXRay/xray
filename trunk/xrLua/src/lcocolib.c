/*
** Coroutine library replacement for Coco.
** Copyright (C) 2004-2005 Mike Pall. See copyright notice in lcoco.c
*/
#ifndef COCO_DISABLE

#define lcocolib_c
#define LUA_LIB

#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
#include "lcoco.h"

/*
** The following function are taken almost verbatim from lbaselib.c.
** See copyright notice in lua.h (same license as Coco).
*/

static int auxresume (lua_State *L, lua_State *co, int narg)
{
  int status;
  if (!lua_checkstack(co, narg))
    luaL_error(L, "too many arguments to resume");
  if (lua_status(co) == 0 && lua_gettop(co) == 0) {
    lua_pushboolean(L, 0);
    lua_pushliteral(L, "cannot resume dead coroutine");
    return -1;  /* error flag */
  }
  lua_xmove(L, co, narg);
  status = lua_resume(co, narg);
  if (status == 0 || status == LUA_YIELD) {
    int nres = lua_gettop(co);
    if (!lua_checkstack(L, nres+1))
      luaL_error(L, "too many results to resume");
    lua_pushboolean(L, 1);
    lua_xmove(co, L, nres);  /* move yielded values */
    return nres;
  } else {
    lua_xmove(co, L, 1);  /* move error message */
    lua_pushboolean(L, 0);
    lua_insert(L, -2);
    return -1;  /* error flag */
  }
}

static int co_resume (lua_State *L)
{
  lua_State *co = lua_tothread(L, 1);
  int r;
  luaL_argcheck(L, co, 1, "coroutine expected");
  r = auxresume(L, co, lua_gettop(L) - 1);
  if (r < 0)
    return 2;  /* return false + error message */
  else
    return r + 1;  /* return true + `resume' returns */
}

static int co_yield (lua_State *L)
{
  return lua_yield(L, lua_gettop(L));
}

static int co_auxwrap (lua_State *L)
{
  lua_State *co = lua_tothread(L, lua_upvalueindex(1));
  int r = auxresume(L, co, lua_gettop(L));
  if (r < 0) {
    if (lua_isstring(L, -1)) {  /* error object is a string? */
      luaL_where(L, 1);  /* add extra info */
      lua_insert(L, -2);
      lua_concat(L, 2);
    }
    lua_error(L);  /* propagate error */
  }
  return r;
}

static int co_create(lua_State *L)
{
  int cstacksize = luaL_optint(L, 2, 0);
  lua_State *NL = lua_newcthread(L, cstacksize);
  luaL_argcheck(L, lua_isfunction(L, 1) &&
		   (cstacksize >= 0 ? 1 : !lua_iscfunction(L, 1)),
		1, "Lua function expected");
  lua_pushvalue(L, 1);  /* move function to top */
  lua_xmove(L, NL, 1);  /* move function from L to NL */
  return 1;
}

static int co_wrap (lua_State *L)
{
  co_create(L);
  lua_pushcclosure(L, co_auxwrap, 1);
  return 1;
}

static int co_cstacksize (lua_State *L)
{
  lua_pushinteger(L, luaCOCO_cstacksize(luaL_optint(L, 1, -1)));
  return 1;
}

static luaL_Reg co_lib[] = {
  { "resume",		co_resume },
  { "yield",		co_yield },
  { "create",		co_create },
  { "wrap",		co_wrap },
  { "cstacksize",	co_cstacksize },
  { NULL, NULL }
};


LUA_API int LUA_CC luaopen_coco(lua_State *L)
{
  luaL_register(L, LUA_COLIBNAME, co_lib);
  lua_pushboolean(L, 1);
  lua_setfield(L, -2, "coco");
  return 1;
}

#endif
