#include <stdio.h>


int main()
{
    //b^2-4ac
    unsigned short int a;
    unsigned short int b;
    unsigned short int c;
    unsigned short int y;
    printf("Введите A,B,C\n");
    scanf ("%hi%hi%hi",&a,&b,&c);
    int e=0;
    if (a==b&b==c)
        printf("Равны");
        else
            printf("Не Равны");
    
   
  int A_h=0;
      int A_l=0;
      int A_x=0;
      int B_h=0;
      int B_l=0;
      int B_x=0;
      int C_h=0;
      int C_l=0;
      int C_x=0;
      int D_h=0;
      int D_l=0;
      int D_x=0;
    __asm
    {
    mov ah,A_h
    mov al,A_l
    mov ax,A_x
    mov bh,B_h
    mov bl,B_l
    mov bx,B_x
    mov ch,C_h
    mov cl,C_l
    mov cx,C_x
    mov dh,D_h
    mov dl,D_l
    mov dx,D_x
            
        mov y,0
        mov ax,a
        cmp ax,b
        jne @m
        mov b,ax
    @m: nop
        

        
  mov A_h,ah
  mov A_l,al
  mov A_x,ax
  mov B_h,bh
  mov B_l,bl
  mov B_x,bx
  mov C_h,ch
  mov C_l,cl
  mov C_x,cx
  mov D_h,dh
  mov D_l,dl
  mov D_x,dx
  }
  printf("\n\n\n");
       printf("ah=%i al=%i ax=%i\nbh=%i bl=%i bx=%i\nch=%i cl=%i cx=%i\ndh=%i dl=%i dx=%i\n", A_h, A_l, A_x, B_h, B_l, B_x, C_h, C_l, C_x, D_h, D_l,D_x );
   
   
    
  __asm
     {
         mov ah,A_h
         mov al,A_l
         mov ax,A_x
         mov bh,B_h
         mov bl,B_l
         mov bx,B_x
         mov ch,C_h
         mov cl,C_l
         mov cx,C_x
         mov dh,D_h
         mov dl,D_l
         mov dx,D_x
         
         
        mov b,ax
        mov ax,a
        mov cl,4
        imul cl
         
         
         
        mov A_h,ah
        mov A_l,al
        mov A_x,ax
        mov B_h,bh
        mov B_l,bl
        mov B_x,bx
        mov C_h,ch
        mov C_l,cl
        mov C_x,cx
        mov D_h,dh
        mov D_l,dl
        mov D_x,dx
     }
    printf("\n\n\n");
          printf("ah=%i al=%i ax=%i\nbh=%i bl=%i bx=%i\nch=%i cl=%i cx=%i\ndh=%i dl=%i dx=%i\n", A_h, A_l, A_x, B_h, B_l, B_x, C_h, C_l, C_x, D_h, D_l,D_x );
    
    __asm
    {
        
        mov ah,A_h
        mov al,A_l
        mov ax,A_x
        mov bh,B_h
        mov bl,B_l
        mov bx,B_x
        mov ch,C_h
        mov cl,C_l
        mov cx,C_x
        mov dh,D_h
        mov dl,D_l
        mov dx,D_x
        
        
        
        imul c
        mov bx,b
        
        
        mov A_h,ah
               mov A_l,al
               mov A_x,ax
               mov B_h,bh
               mov B_l,bl
               mov B_x,bx
               mov C_h,ch
               mov C_l,cl
               mov C_x,cx
               mov D_h,dh
               mov D_l,dl
               mov D_x,dx
    }
    printf("\n\n\n");
             printf("ah=%i al=%i ax=%i\nbh=%i bl=%i bx=%i\nch=%i cl=%i cx=%i\ndh=%i dl=%i dx=%i\n", A_h, A_l, A_x, B_h, B_l, B_x, C_h, C_l, C_x, D_h, D_l,D_x );
    __asm
       {
        mov ah,A_h
        mov al,A_l
        mov ax,A_x
        mov bh,B_h
        mov bl,B_l
        mov bx,B_x
        mov ch,C_h
        mov cl,C_l
        mov cx,C_x
        mov dh,D_h
        mov dl,D_l
        mov dx,D_x
           
           
        sub bx,ax
       // sbb dx,bx
        mov y,bx
           
           mov A_h,ah
           mov A_l,al
           mov A_x,ax
           mov B_h,bh
           mov B_l,bl
           mov B_x,bx
           mov C_h,ch
           mov C_l,cl
           mov C_x,cx
           mov D_h,dh
           mov D_l,dl
           mov D_x,dx
           
    }
    printf("\n\n\n");
    printf("ah=%i al=%i ax=%i\nbh=%i bl=%i bx=%i\nch=%i cl=%i cx=%i\ndh=%i dl=%i dx=%i\n", A_h, A_l, A_x, B_h, B_l, B_x, C_h, C_l, C_x, D_h, D_l,D_x );
    printf("b^2-4ac = %hu\n",y);
    printf("Проверка:b^2-4ac = %i\n", e);
    return 0;
}

