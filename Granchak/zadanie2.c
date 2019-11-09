#include <stdio.h>

int main()
{
int x, t, y;

printf("Enter x: "); scanf("%d", &x);

if (x >= 1)
{
t = x * x + x;
}
else
{
t = -5 * x + 3;
}

y = t * t - t - 1;
printf("Solution: %d\n", y);

return 0;
}
