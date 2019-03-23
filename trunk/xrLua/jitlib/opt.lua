----------------------------------------------------------------------------
-- LuaJIT optimizer.
--
-- Copyright (C) 2005 Mike Pall. All rights reserved.
-- Released under the MIT/X license. See luajit.h for full copyright notice.
----------------------------------------------------------------------------
-- This module contains a simple optimizer that generates some
-- hints for the compiler backend.
--
-- Compare: luajit -j dump -e 'return 1'
-- with:    luajit -O -j dump -e 'return 1'
--
-- This module uses a very simplistic (but fast) abstract interpretation
-- algorithm. It mostly ignores control flow and/or basic block boundaries.
-- Thus the results of the analysis are really only _hints_. The backend
-- _must_ check the preconditions for these hints (e.g. the object type).
-- Still, the generated hints are pretty accurate and quite useful.
--
-- Note that some hints are really definitive (like DEAD or SHORTCUT_K).
--
-- TODO: Try MFP with an extended lattice. But it's unclear whether the
--       added complexity really pays off with the current backend.
------------------------------------------------------------------------------

-- Priority for compiler pipeline. Right in the middle before the backend.
local PRIORITY = 50

-- Default optimizer level, i.e. what you get with -O.
-- Caveat: this may change in the future when more optimizations are added.
local OPTLEVEL = 2

-- Heuristic limits for what the compiler should reasonably handle.
-- Functions outside these limits are unlikely to be run more than once.
-- Maybe a bit on the generous side. Check ljit.h for backend limits, too.
-- TODO: make it depend on the bytecode distribution, too.
local LIMITS = {
  bytecodes =	1500,
  stackslots =	150,
  params =	20,
  consts =	200,
  subs =	30,
}

-- Cache some library functions and objects.
local jit = require("jit")
local jutil = require("jit.util")
local type, rawget, pcall = type, rawget, pcall
local bytecode, const = jutil.bytecode, jutil.const
local hints, fhints = jutil.hints, jutil.fhints

-- Turn compilation off for the whole module. LuaJIT would do that anyway.
jit.off(true, true)

-- Default optimizer level after loading. But -O runs setlevel(), too.
local optlevel = -1


-- Use iterative path marking to mark live instructions and branch targets.
local function marklive(func)
  local live, work, workn, pc = {}, {}, 0, 1
  repeat
    repeat
      local op, a, b, c, test = bytecode(func, pc)
      live[pc] = true
      pc = pc + 1
      if op == "JMP" then
	pc = pc + b
	live[-pc] = true
      elseif op == "FORLOOP" then
	local mpc = -pc
	live[mpc - b] = true
	live[mpc] = true
      elseif op == "RETURN" then
	break
      elseif test then
	local fpc = pc + 1
	-- No need for fallthrough target mark live[-fpc] in our analysis.
	if not live[fpc] then -- Add fallthrough path to work list.
	  workn = workn + 1
	  work[workn] = fpc
	end
      elseif op == "CLOSURE" then
	pc = pc + jutil.closurenup(func, b)
      elseif op == "LOADBOOL" and c ~= 0 then
	pc = pc + 1
	live[-pc] = true
      elseif op == "SETLIST" and c == 0 then
	pc = pc + 1
      end
    until live[pc]
    if workn == 0 then return live end -- Return if work list is empty.
    pc = work[workn] -- Else fetch next path to mark from work list.
    workn = workn - 1
  until false
end


-- Empty objects.
local function empty() end
local emptytable = {}

-- Dummy function to set call hints. Replaced when jit.opt_lib is loaded.
local function callhint(st, slot, pc, base, narg, res, nres)
  st[pc+hints.TYPE] = slot[base]
  for i=res,res+nres-1 do slot[i] = nil end
end

-- Set type hint for numbers, strings or tables.
local function typehint(st, pc, o)
  local tp = type(o)
  if tp == "number" or tp == "string" or tp == "table" then
    st[pc+hints.TYPE] = o
  end
end

-- Check whether the previous instruction sets a const.
local function prevconst(st, slot, pc, reg)
  if st.live[-pc] == nil then -- Current instruction must not be a target.
    local op, ka, kb = bytecode(st.func, pc-1)
    if ka == reg and (op == "LOADK" or op == "LOADBOOL" or
       (op == "LOADNIL" and kb == reg)) then
      return true, slot[reg]
    end
  end
end

