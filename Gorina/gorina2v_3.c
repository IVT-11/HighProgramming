#include <stdio.h>
#include <math.h>
int main()
{
	int n,k;
	float s;
	printf("Введите значение N = ");
	scanf("%d", &n);
	while(1)
	{
		if(n>0)
			break;
		else
		{
			printf("Не может быть определен для отрицательных чисел. Введите еще раз.\nN = ");
			scanf("%d", &n);
		}
	}
		for(k=0;k<=n;k++)
		{
		s+=pow(-2.0,k)/(pow(k,2)+1.0);
		}
		printf("Результат регенерации N-случайных чисел = %.2f\n", s);
	return 0;
	// Компилировать с -lm
}

//1.66

//Итого 5
