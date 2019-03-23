----------------------------------------------------------------------------
-- LuaJIT machine code dumper module.
--
-- Copyright (C) 2005 Mike Pall. All rights reserved.
-- Released under the MIT/X license. See luajit.h for full copyright notice.
----------------------------------------------------------------------------
-- Activate this module to dump the machine code for all functions
-- immediately after they have been compiled. The disassembler
-- output is mixed with the bytecode listing.
--
-- Try: luajit -j dump -e 'print "foo"'
--      luajit -j dump=foo.dump foo.lua
--      luajit -j off -j dump -e 'jit.compile(assert(loadfile"foo.lua")))'
--
-- Default output is to stderr. To redirect output to a file,
-- pass a filename as an argument or set the environment variable
-- "LUAJIT_DUMPFILE".
-- Note: The file is overwritten each time you run luajit.
--
-- Note: 'ndisasm' must be in your path or this module will fail.
--       Get it from http://nasm.sf.net/
--
-- TODO: Find a way to be more selective on what to dump.
------------------------------------------------------------------------------

-- Priority for compiler pipeline. Must run after backend (negative)
-- and should be even because we only catch successful compiles.
local PRIORITY = -98

-- Cache some library functions and objects.
local jit = require("jit")
local jutil = require("jit.util")
local type, format = type, string.format
local bytecode, const = jutil.bytecode, jutil.const
local stderr = io.stderr

-- Turn compilation off for the whole module. LuaJIT would do that anyway.
jit.off(true, true)

-- Separator line.
local sepline = "-------------------------------"


-- Return output from disassembler in a single (huge) string.
local function disass_(code, base)
  if code == nil or code == "" then return "" end
  local itmp = os.tmpname()
  local f = assert(io.open(itmp, "wb"))
  f:write(code)
  f:close()
  local cmd = format("ndisasm -u -o 0x%08x %s", base or 0, itmp)
  local f, err = io.popen(cmd, "r")
  if not f then os.remove(itmp); error(err, 0) end
  local txt = f:read("*a")
  f:close()
  os.remove(itmp)
  if txt == "" then error("ndisasm must be in your path", 0) end
  return txt
end

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

-- Pretty-print a bytecode instruction (one or two lines).
local function bytecodeline(func, pc)
  local op, a, b, c, test = bytecode(func, pc)
  if not op then return format("%s [tail code]", sepline) end
  if op == "JMP" then
    return format("\n--%04d--  JMP   -> %04d", pc, pc+1+b)
  end
  if op == "FORLOOP" or op == "FORPREP" then
    return format("\n--%04d--  %-9s %3d -> %04d", pc, op, a, pc+1+b)
  end
  local s = format("\n--%04d--  %-9s %3d %4s %4s", pc, op, a, b or "", c or "")
  if b and b < 0 then s = s.." ; "..conststr(func, b) end
  if c and c < 0 then s = s.." ; "..conststr(func, c) end
  if test then s = s..bytecodeline(func, pc+1) end
  return s
end

-- Dump machine code and intersperse it with the bytecode listing.
local function dumpfunc(func, out)
  if not out then out = stderr end
  local code, addr = jutil.mcode(func)
  if not code then return addr end -- Not compiled: return status.

  local txt = disass_(code, addr)

  -- Set up a map from mcode addresses to bytecode instruction numbers.
  local pcmap = {}
  for pc=1,1e6 do
    local addr = jutil.mcodeaddr(func, pc)
    if not addr then break end
    if addr ~= 0 then pcmap[format("%08X", addr)] = pc end
    -- TODO: coalesce shortcuts, but do not print dead instructions.
  end

  -- Intersperse the bytecode listing.
  txt = string.gsub(txt, "\n(%x%x%x%x%x%x%x%x)", function(x)
    local pc = pcmap[x]
    if not pc then return "\n"..x end
    return "\n"..bytecodeline(func, pc).."\n"..x
  end)

  -- Print header, the disassembly and a footer.
  local info = debug.getinfo(func, "S")
  out:write(sepline, " ", info.source, ":", info.linedefined, "\n",
	    txt, sepline, "\n")
  out:flush()
end

-- Dump the internal JIT subroutines.
local function dumpjsub_(out)
  if not out then out = stderr end
  out:write(disass_(jutil.jsubmcode()))
  out:flush()
end


-- Active flag and output file handle.
local active, out

-- Dump handler for compiler pipeline.
local function h_dump(st)
  local ok, err = pcall(dumpfunc, st.func, out)
  if not ok then
    stderr:write("\nERROR: jit.dump disabled: ", err, "\n")
    jit.attach(h_dump) -- Better turn ourselves off after a failure.
    if out then out:close() end
    out = nil
    active = nil
  end
end

-- Detach dump handler from compiler pipeline.
local function dumpoff()
  if active then
    active = false
    jit.attach(h_dump)
    if out then out:close() end
    out = nil
  end
end

-- Open the output file and attach dump handler to compiler pipeline.
local function dumpon(filename)
  if active then dumpoff() end
  local outfile = filename or os.getenv("LUAJIT_DUMPFILE")
  out = outfile and assert(io.open(outfile, "w"))
  jit.attach(h_dump, PRIORITY)
  active = true
end


-- Public module functions.
module(...)

disass = disass_
dump = dumpfunc
dumpjsub = dumpjsub_
on = dumpon
off = dumpoff
start = dumpon -- For -j command line option.

