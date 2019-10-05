#include <stdio.h>
#include <stdlib.h>
int main()
{
  system ("clear"); /*Не здесь*/
int c1,c2,c3;
float s1,s2,a,b,c;
a=0;
b=0;
c=0;
printf("c1=");
scanf("%d",&c1);
printf("c2=");
scanf("%d",&c2);
printf("c3=");
scanf("%d",&c3);
printf("s1=");
scanf("%f",&s1);
printf("s2=");
scanf("%f",&s2);
if (c2 != 0 && c2*c3 !=  0){
  a=4/100+(c1/c2*c3)+(c1*c3/c2); /*Нет приведения*/
printf("a=%f\n",a);
}
else
printf("Ne imeet smisla\n");
if (c1 != 0 && c3 !=0 && s1 != 0 && s2+c2/c3 != 0){
b=(s1+c2/c1)/(s2+c2/c3)-1/c1-1/s1;/*Нет приведения*/
printf("b=%f\n",b);
}
else
printf("Ne imeet smisla\n");
if (s2+c2 != 0){
  c=(10*10*10)*((s1+c1)/(s2+c2)+c3); /* 10*10*10 - безобразие!*/
printf("c=%f\n",c);
}
else
printf("Ne imeet smisla\n");
return 0;
}

/*Итоговая оценка 3 */
