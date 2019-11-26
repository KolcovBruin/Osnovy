#include <stdio.h>
#include <time.h>
#include <stdlib.h>
 #define Location_res "/Users/my/Desktop/проекты языка си/Курсач 🥰/Курсач 🥰/Result"
#define Location_bd "/Users/my/Desktop/проекты языка си/Курсач 🥰/Курсач 🥰/Data_ base"
#define Location_buf "/Users/my/Desktop/проекты языка си/Курсач 🥰/Курсач 🥰/Buffer"
struct food
   {
       char Adress[3];
       int vlad;
       int price;
   };
const char *perevod (int inp);
void preobr(char c); //перевод из чара в инт
void out (struct food *ptr, int razmer, FILE* out);//вывод // fpout_1
void in (struct food *ptr, int razmer, FILE* out);//считывание из файла // в тернарке сделать выбор на считывание исхожной бд, те ту которую мы либо сами написали, либо рандом
void sch (struct food *ptr, int razmer, FILE* out);//поиск //fpout_1
void rnd (struct food *ptr, int razmer, FILE* out);//рандомное задание новой БД //fpout_2
void func_two (struct food *tpr);
void del (struct food *ptr, int razmer, FILE* out);//удаление строки //fpout_1
void sor_price (struct food *ptr, int razmer, FILE* out);//сортировка по стоимости //fpout_1
void find (struct food *ptr, int razmer, FILE * out);//поиск по неполному совпадению  //fpout_1
int main ()
{
   
    
    int raz;
    FILE *fpout_1;
    FILE *fpout_2;
    FILE *fpout_3;
   
//    char ad1[3] = {'b','u','x'};
//    char ad2[3] = {'b','u','d'};
//    char ad3[3] = {'n','e','v'};
//    char ad4[3] = {'p','r','l'};

   // int a; //для рандома

     //srand(time(NULL));
    
    /*
     
     Задание рандомной БД
     
     */
    // Искать Здесь
    printf("Введите размер БД\n");
    scanf("%i", &raz);
////    raz=10;
    struct food
    {
        char Adress[3];
        int vlad;
        int price;
    }bd[raz];

//     fpout_1=fopen ( Location_res,"a+");
//    fpout_2=fopen(Location_bd,"wt");
    fpout_1=fopen(Location_res,"r+");
     fpout_2=fopen(Location_bd,"r+");
     fpout_3=fopen(Location_buf,"r+");
    //fpin_2=fopen(Location_bd,"rt");
    /*
     
     Вывод нормальной БД в файл
     
     */
    
   
//    fprintf(fpout,"%s\n","Адрес   Стоимость Колво владельцев " );
//    for(int i=0; i<raz; i++)
//    {
//          fprintf(fpout,"  " );
//        for (int j=0; j<3;j++)
//        fprintf(fpout,"%c",shop[i].Adress[j] );
//        fprintf(fpout,"   " );
//        //u=0;
//        fprintf(fpout,"  %d",shop[i].price);
//        fprintf(fpout,"       " );
//         fprintf(fpout,"  %d",shop[i].vlad);
//         fprintf(fpout,"\n");
//    }
    char line[3];
    int l;
    printf("База данных заданного размера создана.");
    func:
    printf("                                                              \nВы можете выполнить некоторые действия с данной базой данных: \n"                                                  "-Закончить выолнение любых действий - введите '-e';\n"                                                                                                     "-Удалить строку по её номеру - введите '-d';\n"                                                                                                           "-Добавить новую строку: \n"                                                                                                                               "-рандомная строка - введите '-sr' \n"                                                                                                                     "-свою строку - введите '-sn'; \n"                                                                                                                          "-Найти строку по неполному совпадения - введите '-f'; \n"                                                                                                  "-Отсортировать массив(после выбора данной функции будет получена расширенная инструкция) - введите '-so'\n");
   
//    func_two(&shop);
//    printf("  %d",shop[0].price);
//     printf("  %d",shop[1].price);
//    printf("  %d",shop[1].price);
    scanf("%s",&line);
   //  printf("  %d",shop[0].price);
    (strcmp(line,"-d")==0)?                                                                                                                                    (del(&bd,raz-1, fpout_1)):                                                                                                                       (strcmp(line,"-sr")==0)?                                                                                                                  (printf("sr\n")):                                                                                                                                            (strcmp(line,"-sn")==0)?                                                                                                                      (printf("sn\n")):                                                                                                                                           (strcmp(line,"-f")==0)?                                                                                                                      (find(&bd,raz, fpout_1)):                                                                                                                                            (strcmp(line,"-so")==0)?                                                                                                             (sor_price(&bd,raz, fpout_1)):                                                                                                    (strcmp(line,"-rn")==0)?                                                                                                                        (rnd(&bd,raz, fpout_1)):                                                                                                                        (strcmp(line,"-ot")==0)?                                                                                                                       (out(&bd,raz, fpout_3)):                                                                                                                       (strcmp(line,"-in")==0)?                                                                                                                       (in(&bd,raz, fpout_2)):                                                                                                                            NULL ;
    if (strcmp(line,"-e")==0)
        goto end;
    goto func;
    end:
    printf("");

}
void func_two (struct food *tpr)
{
    struct food *tpr_1;
    tpr_1=tpr;
    tpr_1++;
    tpr->price=tpr_1->price;
}
void del (struct food *ptr, int razmer, FILE * out)
{
    
      
    int delete;
    
     int flag=0;
    struct food *ptr_1;
     struct food *ptr_2;
    ptr_1=ptr;
    ptr_2=ptr;
    ptr_1++;
    printf("\nВведите номер ячейки которую нужно удалить \n");
            scanf("%i",&delete);
    fprintf(out,"\nУдаляем строку по номеру %i\n", delete );
    for (int i = 0; i<razmer; i++)
             {
                 if (i==delete)
                 {
                     flag=1;
                 }
                 if (flag==1)
                 {
                  for (int j=0; j<3;j++)
                      ptr_2->Adress[j]=ptr_1->Adress[j];
                     ptr_2->price=ptr_1->price;
                     ptr_2->vlad=ptr_1->vlad;
                 }
                 ptr_2++;
                 ptr_1++;
             }
  
         fprintf(out,"\n" );
         fprintf(out,"%s\n","Адрес   Стоимость Колво владельцев " );
   
          for (int i = 0; i<razmer; i++)
          {
              
              fprintf(out,"  " );
              for (int j=0; j<3;j++)
              fprintf(out,"%c",ptr->Adress[j] );
              fprintf(out,"   " );
              //u=0;
              fprintf(out,"  %d",ptr->price);
              fprintf(out,"       " );
               fprintf(out,"  %d",ptr->vlad);
               fprintf(out,"\n");
              ptr++;
          }
}


