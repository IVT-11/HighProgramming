#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int *A, N, M;
    
    printf("Введите N: "); scanf("%d", &N);
    A = (int *)calloc(N, sizeof(int));
    
    srand(time(NULL));
    
    for (int i = 0; i < N; i++)
        A[i] = rand() % 99;  
    
    while (1)
    {
        int swap = 0;
        
        for (int i = 0; i < N - 1; i ++)
        {
            if (A[i] > A[i + 1])
            {
                int temp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = temp;
                swap = 1;
            }
        }
        if (swap == 0)
            break;
    }
    
    for (int i = 0; i < N; i ++)
        printf("%d ", A[i]);
        
    printf("\nВведите M: "); scanf("%d", &M);
    
    A = (int*)realloc(A, N * sizeof(int) + M * sizeof(int));
    
    for (int i = N; i < M; i++)
        A[i] = rand() % 99; 
        

        for (int i = 0; i < N + M; i++)
        {
        A[i] = rand() % 99; 
        printf("%d ", A[i]);
        }

    return 0;
}
