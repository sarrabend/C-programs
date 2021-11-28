#ifndef HEAD_PILES_H_INCLUDED
#define HEAD_PILES_H_INCLUDED
# define N 10000
typedef struct {
int tab[N];
int sommet;
} Pile;

void CreerPile( Pile *pp );
int PileVide( Pile p );
int PilePleine( Pile p);
int Empiler( int x, Pile *pp );
int Depiler( int *x, Pile *pp );
int operande(char c);
int operation(a,b,c);
#endif // HEAD_PILES_H_INCLUDED
