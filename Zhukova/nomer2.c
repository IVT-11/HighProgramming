#include <stdio.h>
#include <math.h>

int main()
{
int x, y;

printf("Введите х=\n");scanf("%d",&x);

if(x>0)
{
y=-2*pow(x,2)+3;
printf("Функция =%d\n",y);
}
if(x<=0) //Зачем?
{
y=-2*pow(x,2)+x+1;
printf("Функция =%d\n",y);
}

return 0;
}

//1.5
