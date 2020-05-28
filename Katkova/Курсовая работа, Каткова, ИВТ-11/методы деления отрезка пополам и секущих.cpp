/*
    1) Дано:

    2. e^ax - b = 0
    3. log2(ax) - b = 0
    4. x^3 + ax^2 + b = 0

    // Метод деления отрезка пополам и метод секущих

*/

#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <ctype.h>

// Точность
#define eps 0.000001
#define const_e 2.71828
// задаем тип func
typedef double (*func)(double x, double a, double b, short int numberOfEquation);
// прототип вычисляемой функции
double fx(double, double, double, short int);

double Log2(double n)
{
    // log(n)/log(2) is log2.
    return log(n) / log(2);
}

// Вычисляемые функции
double fx(double x, double a, double b, short int numberOfEquation) {
    switch (numberOfEquation) {
    case 0: return pow(const_e, a * x) - b;
    case 1: return Log2(a * x) - b;
    case 2: return pow(x, 3) + a * pow(x, 2) + b;
    }
    return 0;
}

// Метод секущих
double decision_secant_method(double x1, double x2, double a, double b, short int NumOfEquation) {

    double v;
    // пока не достигнута точность eps
    while (fabs(x1 - x2) > eps) {
        v = (x1 * fx(x2, a, b, NumOfEquation) - x2 * fx(x1, a, b, NumOfEquation)) / (fx(x2, a, b, NumOfEquation) - fx(x1, a, b, NumOfEquation));
        x1 = x2;
        x2 = v;
    }
    return x1;
}

// Метод деления отрезков
double decision_line_division_method(double x1, double x2, double a, double b, short int NumOfEquation) {

    double ksi, returnValue;
    ksi = (x1 + x2) / 2.0;

    if ((fabs(fx(x1, a, b, NumOfEquation) - fx(x2, a, b, NumOfEquation)) <= eps) || (fabs(fx(ksi, a, b, NumOfEquation)) <= eps)) {
        returnValue = (x1 + x2) / 2.0;
        return returnValue;
    }

    if (fx(x1, a, b, NumOfEquation) * fx(ksi, a, b, NumOfEquation) <= 0.0) return decision_line_division_method(x1, ksi, a, b, NumOfEquation);
    else return decision_line_division_method(ksi, x2, a, b, NumOfEquation);
}

char no_root () {
    printf("no root");
    return 0;
}

int main()
{
    int testInteger;
    double a = 3, b = 1;
    double x1 = -4, x2 = 2;

    printf("interval:[%.2lf,%.2lf] \n", x1, x2);
    printf("a = %.2lf, b = %.2lf \n \n", a, b);

    double answer_secant_method_0 = decision_secant_method(x1, x2, a, b, 0);
    double answer_secant_method_1 = decision_secant_method(x1, x2, a, b, 1);
    double answer_secant_method_2 = decision_secant_method(x1, x2, a, b, 2);
    double roundValue_secunt_method_0 = round(answer_secant_method_0);
    double roundValue_secunt_method_1 = round(answer_secant_method_1);
    // if function returns ~x2
    // it means root is absent
    if (roundValue_secunt_method_0 == x2) {
       answer_secant_method_0 = -9999999.999999;
    }
    if (roundValue_secunt_method_1 == x2) {
       answer_secant_method_1 = -9999999.999999;
    }

    printf("Results for 'secunt method':\n");
    printf("\n e^ax - b = 0       |   ");
    if (answer_secant_method_0!=-9999999.999999) {
        printf("%lf", answer_secant_method_0);
    } else {
        no_root();
    }

    printf("\n log2(ax) - b = 0   |   ");
    if (answer_secant_method_1!=-9999999.999999) {
        printf("%lf", answer_secant_method_1);
    } else {
        no_root();
    }

    printf("\n x^3 + ax^2 + b = 0 |   ");
    printf("%lf", (float)answer_secant_method_2);
    printf(" \n \n \n");

    double answer_Line_division_method_0 = decision_line_division_method(x1, x2, a, b, 0);
    double answer_Line_division_method_1 = decision_line_division_method(x1, x2, a, b, 1);
    double answer_Line_division_method_2 = decision_line_division_method(x1, x2, a, b, 2);
    double roundValue_line_method_1 = round(answer_Line_division_method_1);
    double roundValue_line_method_2 = round(answer_Line_division_method_2);
    // if function returns ~x2
    // it means root is absent
    if (roundValue_line_method_1 == x2) {
       answer_Line_division_method_1 = -9999999.999999;
    }

    if (roundValue_line_method_2 == x2) {
       answer_Line_division_method_2 = -9999999.999999;
    }

    printf("\n Results for 'line division method':\n");
    printf("\n e^ax - b = 0       |   ");
    printf("%lf", answer_Line_division_method_0);


    printf("\n log2(ax) - b = 0   |   ");
    if (answer_Line_division_method_1!=-9999999.999999) {
        printf("%lf", answer_Line_division_method_1);
    } else {
        no_root();
    }

    printf("\n x^3 + ax^2 + b = 0 |   ");
    if (answer_Line_division_method_2!=-9999999.999999) {
        printf("%lf", answer_Line_division_method_2);
    } else {
        no_root();
    }
    printf("\n \n");

    printf("Press Any Key to Continue\n");  
    getchar();  

    return 0;
}