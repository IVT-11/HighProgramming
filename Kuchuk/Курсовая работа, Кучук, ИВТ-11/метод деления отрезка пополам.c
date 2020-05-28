#include <stdio.h>
#include <math.h>

#define EPS 0.0001
#define PI 3.141592653589793238462643383279

double bisectMethod(double, double);
double fx(double, double, double);

int main(int argc, char const *argv[])
{
	double left;
	double right;
	printf("Введите границы: ");
	scanf("%lf %lf", &left, &right);
	printf("Ответ : %f\n", bisectMethod(left, right));
	return 0;
}

double bisectMethod(double left, double right)
{
	double middle, s_left, s_midle;
	double fx_left = fx(left,1, 3);
	double fx_right = fx(right,1, 3);
	int count = 1000;

	if (fx_left * fx_right > 0) 
	{
		printf("Ведены неверные границы!");
		return 0;
	}
	if (!fx_left)
		return left;
	if (!fx_right)
		return right;
	
	while (right - left > EPS && count)
	{
		count--;
		middle = (left + right) / 2;
		s_left = copysign( 1, fx(left,1, 3) );
 		s_midle = copysign( 1, fx(middle,1, 3) );
		if ( s_left != s_midle )
			right = middle;
		else
			left = middle;
	};
	printf("Число итераций: %d\n", 1000 - count);
	return middle;
}

double fx(double x, double c, double d)
{
	// return sin(c * x * 180 / PI) - d;
	// return exp(c * x) - d;
	// return pow(x, 5) + c * pow(x, 2) - d;
	// return pow(x, 3) - c * d;
	// return c * pow(x, c) - d * pow(x, d);
	return pow(x, 3) + pow(x, c) - d * x - c;
}