#include <stdio.h>
#include <math.h>

int nf; // число вызовов функции

int sign(double x) {
    if (x > 0) return 1;
    else if (x < 0) return -1;
    return 0;
}

double f1(double x) {
    nf++;
    return (x - 1)*(x - 1)*(x - 1)*(x - 1)*(x - 1)*(x - 1) - 1;
}

double f2(double x) {
    nf++;
    return cos(x) - x;
}

double f3(double x) {
    nf++;
    return (x-2)*(x-2);
}

int root_half(double *x, double a, double b,
              double (*f)(double), double epsilon) {
    double fa = f(a), fb = f(b), fc, c;
    int sfa = sign(fa), sfb = sign(fb), sfc;
    int k = 0;

    
    if (fabs(fa) < epsilon) {
        *x = a;
        return 1;
    }
    if (fabs(fb) < epsilon) {
        *x = b;
        return 1;
    }

   
    if (sfa * sfb > 0) {
        return 0;
    }

    while (1) {
        k++;
        c = (a + b) / 2;
        fc = f(c);
        sfc = sign(fc);

       
        if (fabs(fc) < epsilon) {
            *x = c;
            return k;
        }

        
        if (fabs(b - a) < epsilon || fabs(b - a) < epsilon * (a+b)/2) {
            *x = c;
            return k;
        }

        
        if (sfa * sfc < 0) {
            b = c;
            fb = fc;
            sfb = sfc;
        } else {
            a = c;
            fa = fc;
            sfa = sfc;
        }
    }
}

int main() {
    double x;
    int res;

    nf = 0;
    printf("Решение уравнения (x - 1)^6 - 1 = 0\n");
    res = root_half(&x, 1, 3, f1, 1.e-12);
    if (res) {
        printf("x = %lg\nЧисло итераций: %d\nЧисло вызовов функции: %d\n", x, res, nf);
        printf("Абсолютная погрешность: %lg\nОтносительная погрешность: %lg\n\n", fabs(x - 2.0), fabs((x - 2.0) / 2.0));
    } else {
        printf("Корень не найден\n");
    }

    nf = 0;
    printf("Решение уравнения cos(x) - x = 0\n");
    res = root_half(&x, 0, 2, f2, 1.e-12);
    if (res) {
        printf("x = %lg\nЧисло итераций: %d\nЧисло вызовов функции: %d\n", x, res, nf);
        printf("Абсолютная погрешность: %lg\nОтносительная погрешность: %lg\n\n", fabs(x - 0.739085133), fabs((x - 0.739085133) / 0.739085133));
    } else {
        printf("Корень не найден\n");
    }

    nf = 0;
    printf("Решение уравнения (x-2)^2 = 0\n");
    res = root_half(&x, 2, 4, f3, 1.e-12);
    if (res) {
        printf("x = %lg\nЧисло итераций: %d\nЧисло вызовов функции: %d\n", x, res, nf);
        printf("Абсолютная погрешность: %lg\nОтносительная погрешность: %lg\n\n", fabs(x - 2.0), fabs((x - 2.0) / 2.0));
    } else {
        printf("Корень не найден\n");
    }

    return 0;
}
