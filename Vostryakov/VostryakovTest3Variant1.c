#include <stdio.h>
#include <math.h>
double func(double,double);
double func(double x,double y)
{
return(asin(x+y))/(x+y);
}
int main()
{
double x,y;
for(x=0.0;x<=0.5;x+=0.1)
{
for(y=0.10;y<=0.76;y+=0.05)
printf("%7.3lf %7.3lf %7.3lf\n",x,y,func(x,y));
}
return 0;
}
