#include <stdio.h>
#include <math.h>
float func(float,float);
float func(float a,float b)
{
float c;
c=(a*log(a)+b*log(b))/(pow(a,3)-pow(b,3));
return c;
}
int main()
{
float c;
printf("x\t y\t f(x,y)\t\n");
for(float x=1.0;x<=2;x+=0.1)
{
for(float y=-2.0;y<=2;y+=0.5) 
{
printf("%.3f  %.3f   %.3f\n",x,y,func(x,y));
}
}
return 0;
}  
