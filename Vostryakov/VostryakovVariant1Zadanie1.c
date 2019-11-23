#include<stdio.h>
#include<math.h>
int main()
{
float a,b,c,alfa,beta,gama,e,p,s;
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
p=(a+b+c)/2.0;
s=sqrt(p*(p-a)*(p-b)*(p-c));
printf("beta=%f gama=%f c=%f\n периметр=%f площадь=%f",beta,gama,c,p,s);
return 0;
}

//1.66

//Итого: 1.66+1.66+1.5=4.82
