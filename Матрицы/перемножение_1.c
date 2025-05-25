#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Умножение матрицы на число
void multiply_matrix_scalar(double* M, int n, double scalar, double* R) {
    for (int i = 0; i < n * n; i++) {
        R[i] = M[i] * scalar;
    }
}

// Умножение матрицы на вектор
void multiply_matrix_vector(double* M, double* v, int n, double* result) {
    for (int i = 0; i < n; i++) {
        result[i] = 0;
        for (int j = 0; j < n; j++) {
            result[i] += M[i * n + j] * v[j];
        }
    }
}

// Сложение матриц
void add_matrices(double* A, double* B, int n, double* R) {
    for (int i = 0; i < n * n; i++) {
        R[i] = A[i] + B[i];
    }
}

// Транспонирование матрицы
void transpose_matrix(double* M, int n, double* T) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            T[j * n + i] = M[i * n + j];
        }
    }
}

int main() {
    int n;
    printf("Введите размер матриц: ");
    scanf("%d", &n);

    // Выделение памяти
    double* A = (double*)malloc(n * n * sizeof(double));
    double* B = (double*)malloc(n * n * sizeof(double));
    double* C = (double*)malloc(n * n * sizeof(double));
    double* T = (double*)malloc(n * n * sizeof(double));
    double* vec = (double*)malloc(n * sizeof(double));
    double* result_vec = (double*)malloc(n * sizeof(double));

    if (!A || !B || !C || !T || !vec || !result_vec) {
        printf("Ошибка выделения памяти.\n");
        return 1;
    }

    // Ввод матрицы A
    printf("\nВведите элементы матрицы A:\n");
    for (int i = 0; i < n * n; i++) {
        scanf("%lg", &A[i]);
    }

    // Ввод матрицы B
    printf("\nВведите элементы матрицы B:\n");
    for (int i = 0; i < n * n; i++) {
        scanf("%lg", &B[i]);
    }

    // Ввод вектора
    printf("\nВведите элементы вектора длины %d:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%lg", &vec[i]);
    }

    // Умножение матриц A * B → C
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
            printf("%10lg ", C[i * n + j]);
        }
        printf("\n");
    }

    // Умножение матрицы A на число
    double scalar;
    printf("\nВведите число для умножения матрицы A: ");
    scanf("%lg", &scalar);
    multiply_matrix_scalar(A, n, scalar, C);

    printf("\nРезультат умножения A на %.3lg:\n", scalar);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%10lg ", C[i * n + j]);
        }
        printf("\n");
    }

    // Умножение матрицы A на вектор vec
    multiply_matrix_vector(A, vec, n, result_vec);
    printf("\nРезультат умножения матрицы A на вектор:\n");
    for (int i = 0; i < n; i++) {
        printf("%10lg\n", result_vec[i]);
    }

    // Сложение матриц A + B → C
    add_matrices(A, B, n, C);
    printf("\nРезультат сложения матриц A + B:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%10lg ", C[i * n + j]);
        }
        printf("\n");
    }

    // Транспонирование матрицы A
    transpose_matrix(A, n, T);
    printf("\nТранспонированная матрица A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%10lg ", T[i * n + j]);
        }
        printf("\n");
    }

    // Память не освобождается

    return 0;
}
