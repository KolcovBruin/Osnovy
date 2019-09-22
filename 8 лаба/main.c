#include <stdio.h>
#define YES 1
#define NO 0
int bukwa(char *buf);
int razd(char *buf);
int glassniy(char *buf);
void process_line( char buffer[] );
int main( void )
{
    char line[1000];
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
    int pos=0;
    int start=0;
    int j=0;
    char *buf=buffer;
     char buff;
    do
    {
        //test
        c = buffer[i];
        if( razd(buf)==1)
        {
            if( flag == YES )
            {
                if( found == NO ||buk==NO ||a==0)
                {
                    for( j = start; j < i; j++ )
                      
                        buffer[pos++] = buffer[j];
                }
            }
            a=0;
            buk=YES;
            flag = NO;
            
           
            buffer[pos++] = *buf;
            
        }
        else {
            if (bukwa(buf)==0)
                buk=NO;
            if( flag == NO )
                start = i;
            // запомнить позицию
            if (glassniy(buf)==1)
                a++;
            if( a%2==0||a==0)
                found = YES;
            else
                found = NO;
            flag = YES; }
        i++;
        
        buff=*buf;
        *buf++;
    }
    while(  buff!= '\0' );
}
int razd(char *buf)
{
    if (( *buf == ' ' || *buf == '.' || *buf == ',' ||
         *buf == '\n' || *buf == '\0'))
        return 1;
    return 0;
}
int glassniy(char *buf)
{
    if ((*buf=='A'||*buf=='E'||*buf=='I'||*buf=='O'||*buf=='U'||*buf=='Y'||*buf=='a'||*buf=='e'||*buf=='i'||*buf=='o'||*buf=='u'||*buf=='y'))
        return 1;
    return 0;
}
int bukwa(char *buf)
{
    if ((*buf >= 'a' && *buf <= 'z') || (*buf >= 'A' && *buf <= 'Z'))
        return 1;
    return 0;
}
