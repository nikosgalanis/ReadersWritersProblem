#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <semaphore.h>

#include "../headers/utils.h"

int main(int argc, char const *argv[]) {
  /*if less than required arguments are given, return an error*/
  if (argc < 2) {
    print_error(ARG_ERR);
  }
  /*set the default size for the argument of the expodential distribution*/
  size_t l = 10;
  /*if an argument for the spped is given, take it into consideration*/
  if (argc == 3) {
    if (strcmp(argv[2], "slow") == 0)
      l = 5;
    else if (strcmp(argv[2], "medium") == 0)
      l =15;
    else
      l = 30;
  }
  /*initiallize the rand seed*/
  srand(time(NULL));
  /*get the number of entries, loops and processes*/
  int n_entries, n_processes, n_loops;
  printf("Give the number of entries\n"); scanf("%d",&n_entries);
  printf("Give the number of processes\n"); scanf("%d",&n_processes);
  printf("Give the number of loops\n"); scanf("%d",&n_loops);
  /*we get the readers/writers ration from the command line*/
  int r_w_ratio = atoi(argv[1]);
  /*run the program*/
  printf("Operating with %d processes of maximum %d loops on %d entries\n", n_processes, n_loops, n_entries);
  coordinator(n_entries, n_processes, n_loops, r_w_ratio, l);

  exit(EXIT_SUCCESS);
}
