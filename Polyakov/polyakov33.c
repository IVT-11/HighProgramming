#include <stdio.h>
#include <math.h>
int main()
{
float a;
printf("x,y,f(x,y)");
for(float x=1.0;x<=2.0;x+=0.1)
{
for(float y=-2.0;y<=2.0;y+=0.5) 
{
a=(x*log(x)+y*log(y))/(pow(x,3)-pow(y,3));
printf("%.3f  %.3f   %.3f\n",x,y,a);
}
}
return 0;
}  
