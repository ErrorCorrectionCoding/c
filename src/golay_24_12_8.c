#include "template.h"

#define N 24
#define K 12
#define T 8

int n() { return N; }
int k() { return K; }

const int B[K][K] = {
  {1,1,0,1,1,1,0,0,0,1,0,1},
  {1,0,1,1,1,0,0,0,1,0,1,1},
  {0,1,1,1,0,0,0,1,0,1,1,1},
  {1,1,1,0,0,0,1,0,1,1,0,1},
  {1,1,0,0,0,1,0,1,1,0,1,1},
  {1,0,0,0,1,0,1,1,0,1,1,1},
  {0,0,0,1,0,1,1,0,1,1,1,1},
  {0,0,1,0,1,1,0,1,1,1,0,1},
  {0,1,0,1,1,0,1,1,1,0,0,1},
  {1,0,1,1,0,1,1,1,0,0,0,1},
  {0,1,1,0,1,1,1,0,0,0,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,0}
};

int weight_syn(int s[]) {
  int sum = 0;
  for (int i = 0; i < K; i++) {
    sum += s[i];
  }
  return sum;
}

void encode(const int msg[], int codeword[]) {
  for (int i = 0; i < K; i++) {
    codeword[i] = msg[i];
  }

  for (int i = 0; i < K; i++) {
    codeword[K + i] = 0;
    for (int j = 0; j < K; j++) {
      codeword[K + i] ^= msg[j] * B[j][i];
    }
  }
}

void decode(const int codeword[], int msg[]) {
  int s[K] = {}, sb[K] = {};

  for (int i = 0; i < K; i++) {
    s[i] = codeword[i];
    for (int j = 0; j < K; j++) {
      s[i] ^= codeword[K + j] * B[j][i];
    }
  }

  if (weight_syn(s) <= 3) {
    for (int i = 0; i < K; i++) {
      msg[i] = codeword[i] ^ s[i];
    }
    return;
  }
  else {
    for (int i = 0; i < K; i++) {
      for (int j = 0; j < K; j++) {
        sb[j] = s[j] ^ B[i][j];
      }
      if (weight_syn(sb) <= 2) {
        for (int j = 0; j < K; j++) {
          msg[j] = codeword[j] ^ sb[j];
        }
        return;
      }
    }
  }

  for (int i = 0; i < K; i++) {
    s[i] = codeword[K + i];
    for (int j = 0; j < K; j++) {
      s[i] ^= codeword[j] * B[j][i];
    }
  }

  if (weight_syn(s) <= 3) {
    for (int i = 0; i < K; i++) {
      msg[i] = codeword[i];
    }
    return;
  }
  else {
    for (int i = 0; i < K; i++) {
      for (int j = 0; j < K; j++) {
        sb[j] = s[j] ^ B[i][j];
      }
      if (weight_syn(sb) <= 2) {
        for (int j = 0; j < K; j++) {
          msg[j] = j == i ? 1 ^ codeword[j] : codeword[j];
        }
        return;
      }
    }
  }
}