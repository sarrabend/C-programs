#include <stdio.h>
#include <stdlib.h>
#include <string.h>


# define N 10000
typedef struct {
int tab[N];
int sommet;
} Pile;
typedef struct {
int tab[N];
int tete, queue;
} File;
void creerpile( Pile *pp )
{ pp->sommet = -1; }

int pilevide( Pile p )
{ return (p.sommet == -1); }

int pilepleine( Pile p)
{ return (p.sommet == N-1); }


int empiler( int x, Pile *pp ) {
if ( pilepleine(*pp) ) return 0;
pp->tab[++(pp->sommet) ] = x;
return 1;
}
int depiler( int *x, Pile *pp ) {
if ( pilevide(*pp) ) return 0;
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
void CreerFile ( File *pf ) {
pf->tete = N-1;
pf->queue = N-1;
}

int FileVide( File F )
{
 return (F.tete == F.queue);
}

int FilePleine( File F )
{
 return ( F.tete == (F.queue+1 % N) );
}

int Enfiler( int x, File *pf )
{
if ( FilePleine(*pf) ) return 0;
pf->queue = (pf->queue + 1) % N;
pf->tab[ pf->queue ] = x;
return 1;
}

int Defiler( int *x, File *pf )
{
if ( FileVide( *pf ) ) return 0;
*x = pf->tab[ pf->tete ];
pf->tete = (pf->tete+1) % N;
return 1;
}




int main()
{
    char chaine[20], c ;Pile p;int o,a,b,l;
    creerpile(&p);
    printf("veuillez entrer votre expression avec le caractere de fin '#' :");
    scanf("%s",chaine);
     l= strlen(chaine);
    int i=0;
    c=chaine[0];
    while (c!='#')
    {
        if (operande(c)==1)//probleme des cas c=entier !!!!
        {
            printf("entrer %c",c);
            scanf("%d",&o);
            empiler(o,&p);
        }
        else {depiler(&b,&p);depiler(&a,&p);o=operation(a,b,c);empiler(o,&p);}
        i++;c=chaine[i];
    }
    depiler(&o,&p);
    chaine[l-1]='\0';
    printf("%s=%d",chaine,o);
    return 0;
}
