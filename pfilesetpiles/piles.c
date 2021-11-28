#include <stdio.h>
#include <stdlib.h>
#include "head_piles.h"


void CreerPile( Pile *pp )
{ pp->sommet = -1; }

int PileVide( Pile p )
{ return (p.sommet == -1); }

int PilePleine( Pile p)
{ return (p.sommet == N-1); }


int Empiler( int x, Pile *pp ) {
if ( PilePleine(*pp) ) return 0;
pp->tab[++(pp->sommet) ] = x;
return 1;
}
int Depiler( int *x, Pile *pp ) {
if ( PileVide(*pp) ) return 0;
*x = pp->tab[pp->sommet--];
return 1;
}

int operande(char c)
{
    char op[]="+-*/^";int a=1,i=0;
    while ((a==1)&&(i<=4))
    {
    if (c==op[i]) {a=0;}
    i++;
    }
    return a;
}

int operation(a,b,c)
{
    switch(c)
    {
        case '+': return a+b; break;
        case '-': return a-b; break;
        case '/': return a/b; break;
        case '*': return a*b; break;
        case '^': return a^b; break;
    }
}
