#include <stdio.h>

#include <math.h>

float function(float,float);

float function(float a, float b)

{

 float f;

 f=(sin(2*a)+cos(2*a)/sin(a))*(a*a+b*b);

 return f;

}

int main()

{

double x,y;
printf("x\t     y\t     f(x,y)\t\n\n",x,y,function(x,y));
for(x=-1.0;x<=1.0;x+=0.25)
{
    for(y=0.0;y<=2.0;y+=0.1)
printf("%.3lf     %.3lf     %.3lf\n",x,y,function(x,y));
}
return 0;
}
