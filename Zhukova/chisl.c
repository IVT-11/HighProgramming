#include <stdio.h>
#include <math.h>

int main()

{
int a, b, c, d, f;
printf("введите а\n"); scanf("%d",&a); 
b=a%10;
a=a/10;

c=a%10;
a=a/10;

d=a%10;
a=a/10;

f=a%10;
a=a/10;

printf("%d %d %d %d %d", a,f,d,c,b);
return 0;
} 
