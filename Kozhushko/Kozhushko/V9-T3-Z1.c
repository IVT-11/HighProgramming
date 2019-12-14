#include <stdio.h>
float f(float x, int y, float z);
int main()
{
int b=0; float a=-1,c=0;
printf("Таблица значений функции:\n");
while (a<1.1) //1.1 специально, чтобы 1 входила в промежу$
 { while (b<=10)
  {
  f(a,b,c);
  printf("%.3f\n",c);
  b++;
  }
 a+=0.2;
 }
return 0;
}
float f(float x, int y, float z)
{
z=(x*x+y*y+2)/(x*x-y*y);
return z;
}
