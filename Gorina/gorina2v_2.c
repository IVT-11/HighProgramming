#include <stdio.h>
#include <math.h>
int main()
{
	double x,a,b,fx;
	printf("Введите значения:\na = ");
	scanf("%lf", &a);
	printf("b = ");
	scanf("%lf", &b);
	if(fabs(a-fabs(b-x))==0)
	fx=1;
	else
	fx=(a*1.0)/fabs(a-fabs(b-x));
        printf("Функция f(x) = %.2lf\n", fx);
	return 0;
}
