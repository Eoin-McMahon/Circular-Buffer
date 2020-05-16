## A Circular Buffer implemented in C

The queue functionality is implemented in circularBuffer.h and the main
interaction lies in queueExample.c

Run an example of the circular buffer with exampleQueue.c
  > compile and run ./a.out

For the Testing Suite I used this github repositry: https://github.com/danfis/cu

The testing suite is nested in the test directory. Unit tests have been written
for the queue and are also supplied in the test directory. 

For convenience, the compiled binary "test" is provided. Run using `./test`,
output files; tmp.T1.err and tmp.T1.out are generated at the root level
directory when the tests are run.

To build the tests:
  * cd in to test directory
  * make clean to purge any previously compiled test files
  * make to compile the test file
  * run ./test to run the tests


