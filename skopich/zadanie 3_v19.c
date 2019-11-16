#include<stdio.h>
#include<math.h>
int main()
{
  int n,k,x;
 float Ak,s=1;
 scanf("%d",&x);
 Ak=(1/pow(2,k))*sin(x)/pow(x,k+1);
 for(k=1;1;k++)
 if(fabs(Ak/s)<0.0001)
 Ak=(1/pow(2,k))*sin(x)/pow(x,k+1);
 else
  {
   n=k;
   break;
}
 
k=1;
for(k;k<=n;k++)
{
s+=(1.0/pow(2,k))*sin(x)/pow(x,k+1);
printf("%f\n",s);
}
return 0;
}

