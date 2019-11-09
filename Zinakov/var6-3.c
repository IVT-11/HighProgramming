#include <stdio.h>
#include <math.h>

int main()
{
  double sum,n;
  printf("Введите n=");
  scanf("%lf",&n);
  for (int i=0;i<=n;i++)
    sum+=pow(-1,i)*(pow(i,2.0)-i+1)/(pow(i,4)+i+10);
  printf("sum=%lf\n",sum);
  return 0;
}




