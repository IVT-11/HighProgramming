#include <stdio.h>
#include <math.h>

int main()
{
  int a,b,c,p;
  float s,R,A;
  
  printf("Введите длину стороны a треугольника: "); scanf("%d",&a);
  printf("Введите длину стороны b треугольника: "); scanf("%d",&b);
  printf("Введите длину стороны c треугольника: "); scanf("%d",&c);

  /*проверка существования треугольника*/
  while (a>=(b+c) || b>=(a+c) || c>=(a+b) || a==0 || b==0 || c==0)
    {
      printf("Такой треугольник невозможен, введите другие длины сторон: \n");
      printf("Введите длину стороны a треугольника: "); scanf("%d",&a);
      printf("Введите длину стороны b треугольника: "); scanf("%d",&b);
      printf("Введите длину стороны c треугольника: "); scanf("%d",&c);
    }

  /*если треугольник равносторонний*/
  if (a==b && b==c && a==c)
    {
      s=(a*a*sqrt(3))/(float)4;
      printf("Площадь треугольника равна: %f\n",s);
    }
  /*если треугольник равнобедренный*/
  else if (a==b || b==c || a==c)
    {
      p=a+b+c;
      printf("Периметр треугольника равен: %d\n",p);
      /*считаем угол */
      if (a==b)
	{
	  A=asin((float)c/(2*a));
	  printf("Угол между равными сторонами равен: %f\n",2*A);
	}
      if (b==c)
	{
	  A=asin((float)a/(2*c));
	  printf("Угол между равными сторонами равен: %f\n",2*A);
	}
      if (a==c)
	{
	  A=asin((float)b/(2*c));
	  printf("Угол между равными сторонами равен: %f\n",2*A); 
	}
    }
  /*если треугольник обычный*/
  else
    { /*считаем угол, используя теорему синусов и косинусов*/
      R=a/(2*(sqrt(1-powf((float)(a*a-b*b-c*c)/(-2*b*c),2))));
      printf("Радиус описанной окружности равен: %f\n",R);
    }
  

  return 0;
}
