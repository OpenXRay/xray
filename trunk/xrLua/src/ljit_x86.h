/*
** This file has been pre-processed with DynASM.
** http://luajit.luaforge.net/dynasm.html
** DynASM version 1.0.2, DynASM x86 version 1.0.2
** DO NOT EDIT! The original file is in "ljit_x86.dasc".
*/

/*
** Bytecode to machine code translation for x86 CPUs.
** Copyright (C) 2005 Mike Pall. See Copyright Notice in luajit.h
*/

#define DASM_SECTION_CODE	0
#define DASM_SECTION_TAIL	1
#define DASM_MAXSECTION		2
#define Dt1(_V) (int)&(((lua_State *)0)_V)
#define Dt2(_V) (int)&(((TValue *)0)_V)
#define Dt3(_V) (int)&(((TValue *)0)_V)
#define Dt4(_V) (int)&(((CallInfo *)0)_V)
#define Dt5(_V) (int)&(((LClosure *)0)_V)
#define Dt6(_V) (int)&(((global_State *)0)_V)
#define Dt7(_V) (int)&(((TValue *)0)_V)
#define Dt8(_V) (int)&(((Value *)0)_V)
#define Dt9(_V) (int)&(((CallInfo *)0)_V)
#define DtA(_V) (int)&(((GCObject *)0)_V)
#define DtB(_V) (int)&(((TString *)0)_V)
#define DtC(_V) (int)&(((Table *)0)_V)
#define DtD(_V) (int)&(((CClosure *)0)_V)
#define DtE(_V) (int)&(((Proto *)0)_V)
#define DtF(_V) (int)&(((UpVal *)0)_V)
#define Dt10(_V) (int)&(((Node *)0)_V)
static const unsigned char jit_actionlist[3370] = {
  139,142,237,139,129,237,191,247,249,59,129,237,15,131,244,249,7,255,251,15,
  250,86,232,244,131,196,4,139,158,237,252,255,231,255,251,15,250,156,90,137,
  209,129,252,242,0,0,32,0,82,157,156,90,49,192,57,209,15,132,245,255,64,83,
  15,162,91,137,208,249,1,195,255,254,0,251,15,250,85,137,229,131,236,16,137,
  117,252,252,139,117,8,137,93,252,248,139,93,12,137,125,252,244,139,190,237,
  139,131,237,139,142,237,102,252,255,134,237,252,255,144,237,139,142,237,137,
  190,237,139,145,237,139,69,16,137,150,237,139,145,237,133,192,137,150,237,
  255,15,136,245,254,255,193,224,3,255,193,224,2,141,4,64,255,193,224,4,255,
  1,195,49,201,137,158,237,249,1,137,143,237,129,199,243,57,223,15,130,245,
  1,249,2,102,252,255,142,237,184,241,139,125,252,244,139,93,252,248,139,117,
  252,252,137,236,93,195,251,15,250,139,144,237,129,186,237,243,255,15,133,
  245,255,139,146,237,137,144,237,252,255,226,249,1,139,129,237,137,142,237,
  137,190,237,106,252,255,137,134,237,83,43,158,237,86,232,244,131,196,12,133,
  192,15,133,245,254,255,106,1,86,232,244,131,196,8,249,2,3,158,237,139,190,
  237,195,251,15,250,141,135,237,59,134,237,15,131,246,59,142,237,141,137,237,
  15,132,246,255,137,142,237,137,153,237,137,129,237,139,147,237,129,195,243,
  137,190,237,137,158,237,137,153,237,250,86,252,255,146,237,131,196,4,249,
  2,139,142,237,255,139,185,237,15,132,245,252,139,158,237,137,218,41,195,249,
  3,139,3,131,195,4,137,7,131,199,4,57,211,15,130,245,3,249,4,139,153,237,129,
  233,243,137,142,237,195,144,144,144,144,144,144,144,251,15,250,255,252,246,
  134,237,239,15,133,245,249,249,6,86,252,255,146,237,131,196,4,252,246,134,
  237,239,15,132,245,2,80,106,252,255,104,241,86,232,244,131,196,12,88,233,
  245,2,249,7,255,82,106,252,255,104,241,86,232,244,131,196,12,90,233,245,6,
  251,15,250,41,252,248,137,77,252,240,255,193,252,248,3,255,193,252,248,2,
  105,192,171,170,170,170,255,193,252,248,4,255,137,190,237,43,158,237,80,86,
  232,244,131,196,8,3,158,237,139,190,237,139,131,237,139,77,252,240,252,255,
  160,237,251,15,250,137,190,237,86,232,244,131,196,4,141,136,237,139,131,237,
  255,137,142,237,252,255,160,237,255,251,15,255,137,190,237,255,232,244,255,
  251,15,250,252,246,134,237,239,15,132,245,254,252,255,142,237,15,132,245,
  255,252,246,134,237,239,15,132,245,254,249,1,255,139,4,36,80,86,232,244,131,
  196,8,139,158,237,139,190,237,249,2,195,255,141,135,237,59,134,237,15,131,
  244,59,142,237,141,137,237,15,132,244,49,192,137,153,237,129,195,243,137,
  142,237,255,137,158,237,137,153,237,141,147,237,137,129,237,137,145,237,137,
  150,237,255,141,147,237,57,215,15,130,245,251,249,4,254,1,249,5,137,135,237,
  129,199,243,57,215,15,130,245,5,233,245,4,254,0,137,190,237,137,185,237,137,
  129,237,255,139,139,237,139,147,237,137,143,237,139,139,237,137,151,237,137,
  143,237,137,131,237,255,137,252,251,141,147,237,141,187,237,137,145,237,137,
  150,237,255,137,135,237,255,249,2,137,135,237,137,135,237,129,199,243,57,
  215,15,130,245,2,255,86,232,244,131,196,4,255,252,246,134,237,239,15,133,
  244,255,199,134,237,241,255,251,15,250,139,142,237,139,185,237,139,135,237,
  139,184,237,139,135,237,129,192,243,137,134,237,106,252,255,104,241,86,232,
  244,131,196,12,139,135,237,139,158,237,255,252,255,96,4,255,252,246,134,237,
  239,199,134,237,241,184,247,249,15,133,244,249,7,255,251,15,250,137,195,106,
  252,255,104,241,86,232,244,131,196,12,137,216,139,158,237,139,190,237,252,
  255,224,255,83,86,232,244,131,196,8,255,129,195,243,255,139,145,237,57,252,
  251,15,131,245,254,249,1,139,3,131,195,4,137,2,131,194,4,57,252,251,15,130,
  245,1,249,2,139,153,237,129,233,243,137,215,137,142,237,195,255,137,223,129,
  235,243,129,174,237,243,255,139,142,237,139,153,237,129,233,243,141,187,237,
  137,142,237,255,199,131,237,0,0,0,0,255,184,1,0,0,0,137,131,237,137,131,237,
  255,199,131,237,0,0,0,0,199,131,237,1,0,0,0,255,199,131,237,241,199,131,237,
  241,199,131,237,3,0,0,0,255,199,131,237,241,199,131,237,4,0,0,0,255,129,235,
  243,255,139,139,237,139,147,237,139,131,237,137,139,237,137,147,237,137,131,
  237,255,141,187,237,129,174,237,243,195,255,139,142,237,139,185,237,129,233,
  243,137,142,237,255,139,139,237,139,147,237,139,131,237,137,143,237,137,151,
  237,137,135,237,255,137,252,251,255,129,199,243,255,141,187,237,255,131,187,
  237,6,139,131,237,199,129,237,241,15,133,245,251,249,4,252,255,144,237,255,
  137,158,237,255,49,192,255,141,147,237,249,1,137,135,237,137,135,237,129,
  199,243,57,215,15,130,245,1,255,141,187,237,137,190,237,255,249,5,232,244,
  233,245,4,254,0,251,15,250,139,145,237,137,190,237,137,150,237,83,86,232,
  244,131,196,8,137,195,139,190,237,139,131,237,139,142,237,195,255,131,187,
  237,6,15,133,245,251,255,139,139,237,139,147,237,137,139,237,139,139,237,
  137,147,237,137,139,237,255,141,187,237,129,235,243,139,142,237,137,131,237,
  255,139,142,237,141,187,237,139,153,237,139,135,237,137,131,237,255,139,135,
  237,139,151,237,137,131,237,139,135,237,137,147,237,137,131,237,255,141,187,
  237,139,131,237,255,139,145,237,249,1,139,3,131,195,4,137,2,131,194,4,57,
  252,251,15,130,245,1,139,153,237,137,215,139,131,237,255,129,233,243,252,
  255,160,237,254,1,249,5,255,199,134,237,241,233,244,254,0,251,15,250,137,
  190,237,83,86,232,244,131,196,8,139,142,237,139,150,237,139,185,237,249,1,
  139,24,131,192,4,137,31,131,199,4,57,208,15,130,245,1,139,153,237,139,131,
  237,129,233,243,255,141,139,237,141,147,237,249,1,137,1,57,209,141,137,237,
  15,134,245,1,255,233,246,255,139,142,237,139,185,237,139,135,237,255,139,
  136,237,139,185,237,139,143,237,139,151,237,139,135,237,137,139,237,137,147,
  237,137,131,237,255,139,136,237,139,185,237,139,131,237,139,147,237,137,135,
  237,131,252,248,4,139,131,237,137,151,237,137,135,237,15,131,245,251,249,
  4,254,1,249,5,252,246,130,237,239,15,132,245,4,252,246,129,237,239,15,132,
  245,4,82,81,86,232,244,131,196,12,233,245,4,254,0,251,15,250,15,182,143,237,
  184,1,0,0,0,211,224,72,35,130,237,255,193,224,5,255,105,192,243,255,3,135,
  237,249,1,131,184,237,4,15,133,245,254,57,144,237,15,133,245,254,139,136,
  237,133,201,15,132,245,253,139,144,237,139,184,237,255,137,139,237,137,147,
  237,137,187,237,139,158,237,195,249,2,139,128,237,133,192,15,133,245,1,49,
  201,249,3,139,135,237,133,192,15,132,245,252,252,246,128,237,239,255,15,132,
  245,251,249,4,137,139,237,139,158,237,195,249,5,139,12,36,137,142,237,83,
  82,87,86,232,244,131,196,16,139,158,237,195,255,3,135,237,249,1,131,184,237,
  4,15,133,245,252,57,144,237,15,133,245,252,131,184,237,0,15,132,245,250,249,
  2,198,135,237,0,255,252,246,135,237,239,15,133,245,248,137,199,249,3,139,
  139,237,139,147,237,139,131,237,137,143,237,137,151,237,137,135,237,139,158,
  237,195,249,4,255,139,128,237,133,192,15,133,245,1,139,143,237,133,201,15,
  132,245,251,252,246,129,237,239,15,132,245,249,249,5,129,236,243,141,68,36,
  12,137,124,36,4,137,68,36,8,137,144,237,255,199,128,237,4,0,0,0,137,52,36,
  232,244,129,196,243,233,245,2,249,6,139,143,237,133,201,15,132,245,2,252,
  246,129,237,239,15,133,245,2,249,7,255,139,12,36,137,142,237,83,82,87,86,
  232,244,131,196,16,139,158,237,195,249,8,87,137,199,86,232,244,131,196,8,
  233,245,3,255,104,241,104,241,86,232,244,131,196,12,137,131,237,199,131,237,
  5,0,0,0,255,139,184,237,186,241,255,131,187,237,5,15,133,245,251,255,131,
  187,237,4,15,133,245,251,139,147,237,255,139,187,237,255,232,244,249,4,254,
  1,139,147,237,129,186,237,243,139,186,237,15,130,245,251,255,131,187,237,
  3,15,133,245,251,221,131,237,219,85,252,240,219,69,252,240,255,223,233,221,
  216,255,218,233,223,224,158,255,139,125,252,240,15,133,245,251,15,138,245,
  251,139,147,237,79,59,186,237,15,131,245,251,255,193,231,3,255,193,231,2,
  141,60,127,255,193,231,4,255,3,186,237,255,139,135,237,133,192,15,132,245,
  250,139,143,237,139,151,237,137,139,237,137,147,237,249,1,137,131,237,249,
  4,254,1,249,6,131,186,237,0,15,132,245,1,255,185,241,255,141,139,237,255,
  141,147,237,255,199,134,237,241,83,81,82,86,232,244,131,196,16,139,158,237,
  255,131,187,237,5,15,133,245,251,139,187,237,255,187,241,255,131,191,237,
  0,15,133,245,255,131,186,237,0,15,133,245,251,249,1,255,252,246,130,237,239,
  15,133,245,249,249,3,254,1,249,7,82,86,232,244,131,196,8,233,245,3,254,0,
  199,135,237,0,0,0,0,255,184,1,0,0,0,137,135,237,137,135,237,255,199,135,237,
  0,0,0,0,199,135,237,1,0,0,0,255,199,135,237,241,199,135,237,241,199,135,237,
  3,0,0,0,255,199,135,237,241,199,135,237,4,0,0,0,255,199,134,237,241,82,81,
  83,86,232,244,131,196,16,139,158,237,255,141,131,237,41,252,248,252,247,216,
  255,139,139,237,15,132,245,252,255,129,192,243,255,57,129,237,15,131,245,
  255,80,81,86,232,244,131,196,12,139,139,237,249,1,252,246,129,237,239,139,
  145,237,15,133,245,250,249,2,254,1,249,6,137,85,252,240,81,86,232,244,131,
  196,8,139,85,252,240,233,245,2,254,0,139,187,237,129,191,237,243,15,130,245,
  251,249,1,252,246,135,237,239,139,151,237,15,133,245,250,141,187,237,254,
  1,249,5,104,241,87,86,232,244,131,196,12,233,245,1,249,6,87,86,232,244,131,
  196,8,233,245,1,254,0,129,194,243,255,141,139,237,249,3,139,1,131,193,4,137,
  2,131,194,4,57,252,249,15,130,245,3,249,4,255,131,187,237,3,15,133,245,251,
  255,217,252,238,255,217,232,255,221,5,241,255,131,187,237,3,255,139,131,237,
  193,224,8,11,131,237,129,252,248,243,255,15,133,245,251,221,131,237,255,216,
  192,255,220,131,237,255,220,163,237,255,220,171,237,255,216,200,255,220,139,
  237,255,220,179,237,255,220,187,237,255,15,138,246,255,15,130,246,255,15,
  134,246,255,15,135,246,255,15,131,246,255,221,155,237,255,199,134,237,241,
  82,81,86,232,244,131,196,12,133,192,139,158,237,255,15,133,246,255,199,134,
  237,241,104,241,82,81,83,86,232,244,131,196,20,139,158,237,255,131,187,237,
  3,15,133,245,251,221,131,237,217,224,221,155,237,255,249,5,141,139,237,255,
  199,134,237,241,104,241,81,81,83,86,232,244,131,196,20,139,158,237,233,245,
  4,254,0,139,131,237,139,139,237,255,131,252,248,4,15,133,245,251,219,129,
  237,249,1,221,155,237,199,131,237,3,0,0,0,249,4,254,1,249,5,131,252,248,5,
  15,133,245,250,81,232,244,80,219,4,36,131,196,8,255,131,252,248,5,15,133,
  245,251,81,232,244,80,219,4,36,131,196,8,249,1,221,155,237,199,131,237,3,
  0,0,0,249,4,254,1,249,5,131,252,248,4,15,133,245,250,219,129,237,255,233,
  245,1,249,6,141,139,237,255,199,134,237,241,81,83,86,232,244,131,196,12,139,
  158,237,233,245,4,254,0,139,131,237,139,139,237,186,1,0,0,0,33,193,209,232,
  9,193,49,192,57,209,17,192,137,147,237,137,131,237,255,199,134,237,241,104,
  241,104,241,86,232,244,131,196,12,139,158,237,255,131,187,237,0,255,139,131,
  237,139,139,237,72,73,9,200,255,139,131,237,72,11,131,237,255,131,187,237,
  3,15,133,246,221,131,237,221,5,241,255,131,187,237,4,15,133,246,129,187,237,
  241,255,139,131,237,59,131,237,15,133,246,255,131,252,248,3,15,133,245,251,
  221,131,237,221,131,237,255,15,138,246,249,4,254,1,131,252,248,4,15,133,245,
  251,139,139,237,59,139,237,249,4,254,1,249,5,141,147,237,141,139,237,199,
  134,237,241,82,81,86,232,244,131,196,12,72,139,158,237,255,139,131,237,139,
  139,237,137,194,33,202,141,20,80,209,234,255,15,132,245,255,255,15,133,245,
  255,255,139,147,237,137,131,237,137,139,237,137,147,237,233,246,249,1,255,
  139,139,237,193,225,8,11,139,237,129,252,249,243,15,133,245,251,249,4,221,
  131,237,221,131,237,221,147,237,255,249,4,139,139,237,193,225,8,11,139,237,
  193,225,8,11,139,237,129,252,249,243,139,131,237,15,133,245,251,221,131,237,
  221,131,237,133,192,221,147,237,15,136,245,255,255,217,201,249,1,255,199,
  131,237,3,0,0,0,15,130,246,255,249,5,141,131,237,199,134,237,241,80,86,232,
  244,131,196,8,233,245,4,254,0,221,131,237,221,131,237,220,131,237,221,147,
  237,221,147,237,199,131,237,3,0,0,0,255,139,131,237,221,131,237,221,131,237,
  221,131,237,222,193,221,147,237,221,147,237,199,131,237,3,0,0,0,133,192,15,
  136,245,255,217,201,249,1,255,139,139,237,139,147,237,139,131,237,137,139,
  237,137,147,237,137,131,237,139,139,237,139,147,237,139,131,237,137,139,237,
  137,147,237,137,131,237,139,139,237,255,131,187,237,0,15,132,245,255,139,
  139,237,139,147,237,139,131,237,137,139,237,137,147,237,137,131,237,233,246,
  249,1,255,141,131,237,80,255,83,255,139,142,237,139,185,237,139,191,237,255,
  139,151,237,82,104,241,86,232,244,131,196,12,199,128,237,241,137,131,237,
  199,131,237,6,0,0,0,255,139,151,237,137,144,237,255,131,236,8,137,199,137,
  52,36,255,141,131,237,137,68,36,4,255,137,92,36,4,255,232,244,137,135,237,
  255,249,1,139,142,237,139,145,237,129,194,243,141,132,253,27,237,41,208,59,
  134,237,15,131,245,251,141,187,237,57,218,15,131,245,253,249,2,139,2,131,
  194,4,137,7,131,199,4,57,218,15,130,245,2,249,3,254,1,249,5,43,134,237,255,
  80,86,232,244,131,196,8,139,158,237,233,245,1,254,0,139,142,237,139,145,237,
  129,194,243,141,187,237,141,139,237,57,218,15,131,245,254,249,1,139,2,131,
  194,4,137,7,131,199,4,57,207,15,131,245,252,57,218,15,130,245,1,249,2,255,
  49,192,249,3,137,135,237,129,199,243,57,207,15,130,245,3,249,4,255
};


