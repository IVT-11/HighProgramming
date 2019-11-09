#include <stdio.h>
#include <stdlib.h>
int main()
{
	double x,a,b,fx;
	printf("Введите значения:\na = ");
	scanf("%lf", &a);
	printf("b = ");
	scanf("%lf", &b);
	if(abs(a-abs(b-x))==0)
	fx=1;
	else
	{
		{
			if(abs(b-x)<0)
			x=-x;
			{
				if(abs(a-abs(b-x))<0)
				x=-x;
			}
		}
	fx=(a*1.0)/(abs(a-abs(b-x)));
        }
	printf("Функция f(x) = %.2lf\n", fx);
	return 0;
}
