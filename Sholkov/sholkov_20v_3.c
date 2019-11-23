#include <stdio.h>
#include <math.h>
int main()
{
  float s,k,N,x;
    printf("Введите значение N = ");
	scanf("%f", &N);
    printf("Введите значение x = ");
	scanf("%f", &x);  
	while(1)
{
    if(N>0)
	break;
	else
{
	printf("Не может быть определен для отрицательных чисел. Введите еще раз.\nN = ");
	scanf("%f", &N);
}
}
    for(k=0;k<=N;k++)
{
	s+=((k/2.0)+(1/(pow(2,k)))+((1+k*x)/(1+k*(pow(x,2)))));
}
	printf("Результат регенерации N-случайных чисел = %.2f\n", s);
	return 0;
    // Компилировать с -lm
}

//1.66

//Итого: 1.66+1.66+0.5=3.82
