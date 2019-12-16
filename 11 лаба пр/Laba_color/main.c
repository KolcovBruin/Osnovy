#include <stdio.h>
#define Location_data ""// "/Users/my/Desktop/Laba_color/Laba_color/main.c"
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"


int main(int argc,char *argv[])
{
//    printf("jbas \0 jabsdbc");
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
     sim=getc(in);
    int i=0;
    int j=0;
    char **string;
    string = (char**)malloc(sizeof(char*));
    *string= (char*)malloc(sizeof(char));
    while (sim!='\xff')
    {
        while (sim!='\n'&&sim!='\0')
        {
            while (sim!=' '&&sim!='\n'&&sim!='\0')
            {
                string[i][j]=sim;
                sim=getc(in);
                j++;
                string[i]=(char*)realloc(string[i],(j+2)*sizeof(char));
            }
            sim=getc(in);
            string[i][j]='\0';
            j=0;
             printf("%s\n",string[i]);
            i++;
            //string = (char**)malloc(sizeof(char*));
              string[i]=(char*)malloc(sizeof(char));
            string=(char**)realloc(string,(i+2)*sizeof(char*));
            //string=(char*)malloc(sizeof(char));
        }
        sim=getc(in);
        j=0;
        i=0;
         string = (char**)malloc(sizeof(char*));
         string[i]=(char*)malloc(sizeof(char));
    }
   
    for (int i=0;i<350;i++)
    {
    sim=getc(in);
        if (i>100)
             printf ("%s",KGRN);
        printf("%c", sim);
    }
     printf ("\n");
     printf ("%s", KNRM);
    return 0;
}
