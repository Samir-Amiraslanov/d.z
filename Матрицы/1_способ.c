#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
    int n;
    printf("Введите размер матрицы: ");
    scanf("%d", &n);
    double *a = (double *)malloc(n * n * sizeof(double));
    
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
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("[%lg] ", a[i * n + j]);
        }
        printf("\n");
    }
    
  for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                a[i * n + j] = 1;
            } else if (i == j) {
                a[i * n + j] = 2;
            } else if (abs(i - j) == 1) {
                a[i * n + j] = -1;
            } else {
                a[i * n + j] = 0;
            }
        }
    }
         
       printf("\nОбратная матрица:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("[%lg] ", a[i * n + j]);
        }
        printf("\n");
    }

    return 0;
}