/* ------------------------------------------------------------------------ */

/* JIT subroutine numbers. */
enum {
  JSUB_GATE_LJ,
  JSUB_GATE_JL,
  JSUB_GATE_JC,
  JSUB_GATE_JC_PATCH,
  JSUB_GATE_JC_DEBUG,

  JSUB_GROW_STACK,
  JSUB_GROW_CI,

  JSUB_GCSTEP,
  JSUB_CPUDETECT,
  JSUB_HOOKINS,
    JSUB_HOOKCALL,
    JSUB_HOOKRET,
  JSUB_METACALL,
  JSUB_METATAILCALL,
  JSUB_GETTABLE_STR,
  JSUB_SETTABLE_STR,

  JSUB_MAX
};


/* Forward declarations. */
static void jit_hookins(lua_State *L, const Instruction *newpc);
static void jit_gettable_str(lua_State *L, Table *t, TString *skey, StkId dest);
static void jit_settable_str(lua_State *L, Table *t, TString *skey, StkId val);

/* ------------------------------------------------------------------------ */

/* luaC_checkGC() inlined. Destroys caller-saves + TOP (edi). Uses label 7:. */
/* Use this only at the _end_ of an instruction. */
static void jit_checkGC(jit_State *J)
{
  dasm_put(Dst, 0, Dt1(->l_G), Dt6(->totalbytes), Dt6(->GCthreshold), (ptrdiff_t)(J->jsub[JSUB_GCSTEP]));

}

/* ------------------------------------------------------------------------ */

/* Detect CPU features and set JIT flags. */
static void jit_cpudetect(jit_State *J)
{
  unsigned int feature = ((unsigned int (*)(void))J->jsub[JSUB_CPUDETECT])();
  /* See the Intel/AMD manuals for the bit definitions. */
  if (feature & 0x8000) J->flags |= JIT_F_CPU_CMOV;

}

/* ------------------------------------------------------------------------ */

