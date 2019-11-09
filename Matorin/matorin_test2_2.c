#include <stdio.h>
#include <math.h>

int main()
{
  int Ax,Ay,Bx,By,Cx,Cy,ABx,ABy,ACx,ACy,BCx,BCy,ABBC;
  float R,Sin,Cos,AB,AC,BC;

  printf("Введите через пробел координаты точка A: "); scanf("%d%d",&Ax,&Ay);
  printf("Введите через пробел координаты точка B: "); scanf("%d%d",&Bx,&By);
  printf("Введите через пробел координаты точка C: "); scanf("%d%d",&Cx,&Cy);

  /*счтитаем координаты векторов*/
  ABx=Bx-Ax; 
  ABy=By-Ay;
  ACx=Cx-Ax;
  ACy=Cy-Ay;
  BCx=Cx-Bx;
  BCy=Cy-By;
  
  /*считаем длины векторов*/
  AB=sqrt(ABx*ABx+ABy*ABy);
  AC=sqrt(ACx*ACx+ACy*ACy);
  BC=sqrt(BCx*BCx+BCy*BCy);
  ABBC=ABx*ACx+ABy*ACy;
  /*проверка существования треугольника с такими координатами*/
  while (1)
    {
      if (AB>=(BC+AC) || BC>=(AB+AC) || AC>=(AB+BC) || AC==0 || BC==0 || AC==0)
	{
	  printf("Такого треугольника не существует, введите другие координаты точек: \n");
	  printf("Введите через пробел координаты точка A: "); scanf("%d%d",&Ax,&Ay);
	  printf("Введите через пробел координаты точка B: "); scanf("%d%d",&Bx,&By);
	  printf("Введите через пробел координаты точка C: "); scanf("%d%d",&Cx,&Cy);

	  ABx=Bx-Ax; 
	  ABy=By-Ay;
	  ACx=Cx-Ax;
	  ACy=Cy-Ay;
	  BCx=Cx-Bx;
	  BCy=Cy-By;
	  
	  
	  AB=sqrt(ABx*ABx+ABy*ABy);
	  AC=sqrt(ACx*ACx+ACy*ACy);
	  BC=sqrt(BCx*BCx+BCy*BCy);
	  ABBC=ABx*ACx+ABy*ACy;
	}
      else
	  break;
    }

  /*находим синус углага между сторонами*/
  Cos=(float)(ABBC)/(AB*AC);
  Sin=sqrt(1-powf(Cos,2));

  /*находим радиус из теоремы синусов*/
  R=(float)BC/(2*Sin);

  printf("Радиус описанной окружности равен: %f\n",R);

  return 0;
}
