#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 2

int main()
{
    int A[2][2], B[2][2]; 
    
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("Введите элемент первого массива: ");
            scanf("%d", &A[i][j]);
        }
    }
    
    printf("Первый массив: \n");
    
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("Введите элемент второго массива: ");
            scanf("%d", &B[i][j]);
        }
    }
    
    printf("Второй массив: \n");
    
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
    
    int result[SIZE][SIZE], sovp = 0;
    
    printf("\nРезультат: \n");   
    
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (A[i][j] == B[i][j]) {
                result[i][j] = 1;
                sovp++; }
            else 
                result[i][j] = 0;
                
            printf("%d ", result[i][j]);   
        }
        printf("\n");
    }
        return printf("\nКол-во совпадений: %d", sovp);
}
