#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
   int m, p, n;
   float c, s, z, d1, d2;

   system("clear"); /*Очистка экрана должна быть при выводе результата*/

   printf("m="); scanf("%d", &m);
   printf("n="); scanf("%d", &n);
   printf("p="); scanf("%d", &p);
   printf("d1="); scanf("%f", &d1);
   printf("d2="); scanf("%f", &d2);

   if (m + p == 0 || d2 == 0)
      printf("C: Введите корректные значения! \n");
   else {
      c = (m + n) / (m + p) + pow(10, -3) * ( (float)d1 / d2); /*В выражении (m + n) / (m + p) тоже нужно приведение типов */
      printf("C = %f \n", c);
   };

   if (n == 0 || p == 0 || d2 == 0) 
      printf("S: Введите корректные значения! \n");
   else {
      s = m / (p * n) + (m * n) + ( (float)d1 / n ) + ( (float)p / d2 ); /*Не хватает приведения типов*/
      printf("S = %f \n", s);
   };

   if (m == 0 || p == 0 || n == 0 || d2 + (m / p) == 0)
      printf("Z: Введите корректные значения! \n");
   else {
      z = ( (float)p / m ) * ( (d1 + (float)m / n) / (d2 + ( (float)m / p )) );
      printf("Z = %f \n", z);
   };
   
   return 0;
}

/*Итоговая оценка 4*/
