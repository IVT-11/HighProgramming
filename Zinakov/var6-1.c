#include <stdio.h>
#include <math.h>

int main()
{
  double a,b,c;
  int A,B,C,R;
  printf("b=");
  scanf("%lf",&b);
  printf("B=");
  scanf("%d",&B);
  printf("R=");
  scanf("%d",&R);
  A=45;
  printf("A=%d\n",A);
  C=180-A-B;
  printf("C=%d\n",C);
  a=(2*R)*(sin(A*3.14/180));
  printf("a=%lf\n",a);
  c=(2*R)*(sin(C*3.14/180));
  printf("c=%lf\n",c);
  return 0;
}