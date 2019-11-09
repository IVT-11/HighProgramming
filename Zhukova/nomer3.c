#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
float P=1.0,a=0.0;
double x;
int k=1, z=1, n;

printf("Введите значение х=\n");scanf("%lf",&x);
while(fabs(a)<=0.01)
 {
  z*=2*k-1;
  a=(sin(k*x))/z;
  P*=a;
  k++;
 }
n=k-1;
if(k>=1)
{
printf("Геометрическая последовательность равна %f\n",P);
printf("N=%d\n",k);
 }
else
printf("Решений нет\n");

return 0;
}
