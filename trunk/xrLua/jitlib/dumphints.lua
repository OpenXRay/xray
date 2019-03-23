----------------------------------------------------------------------------
-- LuaJIT hints dumper module.
--
-- Copyright (C) 2005 Mike Pall. All rights reserved.
-- Released under the MIT/X license. See luajit.h for full copyright notice.
----------------------------------------------------------------------------
-- Activate this module to dump the bytecode and the hints from
-- the optimizer for all functions to be compiled.
--
-- Try: luajit -O -j dumphints -e 'return 1'
--
-- Default output is to stderr. To redirect output to a file,
-- pass a filename as an argument or set the environment variable
-- "LUAJIT_DUMPHINTSFILE".
-- Note: The file is overwritten each time you run luajit.
--
-- TODO: Find a way to be more selective on what to dump.
------------------------------------------------------------------------------

-- Priority for compiler pipeline. Should run before backend (positive)
-- and should be even because we only catch successful compiles.
local PRIORITY = 10

-- Cache some library functions and objects.
local jit = require("jit")
local jutil = require("jit.util")
local type, pairs, format = type, pairs, string.format
local bytecode, const = jutil.bytecode, jutil.const
local hints, fhints = jutil.hints, jutil.fhints
local stderr = io.stderr

-- Turn compilation off for the whole module. LuaJIT would do that anyway.
jit.off(true, true)

-- Separator line.
local sepline = "-------------------------------"


-- Pretty-print a constant.
local function conststr(func, idx)
  local k = const(func, idx)
  if k == nil then return "nil"
  elseif k == true then return "true"
  elseif k == false then return "false"
  elseif type(k) == "string" then
    if #k > 10 then return format('"%.10s"~', k)
    else return '"'..k..'"' end
  else return k.."" end
end

-- Pretty-print a bytecode instruction.
local function bytecodeline(func, pc, flag)
  local op, a, b, c = bytecode(func, pc)
  if not op then return end
  if op == "JMP" then
    return format("\n%04d %s JMP   -> %04d", pc, flag, pc+1+b)
  end
  if op == "FORLOOP" or op == "FORPREP" then
    return format("\n%04d %s %-9s %3d -> %04d", pc, flag, op, a, pc+1+b)
  end
  local s = format("\n%04d %s %-9s %3d %4s %4s",
		   pc, flag, op, a, b or "", c or "")
  if b and b < 0 then s = s.." ; "..conststr(func, b) end
  if c and c < 0 then s = s.." ; "..conststr(func, c) end
  return s
end

-- Precompute inverse hints table.
local invhints = {}
for k,v in pairs(hints) do invhints[v] = k end

-- The inverse resolver for inline functions is loaded on demand.
local getname

-- Helper functions to pretty-print hints.
local hintprint = {
  TYPE = function(h, v)
    local tp = type(v)
    if tp == "function" then tp = debug.getinfo(v, "S").what end
    if tp == "number" and v % 1 == 0 then tp = "integer" end
    return " #TYPE("..tp..")"
  end,
  INLINE_IDX = function() return "" end,
  INLINE_MATCH = function(h, v)
    if not getname then getname = require("jit.opt_lib").getname end
    return " #INLINE("..getname(v)..")"
  end,
}

-- Dump instructions and hints.
local function dumphints(st, out)
  if not out then out = stderr end
  local func = st.func
  local DEAD = hints.DEAD

  -- Need to recompute branch targets (not part of hints).
  local target = {}
  for pc=1,1e6 do
    local op, a, b, c = bytecode(func, pc)
    if not op then break end
    if op == "JMP" or op == "FORLOOP" then
      local t = pc+1+b
      if not st[pc+DEAD] then target[t] = true end
    elseif op == "LOADBOOL" and c ~= 0 then
      target[pc+2] = true
    end
  end

  -- Map hints to bytecode instructions.
  local hintstr = {}
  for k,v in pairs(st) do
    if type(k) == "number" and k >= DEAD+DEAD then
      local pc = k % DEAD
      if pc > 0 then
	local h = invhints[k-pc]
	local hp = hintprint[h]
	local s = hp and hp(h, v) or (" #"..invhints[k-pc])
	local hs = hintstr[pc]
	hintstr[pc] = hs and (hs..s) or s
      end
    end
  end

  -- Write header.
  local info = debug.getinfo(func, "S")
  out:write(sepline, " ", info.source, ":", info.linedefined)

  -- Write function hints.
  for k,v in pairs(fhints) do
    if st[v] then out:write("\n#", k) end
  end

  -- Write instruction hints and bytecode.
  for pc=1,1e6 do
    local line = bytecodeline(func, pc,
      st[pc+DEAD] and "**" or (target[pc] and "->" or "  "))
    if not line then break end
    local h = hintstr[pc]
    if h then
      out:write(format("%-40s %s", line, h))
    else
      out:write(line)
    end
  end

  -- Write footer.
  out:write("\n", sepline, "\n")
  out:flush()
end


-- Active flag and output file handle.
local active, out

-- Dump hints handler for compiler pipeline.
local function h_dumphints(st)
  local ok, err = pcall(dumphints, st, out)
  if not ok then
    stderr:write("\nERROR: jit.dumphints disabled: ", err, "\n")
    jit.attach(h_dumphints) -- Better turn ourselves off after a failure.
    if out then out:close() end
    out = nil
    active = nil
  end
end

-- Detach dump handler from compiler pipeline.
local function dumphintsoff()
  if active then
    active = false
    jit.attach(h_dumphints)
    if out then out:close() end
    out = nil
  end
end

-- Open the output file and attach dump handler to compiler pipeline.
local function dumphintson(filename)
  if active then dumphintsoff() end
  local outfile = filename or os.getenv("LUAJIT_DUMPHINTSFILE")
  out = outfile and assert(io.open(outfile, "w"))
  jit.attach(h_dumphints, PRIORITY)
  active = true
end


-- Public module functions.
module(...)

dump = dumphints
on = dumphintson
off = dumphintsoff
start = dumphintson -- For -j command line option.

