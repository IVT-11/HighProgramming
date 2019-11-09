#include <stdio.h>
#include <math.h>

int main()
{
  double x,y;
  printf("x=");
  scanf("%lf",&x);
  y=log10(3.0*x-6);
  printf("y=%lf\n",y);
  return 0;
}
