#include <stdio.h>
#include <math.h> 

int main()
{
    int a, b, c, d;
    float mn, h, s, p;
    
    printf("Введите сторону a: "); scanf("%d", &a); // Нижняя сторона
    printf("Введите сторону b: "); scanf("%d", &b); // Верхняя сторона
    printf("Введите сторону c: "); scanf("%d", &c); // Левая сторона 
    printf("Введите сторону d: "); scanf("%d", &d); // Правая сторона

    mn = (a + b) / 2.0; 
    h = sqrt(pow (c, 2) - pow (((pow((a - b), 2) + pow(c, 2) - pow(d, 2))) / ( 2 * (a - b)), 2));
    p = a + b + c + d;
    s = mn * h;
    
    printf("Средняя линия равна: %.1f", mn);
    printf("\nВысота равна: %.1f", h);
    printf("\nПериметр равен: %.1f", p);
    printf("\nПлощадь равна: %.1f", s);
    
    return 0;
}