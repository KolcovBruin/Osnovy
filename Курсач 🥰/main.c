#include <stdio.h>
#include <time.h>
#include <stdlib.h>
 #define Location_res "/Users/my/Desktop/проекты языка си/Курсач 🥰/Курсач 🥰/Res"
const char *perevod (int inp);
int main ()
{
    const char* ui = NULL;
    char uui;
    int raz;
    
    FILE *fpout;
    char ad1[3] = {'b','u','x'};
     char ad2[3] = {'b','u','d'};
     char ad3[3] = {'n','e','v'};
     char ad4[3] = {'p','r','l'};
    //char e = '2+12';
    int a; //для рандома
    FILE *file;
     srand(time(NULL));
    
    /*
     
     Задание рандомной БД
     
     */
    printf("Введите размер БД\n");
    scanf("%i", &raz);
    struct food
    {
        char Adress[3];
        int vlad;
        int price;
    }shop[raz];
    //int b;
    for (int i = 0; i<raz; i++)
    {
        a= 1+ rand()%3;
        //a=1;
        shop[i].price= 10000+ rand()%35000;
        for (int j=0; j<3;j++)
        {
            (a==1)?                                                                                     (shop[i].Adress[j]=ad1[j]): (a==2)?(shop[i].Adress[j]=ad2[j]):(a==3)?(shop[i].Adress[j]=ad3[j]):(shop[i].Adress[j]=ad4[j]);
        }
       // shop[i].price= b;
        shop[i].vlad= 0+ rand()%9;
    
    }
     fpout=fopen ( Location_res,"wt");
    
    /*
     
     Вывод нормальной БД в файл
     
     */
    
    /*int ce;
    char p;*/
    int u=0;
   
    int del;
    int mnoj;
    fprintf(fpout,"%s\n","Адрес   Стоимость Колво владельцев " );
    for(int i=0; i<raz; i++)
    {
        mnoj =10;
        del=1;
        
        //shop[i].price=4;
        
       
        //fputs(shop[i].Adress,fpout);
          fprintf(fpout,"  " );
        for (int j=0; j<3;j++)
        fprintf(fpout,"%c",shop[i].Adress[j] );
        fprintf(fpout,"   " );
        //u=0;
        fprintf(fpout,"  %d",shop[i].price);
        fprintf(fpout,"       " );
         fprintf(fpout,"  %d",shop[i].vlad);
         fprintf(fpout,"\n");
    }
    int delete;
    /*
     Различные пользовательские функции
     */
    printf("\nВведите номер ячейки которую нужно удалить \n");
    scanf("%i",&delete);
    int flag=0;
    for (int i = 0; i<raz; i++)
    {
        if (i==delete)
        {
            flag=1;
            raz-1;
        }
        //shop[i].Adress= shop[i+1].Adress;
        if (flag==1)
               {
                   shop[i]=shop[i+1];
                   /*   shop[i].price=shop[i+1].price;
        shop[i].vlad=shop[i+1].vlad;*/
               }
        
    }
    
    //fpout=fopen ( Location_res,"wt");
       
       /*
        
        Вывод отредактированной БД в файл
        
        */
       
       /*int ce;
       char p;*/
       //int u=0;
      
       //int del;
     //  int mnoj;
      fprintf(fpout,"\n\n\n\n\n" );
       fprintf(fpout,"%s\n","Адрес   Стоимость Колво владельцев " );
       for(int i=0; i<raz-1; i++)
       {
          // mnoj =10;
           //del=1;
           
           //shop[i].price=4;
           
          
           //fputs(shop[i].Adress,fpout);
             fprintf(fpout,"  " );
           for (int j=0; j<3;j++)
           fprintf(fpout,"%c",shop[i].Adress[j] );
           fprintf(fpout,"   " );
           //u=0;
           fprintf(fpout,"  %d",shop[i].price);
           fprintf(fpout,"       " );
            fprintf(fpout,"  %d",shop[i].vlad);
            fprintf(fpout,"\n");
       }
    
    
}
