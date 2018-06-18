// gcc -fopenmp hello_world.c -o  hello_world

#include <stdio.h>
#include "omp.h"

int main(void) {
    #pragma omp parallel
    {
        printf("Hello, world!!!\n");
    }
}