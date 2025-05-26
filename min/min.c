#include <stdio.h>
#include <math.h>

double func(double x)
{
    return x / (1.0 + x * x);
}

double min(double(*f)(double), double a, double b, double eps)
{
    double x1 = (3 * a + b) / 4.0;
    double x2 = (a + b) / 2.0;
    double x3 = (a + 3 * b) / 4.0;
    double y1 = f(x1);
    double y2 = f(x2);
    double y3 = f(x3);

    double ab = fabs(a - b);

    while (ab > eps && ab > eps * fabs((a + b) / 2.0))
    {
        if (y1 < y2 && y1 < y3)
        {
            b = x2;
            x2 = x1;
            x1 = (3 * a + b) / 4.0;
            x3 = (a + 3 * b) / 4.0;
            y2 = y1;
            y1 = f(x1);
            y3 = f(x3);
        }
        else if (y3 < y2 && y3 < y1)
        {
            a = x2;
            x2 = x3;
            x1 = (3 * a + b) / 4.0;
            x3 = (a + 3 * b) / 4.0;
            y2 = y3;
            y1 = f(x1);
            y3 = f(x3);
        }
        else
        {
            a = x1;
            b = x3;
            x1 = (3 * a + b) / 4.0;
            x3 = (a + 3 * b) / 4.0;
            y1 = f(x1);
            y3 = f(x3);
        }

        ab = fabs(a - b);
    }

    return (a + b) / 2.0;
}

int main()
{
    printf("%lf", func(min(func, -9, 1, 1e-16)));
}