/* Compile JIT subroutines. */
static int jit_compile_jsub(jit_State *J)
{
  int status;
  /* Use PC labels as entry points. */
  dasm_setup(Dst, jit_actionlist, JSUB_MAX);
  dasm_put(Dst, 71);
  dasm_put(Dst, 73, JSUB_GATE_LJ, Dt1(->top), Dt2(->value), Dt1(->ci), Dt1(->nCcalls), Dt5(->jit_gate), Dt1(->ci), Dt1(->top), Dt4(->savedpc), Dt1(->savedpc), Dt4(->base), Dt1(->base));
  dasm_put(Dst, 142);
  switch (sizeof(TValue)) {
  case 8:
  dasm_put(Dst, 147);
    break;
  case 12:
  dasm_put(Dst, 151);
    break;
  case 16:
  dasm_put(Dst, 158);
    break;
  default: jit_assert(0); break;
  }
  dasm_put(Dst, 162, Dt1(->top), Dt3(->tt), sizeof(TValue), Dt1(->nCcalls), PCRC, JSUB_GATE_JL, Dt5(->p), DtE(->jit_status), JIT_S_OK);
  dasm_put(Dst, 219, DtE(->jit_mcode), Dt5(->jit_gate), Dt4(->savedpc), Dt1(->ci), Dt1(->top), Dt1(->savedpc), Dt1(->stack), (ptrdiff_t)(luaD_precall));
  dasm_put(Dst, 266, (ptrdiff_t)(luaV_execute), Dt1(->stack), Dt1(->top), JSUB_GATE_JC, Dt3([LUA_MINSTACK]), Dt1(->stack_last), JSUB_GROW_STACK, Dt1(->end_ci), Dt4([1]), JSUB_GROW_CI);
  dasm_put(Dst, 305, Dt1(->ci), Dt4(->func), Dt4(->top), Dt2(->value), sizeof(TValue), Dt1(->top), Dt1(->base), Dt4(->base), JSUB_GATE_JC_PATCH, DtD(->f), Dt1(->ci));
  switch (sizeof(TValue)) {
  case 8:
  dasm_put(Dst, 147);
    break;
  case 12:
  dasm_put(Dst, 151);
    break;
  case 16:
  dasm_put(Dst, 158);
    break;
  default: jit_assert(0); break;
  }
  dasm_put(Dst, 344, Dt4(->func), Dt1(->top), Dt4(->func), sizeof(CallInfo), Dt1(->ci), JSUB_GATE_JC_DEBUG);
  dasm_put(Dst, 399, Dt1(->hookmask), LUA_MASKCALL, DtD(->f), Dt1(->hookmask), LUA_MASKRET, LUA_HOOKRET, (ptrdiff_t)(luaD_callhook));
  dasm_put(Dst, 446, LUA_HOOKCALL, (ptrdiff_t)(luaD_callhook), JSUB_GROW_STACK);
  switch (sizeof(TValue)) {
  case 8:
  dasm_put(Dst, 473);
    break;
  case 12:
  dasm_put(Dst, 478);
    break;
  case 16:
  dasm_put(Dst, 489);
    break;
  default: jit_assert(0); break;
  }
  dasm_put(Dst, 494, Dt1(->top), Dt1(->stack), (ptrdiff_t)(luaD_growstack), Dt1(->stack), Dt1(->top), Dt2(->value), Dt5(->jit_gate), JSUB_GROW_CI, Dt1(->top), (ptrdiff_t)(luaD_growCI), Dt9([-1]), Dt2(->value));
  dasm_put(Dst, 543, Dt1(->ci), Dt5(->jit_gate));
  dasm_put(Dst, 18, JSUB_GCSTEP, (ptrdiff_t)(luaC_step), Dt1(->base));
  dasm_put(Dst, 34, JSUB_CPUDETECT);
  dasm_put(Dst, 561, JSUB_HOOKINS, Dt1(->hookmask), LUA_MASKLINE|LUA_MASKCOUNT, Dt1(->hookcount), Dt1(->hookmask), LUA_MASKLINE);
  dasm_put(Dst, 593, (ptrdiff_t)(jit_hookins), Dt1(->base), Dt1(->top));
    dasm_put(Dst, 785, JSUB_HOOKCALL, Dt1(->ci), Dt4(->func), Dt3(->value), Dt5(->p), DtE(->code), sizeof(Instruction), Dt1(->savedpc), LUA_HOOKCALL, (ptrdiff_t)(luaD_callhook), DtE(->jit_pcaddr), Dt1(->base));
    dasm_put(Dst, 827);
    dasm_put(Dst, 850, JSUB_HOOKRET, LUA_HOOKRET, (ptrdiff_t)(luaD_callhook), Dt1(->base), Dt1(->top));
  dasm_put(Dst, 1165, JSUB_METACALL, Dt4(->savedpc), Dt1(->top), Dt1(->savedpc), (ptrdiff_t)(luaD_tryfuncTM), Dt1(->top), Dt2(->value), Dt1(->ci));
  dasm_put(Dst, 1331, JSUB_METATAILCALL, Dt1(->top), (ptrdiff_t)(luaD_tryfuncTM), Dt1(->ci), Dt1(->top), Dt4(->func), Dt4(->func), Dt2(->value), sizeof(CallInfo));
  dasm_put(Dst, 546, Dt5(->jit_gate));
  dasm_put(Dst, 1508, JSUB_GETTABLE_STR, DtC(->lsizenode), DtB(->tsv.hash));
  if (sizeof(Node) == 32) {
  dasm_put(Dst, 1527);
  } else {
  dasm_put(Dst, 1531, sizeof(Node));
  }
  dasm_put(Dst, 1535, DtC(->node), Dt10(->i_key.tt), Dt10(->i_key.value), Dt10(->i_val.tt), Dt10(->i_val.value), Dt10(->i_val.value.na[1]));
  dasm_put(Dst, 1571, Dt2(->tt), Dt2(->value), Dt2(->value.na[1]), Dt1(->base), Dt10(->i_key.next), DtC(->metatable), DtC(->flags), 1<<TM_INDEX);
  dasm_put(Dst, 1614, Dt2([0].tt), Dt1(->base), Dt1(->savedpc), (ptrdiff_t)(jit_gettable_str), Dt1(->base));
  dasm_put(Dst, 1508, JSUB_SETTABLE_STR, DtC(->lsizenode), DtB(->tsv.hash));
  if (sizeof(Node) == 32) {
  dasm_put(Dst, 1527);
  } else {
  dasm_put(Dst, 1531, sizeof(Node));
  }
  dasm_put(Dst, 1649, DtC(->node), Dt10(->i_key.tt), Dt10(->i_key.value), Dt10(->i_val.tt), DtC(->flags));
  dasm_put(Dst, 1684, DtC(->marked), bitmask(BLACKBIT), Dt2([0].value), Dt2([0].value.na[1]), Dt2([0].tt), Dt3([0].value), Dt3([0].value.na[1]), Dt3([0].tt), Dt1(->base));
  dasm_put(Dst, 1722, Dt10(->i_key.next), DtC(->metatable), DtC(->flags), 1<<TM_NEWINDEX, 3*sizeof(void *)+sizeof(TValue), Dt7([0].value));
  dasm_put(Dst, 1770, Dt7([0].tt), (ptrdiff_t)(luaH_newkey), 3*sizeof(void *)+sizeof(TValue), DtC(->metatable), DtC(->flags), 1<<TM_NEWINDEX);
  dasm_put(Dst, 1811, Dt1(->savedpc), (ptrdiff_t)(jit_settable_str), Dt1(->base), (ptrdiff_t)(luaC_barrierback));
  dasm_put(Dst, 551);

  (void)dasm_checkstep(Dst, DASM_SECTION_CODE);
  status = luaJIT_link(J, &J->jsubmcode, &J->sizejsubmcode);
  if (status != JIT_S_OK)
    return status;

  /* Get addresses of JSUBs. Store the callgates in the global state. */
  dasm_getlabels(Dst, J->jsubmcode, J->jsub);
  G(J->L)->jit_gateLJ = (luaJIT_GateLJ)J->jsub[JSUB_GATE_LJ];
  G(J->L)->jit_gateJL = (lua_CFunction)J->jsub[JSUB_GATE_JL];
  G(J->L)->jit_gateJC = (lua_CFunction)J->jsub[JSUB_GATE_JC];
  jit_cpudetect(J);
  return JIT_S_OK;
}

/* Match with number of nops above. Avoid confusing the instruction decoder. */
#define DEBUGPATCH_SIZE		7

/* Notify backend that the debug mode may have changed. */
void luaJIT_debugnotify(jit_State *J)
{
  unsigned char *patch = (unsigned char *)J->jsub[JSUB_GATE_JC_PATCH];
  unsigned char *target = (unsigned char *)J->jsub[JSUB_GATE_JC_DEBUG];
  /* Yep, this is self-modifying code -- don't tell anyone. */
  if (patch[0] == 0xe9) {  /* Debug patch is active. */
    if (!(J->flags & JIT_F_DEBUG_CALL))  /* Deactivate it. */
      memcpy(patch, target-DEBUGPATCH_SIZE, DEBUGPATCH_SIZE);
  } else {  /* Debug patch is inactive. */
    if (J->flags & JIT_F_DEBUG_CALL) {  /* Activate it. */
      int rel = target-(patch+5);
      memcpy(target-DEBUGPATCH_SIZE, patch, DEBUGPATCH_SIZE);
      patch[0] = 0xe9;  /* jmp */
      memcpy(patch+1, &rel, 4);  /* Relative address. */
      memset(patch+5, 0x90, DEBUGPATCH_SIZE-5);  /* nop */
    }
  }
}

/* ------------------------------------------------------------------------ */

/* Call line/count hook. */
static void jit_hookins(lua_State *L, const Instruction *newpc)
{
  Proto *pt = ci_func(L->ci)->l.p;
  int oldpc = luaJIT_currentpc(L, pt, L->savedpc);
  int pc = luaJIT_currentpc(L, pt, newpc);
  L->savedpc = pt->code + pc;
  if (L->hookmask > LUA_MASKLINE && L->hookcount == 0) {
    resethookcount(L);
    luaD_callhook(L, LUA_HOOKCOUNT, -1);
  } else if (L->hookmask & LUA_MASKLINE) {
    int newline = getline(pt, --pc);
    if (oldpc < 0 || oldpc >= pt->sizecode) oldpc = pc-1;
    if (pc == 0 || pc <= oldpc || newline != getline(pt, oldpc))
      luaD_callhook(L, LUA_HOOKLINE, newline);
  }
}

/* Insert hook check for each instruction in full debug mode. */
static void jit_ins_debug(jit_State *J, int openop)
{
  if (openop) {
    dasm_put(Dst, 554, Dt1(->top));
  }
  dasm_put(Dst, 558, (ptrdiff_t)(J->jsub[JSUB_HOOKINS]));
}

/* Called before every instruction. */
static void jit_ins_start(jit_State *J)
{
  dasm_put(Dst, 397, J->nextpc);
}

