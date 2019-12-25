#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
 //#include "curses.h"
//#include < curses.h >
 #define Location_res "/Users/my/Desktop/проекты языка си/Курсач 🥰/Курсач 🥰/Result"
#define Location_bd "/Users/my/Desktop/проекты языка си/Курсач 🥰/Курсач 🥰/Data_ base"
#define Location_buf "/Users/my/Desktop/проекты языка си/Курсач 🥰/Курсач 🥰/Buffer"
struct Flat
   {
       char Adress[3];
       int owner;
       int price;
   };

//enum function {ened,rndom,dele,sech,srap,srva,new};
void find (struct Flat *ptr, int razmer, FILE * out);//поиск по неполному совпадению  //fpout_1//++
void new_flat (struct Flat *ptr, int razmer, FILE* out);//+-

int size(FILE* out); //++

void out (struct Flat *ptr, int razmer, FILE* out);//вывод // fpout_1 //++
void in (struct Flat *ptr, int razmer, FILE* out);//считывание из файла // в тернарке сделать выбор на считывание исхожной бд, те ту которую мы либо сами написали, либо рандом  //++

void rnd (struct Flat *ptr, int razmer, FILE* out);//рандомное задание новой БД //fpout_2  //++


void del (struct Flat *ptr, int razmer, FILE* out);//удаление строки //fpout_1 //++
void sor_price (struct Flat *ptr, int razmer, FILE* out);//сортировка по стоимости //fpout_1 //+-
void sor_adress (struct Flat *ptr, int razmer, FILE* out);//сортировка по стоимости //fpout_1 //+-
int main ()
{
   
    
    int raz;
    FILE *fpout_1;
    FILE *fpout_2;
    FILE *fpout_3;

    //struct Flat bd;
    struct Flat *BD;

     fpout_3=fopen(Location_buf,"r");//buffer
   raz= size(fpout_3);
    fclose(fpout_3);
   
    BD=(struct Flat*)malloc((raz)*sizeof(struct Flat));

    
    //char line[3];
   // int l;
    printf("База данных заданного размера создана.");
    enum function {
        end=1,
        random,
        delete,
        search,
        sort_P,
        sort_A,
        new,
        release=100
        } user;
     
    user=release;
    while(user-1)
    {
    //system("clear");
   // erase();
     printf("\nМеню:\n"                                                                                                                                                   "1 - выйти из программы\n"                                                                                                                                  "2 - Задать базу данных рандомно \n"                                                                                                      "3 - удалить строку по номеру\n"                                                                                                                           "4 - поиск по неполному совпадению\n"                                                                                                                      "5 - сортировка по уменшению стоимости\n"                                                                                                                  "6 - сортировка в алфавитном порядке по Адресам\n"                                                                                                         "7 - Добавление новой строки\n");
    scanf("%i",&user);
    switch (user) {
        case end:
            printf("1\n");
            break;
            case random:
                       printf("2\n");
            fpout_3=fopen(Location_buf, "w");
            rnd(BD,raz, fpout_3);
            fclose(fpout_3);
            fpout_3=fopen(Location_buf,"r");//buffer
              raz= size(fpout_3);
               fclose(fpout_3);
             BD=(struct Flat*)realloc(BD,(raz)*sizeof(struct Flat));
            fpout_3=fopen(Location_buf, "r");
            in(BD,raz, fpout_3);
            fclose(fpout_3);
            
            fpout_1=fopen(Location_res, "r+");
            out(BD,raz, fpout_1);
            fclose(fpout_1);

                       break;
            case delete:
                       printf("3\n");
            fpout_3=fopen(Location_buf, "r");
            in(BD,raz, fpout_3);
            fclose(fpout_3);
             fpout_3=fopen(Location_buf, "w");
            del(BD, raz, fpout_3);
            fclose(fpout_3);
            raz--;
            BD=(struct Flat*)realloc(BD,(raz)*sizeof(struct Flat));
            fpout_3=fopen(Location_buf, "r");
            in(BD,raz, fpout_3);
            fclose(fpout_3);
            fpout_1=fopen(Location_res, "r+");
            out(BD,raz, fpout_1);
            fclose(fpout_1);
                       break;
            case search:
                       printf("4\n");
            fpout_3=fopen(Location_buf, "r");
            in(BD,raz, fpout_3);
            fclose(fpout_3);
            fpout_3=fopen(Location_buf, "r");
            find(BD, raz, fpout_3);
            fclose(fpout_3);
         
                       break;
            case sort_P:
                       printf("5\n");
            fpout_3=fopen(Location_buf, "r");
            in(BD,raz, fpout_3);
            fclose(fpout_3);
            fpout_3=fopen(Location_buf, "r");
            sor_price(BD, raz, fpout_3);
            fclose(fpout_3);

            fpout_3=fopen(Location_buf, "w");
            out(BD,raz, fpout_3);
            fclose(fpout_3);
            
                       break;
            case sort_A:
                       printf("6\n");
            fpout_3=fopen(Location_buf, "r");
            in(BD,raz, fpout_3);
            fclose(fpout_3);
            fpout_3=fopen(Location_buf, "r");
            sor_adress(BD, raz, fpout_3);
            fclose(fpout_3);
            fpout_1=fopen(Location_res, "r+");
            out(BD,raz, fpout_1);
            fclose(fpout_1);
            fpout_3=fopen(Location_buf, "w");
            out(BD,raz, fpout_3);
            fclose(fpout_3);
                       break;
            case new:
        {
            
                       printf("7\n");
            fpout_3=fopen(Location_buf, "r");
            in(BD,raz, fpout_3);
            fclose(fpout_3);
            fpout_3=fopen(Location_buf, "w");
            new_flat(BD,raz, fpout_3);
            fclose(fpout_3);
            raz++;
             BD=(struct Flat*)realloc(BD,(raz)*sizeof(struct Flat));
             fpout_3=fopen(Location_buf, "r");
            in(BD,raz, fpout_3);
            fclose(fpout_3);
            fpout_3=fopen(Location_buf, "w");
            out(BD,raz, fpout_3);
            fclose(fpout_3);
            
        }
           // new(
                       break;
        default:
            break;
    }
 
    }
    

}


