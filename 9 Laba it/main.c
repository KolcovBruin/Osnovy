#include <stdio.h>
#define MAXLINE 1024
#define Location_data ""
#define Location_res ""
int main(int argc,char *argv[] ) //программа получает входные аргументы
{
    printf ("%s\n",Location_data);
    printf ("%s\n",argv[0]);
    printf ("%s\n",argv[1]);
    printf ("%s\n",argv[2]);
    int flag=0;//повтор разделителей
    int cnt=0;// счётчик слов
    int max_cnt=0;//число слов в самой длинной строке
    int n_str=0;//номер строки в которой определили число слов
    int rgt=0;//номер нужной строки
FILE *fpin;//для считывания информации из файла
FILE *fpout;//для записи информации из файла
char line[MAXLINE];//считанная строка
   char *ptr;//указатель на строку
    if (Location_data!="")
    {
fpin = fopen( Location_data, "rt" ); //открытие файла для чтения
    }
    else fpin = fopen( argv[1], "rt" );
    if( fpin == NULL )//если не удалось открыть файл или он пустой
return 0;
while( !feof( fpin ) ) //конец файла
{
ptr = fgets( line, MAXLINE, fpin );//?? //считывание строки
if( ptr == NULL ) //если "нет" строки
break;
while( *ptr != '\0' )//конец строки
{
if(( *ptr == ' ' || *ptr == '.' || *ptr == ','||*ptr=='\n'))//разделители между словами и строками
{
    (flag==0)?(cnt++):(cnt=cnt);//увеличить колво
    //cnt++;//счетчик колва слов
    flag=1;//повторяющийся разделитель
}
else flag=0;//начинается слово
ptr++;//следующий символ строки
    
}
    n_str++;//счетчик строк
    (cnt>max_cnt)?(max_cnt=cnt)&&(rgt=n_str):(cnt=cnt);//максимальное количество слов
    cnt=0;//обнуление числа слов при переходе на новую строку
}
    n_str=0;//обнуление числа строк перед новым открытием файла
    if (Location_data!="")
        {
    fpin = fopen( Location_data, "rt" ); //открытие файла для чтения
        }
        else fpin = fopen( argv[1], "rt" );
        if( fpin == NULL )//если не удалось открыть файл или он пустой
    return 0;
    if (Location_res!="")
    {
    fpout=fopen ( Location_res,"wt");//открытие файла для записи
    }
    else fpout = fopen( argv[2], "wt" );
        if( fpout == NULL )//если не удалось открыть файл или он пустой
    return 0;
    while( !feof( fpin ) )//
    {
    ptr = fgets( line, MAXLINE, fpin );//??
    if( ptr == NULL )
    break;
        n_str++;//счетчик строк +1
        
        if(n_str==rgt) //если нудна строка
            fputs("\n",fpout);//не выводим эту строку
        else fputs(line,fpout);//если не та строка
    }
    printf ("%i\n",max_cnt);//вывести максимальное колво слов в строке
    printf ("%i\n", rgt);//номер строки с макс колвом слов
    //закрытие файлов
fclose( fpin );
    fclose(fpout);
}

