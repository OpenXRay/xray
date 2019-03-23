----------------------------------------------------------------------------
-- LuaJIT optimizer add-on module for hinting C library functions.
--
-- Copyright (C) 2005 Mike Pall. All rights reserved.
-- Released under the MIT/X license. See luajit.h for full copyright notice.
----------------------------------------------------------------------------
-- This is a simple framework for C function signature maps.
-- It helps with type propagation and C function inlining.
--
-- This module is automatically loaded with -O2 and above.
-- By default most standard library functions are added.
--
-- TODO: generalize it, e.g. for back propagation (i.e. arg types).
-- TODO: extend it for Lua functions (but need to analyze them before use).
------------------------------------------------------------------------------

-- Cache some library functions and objects.
local jit = require("jit")
local jutil = require("jit.util")
local type, rawget = type, rawget
local hints, fhints = jutil.hints, jutil.fhints

-- Turn compilation off for the whole module. LuaJIT would do that anyway.
jit.off(true, true)

-- Dummy objects.
local emptytable = {}
local dummycfunc = collectgarbage -- Pretty sure this is never inlined.


-- Map from C closures to signatures. Avoid holding on to dead functions.
local map_sign = setmetatable({}, { __mode = "k" })

-- Functions to manage the signature map.
local function addfunc(f, libname, name, idx, ...)
  if f then map_sign[f] = { libname = libname, name = name, idx = idx, ...} end
end

local function getname_(f)
  local sign = map_sign[f]
  if sign then
    local libname, name = sign.libname, sign.name
    if libname then
      return libname.."."..name
    else
      return name
    end
  else
    return "?"
  end
end

-- Name, base table and running index for convenience functions.
-- CHECK: the base index and the order below must match with the backend.
local flibname, flib, fidx

local function fadd(name, ...)
  local f = rawget(flib, name)
  if f then
    map_sign[f] = { libname = flibname, name = name, idx = fidx, ... }
  end
  fidx = fidx + 1
end

local function faddf(name, f, ...)
  map_sign[f] = { libname = flibname, name = name, idx = fidx, ... }
  fidx = fidx + 1
end

-- Signatures for base library functions.
-- Note: Only add functions where result type hints or inlining makes sense.
flibname, flib, fidx = nil, _G, 65536*1
fadd("type",		"")
fadd("getmetatable",	emptytable)
fadd("setmetatable",	emptytable)
fadd("rawequal",	true)
fadd("rawget",		"") -- Guess.
fadd("rawset",		emptytable)
fadd("assert",		1) -- Guess.
fadd("tonumber",	1)
fadd("tostring",	"")
fadd("unpack",		"", "", "", "", "") -- Guess.
fadd("select",		"") -- Guess.
fadd("require",		emptytable)
fadd("print"		)
fadd("pairs",		next, emptytable, "", "", "") -- Guess.
fadd("next",		"", "") -- Guess.
if ipairs then
  local ipairs_iter = ipairs(emptytable)
  fadd("ipairs",			ipairs_iter, emptytable, 1, 1, "")
  faddf("ipairs_iter", ipairs_iter,	1, "") -- Guess.
end

-- Signatures for coroutine library functions.
flibname, flib, fidx = "coroutine", coroutine, 65536*2
if flib then
  fadd("yield"		) -- No guess.
  fadd("resume",	true) -- No guess.
  fadd("create"		) -- Really a thread.
  fadd("wrap",		dummycfunc) -- The wrapper is a C function.
  fadd("status",	"")
  fadd("running"	) -- Really a thread.
end

-- Signatures for string library functions.
flibname, flib, fidx = "string", string, 65536*3
if flib then
  fadd("len",		1)
  fadd("sub",		"")
  fadd("char",		"")
  fadd("byte",		1, 1)
  fadd("rep",		"")
  fadd("reverse",	"")
  fadd("upper",		"")
  fadd("lower",		"")
  fadd("format",	"")
  fadd("find",		1, 1, "", "", "")
  fadd("match",		"", "", "")
  fadd("gsub",		"", 1)
  if flib.gmatch then
    local gmatch_iter = flib.gmatch("", "")
    fadd("gmatch",			gmatch_iter, "", "", "", "")
    faddf("gmatch_iter", gmatch_iter,	"", "", "", "")
  end
end

-- Signatures for table library functions.
flibname, flib, fidx = "table", table, 65536*4
if flib then
  fadd("insert"		)
  fadd("remove",	"") -- Guess.
  fadd("concat",	"")
  fadd("getn",		1)
end

-- Signatures for math library functions.
flibname, flib, fidx = "math", math, 65536*5
if flib then
  fadd("abs",		0.5) -- Depends on arg.
  fadd("sin",		0.5)
  fadd("sinh",		0.5)
  fadd("cos",		0.5)
  fadd("cosh",		0.5)
  fadd("tan",		0.5)
  fadd("tanh",		0.5)
  fadd("asin",		0.5)
  fadd("acos",		0.5)
  fadd("atan",		0.5)
  fadd("atan2",		0.5)
  fadd("ceil",		1)
  fadd("floor",		1)
  fadd("fmod",		1) -- Guess.
  fadd("modf",		1, 0.5)
  fadd("frexp",		0.5, 1)
  fadd("ldexp",		1) -- Guess.
  fadd("sqrt",		0.5)
  fadd("min",		1) -- Depends on args.
  fadd("max",		1) -- Depends on args.
  fadd("log",		0.5)
  fadd("log10",		0.5)
  fadd("exp",		0.5)
  fadd("deg",		0.5)
  fadd("pow",		0.5)
  fadd("rad",		0.5)
  fadd("random",	1) -- Depends on args.
  fadd("randomseed"	)
end

-- Signatures for I/O library functions.
flibname, flib, fidx = "io", io, 65536*6
if flib then
  fadd("lines",		dummycfunc, "", "", "")
  fadd("read",		"")
  -- Adding io methods doesn't work, because we don't deal with userdata (yet).
end


-- Set type hints for call results during forward propagation.
-- Set inline hints, too.
local function fwdcallhint(st, slot, pc, base, narg, res, nres)
  local f = slot[base]
  st[pc+hints.TYPE] = f
  -- Clear result type hints. Caveat: clears args, too.
  for i=res,res+nres-1 do slot[i] = nil end
  if type(f) == "function" then
    local sign = map_sign[f]
    if sign then
      local idx = sign.idx
      if idx then
	st[pc+hints.INLINE_IDX] = idx
	st[pc+hints.INLINE_MATCH] = f
      end
      -- Add result type hints.
      for i=1,#sign do slot[res+i-1] = sign[i] end
    end
  end
end

-- Attach call hinter to optimizer.
local function start_()
  local jopt = require "jit.opt"
  jopt.attach_callhint(fwdcallhint)
  -- Note that just loading the optimizer does not start it, yet.
end


-- Public module functions.
module(...)

add = addfunc -- Caveat: the API is still in flux.
getname = getname_
start = start_

