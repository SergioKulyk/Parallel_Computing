#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

int main(int argc, char *argv[]){
    double *A, *B, *C;
    long i, N;
    double time;

    if (argc < 2) {
      printf("Usage: vplusv N [+]\n");
      exit(1);
    }

    N = strtol(argv[1], (char **)NULL, 10);

    A=(double*)malloc(N*sizeof(double));
    B=(double*)malloc(N*sizeof(double));
    C=(double*)malloc(N*sizeof(double));

    for(i=0;i<N;i++){
        A[i]=1;
        B[i]=2;
    }

    time = omp_get_wtime();

    #pragma omp parallel default(none) shared(N, A, B, C) private(i)
    {
        #pragma omp sections nowait
        {
            #pragma omp section
            {
            for(i=0;i<N/2;i++)
                C[i]=A[i]+B[i];
            }
            #pragma omp section
            {
            for(i=N/2;i<N;i++)
                C[i]=A[i]+B[i];
            }
        }
    }

    time = omp_get_wtime() - time;
    printf("%20.15lf\n", time);

    free(A);
    free(B);
    free(C);

    return 0;
}
