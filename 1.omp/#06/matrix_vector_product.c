#include <stdio.h>
#include <stdlib.h>                    // malloc(), free(), strtol(), exit()
#include <omp.h>

double **dmatrix(int, int);
void free_dmatrix(double **);

int main(int argc, char *argv[]) {
   double **A, **B, **C;
   long i, j, N, k, M, R;
   double t_start, t_end;

   if (argc < 4) {
      printf("Usage: mxm N M R [+]\n");
      exit(1);
   }

   N = strtol(argv[1], (char **)NULL, 10);
   M = strtol(argv[2], (char **)NULL, 10);
   R = strtol(argv[3], (char **)NULL, 10);

   A = dmatrix(N, M);
   B = dmatrix(M, R);
   C = dmatrix(N, R);

   if ( !A || !B || !C ) {
       printf("Not enough memory!\n");
       exit(2);
   }

   for (i=0; i < N; i++)
      for (j=0; j < M; j++)
         A[i][j] = (double)i;

    for (i=0; i < M; i++)
      for (j=0; j < R; j++)
         B[i][j] = (double)i;

   t_start = omp_get_wtime();
   #pragma omp parallel for schedule(dynamic, 5) \
               default(none) shared(A, B, C, N, M, R) private(i, j, k)
   for(i = 0; i < N; i++){
        for(j = 0; j < R; j++){
            C[i][j]=0;
            for(k = 0; k < M; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
   t_end = omp_get_wtime();
   printf("%20.15lf\n", t_end - t_start);

   free_dmatrix(A);
   free_dmatrix(B);
   free_dmatrix(C);

   return 0;
}

// allocates a double matrix with range [0..m-1][0..n-1]
double **dmatrix(int m, int n) {
   double **a;
   int i, j;

   a    = (double **) malloc(m   * sizeof(double *));
   a[0] = (double  *) malloc(m*n * sizeof(double  ));
   for (i=1; i < m; i++)
      a[i] = a[i-1] + n;

   return a;
}

// frees a matrix allocated with dmatrix
void free_dmatrix(double **a) {
   free(a[0]);
   free(a);
}
