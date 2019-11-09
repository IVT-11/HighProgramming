#include <stdio.h>
#include <math.h>

int main()
{
  int k, k1,n;
  double x, ak=1, s=0;

  printf("Введите значение х: "); scanf("%lf",&x);

  /*проверяем принаждлежность х диапазону (0;1)*/
  while (fabs(x)>=1)
    {
      printf("Х принадлежит (0;1), введите другое значение Х: ");
      scanf("%lf",&x);
    }

  /*находим N из условия*/
  for (k1=0;1;k1++)
    {
      if (fabs(ak)>0.0001)
	{
	  ak=(1/pow(10,k1))*((x+2)/(powf(x,k1+1)));
	}
      else
	{
	  printf("%d\n",k1);
	  n=k1;
	  break;
	}
    }

  /*считаем сумму*/
  for (k=1;k<=n;k++)
    {
      s+=(1/pow(10,k))*((x+2)/(powf(x,k+1)));
    }
  printf("Сумма равна: %lf | количество итераций: %d\n",s,n);

  return 0;
}
