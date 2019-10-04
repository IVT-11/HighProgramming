#include <stdio.h>
#include <stdlib.h>
int main()
{
system ("clear");
int i,j,k,n;
float v,w,a,b,c;
a=0;
b=0;
c=0;
printf("i=");
scanf("%d",&i);
printf("j=");
scanf("%d",&j);
printf("k=");
scanf("%d",&k);
printf("n=");
scanf("%d",&n);
printf("v=");
scanf("%f",&v);
printf("w=");
scanf("%f",&w);
if (j !=0 && n !=0 && k*n !=0){
a=7/100+((i*j)/(k*n))+(i/j)*(k/n);
printf("a=%f\n",a);
}
else
printf("Ne imeet smisla\n");
if (j !=0 && j*k !=0){
b=v/2+i/(j*k)-(n*k)/j+j;
printf("b=%f\n",b);
}
else
printf("Ne imeet smisla\n");
if (w != 0){
c=(100-i-j-k-n)/w;
printf("c=%f\n",c);
}
else
printf("Ne imeet smisla\n");
return 0;
}