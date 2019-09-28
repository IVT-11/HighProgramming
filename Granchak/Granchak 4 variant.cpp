#include <stdio.h>
#include <stdlib.h>
main()
{
system ("clear");
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
printf ("Z=%f\n",(1.0/2)*((float)a/(b+a/b)));

if(i1!=0||i2!=0||i3!=0)
printf("X=%f\n",(1.0/i1)+(1.0/i2)+(1.0/i3));

else 
printf("ошибка\n");

if((i2*i2!=0)||i2!=0)

printf("V=%d\n",i1/(i2*i2)+(i1*i3)/i2);
else 
printf("ошибка\n");


return 0;
}


