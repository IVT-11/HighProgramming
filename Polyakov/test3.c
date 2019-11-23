#include <stdio.h>
#include <math.h>
int main()
{int k,n;
 float ak,ak1=1,s,x;
s=0;
printf("введите числo x= "); scanf("%f",&x);
while (fabs(x)>=1)
{
printf("x должен принадлежать (0;1) !");
printf("введите числo x= "); scanf("%f",&x);
}
for (k=1;1;k++)
{
if(fabs(ak1)>0.0001)
ak1=(1/pow(100,k))*(sin(k*x)+cos(k*x))/powf(k*x,2);
else
{ n=k;
break;}
}
k=1;
for(k;k<=n;k++){
s+=((1.0/pow(100,k)*(float)sin(k*x)+(float)cos(k*x)/(powf(k*x,2))));
}
printf("результат равен=  %f\n",s);
return 0;
}

//1.66

//Итого 1.66+1.66+1=4.86

