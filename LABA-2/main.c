

#include <stdio.h>
#include <math.h>
int main (void)
{
    float s; // symma ryada
    float a; // ocherednoi element ryada
    //float c; // chislitel a
    //float b; // znamenatel a
    float e; // znachenie pogreshnosti
    //float i; // dellta b
    float o; // nomer elementa
    //vvod parametrov
    // vivod podskazki e =
    printf ("e=");
    // vvod s kalaviaturi znachenia peremennoi e
    scanf ("%f", &e);
    //zadanie znachenii peremennih
    o=1;
    a=1.0/4.0;
    s=0;
    //reshenie zadachi
    while (a>e)
    {
        s=s+a; // symma elementov
        o=o+1; // nomer elementa
     a=o/(pow(o+1,2)); // znachenie ocherednogo elementa
    
    }
    //vivod znachenie summa ryda
    printf ("s= %f\n",s);
    return 0;
}

