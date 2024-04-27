#include "template.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define N n()
#define K k()
#define MAX_WORD 128

int err_num;
int msg_send[MAX_WORD];
int codeword_send[MAX_WORD];
int codeword_recv[MAX_WORD];
int msg_recv[MAX_WORD];

void print_word(int word[], int len) {
  for (int i = 0; i < len; i++) {
    printf("%d", word[i]);
  }
  printf("\n");
}

void verify() {
  for (int i = 0; i < K; i++) {
    if (msg_send[i] != msg_recv[i]) {
      printf("raw message\n\t");
      print_word(msg_send, K);
      printf("encode and send\n\t");
      print_word(codeword_send, N);
      printf("receive\n\t");
      print_word(codeword_recv, N);
      printf("decode\n\t");
      print_word(msg_recv, K);
      assert(0);
    }
  }
}

void sim_err(int num, int start) {
  if (num == err_num) {
    return;
  }

  for (int e = start; e < N; e++) {
    codeword_recv[e] = 1 - codeword_recv[e];

    decode(codeword_recv, msg_recv);
    verify();
    sim_err(num + 1, start + 1);

    codeword_recv[e] = 1 - codeword_recv[e];
  }
}

int main(int argc, char **argv) {
  if (argc == 1) {
    printf("缺少错误个数\n");
    exit(1);
  }

  err_num = atoi(argv[1]);

  for (int i = 0; i < 1 << K; i++) {
    for (int j = 0; j < K; j++) {
      msg_send[j] = i >> j & 1;
    }
    encode(msg_send, codeword_send);
    for (int j = 0; j < N; j++) {
      codeword_recv[j] = codeword_send[j];
    }

    sim_err(0, 0);
  }
}