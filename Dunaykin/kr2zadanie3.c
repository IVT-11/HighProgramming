#include<stdio.h>

#include<math.h>

int main()

{
    int k,n;

float x,s=0,ak,ak1=1;

printf("x=");

scanf("%f",&x);
while(fabs(x)>=1)
{
    printf("x по модулю должен быть <=1\n");
    printf("x=");
    scanf("%f",&x);
}

    for(k=0;;k++)

{
    if(fabs(ak1)>=0.001) ak1=pow(-x,k)/(k*k+2);
    else
    {n=k;
    break;}
}
    k=0;
    for(k;k<=n;k++)
    {
        s+=pow(-x,k)/(float)(k*k+2);
    }
    printf("%f\n",s);
    return 0;
}

//Нет, логика здесь неверная 0.8

//Итого: 0.8+1.4+1.4=3.6
