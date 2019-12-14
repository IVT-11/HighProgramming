#include <stdio.h>
int main()
{
int y=0; float x=-1,f;
printf("Таблица значений функции:\n");
while (y<=10)
 {
 f=(x*x+y*y+2)/(x*x-y*y);
 printf("%.3f\n",f);
 x+=0.2;
 y++;
 }
return 0;
}

