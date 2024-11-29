#ifndef ECC_BCH_H
#define ECC_BCH_H

#include "field.h"

/**
 * BCH 生成生成矩阵
 * 
 * 参数
 * n:     码字长度
 * k:     消息长度
 * g_arr: 生成多项式
 * gf:    有限域
 * 
 * 返回值
 * g_mt:  生成矩阵
 */
void bch_generate_g(int n, int k, int g_arr, GF gf, int *g_mt);

/**
 * BCH 生成校验矩阵
 * 
 * 参数
 * n:     码字长度
 * t:     错误个数
 * gf:    有限域
 * 
 * 返回值
 * h_mt:  校验矩阵
 */
void bch_generate_h(int n, int t, GF gf, int *h_mt);

#endif