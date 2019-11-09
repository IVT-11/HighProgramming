#include <stdio.h>
#include <math.h>
int main()
{
	int n,k;
	float s;
	printf("Введите значение N = ");
	scanf("%d", &n);
	if(n>0)
	{
		for(k=0;k<=n;k++)
		{
		s+=pow(-2.0,k)/(pow(k,2)+1.0);
		}
		printf("Результат регенерации N-случайных чисел = %.2f\n", s);
	}
	else
	printf("Не может быть определен для отрицательных чисел\n");
	return 0;
	// Компилировать с -lm
}
