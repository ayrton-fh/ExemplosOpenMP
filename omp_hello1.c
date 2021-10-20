/* Arquivo:  
 *    omp_hello1.c
 *
 * Propósito:
 *    Demonstrar o uso básico de OpenMP em contraste ao exemplo pth_hello2.c
 *    em ExemplosPthreads 
 *
 * Compile:  gcc -g -Wall -fopenmp -o omp_hello1 omp_hello1.c
 * Usage:    ./omp_hello1
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void Hello(void) {
   int my_rank = omp_get_thread_num(); 
   int thread_count = omp_get_num_threads(); 
   printf("Hello from thread %d of %d\n", my_rank, thread_count);
}

int main(int argc, char* argv[]) {
   int thread_count = 40;
   
   # pragma omp parallel num_threads(thread_count) 
   Hello(); 
   
   return 0; 
}
