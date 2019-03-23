/*
** DynASM x86 encoding engine.
** Copyright (C) 2005 Mike Pall. All rights reserved.
** Released under the MIT/X license. See dynasm.lua for full copyright notice.
*/

#include <stddef.h>
#include <stdarg.h>
#include <string.h>

/* Action definitions. DASM_STOP must be 255. */
enum {
  DASM_DISP = 237,
  DASM_IMM_S, DASM_IMM_B, DASM_IMM_W, DASM_IMM_D, DASM_IMM_WB, DASM_IMM_DB,
  DASM_REL_G, DASM_REL_L, DASM_REL_P, DASM_IMM_L, DASM_IMM_P,
  DASM_LABEL_L, DASM_LABEL_P, DASM_ALIGN, DASM_ESC, DASM_MARK,
  DASM_SECTION, DASM_STOP
};


/* Maximum number of section buffer positions for a single dasm_put() call. */
#define DASM_MAXSECPOS		15

/* DynASM encoder status codes. Action list offset or number are or'ed in. */
#define DASM_S_OK		0x00000000
#define DASM_S_NOMEM		0x01000000
#define DASM_S_PHASE		0x02000000
#define DASM_S_MATCH_SEC	0x03000000
#define DASM_S_RANGE_I		0x11000000
#define DASM_S_RANGE_P		0x12000000
#define DASM_S_RANGE_SEC	0x13000000
#define DASM_S_UNDEF_L		0x21000000
#define DASM_S_UNDEF_P		0x22000000

/* Macros to convert positions (8 bit section + 24 bit index). */
#define DASM_POS2IDX(pos)	((pos)&0x00ffffff)
#define DASM_POS2BIAS(pos)	((pos)&0xff000000)
#define DASM_SEC2POS(sec)	((sec)<<24)
#define DASM_POS2SEC(pos)	((pos)>>24)
#define DASM_POS2PTR(D, pos)	(D->sections[DASM_POS2SEC(pos)].rbuf + (pos))


/* Per-section structure. */
typedef struct dasm_Section {
  int *rbuf;		/* Biased buffer pointer (negative section bias). */
  int *buf;		/* True buffer pointer. */
  size_t bsize;		/* Buffer size in bytes. */
  int pos;		/* Biased buffer position. */
  int epos;		/* End of biased buffer position - max single put. */
  int ofs;		/* Byte offset into section. */
} dasm_Section;

/* Core structure holding the DynASM encoding state. */
struct dasm_State {
  size_t psize;			/* Allocated size of this structure. */
  dasm_ActList actionlist;	/* Current actionlist pointer. */
  int *labels;			/* Local/PC label chains/pos ptrs. */
  size_t lsize;
  dasm_Section *section;	/* Pointer to active section. */
  size_t codesize;		/* Total size of all code sections. */
  int maxsection;		/* 0 <= sectionidx < maxsection. */
  int maxpc;			/* 0 <= pc < maxpc */
  int status;			/* Status code. */
  dasm_Section sections[1];	/* All sections. Alloc-extended. */
};

/* The size of the core structure depends on the max. number of sections. */
#define DASM_PSZ(ms)	(sizeof(dasm_State)+(ms-1)*sizeof(dasm_Section))


/* Initialize DynASM state. */
void dasm_init(Dst_DECL, int maxsection)
{
  dasm_State *D;
  size_t psz = 0;
  int i;
  Dst_REF = NULL;
  dasm_m_grow(Dst, (void **)&Dst_REF, &psz, DASM_PSZ(maxsection));
  D = Dst_REF;
  D->psize = psz;
  D->labels = NULL;
  D->lsize = 0;
  D->maxsection = maxsection;
  for (i = 0; i < maxsection; i++) {
    D->sections[i].buf = NULL;  /* Need this for pass3. */
    D->sections[i].rbuf = D->sections[i].buf - DASM_SEC2POS(i);
    D->sections[i].bsize = 0;
    D->sections[i].epos = 0;  /* Wrong, but is recalculated after resize. */
  }
}

/* Free DynASM state. */
void dasm_free(Dst_DECL)
{
  dasm_State *D = Dst_REF;
  int i;
  for (i = 0; i < D->maxsection; i++)
    if (D->sections[i].buf)
      dasm_m_free(Dst, D->sections[i].buf, D->sections[i].bsize);
  if (D->labels) dasm_m_free(Dst, D->labels, D->lsize);
  dasm_m_free(Dst, D, D->psize);
}

