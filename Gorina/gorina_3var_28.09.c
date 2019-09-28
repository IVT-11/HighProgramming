#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	system("clear");
	int p,r,q,L;
	float a,M,N;
	printf("Ввести с клавиатуры целые числа \n");
	printf("p = ");
	scanf("%d", &p);
	printf("r = ");
        scanf("%d", &r);
	printf("q = ");
        scanf("%d", &q);
	printf("Ввести с клавиатуры действительное число \n");
	printf("a = ");
	scanf("%f", &a);
	if (p==0 || r==0 || q==0)
		printf("M = pешений нет\n");
	else
		printf("M = %.2f\n", 0.8/(float)p + 1/(float)r + 0.5/(float)q);
	if (p==0 || r==0)
		printf("N = peшений нет\n");
	else
		printf("N = %.2f\n", (pow(10,2)) * ((p*q)/(float)r - q/(float)(p*r) + a));
	printf("L = %d\n", p*r + r*q + q*p);
	return 0;
}
