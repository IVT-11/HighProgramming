﻿#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
double func(double, double, int *);
//функция нахождения суммы бесконечного ряда до заданной точности, принимает значение x, переменную toch отвечающую за точность
//и указатель на переменную i, отвечающую за кол-во итераций 
double func(double x, double toch, int *i)
{
    int n=0, t=1;//вводятся переменные n-для подсчета количества членов ряда и t для изменения членов ряда в соответствии с формулой
    double schet=0;//вводится переменная для подсчета суммы бесконечного ряда
    while (fabs(pow(x, t)/(float)t)>toch)//пока последний добавленный член дроби больше точности по модулю...
    {
        schet+=(pow(x, t)/(float)t);//в переменную для подсчета суммы по формуле записывается новый член дроби
        n++;//количество членов ряда увеличивается на единицу
		t=(4*n)+1;//в переменную t по формуле записывается степень(она же является и дробной частью) следующего члена ряда 
        (*i)=n;//разименовываем указатель i и присваиваем ему количество членов ряда, чтобы i изменилась и в main
        //printf("Cумма=%.10f точность=%f кол-во членов ряда:=%d\n", schet,toch,n);//вывод на экран для наглядности значений найденной с каждой итерацией суммы ряда,
		//точности и количества членов ряда
    } 
    return schet;//после прохождения цикла функция возвращает полученную сумму ряда до заданной точности

}

int main()
{
    double x=1, toch, otv, ist;//вводятся переменные x - отвечающая за введенный пользователем x соответственно, toch-отвечающая за точность и otv отвечающая за итоговый ответ
    int vib, chis=-1, i=0;//так же вводится переменная vib, для выбора дальнейших действий, chis,отвечающая за количество знаков после запятой для вычисления точности
	//и переменная i, отвечающая за количество членов ряда

    while(vib!=2)//пока переменная выбора не равна двум...
{
	while ((x>=1)||(x<=-1))//пока x не попадает в допустимый диапазон значений...
    {
        printf("Введите значение x:\n");//на экран выводится предложение ввести х
        scanf("%lf", &x);//с клавиатуры считывается х
        if ((x>=1)||(x<=-1)) printf("Попробуйте еще раз\n");//если х не попадает в допустимый диапазон значений, выводится сообщение попробовать еще раз
        else break;//иначе если х попадает в допустимый диапазон, цикл прерывается
    }
    while (chis<=-1)//пока количество знаков после запятой будет меньше или равно -1...
    {
        printf("Введите точность(до скольки знаков после запятой):\n");//выводится предложение ввести точность, до определенного знака после запятой, не включая его
        scanf("%d", &chis);//считывается количество знаков после запятой
        if (chis<=-1) printf("Попробуйте еще раз\n");//если количество знаков после запятой не вошло в допустимый диапазон, выводится предложение попробовать еще раз
        else toch=1.0/(pow(10.0, chis));//иначе переменной toch(отвечающей за точность) присваивается приемлемый вид для вычислений в соответствии с количеством заданных знаков после запятой
    }
    otv=func(x, toch,&i);//переменной ответ присваивается значение, возвращаемое функцией func, в соответствии с введенными значениями точности и x
    ist=(1.0/4.0*log((1.0+x)/(1.0-x)))+(1.0/2.0*atan(x));//вычисление истинного значения
    printf("При точности до %d знаков после запятой, изначальном х:%f,\nсумма:%.10f, кол-во членов ряда:%d\n", chis,x,otv,i);//далее на экран выводится точность, изначальный х... 
	//найденная сумма и количество членов ряда для ее достижения
    printf("Истинное значение:%.10f\n",ist);//вывод на экран истинного значения для сравнения
    printf("Хотите продолжить? 1-да 2-нет\n");//на экран выводится предложение закончить вычисления или попробовать еще раз
    scanf("%d",&vib);//считывается выбор пользователя с клавиатуры
    if(vib!=1&&vib!=2)//если пользователь случайно ввел выбор, которого не существует
    {
    	printf("Такой операции не существует, попробуйте еще раз!\n");//на экран выводится сообщение, что такой операции не существует
    	while(vib!=1&&vib!=2)//пока выбор не окажется из заданных...
    	{
    		printf("Хотите продолжить? 1-да 2-нет\n");//на экран выводится предложение закончить вычисления или попробовать еще раз 
            scanf("%d",&vib);//считывается выбор пользователя с клавиатуры
    	}
    }
    else if(vib==2) {printf("Конец программы.\n"); vib=2;}//если же выбор пользователя оказался вторым, то выводится сообщение о завершении программы
	//а переменной vib присваивается 2, чтобы выйти из цикла выбора
    x=1;//переменной х присваивается ее "базовое значение", чтобы при выборе продолжить вычисления программа работала верно
    chis=-1;//то же самое повторяется и с переменной chis
}
    return 0;//функция main фозвращает 0, оповещающий о конце работы программы
    
}