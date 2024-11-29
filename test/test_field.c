#include "field.h"
#include <stdio.h>

const int m = 4;
const int prim = 0b10011;

int main() {
  GF gf = gf_ctor(m, prim);

  printf("幂表示\t\t向量表示\n");
  for (int i = 0; i < 1 << m; i++) {
    int e = i, v = gf_e2v(gf, i);

    printf("%d\t\t", e);
    for (int j = m - 1; j >= 0; j--) {
      printf("%d", (v >> j) & 1);
    }
    printf("\n");
  }

  puts("");

  printf("e2v 数组\n");
  printf("int e2v[] = {");
  for (int i = 0; i < 1 << m; i++) {
    printf("%d", gf_e2v(gf, i));
    printf(i != (1 << m) - 1 ? ", " : "};\n");
  }
  printf("int v2e[] = {");
  for (int i = 0; i < 1 << m; i++) {
    printf("%d", gf_v2e(gf, i));
    printf(i != (1 << m) - 1 ? ", " : "};\n");
  }
}