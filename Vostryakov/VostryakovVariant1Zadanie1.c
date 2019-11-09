#include<stdio.h>
#include<math.h>
int main()
{float a,b,c,alfa,beta,gama,e;
printf("Введите а= ");
scanf("%f",&a);
printf("\nВведите b= ");
scanf("%f",&b);
printf("\nВведите угол alfa= ");
scanf("%f",&alfa);
while(1){
if (a>0 && b>0 && alfa>0)
break;
else{
printf("Не корректные значения введите другие значения");
printf("\na= ");
scanf("%f",&a);
printf("\nb= ");
scanf("%f",&b);
printf("\nугол alfa= ");
scanf("%f",&alfa);}}
if(alfa<180){
e=(sin(alfa)*b)/a;
beta=asin(e);
if (beta<0)
beta=beta*(-1);
gama=180-alfa-beta;
c=a*sin(gama)/sin(alfa);}
if(c<0)
c=c*(-1);
printf("beta=%f gama=%f c=%f\n",beta,gama,c);
return 0;
}

