#include <stdio.h>
#include <math.h>
int inverse(int);
int inverse(int a)
{   
    int c=0, b=a;
    while(a>0)
    {
      c=c*10+a%10;
      a/=10;
    }
    
    return c;
}
int sub(int);
int sub(int o)
{
   if(o==0)
   return 0;
   else 
   return o-inverse(o);
  
}
int main()
{
    int l, r;
    printf("Введите число\n"); scanf("%d",l);
    printf("%d\n", sub(l));
    return 0;
}
hb
