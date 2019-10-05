#include <stdio.h>
#include <stdlib.h>
/* Почему файл с расширением cpp, а не с*/
main()
{
  system ("clear"); /*По заданию очистить экран нужно перед выводом результата*/
int  i1,i2,i3,V;
float a,b,Z,X;
printf ("i1=");
scanf("%d",&i1);
printf ("i2=");
scanf("%d",&i2);
printf ("i3=");
scanf("%d",&i3);
printf ("a=");
scanf("%f",&a);
printf ("b=");
scanf("%f",&b);
if((b+a/b)==0)
printf("ошибка\n");
else 
  printf ("Z=%f\n",(1.0/2)*((float)a/(b+a/b)));/*в a/b тоже нужно преобразование типов*/

 if(i1!=0||i2!=0||i3!=0) /* Здесь нужно логическое &&*/
printf("X=%f\n",(1.0/i1)+(1.0/i2)+(1.0/i3));

else 
printf("ошибка\n");

 if((i2*i2!=0)||i2!=0) /*и здесь тоже*/

   printf("V=%d\n",i1/(i2*i2)+(i1*i3)/i2); /*Забыли о преобразовании типов, и результат не целое число*/
else 
printf("ошибка\n");


return 0;
}


/*Итоговая оценка 3.5*/
