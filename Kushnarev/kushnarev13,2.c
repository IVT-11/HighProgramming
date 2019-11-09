#include <stdio.h>
#include <math.h>
int main()
{
int a,b,c,d,A;
printf("Введите отрезкок [a,b]\n"); scanf("%d %d",&a,&b);
printf("Введите отрезкок [c,d]\n"); scanf("%d %d",&c,&d);
printf("Введите А[x]\n"); scanf("%d",&A);
if (A>=a && A<=b)
printf("точка принадлежит [a,b]\n");
else 
printf("точка не принадлежит [a,b]\n");
if (A>=c && A<=d)
printf("точка принадлежит [c,d]\n");
else 
printf("точка не принадлежит [c,d]\n");
return 0;
}
