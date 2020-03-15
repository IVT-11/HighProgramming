#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 5

int func(int mas1[], int mas2[]);

int main()
{
    int array1[SIZE], array2[SIZE]; // По заданию char
    
    srand(time(NULL));
    
    for (int i = 0; i < SIZE; i++)
    {
        array1[i] = rand() % 10;
        array2[i] = rand() % 10;
    }
    
    printf("Первый массив: \n");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", array1[i]);   // Тут %c

    printf("\nВторой массив: \n");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", array2[i]);   // И тут %c

    func(array1, array2);
}

int func(int mas1[], int mas2[])    // И здесь char
{
    int result[SIZE], nesovp = 0;
    
    printf("\nРезультат: \n");   
    
    for (int i = 0; i < SIZE; i++)
        {
            if (mas1[i] == mas2[i])
                result[i] = 1;
            else { 
                result[i] = 0;
                nesovp++; }
            
            printf("%d ", result[i]);   // Только смысл использовать символы, если их очень много, и шансов, что они совпадут почти нет
        }
        return printf("\nКол-во несовпадений: %d", nesovp);
}