/* Called after the last instruction has been encoded. */
static void jit_ins_last(jit_State *J)
{
  dasm_put(Dst, 397, J->nextpc);
}

/* ------------------------------------------------------------------------ */


#ifdef LUA_COMPAT_VARARG
static void jit_vararg_table(lua_State *L)
{
  Table *tab;
  StkId base, func;
  int i, num, numparams;
  luaC_checkGC(L);
  base = L->base;
  func = L->ci->func;
  numparams = clvalue(func)->l.p->numparams;
  num = base - func - numparams - 1;
  tab = luaH_new(L, num, 1);
  for (i = 0; i < num; i++)
    setobj2n(L, luaH_setnum(L, tab, i+1), base - num + i);
  setnvalue(luaH_setstr(L, tab, luaS_newliteral(L, "n")), (lua_Number)num);
  sethvalue(L, base + numparams, tab);
}
#endif

static void jit_prologue(jit_State *J)
{
  Proto *pt = J->pt;
  int numparams = pt->numparams;
  int stacksize = pt->maxstacksize;

  dasm_put(Dst, 71);
  dasm_put(Dst, 613, Dt3([stacksize]), Dt1(->stack_last), (ptrdiff_t)(J->jsub[JSUB_GROW_STACK]), Dt1(->end_ci), Dt4([1]), (ptrdiff_t)(J->jsub[JSUB_GROW_CI]), Dt4(->func), sizeof(TValue), Dt1(->ci));

  if (!pt->is_vararg) {  /* Fixarg function. */
    dasm_put(Dst, 643, Dt1(->base), Dt4(->base), Dt2([stacksize]), Dt4(->tailcalls), Dt4(->top), Dt1(->top));
  } else {  /* Vararg function. */
    int i;
    if (numparams > 0) {
      dasm_put(Dst, 662, Dt2([numparams]));
      dasm_put(Dst, 675, Dt3(->tt), sizeof(TValue));
    }
    dasm_put(Dst, 694, Dt1(->base), Dt4(->base), Dt4(->tailcalls));
    for (i = 0; i < numparams; i++) {  /* Move/clear fixargs. */
      dasm_put(Dst, 704, Dt2([i].value), Dt2([i].value.na[1]), Dt3([i].value), Dt2([i].tt), Dt3([i].value.na[1]), Dt3([i].tt), Dt2([i].tt));
    }
    if (numparams > 0) {
      dasm_put(Dst, 340, Dt1(->ci));
    }
    dasm_put(Dst, 726, Dt2([stacksize]), Dt2([numparams]), Dt4(->top), Dt1(->top));
    stacksize -= numparams;		/* Fixargs are already cleared. */
  }

  /* Clear undefined args and all vars. Still assumes eax = LUA_TNIL = 0. */
  /* Note: cannot clear only args because L->top has grown. */
  if (stacksize <= EXTRA_STACK) {  /* Loopless clear. May use EXTRA_STACK. */
    int i;
    for (i = 0; i < stacksize; i++) {
      dasm_put(Dst, 742, Dt3([i].tt));
    }
  } else {  /* Standard loop. */
    dasm_put(Dst, 746, Dt3([0].tt), Dt3([1].tt), 2*sizeof(TValue));
    /* Note: TOP is undefined now. TOP is only valid across calls/open ops. */
  }

#ifdef LUA_COMPAT_VARARG
  if (pt->is_vararg & VARARG_NEEDSARG) {
    dasm_put(Dst, 764, (ptrdiff_t)(jit_vararg_table));
  }
#endif

  /* Call hook check. */
  if (J->flags & JIT_F_DEBUG_CALL) {
    dasm_put(Dst, 771, Dt1(->hookmask), LUA_MASKCALL, (ptrdiff_t)(J->jsub[JSUB_HOOKCALL]));
    if (J->flags & JIT_F_DEBUG_INS) {
      dasm_put(Dst, 780, Dt1(->savedpc), (ptrdiff_t)(J->nextins));
    }
  }
}

static void jit_op_return(jit_State *J, int rbase, int nresults)
{
  /* Return hook check. */
  if (J->flags & JIT_F_DEBUG_CALL) {
    if (nresults < 0 && !(J->flags & JIT_F_DEBUG_INS)) {
      dasm_put(Dst, 554, Dt1(->top));
    }
    dasm_put(Dst, 832, Dt1(->hookmask), LUA_MASKRET, Dt1(->savedpc), (ptrdiff_t)(J->nextins), (ptrdiff_t)(J->jsub[JSUB_HOOKRET]));
  }

  /* May need to close open upvalues. */
  if (!fhint_isset(J, NOCLOSE)) {
    dasm_put(Dst, 878, (ptrdiff_t)(luaF_close));
  }

  /* Previous op was open: 'return f()' or 'return ...' */
  if (nresults < 0) {
    dasm_put(Dst, 340, Dt1(->ci));
    if (rbase) {
    dasm_put(Dst, 886, rbase*sizeof(TValue));
    }
    dasm_put(Dst, 890, Dt4(->func), Dt4(->func), sizeof(CallInfo), Dt1(->ci));
    return;
  }

  /* Shortcut 'return const' -- but not when debugging. */
  if (nresults == 1 && !(J->flags & JIT_F_DEBUG)) {
    const TValue *kk = hint_get(J, SHORTCUT_K);
    if (!ttisnil(kk)) {
      if (ttisfunction(kk)) kk = &luaO_nilobject;
      if (!J->pt->is_vararg) {
	dasm_put(Dst, 934, sizeof(TValue), Dt1(->ci), sizeof(CallInfo));
      } else {
	dasm_put(Dst, 944, Dt1(->ci), Dt4(->func), sizeof(CallInfo), Dt2([1]), Dt1(->ci));
      }
      switch (ttype(kk)) {
      case 0:
      dasm_put(Dst, 960, Dt2([0].tt));
        break;
      case 1:
      if (bvalue(kk)) {  /* true */
      dasm_put(Dst, 968, Dt2([0].value), Dt2([0].tt));
      } else {  /* false */
      dasm_put(Dst, 980, Dt2([0].value), Dt2([0].tt));
      }
        break;
      case 3: {
      dasm_put(Dst, 995, Dt2([0].value), (&(kk)->value)->na[0], Dt2([0].value.na[1]), (&(kk)->value)->na[1], Dt2([0].tt));
        break;
      }
      case 4:
      dasm_put(Dst, 1011, Dt2([0].value), (ptrdiff_t)(gcvalue(kk)), Dt2([0].tt));
        break;
      default: lua_assert(0); break;
      }
      dasm_put(Dst, 69);
      return;
    }
  }

  if (!J->pt->is_vararg) {  /* Fixarg function, nresults >= 0. */
    int i;
    dasm_put(Dst, 1023, sizeof(TValue));
    for (i = 0; i < nresults; i++) {
      dasm_put(Dst, 1027, Dt2([rbase+i+1].value), Dt2([rbase+i+1].value.na[1]), Dt2([rbase+i+1].tt), Dt2([i].value), Dt2([i].value.na[1]), Dt2([i].tt));
    }
    dasm_put(Dst, 1046, Dt2([nresults]), Dt1(->ci), sizeof(CallInfo));
  } else {  /* Vararg function, nresults >= 0. */
    int i;
    dasm_put(Dst, 1055, Dt1(->ci), Dt4(->func), sizeof(CallInfo), Dt1(->ci));
    for (i = 0; i < nresults; i++) {
      dasm_put(Dst, 1068, Dt2([rbase+i].value), Dt2([rbase+i].value.na[1]), Dt2([rbase+i].tt), Dt3([i].value), Dt3([i].value.na[1]), Dt3([i].tt));
    }
    dasm_put(Dst, 1087);
    if (nresults) {
    dasm_put(Dst, 1091, nresults*sizeof(TValue));
    }
    dasm_put(Dst, 69);
  }
}

static void jit_op_call(jit_State *J, int func, int nargs, int nresults)
{
  if (func) {
  dasm_put(Dst, 886, func*sizeof(TValue));
  }
  dasm_put(Dst, 340, Dt1(->ci));
  if (nargs >= 0) {  /* Previous op was not open and did not set TOP. */
    dasm_put(Dst, 1095, Dt2([1+nargs]));
  }
  dasm_put(Dst, 1099, Dt2([0].tt), Dt2(->value), Dt4(->savedpc), (ptrdiff_t)(J->nextins), Dt5(->jit_gate));
  if (func) {
  dasm_put(Dst, 1023, func*sizeof(TValue));
  }
  dasm_put(Dst, 1121, Dt1(->base));

  /* Clear undefined results TOP <= o < func+nresults. */
  if (nresults > 0) {
    dasm_put(Dst, 1125);
    if (nresults <= EXTRA_STACK) {  /* Loopless clear. May use EXTRA_STACK. */
      int i;
      for (i = 0; i < nresults; i++) {
	dasm_put(Dst, 742, Dt3([i].tt));
      }
    } else {  /* Standard loop. TODO: move to .tail? */
      dasm_put(Dst, 1128, Dt2([func+nresults]), Dt3([0].tt), Dt3([1].tt), 2*sizeof(TValue));
    }
  }

  if (nresults >= 0) {  /* Not an open op. Restore L->top. */
    dasm_put(Dst, 1149, Dt2([J->pt->maxstacksize]), Dt1(->top));
  }  /* Otherwise keep TOP for next instruction. */

  dasm_put(Dst, 673);
  dasm_put(Dst, 1156, (ptrdiff_t)(J->jsub[JSUB_METACALL]));

}

