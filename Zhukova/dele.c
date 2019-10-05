#include <stdio.h>
#include <math.h>

int main()

{
int a, b;

printf("введите первое число=\n");scanf("%d",&a);
printf("введите второе число=\n");scanf("%d",&b);
if(a%b==0)
printf("первое число делится на второе");
else
printf("перове число не делится на второе");
return 0;
}

