#include <stdio.h>
#include <stdlib.h>
#define Location_data "/Users/my/Desktop/проекты языка си/10 лаба/10 лаба/Data"
void main()
{
    FILE *fp;
    char lit='\0';
    int a=0;
    int cbr_1=0;
    int cbr_2=0;
    char br_1='{';
    char br_2='}';
    char *word;
    fp=fopen(Location_data, "rt");
    lit=fgetc(fp);
    int  flag_1=0;
   
    int point=0;
    word=(char*)malloc(sizeof(char));
    while (lit!='\xff')
    {
        while (lit!='\n'&&lit!=';'&&lit!='\0'&&lit!='\xff'&&point==0)
        {
            
            while (lit!='\n'&&lit!=';'&&lit!=' '&&point==0)
            {
                if (lit==br_1)
                               {
                                   point=1;
                                   break;
                               }
                word[a]=lit;
               
                a++;
                word=(char*)realloc(word, (a+1)*sizeof(char));
                lit=fgetc(fp);
               
            }
            if (point ==1)
            
                break;
            
            if (strcmp(word,"char")==0||strcmp(word,"int")==0||strcmp(word,"float")==0||strcmp(word,"const")==0||strcmp(word,"unsigned")==0||strcmp(word,"short")==0||strcmp(word,"long")==0)
            {
            
                flag_1=1;
            }
         
            if (flag_1==1)
            {
               printf("%s ",word);
                 
            }
            a=0;
             word=(char*)malloc(sizeof(char));
            lit=fgetc(fp);
        }
        if (flag_1==1)
        {
           printf("\n");
        }
        lit==br_1?cbr_1++:lit==br_2?cbr_2++:NULL;
        if ((cbr_1-cbr_2)==0)
            point=0;
         lit==';'?flag_1=0:NULL;
        lit=fgetc(fp);
    }
}
int knds=828 ;


