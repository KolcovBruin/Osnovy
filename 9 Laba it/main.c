#include <stdio.h>
#define MAXLINE 1024
#define Location "/Users/my/Desktop/проекты языка си/9 Laba it/9 Laba it/Data"
int main( void )
{
    int cnt=0;// счётчик слов
    int max_cnt=0;//число слов в самой длинной строке
    int n_str=0;//номер строки в которой определили число слов
FILE *fpin;
//FILE *fpout;
char line[MAXLINE];
   char *ptr;
fpin = fopen( Location, "rt" );
    if( fpin == NULL )
return 0;
//ptr = fgets( line, MAXLINE, fpin );

    /*fpout = fopen(Location, "wt" );
    if( fpout == NULL )
return 0;*/
while( !feof( fpin ) )
{
ptr = fgets( line, MAXLINE, fpin );//??
if( ptr == NULL )
break;
while( *ptr != '\0' )
{
if(( *ptr == ' ' || *ptr == '.' || *ptr == ','||*ptr=='\n'))//добавить условие для повторения разделителей)
{
    cnt++;
}
ptr++;
    
}
    (cnt>max_cnt)?(max_cnt=cnt):(cnt=cnt);
    cnt=0;
    n_str++;
    
    //cnt++;
    /*fpout = fopen(Location, "wt" );
    if( fpout == NULL )
        return 0;
fputs( line, fpout );*/
 //   ptr = fgets( line, MAXLINE, fpin );
}
    printf ("%i\n", max_cnt);
fclose( fpin );
 //   fclose( fpout );

}
//jbsjdbvb jbsdjbjb jbsdkvjb
//jbejbb bajkebjbqj

