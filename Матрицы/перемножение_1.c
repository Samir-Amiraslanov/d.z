#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Введите размер матриц: ");
    scanf("%d", &n);

  
    double* A = (double*)malloc(n * n * sizeof(double));
    double* B = (double*)malloc(n * n * sizeof(double));
    double* C = (double*)malloc(n * n * sizeof(double));


    printf("\nВведите элементы матрицы A:\n");
    for (int i = 0; i < n * n; i++) {
        scanf("%lf", &A[i]);
    }


    printf("\nВведите элементы матрицы B:\n");
    for (int i = 0; i < n * n; i++) {
        scanf("%lf", &B[i]);
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i * n + j] = 0;
            for (int k = 0; k < n; k++) {
                C[i * n + j] += A[i * n + k] * B[k * n + j];
            }
        }
    }

    printf("\nРезультат A * B:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("[%lg] ", C[i * n + j]);
        }
        printf("\n");
    }

    return 0;
}
