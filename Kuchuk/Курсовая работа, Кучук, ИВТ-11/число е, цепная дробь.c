#include <stdio.h>                                  //подключаем стандартную библиотеку ввода/вывода;
#include <math.h>                                   //подключаем математическую библиотеку;

double calcE(double);                               //прототип функции;
double calc(int, double);                           //прототип функции;

int main(int argc, char const *argv[])
{
    int eps;                                        //количество членов дроби;
    double res;                                     //переменная для хранения результатов функции;
    printf("Введите кол-во членов дроби: ");        //узнаем кол-во
    scanf("%d",&eps);                               //знаков;
    res = calcE(eps);                               //вызываем функцию и сохраняем возвращенно значение;
    printf("res = %.10f", res);                     //вывод результатa;
    return 0;                                       //выходим из программы;
}

double calcE(double eps)
{
    if (!eps)                                       //если запрошенно 0 знаков;
        return 2;                                   //
    double e = 1;                                   //переменная хранящая значение e
    double z;
    int count = 1;                                  //переменная-счетчик
        e += 1 / calc(count, eps);                  //вычисляем число e
    return e;                                       //возвращаем число e
}

double calc(int count, double eps)
{
    if (count > eps)                               //если значение счетчика больше  точности
        return count;                               //возвращаем значение счетчика
    if (count % 2)                                  //если значение счетчика 
        return count - 1 / calc(count + 1, eps);    //
    else            
        return 2 + 1 / calc(count + 1, eps);        //
}