#include <stdio.h>
#include <math.h>

int main()
{
double result;

printf("x\ty\tf(x,y)\n");

for (double x = 0; x <= 2; x += 0.25)
{
for (double y = 0; y <= 1; y += 0.1)
{
result = exp(x) / (pow(x, 2) + pow(y, 2) - 1.0);
if ((pow(x,2) + pow(y,2) - 1.0) == 0.0)
{
printf("%.2f\t%.1f\tdivision by 0\n", x, y);
}
else
{
printf("%.2f\t%.1f\t%.3f\n", x, y, result);
}
}
}
}