void del (struct Flat *ptr, int razmer, FILE * out)
{
    
      
    int delete=0;
    
 
   
    
    printf("\nВведите номер ячейки которую нужно удалить \n");
            scanf("%i",&delete);
   /// fprintf(out,"\nУдаляем строку по номеру %i\n", delete );
    for (int i = 0; i<razmer; i++)
             {
                 if (i==delete)
                 {
                     ptr++;
                     i++;
                 }
                 fprintf(out," ." );
                 for (int j=0; j<3;j++)
                 fprintf(out,"%c",ptr->Adress[j] );
                 fprintf(out,"   " );
                 //u=0;
                 fprintf(out,"  %d.",ptr->price);
                 fprintf(out,"       " );
                  fprintf(out,"  %d",ptr->owner);
                  fprintf(out,".\n");
                 ptr++;
             }
  
         
}



void find (struct Flat *ptr, int razmer, FILE * out)
{
    char fin[3];
    int e=0;
   
    
    printf("\nвведите данные для поиска по неполному совпадению\n");
    scanf("%s",&fin);
     fprintf(out,"\nПоиск срок по неполному совпадению с %s\n", fin );
    
    while (fin[e]!='\0')
        e++;
     fprintf(out,"%s\n","Адрес   Стоимость Колво владельцев " );
    printf("Адрес   Стоимость Колво владельцев \n" );
    int cnt=0;
    for(int i=0;i<razmer;i++)
    {
        for(int d=0;d<e;d++)
        {
            for( int j=0;j<3;j++)
            {
                (ptr->Adress[j]==fin[d])?(cnt++):NULL;
            }
        }
        if (cnt==e)
        {
            
        printf("  " );
        for (int j=0; j<3;j++)
        printf("%c",ptr->Adress[j] );
        printf("   " );
        //u=0;
        printf("  %d",ptr->price);
        printf("       " );
         printf("  %d",ptr->owner);
         printf("\n");
           
            fprintf(out,"  " );
            for (int j=0; j<3;j++)
            fprintf(out,"%c",ptr->Adress[j] );
            fprintf(out,"   " );
            //u=0;
            fprintf(out,"  %d",ptr->price);
            fprintf(out,"       " );
             fprintf(out,"  %d",ptr->owner);
             fprintf(out,"\n");
            
        }
        cnt=0;
        ptr++;
    }
         
}
void rnd (struct Flat *ptr, int razmer, FILE* out)
{
     printf("рандом\n");
    int a=0;
    int raz=0;
    srand(time(NULL));
        char ad1[3] = {'b','u','x'};
        char ad2[3] = {'b','u','d'};
        char ad3[3] = {'n','e','v'};
        char ad4[3] = {'p','r','l'};
        printf("Введите размер БД\n");
        scanf("%i", &raz);
    for (int i = 0; i<raz; i++)
       {
            a= 1 + rand()%3;
          // printf("%i\n",a);
    //        //a=1;
           fprintf(out," ." );
           for(int j=0;j<3;j++)
           a==1?fprintf(out,"%c",ad1[j]):a==2?fprintf(out,"%c",ad2[j]):a==3?fprintf(out,"%c",ad3[j]):fprintf(out,"%c",ad4[j]);
            fprintf(out,"     " );
           fprintf(out,"%i.",10000+ rand()%35000);
          // printf("%i.",10000+ rand()%35000);
            fprintf(out,"         " );
            fprintf(out,"%i.\n",0+ rand()%9);
       }
}
void out (struct Flat *ptr, int razmer, FILE* out)
{
             for (int i = 0; i<razmer; i++)
             {
                 
                 fprintf(out," ." );
                 for (int j=0; j<3;j++)
                 fprintf(out,"%c",ptr->Adress[j] );
                 fprintf(out,"   " );
                 //u=0;
                 fprintf(out,"  %d.",ptr->price);
                 fprintf(out,"       " );
                  fprintf(out,"  %d",ptr->owner);
                  fprintf(out,".\n");
                 ptr++;
             }
}
void in (struct Flat *ptr, int razmer, FILE* out)
{
    int cnt=0;
    char sim;
        //внутри БД
    sim=fgetc(out);
        char toc='\0';
        while (sim!=EOF)
        {
        while(sim!='\n')
        {
            
            //внутри строки
            
              //  по символьно
                if((sim>='A'&&sim<='Z')||(sim>='a'&&sim<='z'))
                {
                    for (int j=0;j<3;j++)
                    {
                        ptr[cnt].Adress[j]=sim;
                        sim=fgetc(out);
                    }
                }
                else
                {
                    int e=0;
                    
                    if (toc!='.')
                    {
                    while(sim>='0'&&sim<='9')
                    {
                        e*=10;
                        e+=(int)(sim)-'0';
                        sim=fgetc(out);
                        if((toc=sim)=='.')
                            ptr[cnt].price=e;
                        
                    }
                    }
                    

                    while(sim>='0'&&sim<='9')
                    {
                        e*=10;
                        e+=(int)(sim)-'0';
                        sim=fgetc(out);
                        if(sim=='.')
                            ptr[cnt].owner=e;
                    }
                     
                    
                }
            sim=fgetc(out);
            
        }
            cnt++;
           // ptr++;
            toc='\0';
             sim=fgetc(out);
    }
 }
    

