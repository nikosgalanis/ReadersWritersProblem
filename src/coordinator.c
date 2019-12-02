#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#include "../headers/utils.h"

void coordinator(size_t n_entries, size_t n_processes, size_t n_loops, size_t r_w_ratio, size_t l) {
  /*Create two sem arrays*/
  sem_t mutex[n_entries];
  sem_t wrt[n_entries];
  /*Initialize the semaphores' arrays*/
  for (size_t i = 0; i < n_entries; ++i) {
    sem_init(&mutex[i], 1, 1);
    sem_init(&wrt[i], 1, 1);
  }
  size_t shm_id;
  /*get an id to allocate the shared memory*/
  if ((shm_id = shmget(IPC_PRIVATE, n_entries * sizeof(Entry), IPC_CREAT|0666)) == -1)
    print_error(SHM_ERR);
  /*allocate the shared memory for the entries array*/
  Entry* entries = (Entry*) shmat(shm_id, (void*)0, 0);
  if (entries == (Entry *)(-1))
    print_error(SHM_ERR);
  /*Initialize read and write values*/
  for (size_t i = 0; i < n_entries; ++i) {
    entries[i].read = 0;
    entries[i].write = 0;
    entries[i].curr_readers = 0;
  }
  /*create the number of processes given*/
  pid_t pid;
  for (size_t i = 0; i < n_processes; ++i) {
    pid = fork();
    if (pid < 0)
      print_error(FORK_ERR);
    else if (pid == 0) {
      /*child process*/
      /*keep track of the process stats*/
      size_t proc_rd = 0; size_t proc_wrt = 0; size_t wait_time = 0;
      double time_taken = 0;
      /*re-initiallize the rand, to produce different results on every process*/
      srand(time(NULL) - getpid());
      /*we are going to run each process for a pre-known number of loops*/
      size_t loops = rand_num(1, n_loops);
      /*measure the time elapsed for the process*/
      struct timespec start, end;
      if(clock_gettime(CLOCK_MONOTONIC, &start) == -1)
        print_error(TIME_ERR);
      /*read n write for specified loops*/
      for (size_t j = 0; j < loops; ++j) {
        /*choose which entry to operate on*/
        size_t ind = rand_num(0, n_entries - 1);
        /*choose whether to write, or read*/
        size_t rnd = rand_num(0,100);
        useconds_t time = alloc_time(l);
        usleep(time);
        wait_time += time;
        if (rnd < r_w_ratio) {
          /*operation for reading from an entry*/
          sem_wait(&mutex[ind]);
          entries[ind].curr_readers++;
          if (entries[ind].curr_readers == 1)
            sem_wait(&wrt[ind]);
          sem_post(&mutex[ind]);
          /*critical section*/
          proc_rd++;
          entries[ind].read++;
          /*end of critical section, unblock the semaphore*/
          sem_wait(&mutex[ind]);
          entries[ind].curr_readers--;
          if (entries[ind].curr_readers == 0)
            sem_post(&wrt[ind]);
          sem_post(&mutex[ind]);
        }
        else {
          /*operation for writing an entry*/
          sem_wait(&wrt[ind]);
          /*enter critical section*/
          proc_wrt++;
          entries[ind].write++;
          sem_post(&wrt[ind]);
          /*end of critical section*/
        }
      }
      sleep(1);
      /*find the current time*/
      if(clock_gettime(CLOCK_MONOTONIC, &end) == -1)
        print_error(TIME_ERR);
      /*compute the time difference since we started the process*/
      time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) * 1.0e-9;

      /*print statistics for the process*/
      printf("Peer %3ld finished! Reads: %3ld | Writes: %3ld times | average waiting time %.2f | Loops %3ld\n",
      i, proc_rd, proc_wrt, time_taken / loops, loops);
      /*exit, as the child has finished its job*/
      exit(EXIT_SUCCESS);
    }
  }
  /*parent code, all the childs have previously exited*/
  for(size_t i = 0; i < n_processes; ++i)
    wait(&pid);
  /*print stats*/
  size_t writes = 0, reads = 0;
  for (size_t i = 0; i < n_entries; ++i) {
    writes += entries[i].write;
    reads += entries[i].read;
  }
  /*print the total stats of the coordinator*/
  printf("-----------------------Coordinator results-----------------------\n");
  printf("Coordinator finally ended\n");
  printf("The total number of processes was %ld, with each one running maximum %ld times\n", n_processes, n_loops);
  printf("%ld entries were allocated, to operate on\n", n_entries);
  printf("In total, they were %ld writes and %ld reads\n", writes, reads);
  printf("-----------------------------------------------------------------\n");

  /*free the shared memory*/
  shmdt((void *) entries);
  /*free the semaphores*/
  for (size_t i = 0; i < n_entries; ++i){
    sem_destroy(&mutex[i]);
    sem_destroy(&wrt[i]);
  }
}
