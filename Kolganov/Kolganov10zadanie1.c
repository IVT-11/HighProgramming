#include <stdio.h>
float f(float x,float y)
{
return(2*x+3*y-1)/(x*x+y*y-x*y);
}
 int main(int argc,char** argv)
 {
  for(float y=-1.0f,x=-1.0f; x<1.0f; x+=0.2f, y+=0.1f)
   {
    printf("x=%.3f,y=%.3f, f=%.3f\n",x,y,f(x,y));
    y+=0.1f;
    printf("x=%.3f,y=%.3f, f=%.3f\n",x,y,f(x,y));
   }
return 0;
}
