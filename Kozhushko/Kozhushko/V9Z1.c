#include <stdio.h>
#include <math.h>
int main()
{
int a,b,p,c; float S;
printf("Введите две стороны и половину периметра:");
scanf("%d ",&a); scanf("%d ",&b); scanf("%d",&p);
c=2*p-a-b;
S=sqrt(p*(p-a)*(p-b)*(p-c));
printf("Третья сторона равна %d\n",c);
printf("Площадь треугольника равна %f\n",S);
printf("Периметр треугольника равен %d\n",p*2);
return 5;
}

//А углы?

//1
