#include<stdio.h>
#include<stdlib.h>
int main()
{
int i1,i2,i3;
float a,b,A,B,Y;
printf("i1=");
scanf("%d",&i1);
printf("i2=");
scanf("%d",&i2);
printf("i3=");
scanf("%d",&i3);
printf("a=");
scanf("%f",&a);
printf("b=");
scanf("%f",&b);

if(i3!=0&&i2!=0&&i2*i3!=0&&b+((i1*i3)/i2)!=0)

{
A=(3.0/4)*(((float)i1+i2)/i3)+(2.0/3)*(((float)i1+i3)/i2);
system("clear");
printf("A=%f\n",A);
B=((float)a+(i1/(i2*i3)))/(b+((i1*i3)/i2));

printf("B=%f\n",B);
Y=(i1*i2)+(i2*i3)+(i3*i1);

printf("Y=%f\n",Y);


}
else
{ 

printf("невозможно");
}
return 0;
}
