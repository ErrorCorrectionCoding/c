#include "bch.h"
#include <string.h>

void bch_generate_g(int n, int k, int g_arr, GF gf, int *g_mt) {
  memset(g_mt, 0, k * n);

  for (int i = 0; i < k; i++) {
    int r = gf_mod(gf, 1 << (n - 1 - i), g_arr);

    *(g_mt + i * n + i) = 1;
    for (int j = n - 1; j >= k; j--) {
      *(g_mt + i * n + j) = r >> (n - 1 - j) & 1;
    }
  }
}

void bch_generate_h(int n, int t, GF gf, int *h_mt) {
  memset(h_mt, 0, t * n);

  for (int i = 0; i < t; i++) {
    for (int j = 0; j < n; j++) {
      int e = gf_e(gf, (2 * i + 1) * j);

      for (int k = 0; k < gf.m; k++) {
        *(h_mt + (2 * i * gf.m + k) * n + j) = gf_e2v(gf, e) >> k & 1;
      }
    }
  }
}