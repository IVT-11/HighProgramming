#include <stdio.h>
#include <math.h>
#include <stdlib.h>
main()
{
int a,b,c;
float d,e,A,B,Q; /*Какой вариант? */
system("clear");
printf("a="); scanf("%d",&a);
printf("b="); scanf("%d",&b);
printf("c="); scanf("%d",&c);
printf("d="); scanf("%f",&d);
printf("e="); scanf("%f",&e);
    if (c!=0 || b+c!=0) /*Логическое && должно быть */
{A=8/5+a*(float)b/c+(float)a/(b+c);
printf("A=%f\n",A);}
    else printf("A=не имеет смысла\n");
    if (a!=0 || b!=0 || a+b!=0 || a*b!=0 || d+e!=0) /*Логическое && должно быть */
{B=(float)d/(a+b)+(float)e/(a*b)+(float)(a+b+c)/(d+e);
printf("B=%f\n",B);}
    else printf("B=не имеет смысла\n");
    if (b!=0)
{Q=(-d)*10e6+(float)a/b;
printf("Q=%f\n",Q);}
    else printf("Q=не имеет смысла\n");
return 0;
}

/*Итоговая оценка 3.5 */
