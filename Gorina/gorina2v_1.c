#include <stdio.h>
#include <math.h>
int main()
{
	double a,b,c,p,s,h,alpha,beta,gamma;
	printf("Введите сторону треугольникa (см):\na = ");
	scanf("%lf", &a);
	printf(",и прилегающие к ней углы (С):\nalpha = ");
	scanf("%lf", &alpha);
	printf("beta = ");
	scanf("%lf", &beta);
	if(a>0 && alpha>0 && beta>0)
	{
		gamma=180-alpha-beta;
		if(gamma<0)
		{
			printf("Такого треугольника не существует!\n");
		}
		else
		{
			b=a*sin(alpha*M_PI/180)/sin(gamma*M_PI/180);
			c=b*sin(beta*M_PI/180)/sin(alpha*M_PI/180);
			p=(a+b+c)/2.0;
        		s=sqrt(p*(p-a)*(p-b)*(p-c));
        		h=2.0*s/a;
			printf("Сторона b = %.2lf (см)\nСторона с = %.2lf (см)\nУгол (gamma) между сторонами b и c = %.2lf (C)\nПериметр (P) треугольника = %.2lf (см)\nПлощадь (S) треyгольника = %.2lf (кв.см)\nВысота (h) треугольника = %.2lf (см)\n", b,c,gamma,p,s,h);
		}
	}
	else
	printf("Такого треугольника не существует!\n");
	return 0;
	// Компилировать с -lm
}
