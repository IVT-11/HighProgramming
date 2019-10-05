#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
int a, b, c;
float g1, g2, P, R, T;
printf("a="); scanf("%d",&a);
printf("b="); scanf("%d",&b);
printf("c="); scanf("%d",&c);
printf("g1="); scanf("%f",&g1);
printf("g2="); scanf("%f",&g2);


if(g1==0||g2==0||a+b==0)
printf("не имеет смысла\n");
else
{
 P=(10e3/(g1*g2))+(1.0/(a+b));
 printf("P=%f\n",P);
}

if(a==0||c==0)
printf("не имеет смысла\n");
else
{
 R=((a*b)/c)+((float)b/(a*c)); /*В первой части выражения не хватает приведения типов*/
 printf("R=%f\n",R);
}

if(c+b==0||a/b==-c)
printf("не имеет смысла\n");
else
{
 T=((a+b)/((float)c+b))+((a+b/c)/(c+a/b)); /*Не хватает приведения типов*/
 printf("T=%f\n",T);
}
return 0;
system("clear");/* Не здесь */
}

/*Итоговая оценка 4*/

