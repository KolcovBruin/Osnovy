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
    //func:
    printf("База данных заданного размера создана. \nВы можете выполнить некоторые действия с данной базой данных: \n"                                                  "-Закончить выолнение любых действий - введите '-e';\n"                                                                                                     "-Удалить строку по её номеру - введите '-d';\n"                                                                                                           "-Добавить новую строку: \n"                                                                                                                               "-рандомная строка - введите '-sr' \n"                                                                                                                     "-свою строку - введите '-sn'; \n"                                                                                                                          "-Найти строку по неполному совпадения - введите '-f'; \n"                                                                                                  "-Отсортировать массив(после выбора данной функции будет получена расширенная инструкция) - введите '-so'\n");
//    printf("  %d",shop[0].price);
//    func_two(&shop);
//    printf("  %d",shop[0].price);
//     printf("  %d",shop[1].price);
//    printf("  %d",shop[1].price);
    scanf("%s",&line);
    (strcmp(line,"-e")==0)?                                                                                                                                             (printf("end\n")):                                                                                                                                           (strcmp(line,"-d")==0)?                                                                                                                                        (func_one(&shop,raz-1, fpout)):                                                                                                                       (strcmp(line,"-sr")==0)?                                                                                                                      (printf("sr\n")):                                                                                                                                            (strcmp(line,"-sn")==0)?                                                                                                                      (printf("sn\n")):                                                                                                                                           (strcmp(line,"-f")==0)?                                                                                                                      (printf("f\n")):                                                                                                                                            (strcmp(line,"-so")==0)?                                                                                                                     (printf("so\n")): NULL ;
    //goto func;
    printf("  %d",shop[1].price);
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
