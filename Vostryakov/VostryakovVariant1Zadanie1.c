#include<stdio.h>
#include<math.h>
int main()
{
float a,b,c,alfa,beta,gama,e;
printf("Введите а= ");
scanf("%f",&a);
printf("\nВведите b= ");
scanf("%f",&b);
printf("\nВведите угол alfa= ");
scanf("%f",&alfa);
while(1)
{
if (a>0 && b>0 && alfa>0 && alfa<180)
break;
else
{
printf("Не корректные значения введите другие значения");
printf("\na= ");
scanf("%f",&a);
printf("\nb= ");
scanf("%f",&b);
printf("\nугол alfa= ");
scanf("%f",&alfa);
}
}
c=sqrt(a*a+b*b-2*a*b*cos(alfa));
e=(sin(alfa)*b)/a;
beta=asin(e)/M_PI*180;
if (beta<0)
beta=beta*(-1);
gama=180-alfa-beta;
printf("beta=%f gama=%f c=%f\n",beta,gama,c);
return 0;
}
