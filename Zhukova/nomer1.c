#include <stdio.h>
#include <math.h>
int main()

{
float A, a, b, c, h, S, P;

printf("Введите сторону а-\n");scanf("%f",&a);
printf("введите прилежащий угол А-\n");scanf("%f",&A);
printf("Введите площадь S\n");scanf("%f",&S);
if((a||A||S)<0)
printf("Одно из значений введено неверно");

h=(S*2)/a;
b=S/(sin(A)*a/2);
c=sqrt(pow(b,2)+pow(a,2)-2*a*b*(cos(A)));
P=a+b+c;

printf("Сторона b=%f\nСторона с=%f\nВысота равна=%f\nПериметр равен=%f\n",b,c,h,P);

return 0;
}

//А остальные углы? 1.5