-- Common handler for arithmetic opcodes.
local function arithop(st, slot, pc, a, b, c)
  local nb, nc = slot[b], slot[c]
  if (type(nb) == "number" and nb % 1 ~= 0) or
     (type(nc) == "number" and nc % 1 ~= 0) then
    slot[a] = 0.5 -- Probably a non-integral number.
  else
    slot[a] = 1 -- Optimistic guess.
  end
end

-- Common handler for TEST and TESTSET.
local function testop(st, slot, pc, a, b, c)
  -- Optimize the 'expr and k1 or k2' idiom.
  local ok, k = prevconst(st, slot, pc, b)
  if k and a == b then
    st[pc+hints.DEAD] = true -- Kill the TEST/TESTSET.
    if c == 0 then st.live[pc+1] = nil end -- Kill the JMP.
  end
  slot[a] = slot[b]
end

-- Dispatch table for opcode handlers.
local handler = {
  MOVE = function(st, slot, pc, a, b, c)
    slot[a] = slot[b]
  end,

  LOADK = function(st, slot, pc, a, b, c)
    slot[a] = const(st.func, b)
  end,

  LOADBOOL = function(st, slot, pc, a, b, c)
    slot[a] = (b == 1)
  end,

  LOADNIL = function(st, slot, pc, a, b, c)
    for i=a,b do slot[i] = nil end
  end,

  GETUPVAL = function(st, slot, pc, a, b, c)
    slot[a] = jutil.upvalue(st.func, b)
  end,

  GETGLOBAL = function(st, slot, pc, a, b, c)
    slot[a] = rawget(st.stats.env, const(st.func, b))
  end,

  GETTABLE = function(st, slot, pc, a, b, c)
    if c >= 0 then typehint(st, pc, slot[c]) end
    local t = slot[b]
    slot[a] = type(t) == "table" and rawget(t, slot[c]) or nil
  end,

  SETGLOBAL = empty,

  SETUPVAL = empty, -- TODO: shortcut -- but this is rare?

  SETTABLE = function(st, slot, pc, a, b, c)
    if b >= 0 then typehint(st, pc, slot[b]) end
  end,

  NEWTABLE = function(st, slot, pc, a, b, c)
    slot[a] = emptytable
  end,

  SELF = function(st, slot, pc, a, b, c)
    if c >= 0 then st[pc+hints.TYPE] = "" end -- Simplifies backend.
    local t = slot[b]
    slot[a+1] = t
    if type(t) == "string" then t = string end -- String metatable.
    slot[a] = type(t) == "table" and rawget(t, slot[c]) or nil
  end,

  ADD = arithop, SUB = arithop, MUL = arithop, DIV = arithop,
  MOD = arithop, POW = arithop,
  
  UNM = function(st, slot, pc, a, b, c)
    slot[a] = slot[b] or 1
  end,

  NOT = function(st, slot, pc, a, b, c)
    slot[a] = true
  end,

  LEN = function(st, slot, pc, a, b, c)
    typehint(st, pc, slot[b])
    slot[a] = 1
  end,

  CONCAT = function(st, slot, pc, a, b, c)
    slot[a] = ""
  end,

  JMP = function(st, slot, pc, a, b, c)
    if b >= 0 then -- Kill JMPs across dead code.
      local tpc = pc + b
      while not st.live[tpc] do tpc = tpc - 1 end
      if tpc == pc then st[pc+hints.DEAD] = true end
    end
  end,

  EQ = function(st, slot, pc, a, b, c)
    if b >= 0 and c >= 0 then typehint(st, pc, slot[b] or slot[c]) end
  end,

  LT = empty,

  LE = empty,

  TEST = function(st, slot, pc, a, b, c)
    return testop(st, slot, pc, a, a, c)
  end,

  TESTSET = testop,

  CALL = function(st, slot, pc, a, b, c)
    callhint(st, slot, pc, a, b-1, a, c-1)
  end,

  TAILCALL = function(st, slot, pc, a, b, c)
    callhint(st, slot, pc, a, b-1, a, -1)
  end,

  RETURN = function(st, slot, pc, a, b, c)
    if b == 2 then
      local ok, k = prevconst(st, slot, pc, a)
      if ok then
	st[pc+hints.SHORTCUT_K] = k or empty -- Avoid nil.
	st[pc-1+hints.SHORTCUT_K] = pc
      end
    end
  end,

  FORLOOP = empty,

  FORPREP = function(st, slot, pc, a, b, c)
    local ok, step = prevconst(st, slot, pc, a+2)
    if type(step) == "number" then
      st[pc+hints.FOR_STEP_K] = step
    end
    local nstart, nstep = slot[a], slot[a+2]
    if (type(nstart) == "number" and nstart % 1 ~= 0) or
       (type(nstep) == "number" and nstep % 1 ~= 0) then
      slot[a+3] = 0.5
    else
      slot[a+3] = 1
    end
  end,

  TFORLOOP = function(st, slot, pc, a, b, c)
    callhint(st, slot, pc, a, 2, a+2, c+1)
  end,

  SETLIST = empty, -- TODO: if only (numeric) const: shortcut (+ nobarrier).

  CLOSE = empty,

  CLOSURE = function(st, slot, pc, a, b, c)
    slot[a] = empty
    if st.noclose then
      local nup = jutil.closurenup(st.func, b)
      for i=pc+1,pc+nup do
	local op = bytecode(st.func, i)
	if op == "MOVE" then
	  st.noclose = false
	  return
	end
      end
    end
  end,

  VARARG = function(st, slot, pc, a, b, c)
    local params = st.stats.params
    for i=1,b do slot[a+i-1] = st[params+i] end
  end,
}

