#include<stdio.h>
#include<math.h>
int main(){
float x,y,a,b,c;
printf("x= ");
scanf("%f",&x);
if (x>=2)
printf("Нет корней\n");
if (x>1 && x<2) {
a=cos(x)*cos(x);
printf("Функция =%f\n",a);}
b=x/10;
if (x<=b || b>=2){
c=1+sin(x)*sin(x);
printf("Функция =%f\n",c);}
return 0;
}
