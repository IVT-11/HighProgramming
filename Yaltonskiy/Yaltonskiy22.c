
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int a, b, c;
    float alpha, beta, j, k , l;
    
    printf ("Введите число a: "); scanf("%d", &a);
    printf ("Введите число b: "); scanf("%d", &b);
    printf ("Введите число c: "); scanf("%d", &c);
    printf ("Введите число alpha: "); scanf("%f", &alpha);
    printf ("Введите число beta: "); scanf("%f", &beta);
  
    system("clear");
    
    if(c == 0 | a == 0) /*Неверно записали или. Двойная || */
    printf("Выражение не имеет смысла\n"); 
    else 
      { j = pow(10, -7)*b*c+((2*b)/c*a)+(3*alpha*c/(a)); /*Не хватает приведения типов*/
    printf("j = %f\n", j); }
    
     if(b == 0 | a == 0 | beta == 0) /*Неверно записали или. Двойная || */
        printf("Выражение не имеет смысла\n");
    else
    { k = (pow(10, -1)/(pow(c, 3)+b))*(2/(a*beta)+(a/b)-(c/(b*beta)));
    printf("k = %f\n", k); }

     if (1+alpha==0 || 1+beta==0) /*А здесь уже верно использовали лог. знак*/
	printf("Выражение не имеет смысла");
	else
    l = ((a*(b*b)*c)/(1+alpha))+((pow(a, -1)*b*c)/(1+beta))+(1/5);
    printf("l = %f\n", l);

    return 0;
}

/*Итоговая оценка 3.8*/

