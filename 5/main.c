#include <stdio.h>
#define N 10
#include <stdlib.h>
#include <time.h>
int main( void )
{
    int x[N];// массив из N элементов
    int a1ver;
    int a2ver;
    int i;
    srand(time(NULL));
    // ввод массива
    for( i = 0; i < N; i++ )
        x[i]=1 + rand() % 10;
    for( i = 0; i < N; i++ )
        printf("%d ", x[i]);
    printf("\n");
    printf("\n");
    // вычисление значения левой и правой части
    a1ver = 0;
    for( i = 0; i < N/2; i++ )
        a1ver = a1ver + x[i];
    a2ver=0;
        for( i = N/2; i < N; i++ )
        a2ver = a2ver + x[i];
    // выборочное обнуление элементов
        if( a1ver<a2ver)
        {
        for( i = 0; i < N/2; i++ )
            x[i] = 0;
    }
    else
    {
        for( i = N/2; i < N; i++ )
            x[i] = 0;
    }
    // вывод массива
    for( i = 0; i < N; i++ )
        printf("%d ", x[i]);
    printf("\n");
    return 0; }


