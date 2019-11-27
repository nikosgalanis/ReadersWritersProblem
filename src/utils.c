#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "../headers/utils.h"

/*print an error depending on what is caused from*/
void print_error(ErrorCode error) {
  if (error == SHM_ERR)
    printf("Error while allocating shared memory\n");

  else if (error == FORK_ERR)
    printf("Fork failed, memory is full\n");

  else if (error == ARG_ERR)
    printf("You have to give an argument, so we know the percentage of the raders\n");

  exit(EXIT_FAILURE);
}
/*return a random integer between low and high*/
int rand_num(int low, int high) {
  return (rand() % (high - low + 1)) + low;
}

/*return a random number of microseconds depending on the expodential distribution*/
useconds_t alloc_time(int l) {
  float rnd = ((float)rand()) / RAND_MAX;
  /*avoid extreme delays*/
  if (rnd < 0.1)
    rnd += 0.2;
  int ret = 25 * (-logf(rnd) / l);
  return 1.0e6 * ret;
}
