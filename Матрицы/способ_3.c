#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    double **a;

    printf("Введите размер квадратной матрицы: ");
    scanf("%d", &n);


    a = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        a[i] = (double *)malloc(n * sizeof(double));
    }

    
    printf("\nМатрица теста 1:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
         int maxij;
         if(i>j) maxij=i;
         else maxij=j;
         a[i][j]=n-maxij;
            printf("%lg ", a[i][j]);
        }
        printf("\n");
    }

  
    printf("\nОбратная матрица:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                a[i][j] = 1;
            } else if (i == j) {
                a[i][j] = 2;
            } else if (abs(i - j) == 1) {
                a[i][j] = -1;
            } else {
                a[i][j] = 0;
            }
            printf("%lg ", a[i][j]);
        }
        printf("\n");
    }


    return 0;
}
