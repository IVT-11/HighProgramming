#include <stdio.h>	
#include <math.h>	
#include <stdlib.h>

int main()
{
float P=1.0,a=0.0;
double x;
int k=1, z=1;

printf("Введите значение х=\n");scanf("%lf",&x);
a=(sin(k*x))/z;
if(fabs(a)<=0.01)
{
while(fabs(a)<=0.01)
 {
  z*=2*k-1;
  a=(sin(k*x))/z;
  P*=a;
  k++;
 }
}
else printf("Введено неверное значение х\n");
 
if(k>=1)
{
printf("N=%d\n",k-1);
 }
else
printf("Решений нет\n");

return 0;
}
