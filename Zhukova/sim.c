#include <stdio.h>
#define SIZE 7
int main()
{
int A[SIZE];
int i,n, c=1;
for(i=0;i<=SIZE;i++)
{
 printf("Введите %d элемент массива\n",i);
 scanf("%d",&A[i]);
}

for(i=0;i<=SIZE;i++)
{
 printf("%d элемент массива=%d\t",i,A[i]); 
}

for(i=0;i<SIZE/2;i++)
{
n=A[i];
A[i]=A[SIZE-i-1];
A[SIZE-i-1]=n; 
}

for(i=0;i<=SIZE;i++)
{
 printf("%d элемент массива=%d\t",i,A[i]); 
}

return 0;
}
