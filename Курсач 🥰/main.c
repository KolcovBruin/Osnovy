#include <stdio.h>
#include <time.h>
#include <stdlib.h>
 #define Location_res "/Users/my/Desktop/проекты языка си/Курсач 🥰/Курсач 🥰/Res"

main ()
{
    FILE *fpout;
    char ad1[3] = {'b','u','x'};
     char ad2[3] = {'b','u','d'};
     char ad3[3] = {'n','e','v'};
     char ad4[3] = {'p','r','l'};
    char e = '2+12';
    int a; //для рандома
    FILE *file;
     srand(time(NULL));
  //  printf("%c",e);
    struct food
    {
        char Adress[3];
        
        int price;
    }shop[10];
    int b;
    for (int i = 0; i<=10; i++)
    {
        a= 1+ rand()%3;
        //a=1;
        b= 10000+ rand()%35000;
        for (int j=0; j<3;j++)
        {
            (a==1)?                                                                                     (shop[i].Adress[j]=ad1[j]): (a==2)?(shop[i].Adress[j]=ad2[j]):(a==3)?(shop[i].Adress[j]=ad3[j]):(shop[i].Adress[j]=ad4[j]);
        }
        shop[i].price= b;
    
    }
     fpout=fopen ( Location_res,"wt");
    int ce;
    char p;
    int u=0;
    int res_del;
    int del;
    int mnoj;
    for(int i=0; i<10; i++)
    {
        mnoj =10;
        del=1;
        res_del=shop[i].price;
        //shop[i].price=4;
        
       
        //fputs(shop[i].Adress,fpout);
        for (int j=0; j<3;j++)
        fprintf(fpout,"%c",shop[i].Adress[j] );
        fprintf(fpout,"  " );
        u=0;
        do
        {
            //ce= shop[i].price % 10;
            //p=ce+'0';
            //shop[i].price/=10;
            res_del/=10;
            //fprintf(fpout,"%c",p);
            u++;
        }
         while (res_del!=0);
        for (int j=0; j<u-1; j++)
        {
            del*=10;
        }
        do
        {
            ce= (shop[i].price / del)%10;
            
            p=ce+'0';
            //shop[i].price/=10;
            del/=10;
            //res_del/=10;
            fprintf(fpout,"%c",p);
            u++;
           // mnoj*=10;
        }
         while (del!=0);
        fprintf(fpout," \n");
       // fprintf(fpout,"  %c\n",p);
        //printf("%c\n",j );
        //fpritf(fpout,"%i",j);
       // fprintf(fpout, shop[i].Adress);
       // fputs("\n",fpout);
    }
   // printf ("%i",shop[3].price );
}
