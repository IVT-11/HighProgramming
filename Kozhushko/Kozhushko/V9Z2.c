#include <stdio.h>
#include <math.h>
int main()
{
int a,b,x,y;
printf("Введите координаты х и у для точки:\n");
scanf("%d %d",&x,&y);
printf("Введите значения а и b для формулы нахождения:\n");
scanf("%d %d",&a,&b);
if ((x*x)/(a*a) + (y*y)/(b*b) > 1) printf("Точка не принадлежит эллипсу"); 
if ((x*x)/(a*a) + (y*y)/(b*b) < 1) printf("Точка лежит внутри эллипса");
if ((x*x)/(a*a) + (y*y)/(b*b) == 1) printf("Точка лежит на границе эллипса");
return 5;
}
