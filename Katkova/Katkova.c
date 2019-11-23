#
include <stdio.h> //Это как?
#include <math.h>

int main()
{
float S=0.0, a=0.0;
double x;
int k=1, z=1;

printf("Введите значение x"); 
scanf ("%lf",&x);
if(x^(2*k+1)>1||x^(2*k+1)<-1)
{
printf("Введите недоступное значение x");
k=0;
}

while(<=0.01)
{
z*=(2k+1)!;
a=(x^(2k+1))/z;
S*=a;
k++;
}
if((k>1)&&(a>=0.0))
printf("Геометрическая последовательность %f",P);
else
printf("Нет решений");

return 0;
}

//Какую задачу Вы решали?

//0.5 за участие.