static void jit_op_tailcall(jit_State *J, int func, int nargs)
{
  /* May need to close open upvalues. */
  if (!fhint_isset(J, NOCLOSE)) {
    dasm_put(Dst, 878, (ptrdiff_t)(luaF_close));
  }

  dasm_put(Dst, 1197, Dt2([func].tt));

  if (nargs >= 0) {  /* Previous op was not open and did not set TOP. */
    int i;
    /* Relocate [BASE+func, BASE+func+nargs] -> [ci->func, ci->func+nargs]. */
    /* TODO: loop for large nargs? */
    if (!J->pt->is_vararg) {  /* Fixarg function. */
      dasm_put(Dst, 539, Dt2([func].value));
      for (i = 0; i < nargs; i++) {
	dasm_put(Dst, 1206, Dt2([func+1+i].value), Dt2([func+1+i].value.na[1]), Dt2([i].value), Dt2([func+1+i].tt), Dt2([i].value.na[1]), Dt2([i].tt));
      }
      dasm_put(Dst, 1225, Dt2([nargs]), sizeof(TValue), Dt1(->ci), Dt2(->value));
    } else {  /* Vararg function. */
      dasm_put(Dst, 1238, Dt1(->ci), Dt2([func]), Dt4(->func), Dt3(->value), Dt2(->value));
      for (i = 0; i < nargs; i++) {
	dasm_put(Dst, 1254, Dt3([i+1].value), Dt3([i+1].value.na[1]), Dt2([i+1].value), Dt3([i+1].tt), Dt2([i+1].value.na[1]), Dt2([i+1].tt));
      }
      dasm_put(Dst, 1273, Dt2([1+nargs]), Dt2(->value));
    }
  } else {  /* Previous op was open and set TOP. */
    dasm_put(Dst, 340, Dt1(->ci));
    if (func) {
    dasm_put(Dst, 886, func*sizeof(TValue));
    }
    dasm_put(Dst, 1280, Dt4(->func), Dt4(->func), Dt2(->value));
  }
  dasm_put(Dst, 1311, sizeof(CallInfo), Dt5(->jit_gate));
  dasm_put(Dst, 1320);
  if (func) {
  dasm_put(Dst, 886, func*sizeof(TValue));
  }
  if (nargs >= 0) {
    dasm_put(Dst, 1095, Dt2([1+nargs]));
  }
  dasm_put(Dst, 1323, Dt1(->savedpc), (ptrdiff_t)(J->nextins), (ptrdiff_t)(J->jsub[JSUB_METATAILCALL]));


  /* Skip following return instruction. */
  J->nextins++; J->nextpc++;
}

/* ------------------------------------------------------------------------ */

static void jit_op_move(jit_State *J, int dest, int src)
{
  dasm_put(Dst, 1027, Dt2([src].value), Dt2([src].value.na[1]), Dt2([src].tt), Dt2([dest].value), Dt2([dest].value.na[1]), Dt2([dest].tt));
}

static void jit_op_loadk(jit_State *J, int dest, int kidx)
{
  if (!hint_isset(J, SHORTCUT_K) || (J->flags & JIT_F_DEBUG)) {
    const TValue *kk = &J->pt->k[kidx];
    switch (ttype(kk)) {
    case 0:
    dasm_put(Dst, 960, Dt2([dest].tt));
      break;
    case 1:
    if (bvalue(kk)) {  /* true */
    dasm_put(Dst, 968, Dt2([dest].value), Dt2([dest].tt));
    } else {  /* false */
    dasm_put(Dst, 980, Dt2([dest].value), Dt2([dest].tt));
    }
      break;
    case 3: {
    dasm_put(Dst, 995, Dt2([dest].value), (&(kk)->value)->na[0], Dt2([dest].value.na[1]), (&(kk)->value)->na[1], Dt2([dest].tt));
      break;
    }
    case 4:
    dasm_put(Dst, 1011, Dt2([dest].value), (ptrdiff_t)(gcvalue(kk)), Dt2([dest].tt));
      break;
    default: lua_assert(0); break;
    }
  }
}

static void jit_op_loadnil(jit_State *J, int first, int last)
{
  if (!hint_isset(J, SHORTCUT_K) || (J->flags & JIT_F_DEBUG)) {
    int idx, num = last - first + 1;
    dasm_put(Dst, 1125);
    if (num <= 8) {
      for (idx = first; idx <= last; idx++) {
	dasm_put(Dst, 722, Dt2([idx].tt));
      }
    } else {
      dasm_put(Dst, 1381, Dt2([first].tt), Dt2([last].tt), sizeof(TValue));
    }
  }
}

static void jit_op_loadbool(jit_State *J, int dest, int b, int dojump)
{
  if (!hint_isset(J, SHORTCUT_K) || (J->flags & JIT_F_DEBUG)) {
    if (b) {  /* true */
    dasm_put(Dst, 968, Dt2([dest].value), Dt2([dest].tt));
    } else {  /* false */
    dasm_put(Dst, 980, Dt2([dest].value), Dt2([dest].tt));
    }
    if (dojump && !hint_issetpc(J, DEAD, J->nextpc)) {
      dasm_put(Dst, 1401, J->nextpc+1);
    }
  }
}

/* ------------------------------------------------------------------------ */

static void jit_op_getupval(jit_State *J, int dest, int uvidx)
{
  if (!J->pt->is_vararg) {
  dasm_put(Dst, 539, Dt2([-1].value));
  } else {
  dasm_put(Dst, 1404, Dt1(->ci), Dt4(->func), Dt3(->value));
  }
  dasm_put(Dst, 1414, Dt5(->upvals[uvidx]), DtF(->v), Dt3([0].value), Dt3([0].value.na[1]), Dt3([0].tt), Dt2([dest].value), Dt2([dest].value.na[1]), Dt2([dest].tt));
}

static void jit_op_setupval(jit_State *J, int src, int uvidx)
{
  if (!J->pt->is_vararg) {
  dasm_put(Dst, 539, Dt2([-1].value));
  } else {
  dasm_put(Dst, 1404, Dt1(->ci), Dt4(->func), Dt3(->value));
  }
  dasm_put(Dst, 1439, Dt5(->upvals[uvidx]), DtF(->v), Dt2([src].tt), Dt2([src].value), Dt3(->tt), Dt2([src].value.na[1]), Dt3(->value), Dt3(->value.na[1]));
  dasm_put(Dst, 1475, DtA(->gch.marked), WHITEBITS, DtF(->marked), bitmask(BLACKBIT), (ptrdiff_t)(luaC_barrierf));
}

/* ------------------------------------------------------------------------ */

/* Optimized table lookup routines. Enter via jsub, fallback to C. */

/* Fallback for GETTABLE_STR. */
static void jit_gettable_str(lua_State *L, Table *t, TString *skey, StkId dest)
{
  Table *mt = t->metatable;
  const TValue *tm = luaH_getstr(mt, G(L)->tmname[TM_INDEX]);
  if (ttisnil(tm)) {  /* No __index method? */
    mt->flags |= 1<<TM_INDEX;  /* Cache this fact. */
    setnilvalue(dest);
  } else if (ttisfunction(tm)) {  /* __index function? */
    ptrdiff_t destr = savestack(L, dest);
    setobj2s(L, L->top, tm);
    sethvalue(L, L->top+1, t);
    setsvalue(L, L->top+2, skey);
    luaD_checkstack(L, 3);
    L->top += 3;
    luaD_call(L, L->top - 3, 1);
    dest = restorestack(L, destr);
    L->top--;
    setobjs2s(L, dest, L->top);
  } else {  /* Let luaV_gettable() continue with the __index object. */
    TValue key;
    setsvalue(L, &key, skey);
    luaV_gettable(L, tm, &key, dest);
  }

}

/* Fallback for SETTABLE_STR. */
static void jit_settable_str(lua_State *L, Table *t, TString *skey, StkId val)
{
  Table *mt = t->metatable;
  const TValue *tm = luaH_getstr(mt, G(L)->tmname[TM_NEWINDEX]);
  if (ttisnil(tm)) {  /* No __newindex method? */
    mt->flags |= 1<<TM_NEWINDEX;  /* Cache this fact. */
    t->flags = 0;  /* But need to clear the cache for the table itself. */
    setobj2t(L, luaH_setstr(L, t, skey), val);  /* Not in the fast path. */
    luaC_barriert(L, t, val);
  } else if (ttisfunction(tm)) {  /* __newindex function? */
    setobj2s(L, L->top, tm);
    sethvalue(L, L->top+1, t);
    setsvalue(L, L->top+2, skey);
    setobj2s(L, L->top+3, val);
    luaD_checkstack(L, 4);
    L->top += 4;
    luaD_call(L, L->top - 4, 0);
  } else {  /* Let luaV_settable() continue with the __newindex object. */
    TValue key;
    setsvalue(L, &key, skey);
    luaV_settable(L, tm, &key, val);
  }

}

/* ------------------------------------------------------------------------ */

static void jit_op_newtable(jit_State *J, int dest, int lnarray, int lnhash)
{
  dasm_put(Dst, 1845, luaO_fb2int(lnhash), luaO_fb2int(lnarray), (ptrdiff_t)(luaH_new), Dt2([dest].value), Dt2([dest].tt));
  jit_checkGC(J);
}

static void jit_op_getglobal(jit_State *J, int dest, int kidx)
{
  const TValue *kk = &J->pt->k[kidx];
  jit_assert(ttisstring(kk));
  if (!J->pt->is_vararg) {
  dasm_put(Dst, 539, Dt2([-1].value));
  } else {
  dasm_put(Dst, 1404, Dt1(->ci), Dt4(->func), Dt3(->value));
  }
  dasm_put(Dst, 1866, Dt5(->env), (ptrdiff_t)(&kk->value.gc->ts));
  if (dest) {
  dasm_put(Dst, 886, dest*sizeof(TValue));
  }
  dasm_put(Dst, 558, (ptrdiff_t)(J->jsub[JSUB_GETTABLE_STR]));
}

static void jit_op_setglobal(jit_State *J, int rval, int kidx)
{
  const TValue *kk = &J->pt->k[kidx];
  jit_assert(ttisstring(kk));
  if (!J->pt->is_vararg) {
  dasm_put(Dst, 539, Dt2([-1].value));
  } else {
  dasm_put(Dst, 1404, Dt1(->ci), Dt4(->func), Dt3(->value));
  }
  dasm_put(Dst, 1866, Dt5(->env), (ptrdiff_t)(&kk->value.gc->ts));
  if (rval) {
  dasm_put(Dst, 886, rval*sizeof(TValue));
  }
  dasm_put(Dst, 558, (ptrdiff_t)(J->jsub[JSUB_SETTABLE_STR]));
}

/* Check if a numeric key is suitable for array lookup and return it. */
static int arraykey(const TValue *key)
{
  lua_Number n = nvalue(key);
  int k;
  lua_number2int(k, n);
  if ((lua_Number)k == n && k >= 1 && k < (1 << 26))
    return k;
  else
    return 0;
}

