// Vector Adition MPI
#include <stdio.h>
#include <stdlib.h>          // exit()
#include "mpi.h"

#define  ARRAYSIZE	16000000
#define  MASTER		0

int main(int argc, char *argv[]) {
   double a[ARRAYSIZE], b[ARRAYSIZE], c[ARRAYSIZE];
   int    numtasks, taskid;
   int    source, destination, tag=24, rc;
   MPI_Status status;
   long   myoffset, chunksize;
   long   i;

   // Initialize the array
   for (i=0; i < ARRAYSIZE; i++) {
       a[i] = i;
       b[i] = 1.0;
   }

   MPI_Init(&argc, &argv);
   MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
   if (ARRAYSIZE % numtasks != 0) {
      printf("Quitting. Number of MPI tasks must be divisible by numtasks\n");
      MPI_Abort(MPI_COMM_WORLD, rc);
      exit(0);
   }
   MPI_Comm_rank(MPI_COMM_WORLD, &taskid);

   chunksize = ARRAYSIZE / numtasks;
   myoffset = taskid * chunksize;
   for (i=myoffset; i < myoffset+chunksize; i++)
      c[i] = a[i] + b[i];

   if (taskid != MASTER)     // Workers tasks only
      // Send my results back to the master task
      MPI_Send(&c[myoffset], chunksize, MPI_DOUBLE, MASTER, tag, MPI_COMM_WORLD);
   else {                    // Master task
      // Wait to receive results from each task
      for (source=1; source < numtasks; source++)
         MPI_Recv(&c[source*chunksize], chunksize, MPI_DOUBLE, source, tag, MPI_COMM_WORLD, &status);
      for (i=0; i < ARRAYSIZE; i++)
         printf("c[%d] = %lf\n", i, c[i]);
   }

   MPI_Finalize();
   return 0;
}
