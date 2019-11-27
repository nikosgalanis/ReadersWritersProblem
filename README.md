# Readers-Writers Problem
This problem deals with situations in which many threads try to access the same shared resource at one time. Some threads may read and some may write, with the constraint that no process may access the shared resource while another process is currently writing to it.

## Implementing
This project is implemented in C language, using basic thread operations such as fork, and using functions to allocate shared memory, under the shm library. Each process "takes advantage" of the shared memory, for a random time, given by the expodential distribution. The project was implemented for the needs of an Operating Systems course.

## Compiling and running
To compile the program, simply run 
```
make
```
on the project's parent direcotry. To run in, you have to insert one, or two arguments. The first(obligatory) is the ratio of the readers versus the writers(a number from 0 to 100), that you would like the program to keep during the simulation. The second one, which is optional, is a string: "fast", "medium" or "slow", to determine the overall speed of the simulation. So, an example of running the program is:
```
./build/readers_writers 83 fast
```

## Example of execution

```
$ ./build/readers_writers 36 fast
Opperating with 14 processes of maximum 36 loops on 15 entries
Peer   5 finished! Reads:    0 | Writes:    1 times | average waiting time 0.06
Peer   0 finished! Reads:    4 | Writes:    1 times | average waiting time 0.17
Peer  11 finished! Reads:    1 | Writes:   20 times | average waiting time 0.56
Peer  12 finished! Reads:    0 | Writes:   21 times | average waiting time 0.58
Peer  13 finished! Reads:    0 | Writes:   21 times | average waiting time 0.61
Peer   4 finished! Reads:    0 | Writes:   25 times | average waiting time 0.69
Peer   1 finished! Reads:   26 | Writes:    1 times | average waiting time 0.72
Peer   2 finished! Reads:   27 | Writes:    0 times | average waiting time 0.75
Peer   3 finished! Reads:   26 | Writes:    1 times | average waiting time 0.78
Peer   7 finished! Reads:   28 | Writes:    2 times | average waiting time 0.78
Peer   8 finished! Reads:   29 | Writes:    1 times | average waiting time 0.81
Peer   9 finished! Reads:   30 | Writes:    0 times | average waiting time 0.83
Peer  10 finished! Reads:   28 | Writes:    2 times | average waiting time 0.86
Peer   6 finished! Reads:    0 | Writes:   31 times | average waiting time 0.86
-----------------------Coordinator results-----------------------
Coordinator finally ended
The total number of processes was 14, with each one running maximum 36 times
15 entries were allocated, to operate on
In total, they were 127 writes and 199 reads
-----------------------------------------------------------------
```

