#include <stdio.h>
#include <math.h>
float func(float,float);
float func(float a, float b)
{
return (a*sin(b)+b*cos(a))/(pow(a,3)-pow(b,3));
}
int main()
{
double pi=3.14159265;
float x=-pi,y=-2*pi, c;

printf("x\t y\t f(x,y)\n\n");
while(x<=pi)
{
while(y<=2*pi)
{
if((pow(x,3)-pow(y,3))==0)
printf("%.3f, %.3f, происходит деление на 0\n", x, y);
else
{
printf("%.3f, %.3f, %.3f\n",x, y, func(x,y));
y+=(pi/4);
}
}
printf("%.3f, %.3f, %.3f\n",x, y, func(x,y));
x+=(pi/4);
}
return 0;
}
 // Компилировать с -lm.Получаются странные значения,но подругомы мы ще не можем работать с PI,поскольку мы можем вводить аргумент в функции только в радианах
 //А пи не целое число в радианах.
