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
Operating with 36 processes of maximum 21 loops on 476 entries
Peer  25 finished! Reads:   1 | Writes:   0 times | average waiting time 0.00 | Loops   1
Peer  19 finished! Reads:   2 | Writes:   0 times | average waiting time 0.50 | Loops   2
Peer   7 finished! Reads:   2 | Writes:   0 times | average waiting time 2.50 | Loops   2
Peer  21 finished! Reads:   3 | Writes:   0 times | average waiting time 2.00 | Loops   3
Peer   9 finished! Reads:   4 | Writes:   0 times | average waiting time 1.75 | Loops   4
Peer  34 finished! Reads:   4 | Writes:   0 times | average waiting time 2.00 | Loops   4
Peer   3 finished! Reads:   6 | Writes:   0 times | average waiting time 2.00 | Loops   6
Peer  15 finished! Reads:   4 | Writes:   0 times | average waiting time 3.25 | Loops   4
Peer  30 finished! Reads:   5 | Writes:   0 times | average waiting time 2.60 | Loops   5
Peer   0 finished! Reads:   4 | Writes:   0 times | average waiting time 3.75 | Loops   4
Peer  10 finished! Reads:   5 | Writes:   0 times | average waiting time 3.20 | Loops   5
Peer  14 finished! Reads:   7 | Writes:   0 times | average waiting time 2.43 | Loops   7
Peer  22 finished! Reads:   5 | Writes:   0 times | average waiting time 3.40 | Loops   5
Peer  32 finished! Reads:   7 | Writes:   0 times | average waiting time 2.86 | Loops   7
Peer  11 finished! Reads:  12 | Writes:   0 times | average waiting time 1.83 | Loops  12
Peer   5 finished! Reads:   9 | Writes:   1 times | average waiting time 2.40 | Loops  10
Peer  31 finished! Reads:   8 | Writes:   0 times | average waiting time 3.25 | Loops   8
Peer   4 finished! Reads:  13 | Writes:   0 times | average waiting time 2.08 | Loops  13
Peer  27 finished! Reads:  12 | Writes:   0 times | average waiting time 2.33 | Loops  12
Peer   6 finished! Reads:  13 | Writes:   0 times | average waiting time 2.23 | Loops  13
Peer  20 finished! Reads:  10 | Writes:   0 times | average waiting time 2.90 | Loops  10
Peer   1 finished! Reads:  13 | Writes:   0 times | average waiting time 2.38 | Loops  13
Peer  26 finished! Reads:   7 | Writes:   0 times | average waiting time 4.57 | Loops   7
Peer  18 finished! Reads:  10 | Writes:   0 times | average waiting time 3.30 | Loops  10
Peer  28 finished! Reads:  12 | Writes:   0 times | average waiting time 2.92 | Loops  12
Peer  35 finished! Reads:  18 | Writes:   1 times | average waiting time 1.95 | Loops  19
Peer  12 finished! Reads:  16 | Writes:   0 times | average waiting time 2.50 | Loops  16
Peer  29 finished! Reads:  14 | Writes:   0 times | average waiting time 2.86 | Loops  14
Peer  13 finished! Reads:  17 | Writes:   0 times | average waiting time 2.47 | Loops  17
Peer  16 finished! Reads:  11 | Writes:   0 times | average waiting time 3.91 | Loops  11
Peer  24 finished! Reads:   9 | Writes:   1 times | average waiting time 4.60 | Loops  10
Peer   2 finished! Reads:  18 | Writes:   1 times | average waiting time 2.47 | Loops  19
Peer  33 finished! Reads:  19 | Writes:   1 times | average waiting time 2.35 | Loops  20
Peer  23 finished! Reads:  18 | Writes:   0 times | average waiting time 3.06 | Loops  18
Peer  17 finished! Reads:  18 | Writes:   0 times | average waiting time 3.17 | Loops  18
Peer   8 finished! Reads:  21 | Writes:   0 times | average waiting time 3.05 | Loops  21
-----------------------Coordinator results-----------------------
Coordinator finally ended
The total number of processes was 36, with each one running maximum 21 times
476 entries were allocated, to operate on
In total, they were 5 writes and 357 reads
-----------------------------------------------------------------
```

