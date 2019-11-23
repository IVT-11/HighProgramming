#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
int k,P; float a,x,S=0;
k=1; P=1; 
printf("Введите аргумент х(|x|<1): ");
scanf("%f",&x);
a=x;
while (abs(a) > 0.001)
 {
 k+=2; P*=k*(k-1); S+=a; //Расчет P неверен.
 a=pow(x,k)/P;
 }
printf("S равно %f",S);
return 5;
}

//0.8 балл

//Итого: 0.8+1.66+1=3.46
