#include <stdio.h>
#include <math.h>
double f1(double x){
 return 1.0;
}
double f2(double x){
 return x;
}
double f3(double x){
 return x*x;
}
double f4(double x){
 return x*x*x;
}
double f5(double x){
 return x*x*x*x;
}

double nf1(double x){
 return x;
}
double nf2(double x){
 return x*x/2;
}
double nf3(double x){
 return x*x*x/3;
}
double nf4(double x){
 return x*x*x*x/4;
}
double nf5(double x){
 return x*x*x*x*x/5;}
double Newton_Cotes(double a, double b, double (*f)(double)) {
	    double h = (b - a) / 3.0;
    double x1 = a + h;
    double x2 = a + 2*h;

    return (b - a) / 8.0 * (f(a) + 3*f(x1) + 3*f(x2) + f(b));
}
int main(){
	double a, b; scanf("%lg", &a); scanf("%lg", &b);
	double nc1=Newton_Cotes(a,b,f1);
	double nc2=Newton_Cotes(a,b,f2);
	double nc3=Newton_Cotes(a,b,f3);
	double nc4=Newton_Cotes(a,b,f4);
	double nc5=Newton_Cotes(a,b,f5);
	
	
	double nl1=nf1(b)-nf1(a);
	double nl2=nf2(b)-nf2(a);
	double nl3=nf3(b)-nf3(a);
	double nl4=nf4(b)-nf4(a);
	double nl5=nf5(b)-nf5(a);
	
	double r1=fabs(nl1-nc1);
	double r2=fabs(nl2-nc2);
	double r3=fabs(nl3-nc3);
	double r4=fabs(nl4-nc4);
	double r5=fabs(nl5-nc5);
	
	printf("nc1=%lg nl1=%lg r1=%lg\n",nc1,nl1,r1);
	printf("nc2=%lg nl2=%lg r2=%lg\n",nc2,nl2,r2);
	printf("nc3=%lg nl3=%lg r3=%lg\n",nc3,nl3,r3);
	printf("nc4=%lg nl4=%lg r4=%lg\n",nc4,nl4,r4);
	printf("nc5=%lg nl5=%lg r5=%lg\n",nc5,nl5,r5);
}
	



















