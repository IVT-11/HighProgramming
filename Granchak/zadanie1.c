#include <stdio.h>
#include <math.h>
#include <locale.h>
int main()
{
setlocale(LC_ALL, "");
int a, b, c, P;
float S, Ha, p;
printf("Введите сторону А: ");
scanf("%d", &a);
printf("Введите сторону B: ");
scanf("%d", &b);
printf("Введите сторону C: ");
scanf("%d", &c);
P = a + b + c;
p = 0.5 * P;
S = sqrt(p * (p - a) * (p - b) * (p - c));
Ha = 2 * S / a;
printf("P: %d\n", P);
printf("S: %f\n", S);
printf("H: %f\n", Ha);
return 0;
}

//Углы? 1.2
