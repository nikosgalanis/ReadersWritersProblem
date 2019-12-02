#pragma once
#include <unistd.h>


enum {
  false, true
};

typedef struct {
  int write;
  int read;
  int curr_readers;
} Entry;

typedef enum ErrorCode {
  ARG_ERR,
  SHM_ERR,
  FORK_ERR,
  TIME_ERR
} ErrorCode;

void print_error(ErrorCode error);
useconds_t alloc_time(int l);
void coordinator(size_t n_entries, size_t n_loops, size_t n_processes, size_t r_w_ratio, size_t l);
int rand_num(int low, int high);
