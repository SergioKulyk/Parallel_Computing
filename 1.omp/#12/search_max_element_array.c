//
// Created by sergio on 17.06.18.
//

int max(int A[], int i, int j)
{
    int idx;
    int max_val; /* = 0 not needed according to Jim Cownie comment */

#pragma omp parallel for reduction(max:max_val)
    for (idx = i; idx < j; idx++)
        max_val = max_val > A[idx] ? max_val : A[idx];

    return max_val;
}