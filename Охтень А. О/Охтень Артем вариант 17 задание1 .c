#include <stdio.h>
#include <math.h>

int main(){
double a,b,c,h;
printf("Введите а=");
scanf("%lf",&a);
printf("Введите b=");
scanf("%lf",&b);
c=(pow(2,a))*(pow(2,b));
c=sqrt(c);
h=(a*b)/c;
printf("h=%lf",h);
return 0;
}