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
    res = exp(x) / (pow(x, 2) + pow(y, 2) - 1.0);
     if ((pow(x,2) + pow(y,2) - 1.0) == 0.0)
       printf("%.2f\t%.1f\tdiv by 0\n", x, y);
     else
       {
       printf("%.2f\t%.1f\t%.3f\n", x, y, res);
       }
   }
  }
}