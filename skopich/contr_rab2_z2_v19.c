#include<stdio.h>
int main()
{
int k1,k2,b1,b2,r;
printf("k1=\n");
scanf("%d",&k1);
printf("k2=\n");
scanf("%d",&k2);
printf("b1=\n");
scanf("%d",&b1);
printf("b2=\n");
scanf("%d",&b2);
if(k1!=k2)
printf("прямые не праллельны\n");
else
{
 printf("параллельные прямые\n");
 if(b1>b2)
   {
   r=b1-b2;
   printf("расстояние равно %d\n",r);
   }
     else
     {
     r=b2-b1;
     printf("расстояние равно %d\n",r);
     }
}

return 0;
}
