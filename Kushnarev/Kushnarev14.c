#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
int k1,k2,k3;
float m,n,W,U,V;
system("clear");
printf("k1="); scanf("%d",&k1); 
printf("k2="); scanf("%d",&k2);
printf("k3="); scanf("%d",&k3);
printf("m="); scanf("%f",&m);
printf("n="); scanf("%f",&n);
if (k1+k2 != 0 && k2 !=0)
{
W=3.0/2.0+k3/(float)(k1+k2)+(float)(k1+k3)/k2;
printf("W=%f\n",W);
}
else printf("W=Не имеет смысла\n");           
if (n+k3/k1 != 0 &&  k1 != 0)
{
U=(float)(10e2 + 1.0/k1)/10e2 +(float)(m+k2/k1)/(n+k3/k1);
printf("U=%f\n",U);
}
else printf("U=Не имеет смысла\n");
if (3.0+k2 != 0 &&  3.3+k3 != 0)
{
V=(float)((3.0-k3)/(3.0+k2)-(float)(3.3+k1)/(3.3+k3))*10e-3;
printf("V=%f\n",V);
}
else printf("V=Не имеет смысла\n");
 return 0;
}
