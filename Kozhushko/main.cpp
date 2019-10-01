#include <iostream>

using namespace std;

int main()
{
int a,b,c; float e,f,K,L,M;
printf("Введите число а");
scanf("%d,\n",&a);
printf("Введите число b");
scanf("%d,\n",&b);
printf("Введите число с");
scanf("%d,\n",&c);
printf("Введите число e");
scanf("%f,\n",&e);
printf("Введите число f");
scanf("%f,\n",&f);
 if (a==0 or c==0 or (c/a+b)==0)
  printf("Деление на ноль!");
 else
 {
  K = (a + b / c) / (c / a + b) + e * f;
  printf("Результат выражения K K=%f",K);
 }
 if (a==0 or b==0 or c==0)
  printf("Деление на ноль!");
 else
 {
  L = 1000 * (a / (b * c) + (c * f) / a) + 10000 * (b * c) / a;
  printf("Результат выражения L L=%f",L);
 }
 if (a==0 or b==0 or c==0 or e==0 or f==0)
  printf("Деление на ноль!");
 else
 {
  M = 1 / a + 2 / b + 3 / c + 4 / e + 5 / f;
  printf("Результат выражения M M=%f",M);
 }
 system("clear");
    return 0;
}