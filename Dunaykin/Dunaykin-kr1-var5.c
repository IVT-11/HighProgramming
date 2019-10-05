#include <stdio.h>
#include <stdlib.h>
int main()
{
int a,b,c;
float P,R,T,g1,g2;
printf("Введите целые числа\n");
printf("a="); scanf("%d",&a);
printf("b="); scanf("%d",&b);
printf("c="); scanf("%d",&c);
printf("Введите вещественные числа\n");
printf("g1="); scanf("%f",&g1);
printf("g2="); scanf("%f",&g2);
if (g1==0 || g2==0 || (a==0 && b==0)) printf("Не может быть выполнено\n");
else
{   
P=(10e3)/(g1*g2)+(1/(a+b));
system("clear");
printf("P= %f\n",P);
}
if (c==0 || a==0) printf("Нет решений\n");
else 
{
R=((a*b)/c)+(b/(a*c));
printf("R= %f\n",R);
}
if ((c==0 && b==0) || (c==0 || b==0)) printf("Невыполнимо\n"); /* Условие неверное! Где чистка экрана?*/
else
{
T=((a+b)/(c+b))+((a+b/c)/(c+a/b));
printf("T= %f\n",T);
}
return 0;
}

/*Итоговая оценка 4 балла */
