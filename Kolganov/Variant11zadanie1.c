#include <stdio.h>
#include <math.h>

int main()
{
double a,b,h;
printf("a= ");
scanf("%lf",&a);
printf("b= ");
scanf("%lf",&b);
printf("h= ");
scanf("%lf",&h);
double c=sqrt(a*a+b*b);//Кто сказал, что треугольник прямоугольный?
double s=0.5*c*h;
double P=a+b+c;

printf ("c=%lf\n",c);
printf ("P=%lf\n",P);
printf ("s=%lf\n",s);
return 0;
}

//0.5
