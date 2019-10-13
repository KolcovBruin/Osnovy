#include <stdio.h>
#define MAXLINE 1024
#define Location "/Users/my/Desktop/проекты языка си/9 Laba it/9 Laba it/Data"
int main( void )
{

FILE *fpin;
FILE *fpout;
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
    /*fpout = fopen(Location, "wt" );
    if( fpout == NULL )
        return 0;
fputs( line, fpout );*/
 //   ptr = fgets( line, MAXLINE, fpin );
}
fclose( fpin );
 //   fclose( fpout );

}
//jbsjdbvb jbsdjbjb jbsdkvjb
//jbejbb bajkebjbqj

