/*
** JIT engine hints.
** Copyright (C) 2005 Mike Pall. See Copyright Notice in luajit.h
*/

#ifdef STRING_HINTS
#define HH(x, name)		#name
#define HH_START(x)		static const char *const hints_##x [] = {
#define HH_END(x)		NULL }
#else
#define HH(x, name)		JIT_##x##_##name
#define HH_START(x)		enum { JIT_##x##_NONE,
#define HH_END(x)		JIT_##x##_MAX }

/* Macros to access hints. */
#define JIT_H2NUM(x)		((x)<<16)

#define fhint_get(J, hh) \
  (luaH_getnum(J->comstate, JIT_H2NUM(JIT_HF_##hh)))
#define fhint_isset(J, hh)	(!ttisnil(fhint_get(J, hh)))

#define hint_getpc(J, hh, pc) \
  (luaH_getnum(J->comstate, (pc)+JIT_H2NUM(JIT_H_##hh)))
#define hint_get(J, hh)		hint_getpc(J, hh, J->nextpc-1)
#define hint_issetpc(J, hh, pc)	(!ttisnil(hint_getpc(J, hh, pc)))
#define hint_isset(J, hh)	hint_issetpc(J, hh, J->nextpc-1)

#endif

/* Hints for functions. */
HH_START(HF)
  HH(HF, NOCLOSE),		/* No luaF_close() needed. */
HH_END(HF);

/* Hints for individual bytecode instruction. */
HH_START(H)
  HH(H, DEAD),		/* Instruction is dead: true. */
  HH(H, TYPE),		/* Type hint: typed object. */
  HH(H, FOR_STEP_K),	/* FORPREP/FORLOOP step is const: step. */
  HH(H, SHORTCUT_K),	/* Shortcut const: dest: k [nil->func], src: pc. */
  HH(H, INLINE_IDX),	/* Inline function call: internal index. */
  HH(H, INLINE_MATCH),	/* Inline function call: closure to match. */
HH_END(H);

#undef HH
#undef HH_START
#undef HH_END

