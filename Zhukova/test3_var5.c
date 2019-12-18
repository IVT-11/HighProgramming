#include <stdio.h>
#include <math.h>
float func(float,float);
float func(float a, float b)
{
 float c;
 c=(expf(a)+expf(-a))/(expf(b)-expf(-b))*asin((a+b)/2);
 return c;
}
int main()
{
float x=0,y=-0.5, c;
printf("x\t y\t f(x,y)\n\n");
while(x<=2)
{
while(y<=0.5)
{
 if((expf(x)+expf(-x))!=0&&(expf(y)-expf(-y))!=0&&(x+y)/2<=1)
 printf("%.3f, %.3f, %.3f\n",x, y, func(x,y));
 else if((expf(x)+expf(-x))==0||(expf(y)-expf(-y))==0||(x+y)/2>1)
 printf("%.3f, %.3f, происходит деление или умножение на 0\n", x, y);
 y+=0.1;
}
y=-0.5;
x+=0.25;
} 
return 0;
}
