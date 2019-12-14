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
float x=-1,y=0, f;
while(x<=1)
{
while(y<=2)
{
 printf("%.3f\t",function(x,y));
 y+=0.1;
}
printf("\n");
y=0;
x+=0.25;
} 
return 0;
}
