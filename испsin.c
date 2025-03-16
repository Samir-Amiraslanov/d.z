#include <stdio.h>
#include <math.h>
int sign(double x) {
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}
 int kvadr(double b, double c, double *x1, double *x2)
 {
 double d;
 d=b*b-4*c;
 if(d<0) return 0;
 
*x1=(-b+sign(b)*sqrt(d))/2.0;
*x2 = c / (*x1);

 return 1;
 }
 int main() {
double x1_tochnoe, x2_tochnoe,x1,x2,b,c,q;
while (1){
scanf("%lg", &x1_tochnoe);		
scanf("%lg", &x2_tochnoe);
if(x1_tochnoe>x2_tochnoe){
	q=x1_tochnoe;
	x1_tochnoe=x2_tochnoe;
	x2_tochnoe=q;
}
if( fabs(x1_tochnoe)<fabs(x2_tochnoe)){
	q=x1_tochnoe;
	x1_tochnoe=x2_tochnoe;
	x2_tochnoe=q;
}

 b=-( x1_tochnoe+ x2_tochnoe);
  c=x1_tochnoe*x2_tochnoe;
  
kvadr(b,c,&x1,&x2);
double a1=fabs(x1-x1_tochnoe);
double a2=fabs(x2-x2_tochnoe);
  
double o1=fabs(x1/x1_tochnoe-1);
double o2=fabs(x2/x2_tochnoe-1);
printf("x1_tochnoe=%lg\nx2_tochnoe=%lg\n", x1_tochnoe, x2_tochnoe);

printf("x1=%lg\nx2=%lg\n", x1, x2);

printf("абс.погр1=%lg\nабс.погр2=%lg\n", a1, a2);
printf("относ.погр1=%lg \n относ.погр2=%lg\n", o1, o2);}}
  


