#include <stdio.h> 
#include <math.h> 
int main() 
{ 
double result; 
printf("x\ty\tf(x,y)\n"); 
for (double x = -M_PI; x <= M_PI; x += M_PI/4) 
{ 
for (double y = -2*M_PI; y <= 2*M_PI; y += M_PI/4) 
{ 
result = (x*cos(x)+y*cos(y))/(pow(x,2)-pow(y,2)); 
if ((pow(x,2) + pow(y,2)) == 0.0 || x==y || -x==y || x==-y) 
{ 
printf("%.2f\t%.1f\t0.00\n", x, y); 
} 
else 
{ 
printf("%.2f\t%.2f\t%.3f\n", x, y, result); 
} 
} 
} 
}