static void jit_op_gettable(jit_State *J, int dest, int tab, int rkey)
{
  /* Optimize key lookup depending on consts or hints type. */
  const TValue *key = ISK(rkey) ? &J->pt->k[INDEXK(rkey)] : hint_get(J, TYPE);
  int hastail = 0;
  int k;
  if (ttisstring(key)) {  /* String key? */
    dasm_put(Dst, 1872, Dt2([tab].tt));
    if (ISK(rkey)) {
      dasm_put(Dst, 1869, (ptrdiff_t)(&key->value.gc->ts));
    } else {
      dasm_put(Dst, 1881, Dt2([rkey].tt), Dt2([rkey].value));
    }
    dasm_put(Dst, 1893, Dt2([tab].value));
    if (dest) {
    dasm_put(Dst, 886, dest*sizeof(TValue));
    }
    dasm_put(Dst, 1897, (ptrdiff_t)(J->jsub[JSUB_GETTABLE_STR]));
    hastail = 1;
  } else if (ttisnumber(key) && (k = arraykey(key))) {  /* Array key? */
    dasm_put(Dst, 1872, Dt2([tab].tt));
    if (ISK(rkey)) {  /* Constants are easy. */
      dasm_put(Dst, 1903, Dt2([tab].value), DtC(->sizearray), k, DtC(->array));
    } else {  /* Variables are slower because of checknum2int. */
      dasm_put(Dst, 1918, Dt2([rkey].tt), Dt2([rkey].value));
      if (J->flags & JIT_F_CPU_CMOV) {
      dasm_put(Dst, 1938);
      } else {
      dasm_put(Dst, 1943);
      }
      dasm_put(Dst, 1949, Dt2([tab].value), DtC(->sizearray));
      switch (sizeof(TValue)) {
      case 8:
      dasm_put(Dst, 1973);
        break;
      case 12:
      dasm_put(Dst, 1977);
        break;
      case 16:
      dasm_put(Dst, 1984);
        break;
      default: jit_assert(0); break;
      }
      dasm_put(Dst, 1988, DtC(->array));
      k = 1;
    }
    dasm_put(Dst, 1992, Dt3([k-1].tt), Dt3([k-1].value), Dt3([k-1].value.na[1]), Dt2([dest].value), Dt2([dest].value.na[1]), Dt2([dest].tt));
    dasm_put(Dst, 2022, DtC(->metatable));
    hastail = 1;
  }

  dasm_put(Dst, 1320);
  if (ISK(rkey)) {
    dasm_put(Dst, 2033, (ptrdiff_t)(key));
  } else {
    dasm_put(Dst, 2036, Dt2([rkey]));
  }
  dasm_put(Dst, 2040, Dt2([tab]));
  if (dest) {
  dasm_put(Dst, 886, dest*sizeof(TValue));
  }
  dasm_put(Dst, 2044, Dt1(->savedpc), (ptrdiff_t)(J->nextins), (ptrdiff_t)(luaV_gettable), Dt1(->base));
  if (hastail) {
    dasm_put(Dst, 689);
  }
}

static void jit_op_settable(jit_State *J, int tab, int rkey, int rval)
{
  /* Optimize key lookup depending on consts or hints type. */
  const TValue *key = ISK(rkey) ? &J->pt->k[INDEXK(rkey)] : hint_get(J, TYPE);
  const TValue *val = ISK(rval) ? &J->pt->k[INDEXK(rval)] : NULL;
  int hastail = 0;
  int k;
  if (ttisstring(key)) {  /* String key? */
    dasm_put(Dst, 2061, Dt2([tab].tt), Dt2([tab].value));
    if (ISK(rkey)) {
      dasm_put(Dst, 1869, (ptrdiff_t)(&key->value.gc->ts));
    } else {
      dasm_put(Dst, 1881, Dt2([rkey].tt), Dt2([rkey].value));
    }
    if (ISK(rval)) {
      dasm_put(Dst, 2073, (ptrdiff_t)(val));
    } else {
      if (rval) {
      dasm_put(Dst, 886, rval*sizeof(TValue));
      }
    }
    dasm_put(Dst, 1897, (ptrdiff_t)(J->jsub[JSUB_SETTABLE_STR]));
    hastail = 1;
  } else if (ttisnumber(key) && (k = arraykey(key))) {  /* Array key? */
    dasm_put(Dst, 1872, Dt2([tab].tt));
    if (ISK(rkey)) {  /* Constants are easy. */
      dasm_put(Dst, 1903, Dt2([tab].value), DtC(->sizearray), k, DtC(->array));
    } else {  /* Variables are slower because of checknum2int. */
      dasm_put(Dst, 1918, Dt2([rkey].tt), Dt2([rkey].value));
      if (J->flags & JIT_F_CPU_CMOV) {
      dasm_put(Dst, 1938);
      } else {
      dasm_put(Dst, 1943);
      }
      dasm_put(Dst, 1949, Dt2([tab].value), DtC(->sizearray));
      switch (sizeof(TValue)) {
      case 8:
      dasm_put(Dst, 1973);
        break;
      case 12:
      dasm_put(Dst, 1977);
        break;
      case 16:
      dasm_put(Dst, 1984);
        break;
      default: jit_assert(0); break;
      }
      dasm_put(Dst, 1988, DtC(->array));
      k = 1;
    }
    dasm_put(Dst, 2076, Dt3([k-1].tt), DtC(->metatable));
    if (!ISK(rval) || iscollectable(val)) {
      dasm_put(Dst, 2095, DtC(->marked), bitmask(BLACKBIT));
      dasm_put(Dst, 2108, (ptrdiff_t)(luaC_barrierback));
    }
    if (ISK(rval)) {
      switch (ttype(val)) {
      case 0:
      dasm_put(Dst, 2122, Dt3([k-1].tt));
        break;
      case 1:
      if (bvalue(val)) {  /* true */
      dasm_put(Dst, 2130, Dt3([k-1].value), Dt3([k-1].tt));
      } else {  /* false */
      dasm_put(Dst, 2142, Dt3([k-1].value), Dt3([k-1].tt));
      }
        break;
      case 3: {
      dasm_put(Dst, 2157, Dt3([k-1].value), (&(val)->value)->na[0], Dt3([k-1].value.na[1]), (&(val)->value)->na[1], Dt3([k-1].tt));
        break;
      }
      case 4:
      dasm_put(Dst, 2173, Dt3([k-1].value), (ptrdiff_t)(gcvalue(val)), Dt3([k-1].tt));
        break;
      default: lua_assert(0); break;
      }
    } else {
      dasm_put(Dst, 1068, Dt2([rval].value), Dt2([rval].value.na[1]), Dt2([rval].tt), Dt3([k-1].value), Dt3([k-1].value.na[1]), Dt3([k-1].tt));
    }
    dasm_put(Dst, 671);
    hastail = 1;
  }

  dasm_put(Dst, 1320);
  if (ISK(rkey)) {
    dasm_put(Dst, 2033, (ptrdiff_t)(key));
  } else {
    dasm_put(Dst, 2036, Dt2([rkey]));
  }
  if (ISK(rval)) {
    dasm_put(Dst, 1869, (ptrdiff_t)(val));
  } else {
    dasm_put(Dst, 2040, Dt2([rval]));
  }
  if (tab) {
  dasm_put(Dst, 886, tab*sizeof(TValue));
  }
  dasm_put(Dst, 2185, Dt1(->savedpc), (ptrdiff_t)(J->nextins), (ptrdiff_t)(luaV_settable), Dt1(->base));
  if (hastail) {
    dasm_put(Dst, 689);
  }
}

static void jit_op_self(jit_State *J, int dest, int tab, int rkey)
{
  dasm_put(Dst, 1027, Dt2([tab].value), Dt2([tab].value.na[1]), Dt2([tab].tt), Dt2([dest+1].value), Dt2([dest+1].value.na[1]), Dt2([dest+1].tt));
  jit_op_gettable(J, dest, tab, rkey);
}

/* ------------------------------------------------------------------------ */

static void jit_op_setlist(jit_State *J, int ra, int num, int batch)
{
  if (batch == 0) { batch = (int)(*J->nextins++); J->nextpc++; }
  batch = (batch-1)*LFIELDS_PER_FLUSH;
  if (num == 0) {  /* Previous op was open and set TOP: {f()} or {...}. */
    dasm_put(Dst, 2202, Dt2([ra+1]));
    switch (sizeof(TValue)) {
    case 8:
    dasm_put(Dst, 473);
      break;
    case 12:
    dasm_put(Dst, 478);
      break;
    case 16:
    dasm_put(Dst, 489);
      break;
    default: jit_assert(0); break;
    }
    dasm_put(Dst, 2212, Dt2([ra].value));
    if (batch > 0) {
      dasm_put(Dst, 2220, batch);
    }
    dasm_put(Dst, 2224, DtC(->sizearray), (ptrdiff_t)(luaH_resizearray), Dt2([ra].value), DtC(->marked), bitmask(BLACKBIT), DtC(->array));
    dasm_put(Dst, 2260, (ptrdiff_t)(luaC_barrierback));
  } else {  /* Set fixed number of args. */
    dasm_put(Dst, 2282, Dt2([ra].value), DtC(->sizearray), batch+num, DtC(->marked), bitmask(BLACKBIT), DtC(->array), Dt2([ra+1+num]));
    dasm_put(Dst, 2312, batch+num, (ptrdiff_t)(luaH_resizearray), (ptrdiff_t)(luaC_barrierback));
  }
  if (batch > 0) {
    dasm_put(Dst, 2340, batch*sizeof(TValue));
  }
  dasm_put(Dst, 2344, Dt2([ra+1]));
  if (num == 0) {  /* Previous op was open. Restore L->top. */
    dasm_put(Dst, 1149, Dt2([J->pt->maxstacksize]), Dt1(->top));
  }
}

/* ------------------------------------------------------------------------ */

