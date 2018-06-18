/****************************************************************************
* npoints = 10000                                                           *
* circle_count = 0                                                          *
*                                                                           *
* p = number of tasks                                                       *
* num = npoints/p                                                           *
*                                                                           *
* find out if I am MASTER or WORKER                                         *
*                                                                           *
* do i = 1,num                                                              *
*    generate 2 random numbers between 0 and 1                              *
*    xcoordinate = random1                                                  *
*    ycoordinate = random2                                                  *
*    if (xcoordinate, ycoordinate) inside circle then                       *
*       circle_count = circle_count + 1                                     *
* end do                                                                    *
*                                                                           *
* if I am MASTER then                                                       *
*    receive from WORKERS their circle_counts                               *
*    compute PI (use MASTER and WORKER calculations)                        *
* else if I am WORKER                                                       *
*    send to MASTER circle_count                                            *
* endif                                                                     *
****************************************************************************/
#include <stdio.h>                     // printf
#include <stdlib.h>                    // srand, rand
#include <time.h>                      // time
#include "mpi.h"                       // MPI_Init, MPI_Finalize

#define NPOINTS 10000                  // number of throws at dartboard
#define TAG     1505                   // tag


int main(int argc, char *argv[]) {
   double x,                           // xcoordinate
          y,                           // ycoordinate
          rnd,                         // random numbers
          pi;
   unsigned int i,
                ccount,                // circle_count
                wccount,               // worker's circle_count
                ccountrecv;            // circle_count received from worker
   int taskid,                         // task ID
       p;                              // number of tasks
       
   MPI_Init(&argc, &argv);
   MPI_Comm_size(MPI_COMM_WORLD, &p);
   MPI_Comm_rank(MPI_COMM_WORLD, &taskid);
   
   // The pseudo-random number generator is initialized 
   // using the argument passed as seed
   srand(time(0));
   wccount = 0;
   for (i = 1; i <= NPOINTS / p; i++) {
      rnd = 1.0 * rand() / RAND_MAX;
      x = (2.0 * rnd) - 1.0;
      rnd = 1.0 * rand() / RAND_MAX;
      y = (2.0 * rnd) - 1.0;
      if (x*x + y*y <= 1.0)  // if dart lands in circle, increment score
         wccount++;
   }    
   
   if (taskid != MASTER)
      rc = MPI_Send(&wccount, 1, MPI_UNSIGNED, MASTER, TAG, MPI_COMM_WORLD);
   else {
      ccount = wccount;      // MASTER's circle_counts
      // MASTER receive from WORKERS their circle_counts
      for (i = 1; i < p; i++) {
         MPI_Recv(&ccountrecv, 1, MPI_UNSIGNED, i, TAG, MPI_COMM_WORLD, &status);
         ccount = ccount + ccountrecv;
      }
      // calculate pi
      pi = 4.0 * ccount / NPOINTS;
      printf("Calculated value of PI: %f \n", pi);
      printf("Real       value of PI: 3.1415926535897 \n");
   }
   MPI_Finalize();   
   
   return 0;
}

