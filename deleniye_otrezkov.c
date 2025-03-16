#include <stdio.h>
#include <math.h>

double eps = 1e-6;


double f2(double x) {
    return x*x*x + 4 * x*x - 10;
}

double f8(double x) {
    return x*x*x + 4 * x*x - 15;
}

double f10(double x) {
    return cos(x) - x * exp(x);
}
int deleniye_otrezkov(double *x_p, double a, double b, double (*f)(double), double epsilon) {
    int i = 0;
    while (fabs(b - a) >= epsilon) {
        *x_p = (a + b) / 2;
        if (f(*x_p) == 0.0)
            break;
        else if (f(a) * f(*x_p) < 0)
            b = *x_p;
        else
            a = *x_p;
        i++;
    }
    return i;
}

int main() {
    double x_p;
    int i;
    i = deleniye_otrezkov(&x_p, 0, 2, f2, eps);
    printf("Пример 2: x = %.10f, итераций = %d\n", x_p, i);

  
    i = deleniye_otrezkov(&x_p, 0, 2, f8, eps);
    printf("Пример 8 : x = %.10f, итераций = %d\n", x_p, i);

   
    i = deleniye_otrezkov(&x_p, 0, 2, f10, eps);
    printf("Пример 10 x = %.10f, итераций = %d\n", x_p, i);
    
    return 0;
}
