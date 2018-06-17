#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int *A, *B, *C;
    double time_s, time_f, answer;
    long int i,N;

    N = strtol(argv[1], (char **)NULL, 10);

    A=(int*)malloc(N*sizeof(int));
    B=(int*)malloc(N*sizeof(int));
    C=(int*)malloc(N*sizeof(int));

    for(i=0;i<N;i++){
        A[i]=1;
        B[i]=2;
    }

    time_s = omp_get_wtime();
    #pragma omp parallel for
    for(i=0;i<N;i++){
        C[i]=A[i]+B[i];
    }

    time_f = omp_get_wtime();
    answer = time_f- time_s;
    printf("%20.15lf\n", answer);

    free(A);
    free(B);
    free(C);

    return 0;
}


