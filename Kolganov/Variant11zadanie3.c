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
S+=pow(-2,i)*(sin(i*x)/(i*i*i+1));
}
printf("S=%lf\n",S);
return 0;
}

