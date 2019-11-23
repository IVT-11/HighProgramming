#include <stdio.h>
#include <math.h>

int main()
{
int x,N,i;
printf("x= ");
scanf("%d",&x);
printf("N= ");
scanf("%d",&N);
double S=0;
for (i=0; i<N; ++i)
{
S+=pow(-2,i)*(sin(i*x)/(i*i*i+1));//Знаменатель здесь другой, условие i<=N должно быть.
}
printf("S=%lf\n",S);
return 0;
}

//1 балл

//Итого: 0.5+1.66+1=3.16

