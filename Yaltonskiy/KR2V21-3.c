#include <stdio.h>
#include <math.h>

int main()
{
    int n, k = 1, k1 = 0;
    float e = 2.71828, x, ak = 0, s;
    
    printf("Введите x: "); scanf("%f", &x);
   
    if (fabs(x) < 1)
    {
        printf("Введите другое значение x: "); scanf("%f", &x);
    }
    else
        {
         for (k1=0;1;k1++)
            {
            if (fabs(ak)<0.01)
	            {
	            ak = (pow(e, ((k * x) / 2))) / k;
	            }
            else
	            {
	            n=k1;
	            break;
	            }
            }
        }
    for (k = 1; k <= n; k++)
        {
            s = pow(e, ((k * x) / 2)) / k;
        }
        
    printf("Сумма равна: %.2f", s);

    return 0;
}

//Для e есть exp

//1.5

//Итого: 1.5+1.5+1.66=4.66
