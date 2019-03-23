----------------------------------------------------------------------------
-- LuaJIT compiler tracing module.
--
-- Copyright (C) 2005 Mike Pall. All rights reserved.
-- Released under the MIT/X license. See luajit.h for full copyright notice.
----------------------------------------------------------------------------
-- Activate this module to trace the progress of the JIT compiler.
--
-- Try: luajit -j trace -e 'print "foo"'
--      luajit -j trace=foo.trace foo.lua
--
-- Default output is to stderr. To redirect output to a file,
-- pass a filename as an argument or set the environment variable
-- "LUAJIT_TRACEFILE".
-- Note: the file is overwritten each time you run luajit.
------------------------------------------------------------------------------

-- Priority for compiler pipeline. Must run after backend (negative)
-- and should be odd to catch compiler errors, too.
local PRIORITY = -99

-- Cache some library functions and objects.
local jit = require("jit")
local jutil = require("jit.util")
local type, sub, format = type, string.sub, string.format
local getinfo, justats = debug.getinfo, jutil.stats
local stderr = io.stderr

-- Turn compilation off for the whole module. LuaJIT would do that anyway.
jit.off(true, true)

-- Active flag and output file handle.
local active, out

-- Trace handler for compiler pipeline.
local function h_trace(st, status)
  local o = out or stderr
  local func = st.func
  if type(func) ~= "function" then return end
  local info = getinfo(func, "S")
  local src, line = sub(info.source or "??", 2), info.linedefined or -1
  if status == nil then
    local stats = justats(func)
    if not stats then return end
    o:write(format("[LuaJIT: OK %4d %6d  %s:%d]\n",
		   stats.bytecodes, stats.mcodesize, src, line))
    -- o:write(format("[LuaJIT: OK %4d %6d  %08x  %s:%d]\n",
    -- 		   stats.bytecodes, stats.mcodesize, stats.mcodeaddr,
    -- 		   src, line))
    return
  else
    local stname = jit.util.status[status] or status
    local pc, err = st.dasm_pc, st.dasm_err
    if type(pc) == "number" and type(err) == "number" then
      local op = jutil.bytecode(func, pc) or "END"
      o:write(format("[LuaJIT: %s  %s@%d %08x  %s:%d]\n",
		     stname, op, pc, err, src, line))
    else
      o:write(format("[LuaJIT: %s  %s:%d]\n", stname, src, line))
    end
  end
end

-- Detach trace handler from compiler pipeline.
local function traceoff()
  if active then
    active = false
    jit.attach(h_trace)
    if out then out:close() end
    out = nil
  end
end

-- Open the output file and attach trace handler to compiler pipeline.
local function traceon(filename)
  if active then traceoff() end
  local outfile = filename or os.getenv("LUAJIT_TRACEFILE")
  out = outfile and assert(io.open(outfile, "w"))
  jit.attach(h_trace, PRIORITY)
  active = true
end


-- Public module functions.
module(...)

on = traceon
off = traceoff
start = traceon -- For -j command line option.

