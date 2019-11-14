#include <stdio.h>
#include <time.h>
#include <stdlib.h>
 #define Location_data "/Users/my/Desktop/проекты языка си/Курсач 🥰/Курсач 🥰/Data"

main ()
{
    char ad1[3] = {'b','u','x'};
     char ad2[3] = {'b','u','d'};
     char ad3[3] = {'n','e','v'};
     char ad4[3] = {'p','r','l'};
    
    int a; //для рандома
    FILE *file;
     srand(time(NULL));
    
    struct food
    {
        char Adress[3];
    
        int price;
    }shop[10];
    int b;
    for (int i = 0; i<=10; i++)
    {
        a= 1+ rand()%3;
        a=1;
        b= 10000+ rand()%35000;
        for (int j=0; j<3;j++)
        {
            (a==1)?(shop[i].Adress[j]=ad1[j]):( a==2)?(shop[i].Adress[j]=ad2[j]):(a==3)?(shop[i].Adress[j]=ad3[j]):(shop[i].Adress[j]=ad4[j]);
        }
        shop[i].price= b;
    
    }
    printf ("%i",shop[3].price );
}
