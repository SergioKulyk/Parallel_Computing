#include <stdio.h>
#include <omp.h>

int main(void) {
   omp_set_num_threads(4);

   #pragma omp parallel num_threads(6)
   printf("Hello, World!\n");

   return 0;
}

// c:\>SET OMP_NUM_THREADS=4