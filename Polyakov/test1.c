#include <stdio.h>
#include <math.h>
int main()
{
float a,b,c,P,p,s,x1,x2,x3,y1,y2,y3;
printf ("введите x1=");
scanf("%f",&x1); 
printf ("введите x2=");
scanf("%f",&x2);
printf ("введите x3=");
scanf("%f",&x3);
printf ("введите y1=");
scanf("%f",&y1); 
printf ("введите y2=");
scanf("%f",&y2);
printf ("введите y3=");
scanf("%f",&y3);
a=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
P=a*4;
printf("Периметр ромба=%f\n",P);
b=sqrt(pow((x3-x1),2)+pow((y3-y1),2));
c=sqrt(pow((x3-x2),2)+pow((y3-y2),2));
p=(a+b+c)/2;
s=2*sqrt(p*(p-a)*(p-b)*(p-c)/6/2); //https://ru.wikipedia.org/wiki/%D0%A0%D0%BE%D0%BC%D0%B1
printf("Площадь ромба=%f\n",s);
return 0;
}

//1 балл