/* Setup encoder. */
void dasm_setup(Dst_DECL, dasm_ActList actionlist, int maxpc)
{
  dasm_State *D = Dst_REF;
  int i, n;
  D->actionlist = actionlist;
  D->maxpc = maxpc;
  D->status = DASM_S_OK;
  D->section = &D->sections[0];
  n = (10+maxpc)*sizeof(int);
  dasm_m_grow(Dst, (void **)&D->labels, &D->lsize, n);
  memset((void *)D->labels, 0, n);
  for (i = 0; i < D->maxsection; i++) {
    D->sections[i].pos = DASM_SEC2POS(i);
    D->sections[i].ofs = 0;
  }
}

#ifdef DASM_CHECKS
#define CK(x, st) \
  do { if (!(x)) { \
    D->status = DASM_S_##st|(p-D->actionlist-1); return; } } while (0)
#else
#define CK(x, st)	((void)0)
#endif

/* Pass 1: Store actions and args, link branches/labels, estimate offsets. */
void dasm_put(Dst_DECL, int start, ...)
{
  va_list ap;
  dasm_State *D = Dst_REF;
  dasm_ActList p = D->actionlist + start;
  dasm_Section *sec = D->section;
  int pos = sec->pos, ofs = sec->ofs, mrm = 4;
  int *b;

  if (pos >= sec->epos) {
    dasm_m_grow(Dst, (void **)&sec->buf, &sec->bsize,
      sec->bsize + 2*DASM_MAXSECPOS*sizeof(int));
    sec->rbuf = sec->buf - DASM_POS2BIAS(pos);
    sec->epos = sec->bsize/sizeof(int) - DASM_MAXSECPOS + DASM_POS2BIAS(pos);
  }

  b = sec->rbuf;
  b[pos++] = start;

  va_start(ap, start);
  while (1) {
    int action = *p++;
    if (action < DASM_DISP) {
      ofs++;
    } else if (action <= DASM_REL_G) {
      int n = va_arg(ap, int);
      b[pos++] = n;
      switch (action) {
      case DASM_DISP:
	if (n == 0) { if ((mrm&7) == 4) mrm = p[-2]; if ((mrm&7) != 5) break; }
      case DASM_IMM_DB: if (((n+128)&-256) == 0) goto ob;
      case DASM_REL_G: /* Assumes ptrdiff_t is int. !x64 */
      case DASM_IMM_D: ofs += 4; break;
      case DASM_IMM_S: CK(((n+128)&-256) == 0, RANGE_I); goto ob;
      case DASM_IMM_B: CK((n&-256) == 0, RANGE_I); ob: ofs++; break;
      case DASM_IMM_WB: if (((n+128)&-256) == 0) goto ob;
      case DASM_IMM_W: CK((n&-65536) == 0, RANGE_I); ofs += 2; break;
      }
      mrm = 4;
    } else {
      int *pl, n;
      switch (action) {
      case DASM_REL_L:
      case DASM_IMM_L:
	n = *(char *)p++;
	if (n > 0) goto putrel;  /* Bkwd rel. */
	pl = D->labels - n;
	n = *pl;
	if (n < 0) n = 0;  /* Start new chain for fwd rel if label exists. */
	goto linkrel;
      case DASM_REL_P:
      case DASM_IMM_P:
	n = va_arg(ap, int); CK(n >= 0 && n < D->maxpc, RANGE_P); n += 10;
      putrel:
	pl = D->labels + n;
	n = *pl;
	if (n < 0) {  /* Label exists. Get label pos and store it. */
	  b[pos] = -n;
	} else {
      linkrel:
	  b[pos] = n;  /* Else link to rel chain, anchored at label. */
	  *pl = pos;
	}
	pos++;
	ofs += 4;  /* Maximum offset needed. */
	if (action == DASM_REL_L || action == DASM_REL_P)
	  b[pos++] = ofs;  /* Store pass1 offset estimate. */
	break;
      case DASM_LABEL_L: n = *p++; goto putlabel;
      case DASM_LABEL_P:
	n = va_arg(ap, int); CK(n >= 0 && n < D->maxpc, RANGE_P); n += 10;
      putlabel:
	pl = D->labels + n;
	n = *pl;
	while (n > 0) {  /* Collapse rel chain and replace with label pos. */
	  int *pb = DASM_POS2PTR(D, n);
	  n = *pb;
	  *pb = pos;
	}
	*pl = -pos;  /* Label exists now. */
	b[pos++] = ofs;  /* Store pass1 offset estimate. */
	break;
      case DASM_ALIGN:
	ofs += *p++;  /* Maximum alignment needed (arg is 2**n-1). */
	b[pos++] = ofs;  /* Store pass1 offset estimate. */
	break;
      case DASM_ESC: p++; ofs++; break;
      case DASM_MARK: mrm = p[-2]; break;
      case DASM_SECTION:
	n = *p; CK(n < D->maxsection, RANGE_SEC); D->section = &D->sections[n];
      case DASM_STOP: goto stop;
      }
    }
  }
stop:
  va_end(ap);
  sec->pos = pos;
  sec->ofs = ofs;
}
#undef CK

/* Pass 2: Link sections, shrink branches/aligns, fix label offsets. */
int dasm_link(Dst_DECL, size_t *szp)
{
  dasm_State *D = Dst_REF;
  int secnum;
  int ofs = 0;

#ifdef DASM_CHECKS
  *szp = 0;
  if (D->status != DASM_S_OK) return D->status;
  {
    int pc;
    for (pc = 0; pc < D->maxpc; pc++)
      if (D->labels[10+pc] > 0) return DASM_S_UNDEF_P|pc;
  }
#endif

  /* Combine all code sections. No support for data sections (yet). */
  for (secnum = 0; secnum < D->maxsection; secnum++) {
    dasm_Section *sec = D->sections + secnum;
    int *b = sec->rbuf;
    int pos = DASM_SEC2POS(secnum);
    int lastpos = sec->pos;

    while (pos != lastpos) {
      dasm_ActList p = D->actionlist + b[pos++];
      while (1) {
	int op, action = *p++;
	switch (action) {
	case DASM_REL_L: p++; op = p[-3]; goto relp;
	case DASM_REL_P: op = p[-2]; relp: {
	  int shrink = op == 0xe9 ? 3 : ((op&0xf0) == 0x80 ? 4 : 0);
	  if (shrink) {  /* Shrinkable branch opcode? */
	    int lpos = b[pos];
	    int lofs = *DASM_POS2PTR(D, lpos);
	    if (lpos > pos) {  /* Fwd label: add cumulative section offsets. */
	      int i;
	      for (i = secnum; i < DASM_POS2SEC(lpos); i++)
		lofs += D->sections[i].ofs;
	    } else {
	      lofs -= ofs;  /* Bkwd label: unfix offset. */
	    }
	    lofs -= b[pos+1];
	    if (lofs >= -128-shrink && lofs <= 127)  /* Short branch ok? */
	      ofs -= shrink;  /* Yes, adjust offset. */
	    else
	      shrink = 0;  /* Else cannot shrink op. */
	  }
	  b[pos+1] = shrink;
	  pos += 2;
	  break;
	}
	case DASM_IMM_L: p++;
	case DASM_DISP: case DASM_IMM_S: case DASM_IMM_B: case DASM_IMM_W:
	case DASM_IMM_D: case DASM_IMM_WB: case DASM_IMM_DB: case DASM_REL_G:
	case DASM_IMM_P: pos++; break;
	case DASM_LABEL_L: p++;
	case DASM_LABEL_P: b[pos++] += ofs; break; /* Fix label offset. */
	case DASM_ALIGN: ofs -= (b[pos++]+ofs)&*p++; break; /* Adjust ofs. */
	case DASM_ESC: p++;
	case DASM_MARK: break;
	case DASM_SECTION: case DASM_STOP: goto stop;
	}
      }
      stop: (void)0;
    }
    ofs += sec->ofs;  /* Next section starts right after current section. */
  }

  D->codesize = ofs;  /* Total size of all code sections */
  *szp = ofs;
  return DASM_S_OK;
}

#define dasmb(x)	*cp++ = (unsigned char)(x)
#ifndef DASM_ALIGNED_WRITES
#define dasmw(x) \
  do { *((unsigned short *)cp) = (unsigned short)(x); cp+=2; } while (0)
#define dasmd(x) \
  do { *((unsigned int *)cp) = (unsigned int)(x); cp+=4; } while (0)
#else
#define dasmw(x)	do { dasmb(x); dasmb((x)>>8); } while (0)
#define dasmd(x)	do { dasmw(x); dasmw((x)>>16); } while (0)
#endif

/* Pass 3: Encode sections. */
int dasm_encode(Dst_DECL, void *buffer)
{
  dasm_State *D = Dst_REF;
  unsigned char *base = (unsigned char *)buffer;
  unsigned char *cp = base;
  int secnum;

  /* Encode all code sections. No support for data sections (yet). */
  for (secnum = 0; secnum < D->maxsection; secnum++) {
    dasm_Section *sec = D->sections + secnum;
    int *b = sec->buf;
    int *endb = sec->rbuf + sec->pos;

    while (b != endb) {
      dasm_ActList p = D->actionlist + *b++;
      unsigned char *mark = NULL;
      while (1) {
	int action = *p++;
	int n = (action >= DASM_DISP && action <= DASM_ALIGN) ? *b++ : 0;
	switch (action) {
	case DASM_DISP: if (!mark) mark = cp; {
	  unsigned char *mm = mark;
	  if (*p != DASM_IMM_DB && *p != DASM_IMM_WB) mark = NULL;
	  if (n == 0) { int mrm = mm[-1]&7; if (mrm == 4) mrm = mm[0]&7;
	    if (mrm != 5) { mm[-1] -= 0x80; break; } }
	  if (((n+128) & -256) != 0) goto wd; else mm[-1] -= 0x40;
	}
	case DASM_IMM_S: case DASM_IMM_B: wb: dasmb(n); break;
	case DASM_IMM_DB: if (((n+128)&-256) == 0) {
	    db: if (!mark) mark = cp; mark[-2] += 2; mark = NULL; goto wb;
	  } else mark = NULL;
	case DASM_IMM_D: wd: dasmd(n); break;
	case DASM_IMM_WB: if (((n+128)&-256) == 0) goto db; else mark = NULL;
	case DASM_IMM_W: dasmw(n); break;
	case DASM_REL_G: n -= (int)(cp+4); goto wd;  /* !x64 */
	case DASM_REL_L: p++;
	case DASM_REL_P: {
	  int shrink = *b++;
	  n = *DASM_POS2PTR(D, n) - ((cp-base) + 4-shrink);
	  if (shrink == 0) goto wd;
	  if (shrink == 4) { cp--; cp[-1] = *cp-0x10; } else cp[-1] = 0xeb;
	  goto wb;
	}
	case DASM_IMM_L: p++;
	case DASM_IMM_P: n = (ptrdiff_t)base + *DASM_POS2PTR(D, n); goto wd;
	case DASM_LABEL_L: p++;
	case DASM_LABEL_P: break;
	case DASM_ALIGN:
	  n = *p++;
	  while (((cp-base) & n)) *cp++ = 0x90; /* nop */
	  break;
	case DASM_MARK: mark = cp; break;
	case DASM_ESC: action = *p++;
	default: *cp++ = action; break;
	case DASM_SECTION: case DASM_STOP: goto stop;
	}
      }
      stop: (void)0;
    }
  }

  if (base + D->codesize != cp)  /* Check for phase errors. */
    return DASM_S_PHASE;
  return DASM_S_OK;
}

/* Get PC label addresses. */
void dasm_getlabels(Dst_DECL, void *base, void **pcaddr)
{
  dasm_State *D = Dst_REF;
  int pc;

  for (pc = 0; pc < D->maxpc; pc++) {
    int pos = D->labels[10+pc];
    if (pos >= 0) pcaddr[pc] = NULL;
    else pcaddr[pc] = (void *)((unsigned char *)base + *DASM_POS2PTR(D, -pos));
  }
}

#ifdef DASM_CHECKS
/* Optional sanity checker to call between isolated encoding steps. */
int dasm_checkstep(Dst_DECL, int secmatch)
{
  dasm_State *D = Dst_REF;
  if (D->status == DASM_S_OK) {
    int i;
    for (i = 1; i <= 9; i++)
      if (D->labels[i] > 0) { D->status = DASM_S_UNDEF_L|i; break; }
  }
  if (D->status == DASM_S_OK && secmatch >= 0 &&
      D->section != &D->sections[secmatch])
    D->status = DASM_S_MATCH_SEC|(D->section-D->sections);
  return D->status;
}
#endif

