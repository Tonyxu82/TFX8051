clang-3.4 -I/home/tonyxu/Project/klee/include/klee -emit-llvm -g -c goto.c

klee goto.bc

ktest-tool --write-ints klee-last/test000532.ktest 

