#include <stdio.h>
int main(void)
{
int z,l=0;
    //int l=0;
    int y;
    int n=0;
    int mask;
    int ctr;
    int i;
    i=0;
    mask=1;
    ctr=0;
    printf("z = ");
    scanf("%llx", &z);
    y = (unsigned int)z;
    while(y!=0&&n<64)
    {
        l=y&mask;
        printf("%lld",l);
        if(l==1)
        {
            ctr++;
        }
        y>>=1;
        i++;
        n++;
        if(i==8)
        {
            printf("ctr=%d\n",ctr);
            i=0;
            ctr=0;
        }
    }
    /*if((i>=0)&&(i<8))
    {
        printf("ctr=%d\n",ctr);
    }*/
    while(n<64)
    {
        // printf("%lld",l);
        //ctr=0;
        l=y&mask;
    printf("%lld",l);
     y>>=1;
        i++;
        n++;
        if(i==8)
        {
            printf("ctr=%d\n",ctr);
            i=0;
            ctr=0;
        }
    }
    //gets();
    return 0;
}
