#include <stdio.h>
#include <math.h>
int main(){
float x,y,b;
printf("x=");
scanf("%f", &x);
b = x/10;
if(x>1 && x<2){
y = cos(x)*cos(x);
printf("y=");
printf("%f", y);
}
else{
    if(b>=x || b>=2){
y = 1+sin(x)*sin(x);
printf("y=");
printf("%f", y);
}
else{
    printf("Error!");
}
}
return 0;
}

//Зачем b?

//1.5
