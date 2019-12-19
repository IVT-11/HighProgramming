#include <stdio.h>
#include <math.h>

int main()
{
 double res;
 printf("x\ty\tf(x,y)\n");

 for (double x = 1; x <= 5; x += 1)
  {
  for (double y = 0; y <= 2; y += 0.25)
   {
    res = log10(x-y)/pow(x,2)+pow(y,2)+x+y+1;
     if ((pow(x,2)+pow(y,2)+x+y+1) == 0.0 || x==y || x<y)
       printf("%.2f\t%.2f\t0.000\n", x, y);
     else
       {
       printf("%.2f\t%.2f\t%.3f\n", x, y, res);
       }
   }
  }
}
