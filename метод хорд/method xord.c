#include <stdio.h>
#include <math.h>

int nf; // число вызовов функции

int sign(double x)
{
    if(x > 0) return 1;
    else if(x < 0) return -1;
    return 0;
}

double f1(double x)
{
    nf++;
    return (x - 1)*(x - 1)*(x - 1)*(x - 1)*(x - 1)*(x - 1) - 1;
}

double f2(double x)
{
    nf++;
    return cos(x) - x;
}

double f3(double x)
{
    nf++;
    return exp(x*x + 7*x) - 30;
}

int root_chords(double *x, double a, double b,
                double (*f)(double), double epsilon)
{
    double fa, fb, fc, c[2];
    int i = 0, ifa, ifb, ifc, k;
    c[0] = a; c[1] = b;
    fa = f(a); fb = f(b);

    // Проверка начальных приближений:
    if (fabs(fa) < epsilon) { *x = a; return 1; }
    if (fabs(fb) < epsilon) { *x = b; return 1; }
    ifa = sign(fa); ifb = sign(fb);
    if (ifa * ifb != -1) return 0;

    for (k = 1; fabs(c[1] - c[0]) > epsilon; k++)
    {
        // Вычисление новой точки по методу хорд
        i = !i;
        c[i] = (a * fb - b * fa) / (fb - fa);
        fc = f(c[i]);
        ifc = sign(fc);

        // Проверка достижения нужной точности:
        if (fabs(fc) < epsilon) { *x = c[i]; return k + 1; }

        // Уточнение отрезка [a,c] или [c,b]:
        if (ifc * ifa == 1) { a = c[i]; fa = fc; }
        else { b = c[i]; fb = fc; }
    }
    *x = c[i]; // результат метода хорд
    return k;  // количество итераций
}

int main()
{
    double x;
    int res;

    nf = 0;
    printf("Решение уравнения (x - 1)^6 - 1 = 0\n");
    res = root_chords(&x, 1, 3, f1, 1.e-12);
    if (res) {
        printf("x = %lg\nЧисло итераций: %d\nЧисло вызовов функции: %d\n", x, res - 1, nf);
        printf("Абсолютная погрешность: %lg\nОтносительная погрешность: %lg\n\n", fabs(x - 2.0), fabs((x - 2.0) / 2.0));
    } else {
        printf("Корень не найден\n");
    }

    nf = 0;
    printf("Решение уравнения cos(x) - x = 0\n");
    res = root_chords(&x, 0, 2, f2, 1.e-12);
    if (res) {
        printf("x = %lg\nЧисло итераций: %d\nЧисло вызовов функции: %d\n", x, res - 1, nf);
        printf("Абсолютная погрешность: %lg\nОтносительная погрешность: %lg\n\n", fabs(x - 0.739085133), fabs((x - 0.739085133) / 0.739085133));
    } else {
        printf("Корень не найден\n");
    }

    nf = 0;
    printf("Решение уравнения e^(x^2 + 7x) - 30 = 0\n");
    res = root_chords(&x, 2, 4, f3, 1.e-12);
    if (res) {
        printf("x = %lg\nЧисло итераций: %d\nЧисло вызовов функции: %d\n", x, res - 1, nf);
        printf("Абсолютная погрешность: %lg\nОтносительная погрешность: %lg\n\n", fabs(x - 3.0), fabs((x - 3.0) / 3.0));
    } else {
        printf("Корень не найден\n");
    }

    return 0;
}
