#include <stdio.h>
#include <time.h>
#include <stdlib.h>
 #define Location_res "/Users/my/Desktop/проекты языка си/Курсач 🥰/Курсач 🥰/Res"
struct food
   {
       char Adress[3];
       int vlad;
       int price;
   };
const char *perevod (int inp);
void func_two (struct food *tpr);
void func_one (struct food *ptr, int razmer, FILE* out);
void sor_price (struct food *ptr, int razmer, FILE* out);
void find (struct food *ptr, int razmer, FILE * out);
int main ()
{
   
    
    int raz;
    FILE *fpout;
    char ad1[3] = {'b','u','x'};
    char ad2[3] = {'b','u','d'};
    char ad3[3] = {'n','e','v'};
    char ad4[3] = {'p','r','l'};

    int a; //для рандома

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
        a= 1 + rand()%3;
        //a=1;
        shop[i].price= 10000+ rand()%35000;
        for (int j=0; j<3;j++)
        {
            (a==1)?                                                                                                                          (shop[i].Adress[j]=ad1[j]):                                                                                                                        (a==2)?                                                                                                                         (shop[i].Adress[j]=ad2[j]):                                                                                                                   (a==3)?                                                                                                                         (shop[i].Adress[j]=ad3[j]):                                                                                                (shop[i].Adress[j]=ad4[j]);
        }
       // shop[i].price= b;
        shop[i].vlad= 0+ rand()%9;
    
    }
     fpout=fopen ( Location_res,"wt");
    
    /*
     
     Вывод нормальной БД в файл
     
     */
    
   
    fprintf(fpout,"%s\n","Адрес   Стоимость Колво владельцев " );
    for(int i=0; i<raz; i++)
    {
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
                                                                                                                                              (strcmp(line,"-d")==0)?                                                                                                                                        (func_one(&shop,raz-1, fpout)):                                                                                                                       (strcmp(line,"-sr")==0)?                                                                                                                      (printf("sr\n")):                                                                                                                                            (strcmp(line,"-sn")==0)?                                                                                                                      (printf("sn\n")):                                                                                                                                           (strcmp(line,"-f")==0)?                                                                                                                      (find(&shop,raz, fpout)):                                                                                                                                            (strcmp(line,"-so")==0)?                                                                                                                     (sor_price(&shop,raz, fpout)): NULL ;
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
void func_one (struct food *ptr, int razmer, FILE * out)
{
      fprintf(out,"\n\n\n\n\nКееееек\n" );
    int delete;
    
     int flag=0;
    struct food *ptr_1;
     struct food *ptr_2;
    ptr_1=ptr;
    ptr_2=ptr;
    ptr_1++;
    printf("\nВведите номер ячейки которую нужно удалить \n");
            scanf("%i",&delete);
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
  
         fprintf(out,"\n\n\n\n\n" );
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
      fprintf(out,"\n\n\n\n\nКееееек\n" );
    int delete;
    
    int buf_1=0;
    int buf_2=0;
    int buf_3=0;
     int flag=0;
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
                    buf_3=ptr_2->price;
                    jj=j;
                    buf_1=ptr_1->price;
                    ptr_1->price=ptr_2->price;
                    do
                    {
                        ptr_1++;
                        buf_2=ptr_1->price;
                        ptr_1->price=buf_1;
                        buf_1=buf_2;
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
  
         fprintf(out,"\n\n\n\n\n" );
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
    fprintf(out,"\n\n\n\n\nКЕК\n" );
    
    printf("\nвведите данные для поиска по неполному совпадению\n");
    scanf("%s",&fin);
    
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
