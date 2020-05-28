#include <stdio.h>
#include <math.h>

#define EPS 0.0001
#define PI 3.141592653589793238462643383279

double tangetMethod(double, double, double);
double fx(double, double, double);
double dfx(double, double, double);

int main(int argc, char const *argv[])
{
	printf("Ответ : %lf\n", tangetMethod(6, 4, 2));
	return 0;
}

double tangetMethod(double x, double c, double d)
{
	double x1;
	int count = 1000;
	x1 = x - fx(x, c, d) / dfx(x, c, d);
	while (fabs(x1 - x) > EPS && count)
	{
		count--;
		x = x1;
		x1 = x1 - fx(x1, c, d) / dfx(x1, c, d);
	}
	printf("Количество итераций: %d\n", 1000 - count);
	return x1;
}

double fx(double x, double c, double d) // вычисляемая функция
{
	return pow(x, 5) + c * pow(x, 2) - d;
   	// return sin(c * x * PI / 180) - d;
	// return pow(exp(1), c * x) + c * pow(x, 3) - d * x;
	// return pow(x, 3) - c * d;
	// return c * pow(x, c) - d * pow(x, d);
	// return pow(x, 3) + pow(x, c) - d * x;
}

double dfx(double x, double c, double d) // производная функции
{
	return 5 * pow(x, 4) + 2 * c * x - d;
	// return c * cos(c * x * PI / 180);
	// return c * pow(exp(1), c * x) + 3 * c * pow(x, 2) - d;
	// return 3 * x;
	// return c*c*pow(x,c-1)-d*d*pow(x, d);
	// return 3*pow(x, 2)+c*pow(x,c-1) - d;
}