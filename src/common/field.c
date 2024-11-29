#include "field.h"

GF gf_ctor(int m, gf_t prim) {
  GF gf = {m, prim};

  gf.e2v[0] = 1;

  for (int i = 1; i < 1 << m; i++) {
    gf.e2v[i] = gf.e2v[i - 1] << 1;
    if ((gf.e2v[i] >> m) & 1) {
      gf.e2v[i] ^= prim;
    }
    gf.v2e[gf.e2v[i]] = i;
  }

  gf.v2e[0] = -1;
  gf.v2e[1] = 0;

  return gf;
}

gf_t gf_e(GF gf, gf_t e) {
  return e % ((1 << gf.m) - 1);
}

gf_t gf_e2v(GF gf, gf_t e) {
  return gf.e2v[e % ((1 << gf.m) - 1)];
}

gf_t gf_v2e(GF gf, gf_t v) {
  return gf.v2e[v];
}

gf_t gf_add(GF gf, gf_t le, gf_t ri) {
  return le ^ ri;
}

gf_t gf_mul(GF gf, gf_t le, gf_t ri) {
  return gf_e2v(gf, gf_v2e(gf, le) + gf_v2e(gf, ri));
}

static int high_bit(gf_t x) {
  int res = -1;
  for (int i = 0; i < sizeof(gf_t) * 8; i++) {
    if (x >> i & 1) {
      res = i;
    }
  }
  return res;
}

gf_t gf_mod(GF gf, gf_t le, gf_t ri) {
  int hb_le = high_bit(le), hb_ri = high_bit(ri);

  while (hb_le >= hb_ri) {
    int ri_align = ri << (hb_le - hb_ri);
    le = le ^ ri_align;
    hb_le = high_bit(le);
  }

  return le;
}