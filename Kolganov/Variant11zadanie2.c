#include <stdio.h>
#include <math.h>

int main()
{
printf("x=");
double x;
scanf("%lf",&x);
if(4*x<6)
 printf("Ошибка,введите другое число\n");
else
 printf("%f\n",sqrt(4*x-6));
return 0;
}

//1.66
