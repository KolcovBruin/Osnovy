#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define K 5
#define N 5
int main( void )
{
    int x[K][N];
    int aver;
    int i, j;
    int max=0;
    int min=1000;
    int Kz1=0;
    int Nz1=0;
    int Kz2=0;
    int Nz2=0;
    srand(time(NULL));
    // массив из K на N элементов
    // ввод массива
    for( i = 0; i < K; i++ )
        for( j = 0; j < N; j++ )
            x[i][j]=rand() % 10;
    for( i = 0; i < K; i++ )
    {
        for( j = 0; j < N; j++ )
            printf("%4d ", x[i][j]);
        printf("\n");
    }
    printf("\n");
            //scanf("%d", &x[i][j]);
    // вычисление среднего арифметического значения
    aver = 0;
    for( i = 0; i < K; i++ )
    {
        for( j = 0; j < N; j++ )
        {
            if (x[i][j]>max)
            {
                max=x[i][j];
                Kz1=i;
                Nz1=j;
            }
            if(x[i][j]<min)
            {
                min=x[i][j];
                Kz2=i;
                Nz2=j;
            }
        }
    }
    if (Kz1 == Kz2)
    {
        
    // выборочное обнуление элементов
    for( j = 0; j < N; j++ )
    {
        x[Kz1][j]=0;
    }
    printf("\n");
    printf("max = %d",max);
    printf("\n");
    printf("min = %d",min);
    printf("\n");
    printf("№nyjnay stroka = %d",Kz1);
    printf("\n");
    printf("\n");
    }
    // вывод массива
    for( i = 0; i < K; i++ )
    {
        for( j = 0; j < N; j++ )
            printf("%4d ", x[i][j]);
        printf("\n");
    }
    printf("\n");
    printf("\n");
    printf("max = %d",max);
    printf("\n");
    printf("min = %d",min);
    printf("\n");
    printf("№nyjnay stroka = %d",Kz1);
    printf("\n");
    return 0; }
