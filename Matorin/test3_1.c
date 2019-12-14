#include <stdio.h>
#include <math.h>

float func(float,float);

int main()
{
  float x,y;
  int i,j;
  
  x=-1.0;
  y=-2.0;
  
  printf("  x         y         f\n");
  printf("----------------------------\n");
  
  for (i=1;i<=11;i++) //от -1 до 1 с шагом 0.2 11 итераций
    {
      for (j=1;j<=9;j++) //от -2 до 2 с шагом 0.5 9 итераций
	{
	  printf("%.3f    %.3f    %.3f\n",x,y,func(x,y));
	  y+=0.5;
	}
      x+=0.2;
      y=-2.0; //приведение y к начальному значению -2, т.к. -2<= y >=2
    }    
  return 0;
}

float func(float x,float y)
{
  return (powf(x,2)+powf(y,2))/(powf(x,3)-powf(y,3));
}
