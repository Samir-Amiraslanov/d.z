#include <stdio.h>
#include <math.h>

double f1(double x) {
    return sin(x);
}

double f2(double x) {
    return 1.0 / x;
}

double f3(double x) {
    return 10.0 / (1.0 + 25.0 * x * x);
}

double F1(double x) {
    return -cos(x);
}

double F2(double x) {
    return log(fabs(x));
}

double F3(double x) {
    return 2.0 * atan(5.0 * x);
}

double Newton_Cotes(double a, double b, double (*f)(double)) {
    double h = (b - a) / 3.0;
    double x1 = a + h;
    double x2 = a + 2*h;
    return (b - a) / 8.0 * (f(a) + 3*f(x1) + 3*f(x2) + f(b));
}

double sostav_kvadr(double a, double b, int n, double (*f)(double)) {
    double h = (b - a) / (n-1);
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        double x0 = a + i * h;
        double x1 = x0 + h;
        result += Newton_Cotes(x0, x1, f);
    }
    return result;
}

int main() {
    int n;
    double a, b;

    printf("������ ������⢮ ࠧ������ : ");
    scanf("%d", &n);

    printf("������ �࠭��� ��१�� a � b: ");
    scanf("%lf %lf", &a, &b);

    double r1 = sostav_kvadr(a, b, n, f1);
    double g1 = F1(b) - F1(a);
    double abs_pogr1 = fabs(g1 - r1);
    double otn_pogr1 = abs_pogr1 / fabs(g1);
    printf("\nf(x) = sin(x)\n  результут1=%lg\nрезультут2=%lg\nабс.погр = %lg\nотнос.погр = %lg\n",g1,r1, abs_pogr1, otn_pogr1);

    double r2 = sostav_kvadr(a, b, n, f2);
    double g2 = F2(b) - F2(a);
    double abs_pogr2 = fabs(g2 - r2);
    double otn_pogr2 = abs_pogr2 / fabs(g2);
    printf("\nf(x) = 1/x\n результут1=%lg\nрезультут2=%lg\nабс.погр = %lg\nотнос.погр = %lg\n",g2,r2, abs_pogr2, otn_pogr2);

    double r3 = sostav_kvadr(a, b, n, f3);
    double g3 = F3(b) - F3(a);
    double abs_pogr3 = fabs(g3 - r3);
    double otn_pogr3 = abs_pogr3 / fabs(g3);
    printf("\nf(x) = 10/(1+25x^2)\nа результут1=%lg\nрезультут2=%lg\nабс.погр = %lg\nотнос.погр = %lg\n",g3,r3, abs_pogr3, otn_pogr3);

    return 0;
}
