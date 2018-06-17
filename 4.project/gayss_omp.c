
#include <stdio.h>
#include <stdlib.h>

double **dMatrix(int m, int n) {
    double **a;
    a = (double **) malloc(m * sizeof(double *));
    a[0] = (double *) malloc(m * n * sizeof(double));

    for (int i = 1; i < m; i++) {
        a[i] = a[i - 1] + n;
    }
    return a;
}

// Equation system output.
void out(double** A, double* y, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%lf * x%d", A[i][j], j);
            if (j < n - 1)
                printf(" + ");
        }
        printf(" = %f\n", y[i]);
    }
}

double* gauss(double** A, double *Y, int n)
{
    double* x, max;
    int k, index;

    // Точність
    const double eps = 0.00001;
    x = (double *) malloc(n * sizeof(double));
    k = 0;

    while (k < n)
    {
        // Пошук рядка з максимальним A[i][k]
        max = abs((int) A[k][k]);
        index = k;
        for (int i = k + 1; i < n; i++)
        {
            if (abs((int) A[i][k]) > max)
            {
                max = abs((int) A[i][k]);
                index = i;
            }
        }

        // Перестановка рядків
        if (max < eps) {
            // Немає нульвих діагональних елементів.
            printf("Решение получить невозможно из-за нулевого столбца ");
            printf("%d матрицы A\n", index);
            return 0;
        }
        for (int j = 0; j < n; j++)
        {
            double temp = A[k][j];
            A[k][j] = A[index][j];
            A[index][j] = temp;
        }
        double temp = Y[k];
        Y[k] = Y[index];
        Y[index] = temp;
        // Нормалізація рівняння
        for (int i = k; i < n; i++)
        {
            double temp = A[i][k];

            if (abs(temp) < eps) {
                // Для нульового коефіцієнта пропустити.
                continue;
            }

            for (int j = 0; j < n; j++) {
                A[i][j] = A[i][j] / temp;
            }

            Y[i] = Y[i] / temp;

            if (i == k)  continue;

            for (int j = 0; j < n; j++) {
                A[i][j] = A[i][j] - A[k][j];
            }

            Y[i] = Y[i] - Y[k];
        }

        k++;
    }

    // Обробка підстановки
    for (k = n - 1; k >= 0; k--) {
        x[k] = Y[k];

        for (int i = 0; i < k; i++) {
            Y[i] = Y[i] - A[i][k] * x[k];
        }
    }

    return x;
}

int main(void) {

    double **A, *Y, *X;
    int n;

    printf("Ведіть кількість рівнянь: ");
    scanf("%d", &n);

    A = dMatrix(n, n);
    Y = (double *) malloc(n * sizeof(double));
    X = (double *) malloc(n * sizeof(double));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("a[%d][%d]= ", i, j);
            scanf("%lf", &A[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        printf("y[%d]=", i);
        scanf("%lf", &Y[i]);
    }

    out(A, Y, n);

    X = gauss(A, Y, n);
    for (int i = 0; i < n; i++)
        printf("x[%d]= %lf\n", i, X[i]);
    return 0;
}