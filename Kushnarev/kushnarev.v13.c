#include <stdio.h>
#include <math.h>
double fxy(double, double);
double fxy(double x,double y)
{
return (pow(x,2)+y/3+7)/(x-y);
}
int main()
{
double x,y,h,h1;
printf("x         y         f(x,y)\n\n",x,y,fxy(x,y));
for(x=0.0,h=0.5;x<=5.0;x+=h)
{
for(y=-1.0,h1=1.0;y<=3.0;y+=h1)
printf("%7.3lf %7.3lf %7.3lf\n",x,y,fxy(x,y));
}
return 0;
}

