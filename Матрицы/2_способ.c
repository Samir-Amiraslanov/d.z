#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
    int n;
    printf("Введите размер матрицы: ");
    scanf("%d", &n);
    double *a = (double *)malloc(n * n * sizeof(double));
    double *obr = (double *)malloc(n * n * sizeof(double));
    double *r = (double *)malloc(n * n * sizeof(double));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int maxij;
            if (i > j)
                maxij = i;
            else
                maxij = j;
            a[i * n + j] = n - maxij; 
        }
    }
    printf("\nМатрица:\n");
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            printf("[%lg] ", a[i * n + j]);
        }
        printf("\n");
    }
    
     for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            if (i == 0 && j == 0) {
                obr[i * n + j] = 1;
            } else if (i == j) {
                obr[i * n + j] = 2;
            } else if (abs(i - j) == 1) {
                obr[i * n + j] = -1;
            } else {
                obr[i * n + j] = 0;
            }
        }
    }
         
       printf("\nОбратная матрица:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("[%lg] ", obr[i * n + j]);
        }
        printf("\n");
    }
    
    
      for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            r[i * n + j] = 0;
            for (int k = 0; k < n; k++) {
                r[i * n + j] += a[i * n + k] * obr[k * n + j];
            }
        }
    }

    printf("\nРезультат перемножения (a * obr):\n");
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            printf("[%lg] ", r[i * n + j]);
        }
        printf("\n");
    }

    return 0;
}
