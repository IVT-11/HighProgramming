#include <stdio.h>//Подключаем стандартную библиотеку ввода-вывода данных
#include <math.h>//Подключаем математическую библиотеку
int fact(int);//Прототип функции, вычисляющей факториал
int main()//Главная функция
{//начало функции
    int i,accr;//объявление целочисленных переменных, где "accr" отвечает за количество знаков после запятой, а  "i" отвечает за кол-во членов ряда и участвует в нахождении правой части 
    float x,expr,exprl=0;//объявление вещественных переменных, где "expr" отвечает за значение левой части,"exprl" отвечает за значение правой части, "x" участвует в нахождении левой и правой части; также "exprl" присваивается значение “нуль”
    printf("введите x= ");//выводит на экран сообщение "введите x= "
    scanf("%f",&x);//пользователь должен ввести значение переменной "x" с клавиатуры
    printf("точность = ");//выводит на экран сообщение "точность = "
    scanf("%d",&accr);//пользователь должен ввести значение переменной "accr" с клавиатуры
    expr=(1+2*x*x)*exp(x*x);//происходит расчёт левой части 
    i=0;//присваивает i значение "0", т.к. для последующей формулы необходимо, чтобы у переменной "i" было значение
    while(expr-exprl>pow(10,-accr))//цикл, в котором с каждой новой итерацией разность левой и правой части будет все меньше и меньше, цикл заканчивается, когда разность левой и правой части меньше или равно "pow(10,-accr)"
    {//начало цикла
        exprl+=((2*i+1)*powf(x,2*i))/fact(i);//происходит расчёт правой части, где к каждому новому значению "exprl" будет прибавляться предыдущее значение "exprl"
        i++;//счетчик, увеличивающий i на 1;
	printf("i = %-2d | right ~ %-20f | ",i,exprl);//выводит на экран значение "i" и "exprl"
    }//конец цикла
	printf("\n");//перенос на следующую строку
	printf("left  = %f\n",expr);//выводит на экран значение левой части
	printf("right ~ %f\n",exprl);//выводит на экран значение правой части
    return 0;//возвращаем нуль
}//конец функции
int fact(int i)//функция отвечающая за расчёт факториала
{//начало функции
    int f,n;//объявление целочисленных переменных, где "f" - переменная отвечающая за значение факториала, "n" - переменная увеличивающая значения факториала в n раз
	f=1;//присваивание "f" значения "1", т.к. далее в for идёт умножение, то "f" присваивается значение "1", а не "0"
	for(n=2;n<=i;n++)// цикл, в котором происходит расчёт факториала, цикл заканчивается, когда n>i, начинается "n" c "2", а не с "1", т.к. умножение на "1" никак не влияет на значение факториала
	f*=n;//увеличение факториала "f" в n раз
	printf("fact = %d\n",f);//выводит на экран значение факториала
	return f;//возвращает значение факториала
}//конец функции	
