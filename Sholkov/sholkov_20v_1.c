#include <stdio.h>
#include <math.h>
int main()
{
    float a,b,c,p,hA,hB,hC,num,Y;
    printf("Введите сторону треугольникa a=");
	scanf("%f", &a);
    printf("Введите сторону треугольникa b=");
	scanf("%f", &b);
	printf("Введите сторону треугольника c=");
	scanf("%f", &c);
	if(a>(b+c)|| b>(a+c) || c>(a+b))
    printf("Такого треугольнка не существует,введите данные повторно\n");
	else
	p=(a+b+c)/2.0;
	num=2*sqrt(p*(p-a)*(p-b)*(p-c));
	hA=num/a;
    hB = num/b;
    hC = num/c;     
    Y=hA*hB*hC;
    printf("Произведение высот треугольнка = %f",Y);
    return 0;	
}
