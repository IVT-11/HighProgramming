#include <stdio.h>

    int main()
    {
    int k, n, factorial = 1;
    float p = 1;

    printf("Enter n: "); scanf("%d", &n);

    for (k = 1;k <= n;k++)
    {
    factorial *= k;
    p *= ((-1.0) * (k * k + k + 1)) / factorial;
    }
    printf("Solution: %f\n", p);

    return 0;
    }
