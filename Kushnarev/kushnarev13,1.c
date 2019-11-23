#include <stdio.h>
#include <math.h>
int main()
{
int ax,ay,bx,by,cx,cy;
float ab,bc,ca,s,p;
printf("Введите координаты A\n"); scanf("%d %d",&ax,&ay);
printf("Введите координаты B\n"); scanf("%d %d",&bx,&by);
printf("Введите координаты C\n"); scanf("%d %d",&cx,&cy);
ab=sqrt(pow((ax-bx),2)+pow((ay-by),2));
bc=sqrt(pow((bx-cx),2)+pow((by-cy),2));
ca=sqrt(pow((cx-ax),2)+pow((cy-ay),2));
p=ab+bc+ca;
s=1.0/2.0*(ay+by)*(ax-bx)+(by+cy)*(bx-cx)+(cy+ay)*(cx-ax);
printf("Площадь= %f\n",fabs(s));
printf("Периметр= %f\n",fabs(p));
printf("Стороны равны= %f %f %f \n",ab,bc,ca);
return 0;
}

//Углы? 1 балл

//Итого: 1+1.66+1.66=4.32
