#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
double x,y,a,b,c,f,k,r,d,x1,x2,y1,y2;
printf("Введите значения:\na = ");
scanf("%lf", &a);
printf("b = ");
scanf("%lf", &b);
k=-a/b;
y=k*x+b;
a*pow(x,2)+b*x+c=0;
a=1+pow(k,2);
b=-2*x+2*k*b-2*k*y;
c=pow(b,2)+pow(x,2)-2*b*y+pow(y,2)-pow(r,2);
// -k*x+y-b=0;
// k=tg(alpha);
// tg(alpha)=
// r=sqrt(pow(x-a,2)+pow(y-b,2));
pow(x-a,2)+pow(y-b,2)=0;
c=pow(x-a,2);
f=pow(y-b,2);
c+f=0;
d=pow(b,2)-4*a*c;
if(d<0)
printf("Уравнение не имеет решений\n");
if(d==0)
x=-b/(2.0*a);
else
x1=(-b+sqrt(d))/(2.0*a);
x2=(-b-sqrt(d))/(2.0*a);
y1=k*x1+b;
y2=k*x2+b;
(a*x1+b*y1+c)/sqrt(a*a+b*b)

if (x1==x2)
printf("Прямая и окружность имеют точку касания:(%.2lf,%.2lf)",x1,y1);
else
printf("Прямая и окружность пересекаются в точках: (%.2lf,%.2lf),(%.2lf,%.2lf)",x1,y1,x2,y2);
return 0;
}

/*

y1=sqrt(pow(r, 2)-pow(d,2);
y2=-sqrt(pow(r, 2)-pow(d,2);
if(r>d)
printf("Oкружность и прямая пересекаются в двух точках\n");
if(r==d)
printf("Прямая касается окружности\n");
else
printf("Прямая и окружность не пересекаются\n");
// я не знаю как решить задачу,но алгоритм кажется такой(сложный вариант попался).
