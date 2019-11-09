#include<stdio.h>
#include<math.h>
int main()
{
float k=0.0,x,N,S=0.0,a=0.0;
printf("x=");
scanf("%f",&x);
for(k=0.0;abs(x)<1,abs(a)<=0.001;k++)
{
a=pow(-x,k)/(k*k+2);
N=a;
S+=pow(-x,k)/(k*k+2);
}
printf("%f",S);
return 0;
}

