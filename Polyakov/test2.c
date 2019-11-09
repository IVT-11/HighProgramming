#include <stdio.h>
#include <math.h>
int main ()
{
int a,b,c,P;
float s,p;
printf("Введите a=");
scanf("%d",&a);
printf("Введите b=");
scanf("%d",&b);
printf("Введите с=");
scanf("%d",&c);
if (a+b>c||a+c>b||b+c>a)
{
printf("Треугольник существует\n");
P=a+b+c;
printf("Периметр равен= %d\n",P);
p=(a+b+c)/2;
s=sqrt(p*(p-a)*(p-b)*(p-c));
printf("Площадь равна=%f\n",s);
}
else 
printf("Треугольник не существует\n");
return 0;
} 
