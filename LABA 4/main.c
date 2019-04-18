#include <stdio.h>
// определение символических констант
#define YES 1
#define NO 0
#define MAXLINE 1000
int bukwa(char c);
int razd(char c);
int glassniy(char c);
void process_line( char buffer[] );
int main( void )
{
    char line[MAXLINE];
    gets( line );
    process_line( line );
    puts( line );
    return 0;
}
void process_line( char buffer[] )
{
    char c;
    int buk=YES;
    int flag = NO;
    int found = NO;
    int i=0;
    int a=0;
    int pos=0; // позиция текущего символа // результирующей строки
    int start=0; // позиция начала слова
    int j=0;
    
    // цикл чтения символов из строки
    do
    {
        c = buffer[i]; // взять текущий символ из // буфера
        
        if( razd(c)==1)
        {
            
            // найден разделитель
            if( flag == YES )
            {
                if( found == NO ||buk==NO ||a==0)
                {
                    for( j = start; j < i; j++ )
                        buffer[pos++] = buffer[j];
                }
                a=0;
            }
            
            buk=YES;
            flag = NO;
            buffer[pos++] = c;
        }
        else {
            // найдена буква
           if (bukwa(c)==0)
                buk=NO;
            if( flag == NO )
                start = i;
            // запомнить позицию
            if (glassniy(c)==1)
                a++;
           // a=a%2;
            if( a%2==0||a==0)
                found = YES;
            else
                found = NO;
            flag = YES; }
        
        
        i++;
        
    }
    while( c != '\0' );
    //buffer[pos] = '\0';
}
int razd(char c)
{
    if (( c == ' ' || c == '.' || c == ',' ||
         c == '\n' || c == '\0'))
        return 1;
    return 0;
}
int glassniy(char c)
{
    if ((c=='A'||c=='E'||c=='I'||c=='O'||c=='U'||c=='Y'||c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='y'))
        return 1;
    return 0;
}
int bukwa(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    return 0;
}
