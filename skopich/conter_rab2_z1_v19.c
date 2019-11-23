#include<stdio.h>
#include<math.h>
int  main()
{
int a,b;
double h;
float c;
printf("введите сторону а\n");
scanf("%d",&a);
printf("введите сторону b\n");
scanf("%d",&b);
printf("введите угол h\n");
scanf("%lf",&h);
if(a==0||b==0||h==0||h>180)
printf("не верно введены данные\n");
else
{
c=sqrt(a*a+b*b-2*a*b*cos(h));
printf("третья сторона равна %f\n",c);
}
return 0;
}

//А площадь?

//1
