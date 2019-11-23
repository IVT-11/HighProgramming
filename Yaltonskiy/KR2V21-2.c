#include <stdio.h>


int main()
{
    int n1, n2, s, p, r;
    
    printf("Число 1: "); scanf("%d", &n1); 
    printf("Число 2: "); scanf("%d", &n2); 
 
    if (n1 != n2)
    {
        s = n1 + n2;
        p = n1 * n2;
        printf("Сумма чисел: %d", s);
        printf("\nПроизведение: %d", p);
        if (p > s)
            printf("\nПроизведение больше суммы на %d", r = p - s);
    }   
    else printf("Числа равны");
    
    return 0;
}
//1.66