void oforml(FILE* out)
{
    fprintf(out,"%s\n","Адрес   Стоимость Колво владельцев " );
}
//save

int size(FILE* out)
{
    char sim='\0';
    int raz=0;
    do {
        sim=getc(out);
        if (sim =='\n')
            raz++;
    } while (sim!='\xff');
    return raz;
}
void new_flat (struct Flat *ptr, int razmer, FILE* out)
{
    printf("Введите номер строки, которую хотите добавить\n");
    int str=0;
    char adr_str[4];
    for(int i=0;i<3;i++)
        adr_str[i]='\0';
    char *adr=adr_str;
    int inp=0;
    scanf("%i",&str);
    for (int i = 0; i<razmer; i++)
                {
                    if (i==str)
                    {
                       printf("Введите адрес новой квартиры\n");
                        scanf("%s",adr);
                        adr[4]='\0';
                        fprintf(out," .%s", adr);
                         fprintf(out,"   " );
                        printf("Введите стоимость новой квартиры\n");
                         scanf("%d",&inp);
                          fprintf(out,"  %d.",inp);
                        fprintf(out,"       " );
                        printf("Введите кол-во владельцев квартиры\n");
                         scanf("%d",&inp);
                          fprintf(out,"  %d.\n",inp);
                    }
                    fprintf(out," ." );
                    for (int j=0; j<3;j++)
                    fprintf(out,"%c",ptr->Adress[j] );
                    fprintf(out,"   " );
                    //u=0;
                    fprintf(out,"  %d.",ptr->price);
                    fprintf(out,"       " );
                     fprintf(out,"  %d",ptr->owner);
                     fprintf(out,".\n");
                    ptr++;
                }
}
 

void sor_price (struct Flat *ptr, int razmer, FILE * out)
{
    struct Flat buf;
    
    for(int j=0;j<(razmer);j++)
    {
        for(int i=0;i<(razmer);i++)
        {
      if(ptr[j].price>ptr[i].price)
      {
          //printf("%i  %i",ptr[j].price,ptr[i].price);
          buf=ptr[j];
          ptr[j]=ptr[i];
          ptr[i]=buf;
        //  printf("%i  %i",ptr[j].price,ptr[i].price);
      }
        }
    }
}
void sor_adress (struct Flat *ptr, int razmer, FILE * out)
{
    struct Flat buf;
    
    for(int j=0;j<(razmer);j++)
    {
        for(int i=0;i<(razmer);i++)
        {
      if((strcmp(ptr[j].Adress, ptr[i].Adress))<0)
      {
         // printf("%i  %i",ptr[j].price,ptr[i].price);
          buf=ptr[j];
          ptr[j]=ptr[i];
          ptr[i]=buf;
          //printf("%i  %i",ptr[j].price,ptr[i].price);
      }
        }
    }
}
