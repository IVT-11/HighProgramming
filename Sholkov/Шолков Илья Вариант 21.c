#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main ()
{
  int k1,k2,k3;
  float m,n,W,U,V;
  system("clear"); /*Очитска при выводе результата*/
  printf("k1=");
  scanf("%f",&k1); /*Ошибка типа переменной*/
  printf("k2=");
  scanf("%f",&k2); /*Ошибка типа переменной*/
  printf("k3=");
  scanf("%f",&k3); /*Ошибка типа переменной*/
  W=(6.0/7)+(k1/(k3+k2))+((m+n)/k2); /*Условия нужно совмещать с вычислением, так не работает*/
  
  U=((pow(10,-2)+(1.0/k1))/pow(10,2))+((m+(k1/k3))/(m+(k2/k3)));
  
  V=(((13-k1)/(13.0+k3))-((pow(10,-7)+k1)/(20+k3)))*pow(10,-3);
  
  printf("W=%f\n",W);
  printf("U=%f\n",U);
  printf("V=%f\n",V);

  if ((k3+k2)==0 || k2==0)
    printf("W=Выражение не имеет смысла\n");
  
  if (((m+(k2/k3))==0))
    printf("U=Выражение не имеет смысла\n");
  
  if ((13+k3)==0 || ((20+k3)==0))
    printf("V=Выражение не имеет смысла\n");
  
  return 0;
  
}

/*Слишком много смысловых ошибок. Итоговая оценка 2*/
      
