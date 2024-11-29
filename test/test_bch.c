#include "bch.h"
#include "field.h"
#include <stdio.h>

int test_15_11_3() {
  int n = 15, k = 11, t = 1, g_arr = 0b10011;
  GF gf = gf_ctor(4, 0b10011);
  int g_mt[11][15] = {};
  int h_mt[2 * 4][15] = {};

  bch_generate_g(n, k, g_arr, gf, (int*)g_mt);
  bch_generate_h(n, t, gf, (int*)h_mt);

  printf("生成矩阵\n");
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d", g_mt[i][j]);
    }
    printf("\n");
  }
  
  puts("");

  printf("校验矩阵\n");
  for (int i = 0; i < 2 * t * gf.m; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d", h_mt[i][j]);
    }
    printf("\n");
  }
}

int main() {
  test_15_11_3();
}