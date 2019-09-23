#include <stdio.h>
#define YES 1
#define NO 0
int bukwa(char *buf);//для проверки на буквы
int razd(char *buf); //для проверки на разделители
int glassniy(char *buf); //для проверки на гласные
void process_line( char buffer[] ); //основная функция
int main( void )
{
    char line[1000];
    gets( line );//считывание
    process_line( line );
    puts( line );//вывод
    return 0;
}
void process_line( char buffer[] )
{
   
   // char c; вроде не нужно уже
    int buk=YES; //нужно оптимизировать возможно лишнее
    int flag = NO;//для определения начала слова
    int found = NO; //проверка наличия четного колва гласных
    int i=0;//номер текущего симола
    int a=0;//число гласных
    int pos=0;//используется для затирания, если чет гласных
    int start=0;//заменить на о в коде
    int j=0; // Значения начала слова которое нужно удалить
    char *buf=buffer;//текущий символ
     char buff;
    do
    {
        //test
        //c = buffer[i];
        if( razd(buf)==1)  //проверяем тек символ на разделитель
        {
            if( flag == YES )  //не начало слова
            {
                if( found == NO ||buk==NO ||a==0) // Слово не подходит под условия слова которое нужно удалить
                {
                    for( j = start; j < i; j++ )   //затираем не нужное слово
                      
                        buffer[pos++] = buffer[j];
                }
            }
            a=0;//обнуления колва гласных
            buk=YES;//!!!
            flag = NO;//после прохода слова, чтобы запистаь начало сл слова
            
           
            buffer[pos++] = *buf;//удаление слова с двумя гласными
            
        }
        else {
            if (bukwa(buf)==0)//проверка на букву
                buk=NO;
            if( flag == NO )//проверка на нач слова
                start = i; //!!!!
            
            if (glassniy(buf)==1)//проверка на гласные и подсчет их колва в слове
                a++;
            if( a%2==0||a==0)// проверка на четность колва гласных, можно убрать видимо лобавив сразу в условия затирания
                found = YES;
            else
                found = NO;
            flag = YES; }
        i++;//номер текущего символа
        
        buff=*buf; //запоминание пред символа
        *buf++; //сл символ
    }
    while(  buff!= '\0' );//проверка на уконец строки
}
//проверка на разделители
int razd(char *buf)
{
    if (( *buf == ' ' || *buf == '.' || *buf == ',' ||
         *buf == '\n' || *buf == '\0'))
        return 1;
    return 0;
}
//проверка на разделители
int glassniy(char *buf)
{
    if ((*buf=='A'||*buf=='E'||*buf=='I'||*buf=='O'||*buf=='U'||*buf=='Y'||*buf=='a'||*buf=='e'||*buf=='i'||*buf=='o'||*buf=='u'||*buf=='y'))
        return 1;
    return 0;
}
//проверка на разделители
int bukwa(char *buf)
{
    if ((*buf >= 'a' && *buf <= 'z') || (*buf >= 'A' && *buf <= 'Z'))
        return 1;
    return 0;
}
