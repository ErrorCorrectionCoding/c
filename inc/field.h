#ifndef FIELD_H
#define FIELD_H

/**
 * 最大支持的有限域的位数
 * 
 * char:        最大支持 GF(2^8)
 * int:         最大支持 GF(2^32)
 * long long:   最大支持 GF(2^64)
 */
#define gf_t int

/**
 * 幂表示和向量表示转换查找表
 * 
 * 最大支持的有限域的位数为 16 位
 */
#define GF_MAX_TABLE_SIZE (1 << 16)

typedef struct GF {
  /**
   * 有限域 GF(2^m)
   */
  int m;

  /**
   * 本原多项式
   */
  gf_t prim;

  /**
   * 幂表示(exp) -> 向量表示(vec) 表
   */
  gf_t e2v[GF_MAX_TABLE_SIZE];
  
  /**
   * 向量表示(vec) -> 幂表示(exp) 表
   */
  gf_t v2e[GF_MAX_TABLE_SIZE];
} GF;

/**
 * GF 构造函数
 */
GF gf_ctor(int m, gf_t prim);

/**
 * 对幂表示取模做归一化
 */
gf_t gf_e(GF gf, gf_t e);

/**
 * 幂表示(exp) -> 向量表示(vec) 接口
 */
gf_t gf_e2v(GF gf, gf_t e);

/**
 * 向量表示(vec) -> 幂表示(exp) 接口
 */
gf_t gf_v2e(GF gf, gf_t v);

/**
 * 向量表示加法
 */
gf_t gf_add(GF gf, gf_t le, gf_t ri);

/**
 * 向量表示乘法
 */
gf_t gf_mul(GF gf, gf_t le, gf_t ri);

/**
 * 向量表示模
 */
gf_t gf_mod(GF gf, gf_t le, gf_t ri);

#endif