#include <stdio.h>
#define MAXLINE 1024
#define Location_data "/Users/my/Desktop/проекты языка си/9 Laba it/9 Laba it/Data"
#define Location_res "/Users/my/Desktop/проекты языка си/9 Laba it/9 Laba it/Result"
int main( void )
{
    int cnt=0;// счётчик слов
    int max_cnt=0;//число слов в самой длинной строке
    int n_str=0;//номер строки в которой определили число слов
    int rgt=0;//номер нужной строки
FILE *fpin;
FILE *fpout;
char line[MAXLINE];
   char *ptr;
fpin = fopen( Location_data, "rt" );
    if( fpin == NULL )
return 0;
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
    n_str++;
    (cnt>max_cnt)?(max_cnt=cnt)&&(rgt=n_str):(cnt=cnt);
    cnt=0;
}
    n_str=0;
    fpin = fopen( Location_data, "rt" );
        if( fpin == NULL )
    return 0;
    fpout=fopen ( Location_res,"wt");
    while( !feof( fpin ) )
    {
    ptr = fgets( line, MAXLINE, fpin );//??
    if( ptr == NULL )
    break;
        n_str++;
        
        if(n_str==rgt)
            fputs("\n",fpout);
        else fputs(line,fpout);
    }
    
    printf ("%i\n", rgt);
fclose( fpin );
}


