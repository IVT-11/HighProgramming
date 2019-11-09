#include <stdio.h>
#include <math.h>

int main()
{
  double a,b,c,D,x1,x2;
  printf("Введите значение переменных a=");
  scanf("%lf",&a);
  printf("Введите значение переменных b=");
  scanf("%lf",&b);
  printf("Введите значение переменных c=");
  scanf("%lf",&c);
  if (a>0)
   printf("Ветви направлены вверх\n");
  else
   printf("Ветви направлены вниз\n");
  D=(pow(b,2))-(4*a*c);
  if (D>0){
  x1 = ((-b) - (sqrt(D))) / (2 * a); 
  x2 = ((-b) + (sqrt(D))) / (2 * a);
  printf("x1=%lf",x1);
  printf(" x2=%lf", x2);}
  else
  if (D = 0){
  x1 = (-b) / (2 * a);
  printf("x1=%lf",  x1);}
  else
  printf("Короней нет");
  return 0;
}