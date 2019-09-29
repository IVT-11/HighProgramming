#include <stdio.h>
#include <stdlib.h>
int main()
{
 system("clear");
 int a1,a2,a3,b1,b2;
 printf("a1="); scanf("%d",&a1);
 printf("a2="); scanf("%d",&a2);
 printf("a3="); scanf("%d",&a3);
 printf("b1="); scanf("%d",&b1);
 printf("b2="); scanf("%d",&b2);

 float A,B,C;
 if(1+a1/a2 !=0 && b1/b2 !=0 && b2 !=0){
  A=((1+a1/a2)/(1+a3/a2))+(b1/b2)+((a1*b1)/(a2+b2));
  printf("A=%f\n",A);}
  else
  printf("Выражение не имеет смысла\n");

 if(a2+a3!=0){
  B=(10e+3*b1+10e+4*b2+(a1/a2+a3));
  printf("B=%f\n",B);}
  else
  printf("Выражение не имеет смысла\n");

 if(2/a1!=0 && 3/b1!=0 && 4/a2 && 5/b2){
  C=(1/2)+(2/a1)+(3/b1)-(4/a2)-(5/b2);
  printf("C=%f\n",C);}
  else
  printf("Выражение не имеет смысла\n");

 return 0;
}