static void jit_op_arith(jit_State *J, int dest, int rkb, int rkc, int ev,
			 int target)
{
  const TValue *kkb = NULL, *kkc = NULL;
  int special = 0;

  /* Get constant pointers and check for numeric types. */
  if (ISK(rkb)) {
    kkb = &J->pt->k[INDEXK(rkb)];
    if (!ttisnumber(kkb)) special = 1;
  }
  if (ISK(rkc)) {
    kkc = &J->pt->k[INDEXK(rkc)];
    if (!ttisnumber(kkc)) special = 1;
  }

  /* Evaluate operations on two numeric constants at compile time. */
  if (ISK(rkb&rkc) && !special) {
    /* Note: these must _not_ throw an error (ever)! */
    lua_Number nb = nvalue(kkb), nc = nvalue(kkc);
    Value vn;
    switch (ev) {
    case TM_ADD: vn.n = luai_numadd(J->L, nb, nc); break;
    case TM_SUB: vn.n = luai_numsub(J->L, nb, nc); break;
    case TM_MUL: vn.n = luai_nummul(J->L, nb, nc); break;
    case TM_DIV: vn.n = luai_numdiv(J->L, nb, nc); break;
    case TM_MOD: vn.n = luai_nummod(J->L, nb, nc); break;
    case TM_POW: vn.n = luai_numpow(J->L, nb, nc); break;
    case TM_LT:
      if (luai_numlt(J->L, nb, nc) == dest) {  /* cond */
	dasm_put(Dst, 1401, target);
      }
      return;
    case TM_LE:
      if (luai_numle(J->L, nb, nc) == dest) {  /* cond */
	dasm_put(Dst, 1401, target);
      }
      return;
    default: jit_assert(0); break;
    }
    dasm_put(Dst, 995, Dt2([dest].value), (&vn)->na[0], Dt2([dest].value.na[1]), (&vn)->na[1], Dt2([dest].tt));
    return;
  }

  /* Inline FP arithmetics if possible. */
  special |= (ev == TM_MOD) | (ev == TM_POW);
  if (!special) {  /* At most one of the operands is a constant. */
    const Value *kval;
    int idx, rev;
    /* Reverse operation and swap operands so the 2nd operand is a variable. */
    if (kkc) { kval = &kkc->value; idx = rkb; rev = 1;
    } else { kval = kkb ? &kkb->value : NULL; idx = rkc; rev = 0; }
    /* Check for fallback to non-numeric handler and load 1st operand. */
    if (kval) {
      dasm_put(Dst, 2369, Dt2([idx].tt));
      if (kval->n == (lua_Number)0) {
	dasm_put(Dst, 2378);
      } else if (kval->n == (lua_Number)1) {
	dasm_put(Dst, 2382);
      } else {
	dasm_put(Dst, 2385, kval);
      }
    } else {
      if (rkb == rkc) {
	dasm_put(Dst, 2389, Dt2([rkb].tt));
      } else {
	dasm_put(Dst, 2394, Dt2([rkb].tt), Dt2([rkc].tt), (3<<8)|3);
      }
      dasm_put(Dst, 2408, Dt2([rkb].value));
    }
    /* Encode arithmetic operation with 2nd operand. */
    switch ((ev<<1)+rev) {
    case TM_ADD<<1: case (TM_ADD<<1)+1:
      if (rkb == rkc) {
	dasm_put(Dst, 2416);
      } else {
	dasm_put(Dst, 2419, Dt2([idx].value));
      }
      break;
    case TM_SUB<<1:
      dasm_put(Dst, 2423, Dt2([idx].value));
      break;
    case (TM_SUB<<1)+1:
      dasm_put(Dst, 2427, Dt2([idx].value));
      break;
    case TM_MUL<<1: case (TM_MUL<<1)+1:
      if (rkb == rkc) {
	dasm_put(Dst, 2431);
      } else {
	dasm_put(Dst, 2434, Dt2([idx].value));
      }
      break;
    case TM_DIV<<1:
      dasm_put(Dst, 2438, Dt2([idx].value));
      break;
    case (TM_DIV<<1)+1:
      dasm_put(Dst, 2442, Dt2([idx].value));
      break;
    default:  /* TM_LT or TM_LE. */
      dasm_put(Dst, 2412, Dt2([idx].value));
      if (J->flags & JIT_F_CPU_CMOV) {
      dasm_put(Dst, 1938);
      } else {
      dasm_put(Dst, 1943);
      }
      dasm_put(Dst, 2446, dest?J->nextpc:target);
      switch (((rev^dest)<<1)+(dest^(ev == TM_LT))) {
      case 0:
	dasm_put(Dst, 2450, target);
	break;
      case 1:
	dasm_put(Dst, 2454, target);
	break;
      case 2:
	dasm_put(Dst, 2458, target);
	break;
      case 3:
	dasm_put(Dst, 2462, target);
	break;
      }
      goto skipstore;
    }
    /* Store result and set result type (if necessary). */
    dasm_put(Dst, 2466, Dt2([dest].value));
    if (dest != rkb && dest != rkc) {
      dasm_put(Dst, 1003, Dt2([dest].tt));
    }
skipstore:
    dasm_put(Dst, 671);
    dasm_put(Dst, 1320);
  }

  /* Generic fallback for arithmetic ops. */
  if (kkb) {
    dasm_put(Dst, 2033, (ptrdiff_t)(kkb));
  } else {
    dasm_put(Dst, 2036, Dt2([rkb]));
  }
  if (kkc) {
    dasm_put(Dst, 1869, (ptrdiff_t)(kkc));
  } else {
    dasm_put(Dst, 2040, Dt2([rkc]));
  }
  if (target) {  /* TM_LT or TM_LE. */
    dasm_put(Dst, 2470, Dt1(->savedpc), (ptrdiff_t)(J->nextins), (ptrdiff_t)(ev==TM_LT?luaV_lessthan:luaV_lessequal), Dt1(->base));
    if (dest) {  /* cond */
      dasm_put(Dst, 2488, target);
    } else {
      dasm_put(Dst, 301, target);
    }
  } else {
    if (dest) {
    dasm_put(Dst, 886, dest*sizeof(TValue));
    }
    dasm_put(Dst, 2492, Dt1(->savedpc), (ptrdiff_t)(J->nextins), ev, (ptrdiff_t)(luaV_arith), Dt1(->base));
  }

  if (!special) {
    dasm_put(Dst, 689);
  }
}

/* ------------------------------------------------------------------------ */

static void jit_op_unm(jit_State *J, int dest, int rb)
{
  dasm_put(Dst, 2511, Dt2([rb].tt), Dt2([rb].value), Dt2([dest].value));
  if (dest != rb) {
    dasm_put(Dst, 1003, Dt2([dest].tt));
  }
  dasm_put(Dst, 671);
  dasm_put(Dst, 2528, Dt2([rb]));
  if (dest) {
  dasm_put(Dst, 886, dest*sizeof(TValue));
  }
  dasm_put(Dst, 2534, Dt1(->savedpc), (ptrdiff_t)(J->nextins), TM_UNM, (ptrdiff_t)(luaV_arith), Dt1(->base));
}

static void jit_fallback_len(lua_State *L, StkId ra, const TValue *rb)
{
  const TValue *tm = luaT_gettmbyobj(L, rb, TM_LEN);
  if (ttisfunction(tm)) {
    ptrdiff_t rasave = savestack(L, ra);
    setobj2s(L, L->top, tm);
    setobj2s(L, L->top+1, rb);
    luaD_checkstack(L, 2);
    L->top += 2;
    luaD_call(L, L->top - 2, 1);
    ra = restorestack(L, rasave);
    L->top--;
    setobjs2s(L, ra, L->top);
  } else {
    luaG_typeerror(L, rb, "get length of");
  }
}

static void jit_op_len(jit_State *J, int dest, int rb)
{
  const TValue *typehint = hint_get(J, TYPE);
  dasm_put(Dst, 2557, Dt2([rb].tt), Dt2([rb].value));
  if (ttisstring(typehint)) {
    dasm_put(Dst, 2564, DtB(->tsv.len), Dt2([dest].value), Dt2([dest].tt));
    dasm_put(Dst, 2591, (ptrdiff_t)(luaH_getn));
  } else {
    dasm_put(Dst, 2612, (ptrdiff_t)(luaH_getn), Dt2([dest].value), Dt2([dest].tt));
    dasm_put(Dst, 2646, DtB(->tsv.len));
  }
  dasm_put(Dst, 2660, Dt2([rb]));
  if (dest) {
  dasm_put(Dst, 886, dest*sizeof(TValue));
  }
  dasm_put(Dst, 2669, Dt1(->savedpc), (ptrdiff_t)(J->nextins), (ptrdiff_t)(jit_fallback_len), Dt1(->base));
}

static void jit_op_not(jit_State *J, int dest, int rb)
{
  /* l_isfalse() without a branch -- truly devious. */
  /* ((value & tt) | (tt>>1)) is only zero for nil/false. */
  /* Assumes: LUA_TNIL == 0, LUA_TBOOLEAN == 1, bvalue() == 0/1 */
  dasm_put(Dst, 2689, Dt2([rb].tt), Dt2([rb].value), Dt2([dest].tt), Dt2([dest].value));
}

/* ------------------------------------------------------------------------ */

static void jit_op_concat(jit_State *J, int dest, int first, int last)
{
  dasm_put(Dst, 2719, Dt1(->savedpc), (ptrdiff_t)(J->nextins), last, last-first+1, (ptrdiff_t)(luaV_concat), Dt1(->base));
  if (dest != first) {
    dasm_put(Dst, 1027, Dt2([first].value), Dt2([first].value.na[1]), Dt2([first].tt), Dt2([dest].value), Dt2([dest].value.na[1]), Dt2([dest].tt));
  }
  jit_checkGC(J);
}

/* ------------------------------------------------------------------------ */

static void jit_op_eq(jit_State *J, int cond, int rkb, int rkc, int target)
{
  int condtarget = cond ? J->nextpc : target;
  jit_assert(cond == 0 || cond == 1);

  /* Comparison of two constants. Evaluate at compile time. */
  if (ISK(rkb&rkc)) {
    if ((rkb == rkc) == cond) {  /* Constants are already unique. */
      dasm_put(Dst, 1401, target);
    }
    return;
  }

  if (ISK(rkb|rkc)) {  /* Compare a variable and a constant. */
    const TValue *kk;
    if (ISK(rkb)) { int t = rkc; rkc = rkb; rkb = t; }  /* rkc holds const. */
    kk = &J->pt->k[INDEXK(rkc)];
    switch (ttype(kk)) {
    case LUA_TNIL:
      dasm_put(Dst, 2737, Dt2([rkb].tt));
      break;
    case LUA_TBOOLEAN:
      if (bvalue(kk)) {
	dasm_put(Dst, 2742, Dt2([rkb].tt), Dt2([rkb].value));
      } else {
	dasm_put(Dst, 2753, Dt2([rkb].tt), Dt2([rkb].value));
      }
      break;
    case LUA_TNUMBER:
      dasm_put(Dst, 2761, Dt2([rkb].tt), condtarget, Dt2([rkb].value), &kk->value);
      if (J->flags & JIT_F_CPU_CMOV) {
      dasm_put(Dst, 1938);
      } else {
      dasm_put(Dst, 1943);
      }
      dasm_put(Dst, 2446, condtarget);
      break;
    case LUA_TSTRING:
      dasm_put(Dst, 2775, Dt2([rkb].tt), condtarget, Dt2([rkb].value), (ptrdiff_t)(rawtsvalue(kk)));
      break;
    default: jit_assert(0); break;
    }
  } else {  /* Compare two variables. */
    const TValue *typehint = hint_getpc(J, TYPE, J->nextpc-2);
    int hastail = 0;
    dasm_put(Dst, 2787, Dt2([rkb].tt), Dt2([rkc].tt), condtarget);
    if (ttisnumber(typehint)) {
      dasm_put(Dst, 2797, Dt2([rkb].value), Dt2([rkc].value));
      if (J->flags & JIT_F_CPU_CMOV) {
      dasm_put(Dst, 1938);
      } else {
      dasm_put(Dst, 1943);
      }
      dasm_put(Dst, 2812, condtarget);
      hastail = 1;
    } else if (ttisstring(typehint)) {
      dasm_put(Dst, 2819, Dt2([rkb].value), Dt2([rkc].value));
      hastail = 1;
    }
    dasm_put(Dst, 2837, Dt2([rkc]), Dt2([rkb]), Dt1(->savedpc), (ptrdiff_t)(J->nextins), (ptrdiff_t)(luaV_equalval), Dt1(->base));
    if (hastail) {
      dasm_put(Dst, 689);
    }
  }
  if (cond) {
    dasm_put(Dst, 301, target);
  } else {
    dasm_put(Dst, 2488, target);
  }
}

