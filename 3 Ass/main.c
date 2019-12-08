#include <stdio.h>


int main()
{
    //b^2-4ac
     short int a;
     short int b;
     short int c;
     short int y;
    short int r;
    printf("Введите A,B,C\n");
    scanf ("%hi%hi%hi",&a,&b,&c);
    int e=0;
    if (a==b&b==c)
        printf("Равны");
        else
            printf("Не Равны");
    
   

    __asm
    {
        mov y,0
        mov r,0
        mov ax,a
        cmp ax,b
        jge m
        cmp ax,c
        jl na
        m:
        mov ax,b
            cmp ax,a
            jge n
          
            cmp ax,c
            jl nb
            
    n:
        mov ax,c
                   cmp ax,a
                   jge l
                 
                   cmp ax,b
                   jl nc
    l:
   na: mov a,0
        cmp a,ax
        jne f
   nb: mov b,0
        cmp b,ax
        jne f
   nc: mov c,0
        cmp c,ax
        jne f
    f: nop
    
  }
  printf("\n\n\n");
    printf("A=%i\nB=%i\nC=%i\n", a,b,c);
 
    return 0;
}

