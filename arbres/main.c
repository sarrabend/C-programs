#include <stdio.h>
#include <stdlib.h>
typedef int Typeelem_Ai ;
typedef struct Noeud_Ai * Pointeur_Ai ;
struct Noeud_Ai
{
Typeelem_Ai Val ;
Pointeur_Ai Fg ;
Pointeur_Ai Fd ;
};
void Creernoeud_Ai( Pointeur_Ai *P)
{
*P = (struct Noeud_Ai *) malloc( sizeof( struct Noeud_Ai)) ;
(*P)->Fg = NULL;
(*P)->Fd = NULL;
}
void Liberernoeud_Ai( Pointeur_Ai P)
{ free( P ) ; }
Typeelem_Ai Info_Ai( Pointeur_Ai P )
{ return P->Val; }
Pointeur_Ai Fg_Ai( Pointeur_Ai P)
{ return P->Fg ; }
Pointeur_Ai Fd_Ai( Pointeur_Ai P)
{ return P->Fd ; }
void Aff_info_Ai ( Pointeur_Ai P, Typeelem_Ai Val)
{
P->Val = Val ;
}
void Aff_fg_Ai( Pointeur_Ai P, Pointeur_Ai Q)
{ P->Fg = Q; }
void Aff_fd_Ai( Pointeur_Ai P, Pointeur_Ai Q)
{ P->Fd = Q ; }

void rech(Typeelem_Ai val , Pointeur_Ai *R,Pointeur_Ai*p)
{
    if ( R!=NULL )
    {
        if (val==Info_Ai(*R)){*p=NULL;}
        else
        {
        if (val>Info_Ai(*R)){ *p=*R; *R=Fd_Ai(*R);rech(val,&*R,&*p);}
        else { *p=*R;*R=Fg_Ai(*R);rech(val,&*R,&*p);}
        }
    }
}

void inser(Pointeur_Ai R,Typeelem_Ai val)
{
   Pointeur_Ai s,p,q;
   p=NULL; q=R;rech(val,&q,&p);
   if (R==NULL){Creernoeud_Ai(&s);Aff_info_Ai(s,val);Aff_fd_Ai(s,NULL);Aff_fg_Ai(s,NULL);}
   else { if(q==NULL)
        {
          if (Info_Ai(p)<val) Aff_fd_Ai(p,s);
          else  Aff_fg_Ai(p,s);
          }
   }

}

void afficher_arb (Pointeur_Ai R)
{
    int val;
    if (R!=NULL)
    {

      val=Info_Ai(R);
      printf("%d",val);
      afficher_arb(Fd_Ai(R));
      afficher_arb(Fg_Ai(R));
    }
}
int main()
{
    int i,n;
    int val;
    Pointeur_Ai R=NULL;
    printf("nombre de noeuds :!\n");
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        printf("entrer une valeur:\n");
      scanf("%d",&val);
      inser(R,val);
    }
    afficher_arb(R);
    return 0;
}
