#include "template.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#define N n()
#define K k()
#define MAX_WORD 128

int err_num;
int msg_times;
int err_times;
int err_pos[8];
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
      print_word(codeword_send, N);
      printf("decode\n\t");
      print_word(msg_recv, K);
      assert(0);
    }
  }
}

void sim_err() {
  for (int i = 0; i < err_times; i++) {
    int num = 0;
    while (num < err_num) {
      int pos = rand() % N;

      for (int j = 0; j < num; j++) {
        if (err_pos[j] == pos) {
          continue;
        }
      }

      err_pos[num++] = pos;
    }

    for (int j = 0; j < err_num; j++) {
      codeword_recv[err_pos[j]] = 1 - codeword_recv[err_pos[j]];
    }

    decode(codeword_recv, msg_recv);
    verify();

    for (int j = 0; j < err_num; j++) {
      codeword_recv[err_pos[j]] = 1 - codeword_recv[err_pos[j]];
    }
  }
}

int main(int argc, char **argv) {
  if (argc < 4) {
    switch (argc) {
      case 1:
        printf("缺少错误个数\n");
        break;
      case 2:
        printf("缺少消息仿真次数\n");
        break;
      case 3:
        printf("缺少错误仿真次数\n");
        break;
    }
    exit(1);
  }
  
  srand(time(NULL));

  err_num = atoi(argv[1]);
  msg_times = atoi(argv[2]);
  err_times = atoi(argv[3]);

  for (int i = 0; i < msg_times; i++) {
    int msg = rand() % (1 << K);

    for (int j = 0; j < K; j++) {
      msg_send[j] = msg >> j & 1;
    }

    encode(msg_send, codeword_send);
    for (int j = 0; j < N; j++) {
      codeword_recv[i] = codeword_send[i];
    }

    sim_err();
  }
}