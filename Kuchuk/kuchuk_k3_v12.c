#include <stdio.h>
#include <math.h>

double calcFunction(int x, int y);

int main()
{
	int x = 0;

	for (int y = -180; y <= 180; y += 18)
	{
		if (x < 360)
		{
			printf( "При x = %d, y = %d, то f(x, y) = %.3f\n", x, y, calcFunction(x, y) );
			x += 36;
		}
		else
		{
			printf( "При x = %d, y = %d, то f(x, y) = %.3f\n", x, y, calcFunction(x, y) );
		}
	}
	
	
	return 0;
}

double calcFunction(int x, int y)
{
	double val;
	return val = tan(x) / ( sin(x) + cos(y) );
}