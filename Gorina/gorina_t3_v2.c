#include<stdio.h>
#include<math.h>
double fxy(double, double);
double fxy(double x, double y)
{
    return (sin(x)+sin(y))/(pow(x,2)+pow(y,2));
}
int main()
{
  double x,y;
  printf("    x\t      y\t     F(x,y)\n\n");
  for(x=0.0;x<=0.5;x+=0.1)
    {
      for(y=-1.0;y<=1.0;y+=0.2)
      {
          if(x==0 && y<0.1 && y>-0.2)
          printf("%7.3lf   %7.3lf     0.000\n", x,y);
          else
          printf("%7.3lf   %7.3lf   %7.3lf\n", x,y,fxy(x,y));
      }
    }
  return 0;
  // Компилировать с -lm
}
