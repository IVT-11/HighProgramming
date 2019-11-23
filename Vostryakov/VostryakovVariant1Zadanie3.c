#include<stdio.h>
#include<math.h>
int main()
{
float a,b,c,k,S=0,n,x;
printf("n= ");
scanf("%f",&n);
printf("\nx= ");
scanf("%f",&x);
while(1)
{
if (n>0)
break;
else
{
printf("Не корректные значения введите другие значения");
printf("\nn= ");
scanf("%f",&n);
printf("\nx= ");
scanf("%f",&x);
}
}
for(k=1;k<n;k++)
{
a=pow(-1,k-1);
b=(k*k+k+1)/pow(x,k);
c=a*b;
S+=c;
}
printf("%f\n",S);
return 0;
}
//1.66
