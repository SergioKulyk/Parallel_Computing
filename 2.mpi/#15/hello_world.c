// mpic++ -o hello_world hello_world.c
// mpiexec -n 5 ./hello_world

#include <stdio.h>

#include "/usr/include/mpich/mpi.h"

int main(int argc, char **argv) {
    // Ініціалізуємо mpi
    MPI_Init(&argc, &argv);

    printf("Hello, world!!!\n");

    // Завершуємо роботу з mpi
    MPI_Finalize();

    return 0;
}