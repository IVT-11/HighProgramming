#include<stdio.h>
#include<math.h>
int main()
{
int a,b,S,c,P;
double sinAa,cosAa;
float h;
printf("a=");
scanf("%d",&a);
printf("b=");
scanf("%d",&b);
printf("S=");
scanf("%d",&S);
sinAa=(2*S)/(a*b);
cosAa=sqrt(1-sinAa*sinAa);
c=sqrt((a*a+b*b)-2*a*b*cosAa);
h=S/(0.5*a);
P=a+b+c;
printf("h= %f\n",h);
printf("c= %d\n",c);
printf("P= %d\n",P);
return 0;
}

//Нужно было вычислить также углы 1.4 балла