/* ------------------------------------------------------------------------ */

static void jit_op_test(jit_State *J, int cond, int dest, int src, int target)
{
  /* l_isfalse() without a branch. But this time preserve tt/value. */
  /* (((value & tt) * 2 + tt) >> 1) is only zero for nil/false. */
  /* Assumes: 3*tt < 2^32, LUA_TNIL == 0, LUA_TBOOLEAN == 1, bvalue() == 0/1 */
  dasm_put(Dst, 2862, Dt2([src].tt), Dt2([src].value));

  /* Check if we can omit the stack copy. */
  if (dest == src) {  /* Yes, invert branch condition. */
    if (cond) {
      dasm_put(Dst, 2488, target);
    } else {
      dasm_put(Dst, 301, target);
    }
  } else {  /* No, jump around copy code. */
    if (cond) {
      dasm_put(Dst, 2878);
    } else {
      dasm_put(Dst, 2883);
    }
    dasm_put(Dst, 2888, Dt2([src].value.na[1]), Dt2([dest].tt), Dt2([dest].value), Dt2([dest].value.na[1]), target);
  }
}

static void jit_op_jmp(jit_State *J, int target)
{
  dasm_put(Dst, 1401, target);
}

/* ------------------------------------------------------------------------ */

enum { FOR_IDX, FOR_LIM, FOR_STP, FOR_EXT };

/* Coerce string to number in place. Return non-zero on failure. */
static int coerce_s2n(TValue *obj)
{
  lua_Number num;
  if (ttisnumber(obj)) return 0;
  if (ttisstring(obj) && luaO_str2d(svalue(obj), &num)) {
    setnvalue(obj, num);
    return 0;
  }
  return 1;
}

static void jit_for_coerce(lua_State *L, TValue *ra)
{
  if (coerce_s2n(ra+FOR_IDX))
    luaG_runerror(L, LUA_QL("for") " initial value must be a number");
  else if (coerce_s2n(ra+FOR_LIM))
    luaG_runerror(L, LUA_QL("for") " limit must be a number");
  else if (coerce_s2n(ra+FOR_STP))
    luaG_runerror(L, LUA_QL("for") " step must be a number");
}

static void jit_op_forprep(jit_State *J, int ra, int target)
{
  const TValue *step = hint_get(J, FOR_STEP_K);
  if (ttisnumber(step)) {
    dasm_put(Dst, 2905, Dt2([ra+FOR_IDX].tt), Dt2([ra+FOR_LIM].tt), (3<<8)|3, Dt2([ra+FOR_LIM].value), Dt2([ra+FOR_IDX].value), Dt2([ra+FOR_EXT].value));
    if (J->flags & JIT_F_CPU_CMOV) {
    dasm_put(Dst, 1938);
    } else {
    dasm_put(Dst, 1943);
    }
    dasm_put(Dst, 1003, Dt2([ra+FOR_EXT].tt));
    if (nvalue(step) < (lua_Number)0) {
      dasm_put(Dst, 2450, target+1);
    } else {
      dasm_put(Dst, 2458, target+1);
    }
  } else {
    dasm_put(Dst, 2934, Dt2([ra+FOR_IDX].tt), Dt2([ra+FOR_LIM].tt), Dt2([ra+FOR_STP].tt), (3<<16)|(3<<8)|3, Dt2([ra+FOR_STP].value.na[1]), Dt2([ra+FOR_LIM].value), Dt2([ra+FOR_IDX].value), Dt2([ra+FOR_EXT].value));
    dasm_put(Dst, 2978);
    if (J->flags & JIT_F_CPU_CMOV) {
    dasm_put(Dst, 1938);
    } else {
    dasm_put(Dst, 1943);
    }
    dasm_put(Dst, 2983, Dt2([ra+FOR_EXT].tt), target+1);
  }
  dasm_put(Dst, 673);
  dasm_put(Dst, 2994, Dt2([ra]), Dt1(->savedpc), (ptrdiff_t)(J->nextins), (ptrdiff_t)(jit_for_coerce));
}

static void jit_op_forloop(jit_State *J, int ra, int target)
{
  const TValue *step = hint_getpc(J, FOR_STEP_K, target-1);
  if (ttisnumber(step)) {
    dasm_put(Dst, 3015, Dt2([ra+FOR_LIM].value), Dt2([ra+FOR_IDX].value), Dt2([ra+FOR_STP].value), Dt2([ra+FOR_EXT].value), Dt2([ra+FOR_IDX].value), Dt2([ra+FOR_EXT].tt));
    if (J->flags & JIT_F_CPU_CMOV) {
    dasm_put(Dst, 1938);
    } else {
    dasm_put(Dst, 1943);
    }
    if (nvalue(step) < (lua_Number)0) {
      dasm_put(Dst, 2462, target);
    } else {
      dasm_put(Dst, 2454, target);
    }
  } else {
    dasm_put(Dst, 3038, Dt2([ra+FOR_STP].value.na[1]), Dt2([ra+FOR_LIM].value), Dt2([ra+FOR_IDX].value), Dt2([ra+FOR_STP].value), Dt2([ra+FOR_IDX].value), Dt2([ra+FOR_EXT].value), Dt2([ra+FOR_EXT].tt));
    if (J->flags & JIT_F_CPU_CMOV) {
    dasm_put(Dst, 1938);
    } else {
    dasm_put(Dst, 1943);
    }
    dasm_put(Dst, 2462, target);
  }
}

/* ------------------------------------------------------------------------ */

static void jit_op_tforloop(jit_State *J, int ra, int nresults, int target)
{
  dasm_put(Dst, 3076, Dt2([ra+2].value), Dt2([ra+2].value.na[1]), Dt2([ra+2].tt), Dt2([ra+5].value), Dt2([ra+5].value.na[1]), Dt2([ra+5].tt), Dt2([ra+1].value), Dt2([ra+1].value.na[1]), Dt2([ra+1].tt), Dt2([ra+4].value), Dt2([ra+4].value.na[1]), Dt2([ra+4].tt), Dt2([ra].value));
  dasm_put(Dst, 1030, Dt2([ra].value.na[1]), Dt2([ra].tt), Dt2([ra+3].value), Dt2([ra+3].value.na[1]), Dt2([ra+3].tt));
  jit_op_call(J, ra+3, 2, nresults);
  dasm_put(Dst, 3116, Dt2([ra+3].tt), Dt2([ra+3].value), Dt2([ra+3].value.na[1]), Dt2([ra+3].tt), Dt2([ra+2].value), Dt2([ra+2].value.na[1]), Dt2([ra+2].tt), target);
}

/* ------------------------------------------------------------------------ */

static void jit_op_close(jit_State *J, int ra)
{
  if (ra) {
    dasm_put(Dst, 3147, Dt2([ra]));
  } else {
    dasm_put(Dst, 3152);
  }
  dasm_put(Dst, 879, (ptrdiff_t)(luaF_close));
}

static void jit_op_closure(jit_State *J, int dest, int ptidx)
{
  Proto *npt = J->pt->p[ptidx];
  int nup = npt->nups;
  if (!J->pt->is_vararg) {
  dasm_put(Dst, 1893, Dt2([-1].value));
  } else {
  dasm_put(Dst, 3154, Dt1(->ci), Dt4(->func), Dt3(->value));
  }
  dasm_put(Dst, 3164, Dt5(->env), nup, (ptrdiff_t)(luaF_newLclosure), Dt5(->p), (ptrdiff_t)(npt), Dt2([dest].value), Dt2([dest].tt));
  /* Process pseudo-instructions for upvalues. */
  if (nup > 0) {
    const Instruction *uvcode = J->nextins;
    int i, uvuv;
    /* Check which of the two types we need. */
    for (i = 0, uvuv = 0; i < nup; i++)
      if (GET_OPCODE(uvcode[i]) == OP_GETUPVAL) uvuv++;
    /* Copy upvalues from parent first. */
    if (uvuv) {
      /* LCL:eax->upvals (new closure) <-- LCL:edi->upvals (own closure). */
      for (i = 0; i < nup; i++)
	if (GET_OPCODE(uvcode[i]) == OP_GETUPVAL) {
	  dasm_put(Dst, 3191, Dt5(->upvals[GETARG_B(uvcode[i])]), Dt5(->upvals[i]));
	}
    }
    /* Next find or create upvalues for our own stack slots. */
    if (nup > uvuv) {
      dasm_put(Dst, 3198);
      /* LCL:edi->upvals (new closure) <-- upvalue for stack slot. */
      for (i = 0; i < nup; i++)
	if (GET_OPCODE(uvcode[i]) == OP_MOVE) {
	  int rb = GETARG_B(uvcode[i]);
	  if (rb) {
	    dasm_put(Dst, 3207, Dt2([rb]));
	  } else {
	    dasm_put(Dst, 3215);
	  }
	  dasm_put(Dst, 3220, (ptrdiff_t)(luaF_findupval), Dt5(->upvals[i]));
	}
      dasm_put(Dst, 882);
    }
    J->nextpc += nup;  /* Skip pseudo-instructions. */
    J->nextins += nup;
  }
  jit_checkGC(J);
}

/* ------------------------------------------------------------------------ */

static void jit_op_vararg(jit_State *J, int dest, int num)
{
  if (num < 0) {  /* Copy all varargs. */
    dasm_put(Dst, 3226, Dt1(->ci), Dt4(->func), (1+J->pt->numparams)*sizeof(TValue), J->pt->maxstacksize*sizeof(TValue), Dt1(->stack_last), Dt2([dest]));
    dasm_put(Dst, 3282, Dt1(->top));
    switch (sizeof(TValue)) {
    case 8:
    dasm_put(Dst, 473);
      break;
    case 12:
    dasm_put(Dst, 478);
      break;
    case 16:
    dasm_put(Dst, 489);
      break;
    default: jit_assert(0); break;
    }
    dasm_put(Dst, 3288, (ptrdiff_t)(luaD_growstack), Dt1(->base));
  } else if (num > 0) {  /* Copy limited number of varargs. */
    dasm_put(Dst, 3303, Dt1(->ci), Dt4(->func), (1+J->pt->numparams)*sizeof(TValue), Dt2([dest]), Dt2([dest+num]));
    dasm_put(Dst, 3351, Dt3([0].tt), sizeof(TValue));
  }
}

/* ------------------------------------------------------------------------ */

