#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 2 // По заданию 5

int func (int a[][SIZE], int b[][SIZE], int c[][SIZE]);

int main(void)
{
    int A[SIZE][SIZE], B[SIZE][SIZE], result[SIZE][SIZE];
 
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("Введите элемент первого массива: ");
            scanf("%d", &A[i][j]);
        }
    }
    
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("Введите элемент второго массива: ");
            scanf("%d", &B[i][j]);
        }
    }
 
    printf("\nПервый массив: \n");
    
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
 
    printf("\nВторой массив: \n");
    
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
 
    func(A, B, result);
}

int func (int a[][SIZE], int b[][SIZE], int c[][SIZE])
{
    int sovp = 0;    // кол-во совпадений
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (a[i][j] == b[i][j])
            {
                c[i][j] = 1;
                sovp++;
            }
            else
                c[i][j] = 0;
        }
    }
    
    printf("\nРезультат:\n");

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    
    return printf("\nКол-во совпадений: %d", sovp);
}