-- Generate some hints for the compiler backend.
local function optimize(st)
  local func = st.func
  local stats = jutil.stats(func)
  if not stats then return jutil.status.COMPILER_ERROR end -- Eh?

  -- Check limits.
  if stats.bytecodes > LIMITS.bytecodes or
     stats.stackslots > LIMITS.stackslots or
     stats.params > LIMITS.params or
     stats.consts > LIMITS.consts or
     stats.subs > LIMITS.subs then
    return jutil.status.TOOLARGE
  end

  -- Mark live instructions (live[pc]) and branch targets (live[-pc]).
  local live = marklive(func)

  -- Handlers need access to some temporary state fields.
  st.noclose = true
  st.stats = stats
  st.live = live

  -- Initialize slots with argument hints and constants.
  local slot = {}
  for i=1,stats.params do slot[i-1] = st[i] end
  for i=-1,-256,-1 do -- No need to copy non-RK-able consts.
    local k, ok = const(func, i)
    if not ok then break end
    slot[i] = k
  end

  -- Step through all live instructions, update slots and add hints.
  for pc=1,stats.bytecodes do
    if live[pc] then
      local op, a, b, c, test = bytecode(func, pc)
      handler[op](st, slot, pc, a, b, c)
    else
      st[pc+hints.DEAD] = true
    end
  end

  -- Update function hints.
  if st.noclose then st[fhints.NOCLOSE] = true end

  -- Clear temporary state fields.
  st.noclose = nil
  st.stats = nil
  st.live = nil
end


-- Active flags.
local active, active_opt_lib

-- Handler for compiler pipeline.
local function h_opt(st)
  if optlevel <= 0 then return end
  local ok, err = pcall(optimize, st)
  if not ok then
    io.stderr:write("\nERROR: jit.opt disabled: ", err, "\n")
    jit.attach(h_opt) -- Better turn ourselves off after a failure.
    active = nil
  else
    if err then return err end
  end
end

-- Load add-on module.
local function loadaddon(opt)
  local name, val = string.match(opt, "^(.-)=(.*)$") -- Strip value.
  if not name then name = opt end
  name = "jit.opt_"..name
  local ok, mod = pcall(require, name)
  if not ok then
    -- Return error if not installed, but propagate other errors.
    if string.sub(mod, 1, 7) ~= "module " then error(mod, 0) end
    return "optimizer add-on module "..name.." not found"
  end
  mod.start(val)
end

-- Attach optimizer and set optimizer level or load add-on module.
local function setlevel(opt)
  -- Easier to always attach the optimizer (even for -O0).
  if not active then
    jit.attach(h_opt, PRIORITY)
    active = true
  end

  -- Parse -O<level> or -O<name[=value]>.
  if opt == nil or opt == "" then
    optlevel = OPTLEVEL
  else
    local level = tonumber(opt) -- Numeric level?
    if level then
      if level < 0 or level % 1 ~= 0 then
	error("bad optimizer level", 0)
      end
      optlevel = level
    else
      if optlevel == -1 then optlevel = OPTLEVEL end
      local err = loadaddon(opt)
      if err then error(err, 0) end
    end
  end

  -- Load add-on module for hinting C library functions for -O2 and above.
  if not active_opt_lib and optlevel >= 2 then
    loadaddon("lib") -- Be silent if not installed.
    active_opt_lib = true -- Try this only once.
  end
end


-- Public module functions.
module(...)

-- Callback to allow attaching a call hinter. Used by jit.opt_lib.
function attach_callhint(f)
  callhint = f
end

function getlevel()
  return optlevel
end

setlevel = setlevel
start = setlevel -- For -O command line option.

