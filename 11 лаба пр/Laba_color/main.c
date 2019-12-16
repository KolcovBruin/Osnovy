#include <stdio.h>
#include <stdlib.h>
#define Location_data ""// "/Users/my/Desktop/Laba_color/Laba_color/main.c"
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#define jkl 7.7
int main(int argc,char *argv[])
{
    /*
       7.7
       */
    printf ("%f", 7.7 );
    //7.7
    float a= 7.7 ;
    printf(" 7.7 %f", 7.7 );
//    printf("jbas  jabsdbc");
//    printf ("%s",KRED);
    FILE *in;
    if (Location_data!="")
        {
    in = fopen(Location_data, "rt" ); //открытие файла для чтения
        }
        else in = fopen(argv[1], "rt" );
        if( in == NULL )//если не удалось открыть файл или он пустой
        {printf("Возможно Вы не ввели адрес файла с данными.\n Это можно сделать через входные аргменты или задать адрес в константы в начале программы. \n Location_data - константа содержащая адрес файла с данными. \n Location_res - константа содержащая адрес файла для вывода строк. \n Чтобы внести входные аргументы: \n Windows: открываем консоль запускаем файл exe нашего проека и через пробел к нему прописываем входные параметры.\n Пример: 9 Laba it.exe Location_data Location_res \n MAC OS: Комбинация клавишь Cmd и <  затем  первым параметром вводить Location_data, вторым  Location_res \n");
             printf ("%s", KNRM);
            return 0;}
     char sim;
    // sim=getc(in);
    int i=0;
    int j=0;
    char **string;
    string = (char**)malloc(sizeof(char*));
    *string= (char*)malloc(sizeof(char));
  

    int dot_pos=0;
    int cmt_pos_1=0;
     int cmt_pos_2=0;
    int cmt_2_pos_1=0;
    int cmt_2_pos_2=0;
    int flag_dot=0;// на точку
    int flag_brkt=0;//на скобку
   
    int flag_cmt_1=0;//на закомментированнойсть текста //
     int flag_cmt_2=0;//на закомментированнойсть текста /* */
    int flag_true=0;//выполнение условия для вещ конст
   do
    {
       do
        {
        do
            {
                 sim=getc(in);
                string[i][j]=sim;
               if (sim=='.')
               {
                   flag_dot=1;
                   dot_pos=j;
               }
            if (sim =='/'&& flag_cmt_2!=3 )
            {
               // flag_cmt_2=1;
                cmt_2_pos_1=j;
            }
                if (sim=='*'&&j==cmt_2_pos_1+1)
                {
                    flag_cmt_2=2;
                    cmt_2_pos_1=j;
                }
                if (sim=='*'&&flag_cmt_2==2&&cmt_2_pos_1!=j)
                {
                    cmt_2_pos_2=j;
                    flag_cmt_2=3;
                }
                if (sim=='/'&&j==cmt_2_pos_2+1&&  flag_cmt_2==3)
                    flag_cmt_2=0;
//                if (sim=='"'&&flag_brkt==1)
//                    flag_brkt=0;
//                if (sim=='"')
//                  flag_brkt=1;
//                if (sim =='/'&&flag_cmt_1==1)
//                    flag_cmt_1=2;
                if (sim=='/'&&flag_cmt_1!=1)
                {
                    flag_cmt_1=1;
                    cmt_pos_1=j;
                    cmt_pos_2=i;
                    
                }
                if (sim == '"'&&flag_brkt==1)
                    flag_brkt=2;
                if (sim=='"'&&flag_brkt!=2)
                    flag_brkt=1;
                
                    
//                if (sim=='/')
//                flag_cmt_2=1;
//                if (sim=='*'&&flag_cmt_2==1)
//                    flag_cmt_2=2;
//               // else flag_cmt_2=0;
//                if (sim=='*'&&flag_cmt_2==2)
//                    flag_cmt_2=3;
//                if (sim=='/'&&flag_cmt_2==3)
//                    flag_cmt_2=0;
                j++;
                string[i]=(char*)realloc(string[i],(j+2)*sizeof(char));
            }
            while (sim!=' '&&sim!='\xff'&&sim!='\n'&&sim!='\0'&&sim!=';');
            
            string[i][j]='\0';
           
            
            if (  flag_dot==1 && string[i][dot_pos+1]>='0' && string[i][dot_pos+1]<='9'  &&    string[i][dot_pos-1]>='0' && string[i][dot_pos-1]<='9')
                flag_true=1;
            flag_dot=0;
            if (flag_cmt_1==1&&string[cmt_pos_2][cmt_pos_1+1]=='/')
                flag_true=0;
            if (flag_brkt==1)
                 flag_true=0;
            if (flag_cmt_2!=0)
                 flag_true=0;
           // flag_brkt=0;
//            flag_cmt_1=0;
            //sim=getc(in);
            
            j=0;
            if (flag_true==1)
            {
                printf ("%s",KRED);
            printf("%s",string[i]);
            printf ("%s",KNRM);
            }
            else  printf("%s",string[i]);
             
            flag_true=0;
            i++;
            //string = (char**)malloc(sizeof(char*));
              string[i]=(char*)malloc(sizeof(char));
            string=(char**)realloc(string,(i+2)*sizeof(char*));
            //string=(char*)malloc(sizeof(char));
        }
        while (sim!='\n'&&sim!='\xff'&&sim!='\0');
        flag_cmt_1=0;
        flag_brkt=0;  // !!!!!!
       // sim=getc(in);
        
        j=0;
        i=0;
        //string=(char**)realloc(string,1*sizeof(char*));
//         string = (char**)malloc(sizeof(char*));
//         string[i]=(char*)malloc(sizeof(char));
        //printf("%s",KRED);
    }
    while (sim!='\xff');
   
    return 0;
}

