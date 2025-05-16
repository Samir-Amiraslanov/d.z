#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    double **a;

    printf("Введите размер матрицы: ");
    scanf("%d", &n);

    a = (double **)malloc(n * sizeof(double *));
    for (int j = 0; j < n; j++) {
        a[j] = (double *)malloc(n * sizeof(double));
    }

    
    printf("\nМатрица:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int maxij;
            if (i > j) maxij = i;
            else maxij = j;
            a[j][i] = n - maxij; 
            printf("%lg ", a[j][i]);
        }
        printf("\n");
    }

    printf("\nОбратная матрица:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                a[j][i] = 1;
            } else if (i == j) {
                a[j][i] = 2;
            } else if (abs(i - j) == 1) {
                a[j][i] = -1;
            } else {
                a[j][i] = 0;
            }
            printf("%lg ", a[j][i]);
        }
        printf("\n");
    }

    return 0;
}
