// Dot Product (scalar product) MPI
#include <stdio.h>
#include <stdlib.h>          // exit()
#include "mpi.h"

#define  ARRAYSIZE   16000000
#define  MAXTASKS    100
#define  MASTER      0

int main(int argc, char *argv[]) {
   double a[ARRAYSIZE], b[ARRAYSIZE], c, c_recv;
   int    numtasks, taskid;
   int    task, tag=24, rc;
   MPI_Status status;
   long   aver, extra, offset[MAXTASKS]; 
   long   i;

   // Initialize the arrays
   for (i=0; i < ARRAYSIZE; i++) {
       a[i] = i;
       b[i] = 1.0;
   }    
       
   MPI_Init(&argc, &argv);
   MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
   MPI_Comm_rank(MPI_COMM_WORLD, &taskid);

   aver  = ARRAYSIZE / numtasks;
   extra = ARRAYSIZE % numtasks;
   offset[0] = 0;
   for (task=1; task < numtasks; task++)
      offset[task] = offset[task-1] + (task <= extra) ? aver+1 : aver;

   c = 0.0;
   for (i=offset[taskid]; i < offset[taskid+1]; i++)     // must be corrected!
      c += a[i] * b[i];

   if (taskid != MASTER)     // Workers tasks only
      // Send my results back to the master task
      MPI_Send(&c, 1, MPI_DOUBLE, MASTER, tag, MPI_COMM_WORLD);
   else {                    // Master task
      // Wait to receive results from each task
      c_total = c;           // c from MASTER
	  for (task=1; task < numtasks; task++) {
         MPI_Recv(&c_recv, 1, MPI_DOUBLE, task, tag, MPI_COMM_WORLD, &status);
         c_total += c_recv;         
      }
      printf("c = %lf\n", c_total);
   }
   
   MPI_Reduce(&c, &c_total, 1, MPI_DOUBLE, MPI_SUM, MASTER, MPI_COMM_WORLD);
   if (taskid == MASTER)
      printf("c = %lf\n", c_total);
   
   MPI_Finalize();   
   return 0;
}