/*
 Сортровка
 */


void sor_price (struct food *ptr, int razmer, FILE * out)
{
      fprintf(out,"\nСортировка строк по стоимости\n" );
    int delete;
    
    int buf_1=0;
    int buf_2=0;
    int buf_3=0;
    int buf_4=0;
    char buf_c1[3];
     char buf_c2[3];
    // int flag=0;
    struct food *ptr_1;
     struct food *ptr_2;
    ptr_1=ptr;
    ptr_2=ptr;
    ptr_2++;
    //printf(ptr->price);
    int cnt=0;
//    printf("\nВведите номер ячейки которую нужно удалить \n");
//            scanf("%i",&delete);
    int j;
    int jj;
    for (int i = 0; i<razmer; i++)
             {
                 for(j=0;j<razmer;j++)
                 {
                     
                if(ptr_1->price<ptr_2->price)
                {
                    
                    //buf_3=ptr_2->price;
                    for(int a=0;a<3;a++)
                    {
                        buf_c1[a]=ptr_1->Adress[a];
                    }
                    buf_3=ptr_1->vlad;
                    jj=j;
                    buf_1=ptr_1->price;
                    ptr_1->price=ptr_2->price;
                    ptr_1->vlad=ptr_2->vlad;
                    for(int a=0;a<3;a++)
                    {
                        ptr_1->Adress[a]=ptr_2->Adress[a];
                    }
                    do
                    {
                        ptr_1++;
                        buf_2=ptr_1->price;
                        buf_4=ptr_1->vlad;
                        for(int a=0;a<3;a++)
                        {
                            buf_c2[a]=ptr_1->Adress[a];
                        }
                        ptr_1->price=buf_1;
                         ptr_1->vlad=buf_3;
                        for(int a=0;a<3;a++)
                        {
                            ptr_1->Adress[a]=buf_c1[a];
                        }
                        buf_1=buf_2;
                        buf_3=buf_4;
                        for(int a=0;a<3;a++)
                        {
                            buf_c1[a]=buf_c2[a];
                        }
//                        ptr_1++;
//                        buf_1=buf_2;
//                        ptr_1->price=buf_1;
//                        buf_1=buf_2;
                    }
                    while (ptr_1!=ptr_2);
                    /* for (int j=0; j<3;j++)
                      ptr_2->Adress[j]=ptr_1->Adress[j];*/
//                    buf=ptr_1->price;
//                    ptr_1->price=ptr_2->price;
//                    ptr_2->price=buf;
                    // ptr_2->vlad=ptr_1->vlad;
                    break;
                }
                     if(j==razmer-1)
                     {
                         ptr_1++;
                         ptr_2=ptr;
                         cnt++;
                         // ptr_2++;
                         j=0;
                         //i++;
                         for(int r=0;r<cnt;r++)
                         {ptr_2++;
                             j++;
                         }
                     }
                     ptr_2++;
                     //ptr_1++;
                     
                     
                 }
                 cnt=0;
                 ptr_1=ptr;
                 ptr_2=ptr;
                 ptr_2++;
                 
             }
  
         fprintf(out,"\n" );
         fprintf(out,"%s\n","Адрес   Стоимость Колво владельцев " );
   
          for (int i = 0; i<razmer; i++)
          {
              
              fprintf(out,"  " );
              for (int j=0; j<3;j++)
              fprintf(out,"%c",ptr->Adress[j] );
              fprintf(out,"   " );
              //u=0;
              fprintf(out,"  %d",ptr->price);
              fprintf(out,"       " );
               fprintf(out,"  %d",ptr->vlad);
               fprintf(out,"\n");
              ptr++;
          }
}
void find (struct food *ptr, int razmer, FILE * out)
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
         printf("  %d",ptr->vlad);
         printf("\n");
           
            fprintf(out,"  " );
            for (int j=0; j<3;j++)
            fprintf(out,"%c",ptr->Adress[j] );
            fprintf(out,"   " );
            //u=0;
            fprintf(out,"  %d",ptr->price);
            fprintf(out,"       " );
             fprintf(out,"  %d",ptr->vlad);
             fprintf(out,"\n");
            
        }
        cnt=0;
        ptr++;
    }
         
}
void rnd (struct food *ptr, int razmer, FILE* out)
{
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
            a= 1 + rand()%4;
    //        //a=1;
            ptr->price= 10000+ rand()%35000;
            for (int j=0; j<3;j++)
           {
                (a==1)?                                                                                                                          (ptr->Adress[j]=ad1[j]):                                                                                                                        (a==2)?                                                                                                                         (ptr->Adress[j]=ad2[j]):                                                                                                                   (a==3)?                                                                                                                         (ptr->Adress[j]=ad3[j]):                                                                                                  (ptr->Adress[j]=ad4[j]);
           }
           ptr->vlad= 0+ rand()%9;
           ptr++;
      }
        
}
void out (struct food *ptr, int razmer, FILE* out)
{
   // fprintf(out,"\n" );
           // fprintf(out,"%s\n","Адрес   Стоимость Колво владельцев " );
      
             for (int i = 0; i<razmer; i++)
             {
                 
                 fprintf(out," ." );
                 for (int j=0; j<3;j++)
                 fprintf(out,"%c",ptr->Adress[j] );
                 fprintf(out,"   " );
                 //u=0;
                 fprintf(out,"  %d.",ptr->price);
                 fprintf(out,"       " );
                  fprintf(out,"  %d",ptr->vlad);
                  fprintf(out,".\n");
                 ptr++;
             }
}
void in (struct food *ptr, int razmer, FILE* out)
{
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
                        ptr->Adress[j]=sim;
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
                            ptr->price=e;
                        
                    }
                    }
                    

                    while(sim>='0'&&sim<='9')
                    {
                        e*=10;
                        e+=(int)(sim)-'0';
                        sim=fgetc(out);
                        if(sim=='.')
                            ptr->vlad=e;
                    }
                     
                    
                }
            sim=fgetc(out);
        }
            ptr++;
            toc='\0';
             sim=fgetc(out);
    }
 }
    

void oforml(FILE* out)
{
    fprintf(out,"%s\n","Адрес   Стоимость Колво владельцев " );
}
//save
