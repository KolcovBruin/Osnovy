#pragma warning(disable : 4996)

#include <stdio.h>
int main(void)
{
    unsigned long long int z=0;//число и результат после маски
    int l;
    //int y;
    int n=0;//счетчик байтов
    int mask=1;//маска
    int ctr=0;//счетчик единиц
    int i=0;//счетчик битов
    
    printf("z = ");
    scanf("%llx", &z);
   // y = /*(unsigned int)*/z;
    while(z!=0&&n<64)//нахождение внутри значащей части числа
    {
        l=z&mask;//маска
        printf("%d",l);//вывод бита
        if(l==1)//нахождение единицы
        {
            ctr++;
        }
        z>>=1;//сдвиг на один бит
        i++;//++бит до байта
        n++;//++бит
        if(i==8)//проверка на байт
        {
            printf(" ctr=%d\n",ctr);//вывод колва единиц
            i=0;
            ctr=0;
        }
    }
    while(n<64)//проверка на нахождение внутри длинного числа
    {
        l=z&mask;//маска
        printf("%d",l);//вывод числа под маской
        z>>=1;//сдвиг вправо
        i++;
        n++;
        if(i==8)
        {
            printf(" ctr=%d\n",ctr);
            i=0;
            ctr=0;
        }
    }
    return 0;
}
