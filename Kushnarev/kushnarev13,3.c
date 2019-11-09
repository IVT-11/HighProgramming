#include <stdio.h>
#include <math.h>
int main()
{
int k,n,x;
float p=1;
printf("введите числа: \n"); scanf("%d %d",&n,&x);
for (k=1;k<=n;k++)
p*=(pow(x,k)*log10(k*x))/(float)(k*k+k+1.0);
printf("результат равен= %f\n",p);
return 0;
}
