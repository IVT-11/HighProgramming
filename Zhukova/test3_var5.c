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
while(x<=2)
{
while(y<=2)
{
 printf("%f\t",func(x,y));
 y+=0.1;
}
printf("\n");
y=-0.5;
x+=0.25;
} 
return 0;
}

