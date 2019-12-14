#include <stdio.h>
#include <math.h>

int main()
{
float result;

printf("x     y      f(x,y)\n");

for (float x = 1; x <= 2.1; x += 0.1)
{
for (float y = -2; y <= 2; y += 0.5)
{
result =(2*pow(x,3)+3*pow(y,3))/(3*pow(x,2)-2*pow(y,2));
printf("%.1f   %.1f   %.3f\n", x,y,result);
}
}
return 0;
}
