#include <stdio.h>
#define MAXLINE 1024
#define Location_data "/Users/my/Desktop/проекты языка си/9 Laba it/9 Laba it/Data"
#define Location_res "/Users/my/Desktop/проекты языка си/9 Laba it/9 Laba it/Result"
int main( void )
{
    int flag=0;//повтор разделителей
    int cnt=0;// счётчик слов
    int max_cnt=0;//число слов в самой длинной строке
    int n_str=0;//номер строки в которой определили число слов
    int rgt=0;//номер нужной строки
FILE *fpin;//для считывания информации из файла
FILE *fpout;//для записи информации из файла
char line[MAXLINE];//считанная строка
   char *ptr;//указатель на строку
fpin = fopen( Location_data, "rt" ); //открытие файла для чтения
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
    fpin = fopen( Location_data, "rt" );//открытие файла для чтения
        if( fpin == NULL )
    return 0;
    fpout=fopen ( Location_res,"wt");//открытие файла для записи
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


