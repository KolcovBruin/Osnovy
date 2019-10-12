#include <stdio.h>
#define MAXLINE 1024
int main( void )
{

FILE *fpin;
FILE *fpout;
char line[MAXLINE];
   char *ptr;
fpin = fopen( "test.txt", "rt" );
    if( fpin == NULL )
return 0;

fpout = fopen("test.txt", "wt" );
    if( fpout == NULL )
return 0;
while( !feof( fpin ) )
{
ptr = fgets( line, MAXLINE, fpin );
if( ptr == NULL )
break;
while( *ptr != '\0' )
{
if( *ptr == ' ' || *ptr == '.' || *ptr == ',' )
{

*ptr++ = '\n';

*ptr = '\0';

break; }
ptr++;
    
}
fputs( line, fpout );
}
fclose( fpin );
    fclose( fpout );

}
