#include <stdio.h>

#include <math.h>

double function(double,double);

double function(double a,double b)

{

 double f;

 f=(sin(2*a)+cos(2*a)/sin(a))*(a*a+b*b);

 return f;

}

int main()

{

double x,y;
printf("x\t     y\t     f(x,y)\t\n\n",x,y,function(x,y));
for(x=-1;x<=1;x+=0.25)
{
    for(y=0;y<=2;y+=0.1)
	{
		if(x==0)
			printf("%.3lf	  %.3lf	    Деление на ноль\n",x,y);
		else
		{
			printf("%.3lf     %.3lf     %.3lf\n",x,y,function(x,y));
		}
	}
}
return 0;
}