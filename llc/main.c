#include <stdio.h>
#include <stdlib.h>

typedef struct Maillon { int val; struct Maillon *next;} Maillon;

void allouer(Maillon **nouveau)
{ *nouveau=(Maillon*)malloc(sizeof(Maillon));}

void aff_adr(Maillon *p,Maillon *q)
{p->next=q;}

void aff_val(Maillon *p, int valeur)
{ p->val=valeur;}

Maillon *suivant(Maillon *p)
{return p->next;}

int valeur(Maillon *p)
{return p->val;}

void liberer(Maillon**ancien)
{free(*ancien); *ancien=NULL;}

Maillon *creation(int n)
{
Maillon *tete,*p,*q; int i, v;
allouer(&p);scanf("%d",&v); aff_val(p,v); tete=p;
for (i=1; i<n; i++)
{
allouer(&q);scanf("%d",&v);aff_val(q,v);aff_adr(p,q);p=q;
}
aff_adr(p,NULL);
return tete;
}

void afficher(Maillon *p)
{
while(p!=NULL)
{printf("%d ",valeur(p)); p=suivant(p);}
}

int freq( Maillon *tete ,int v )
{
    int n=0 ;
    Maillon *p;
    p=tete;
    while (p!=NULL)
    {
        if (valeur(p)==v) n++ ;
        p=suivant(p);
    }
    return n ;
}

void pg_occ(Maillon *tete , int *max ,Maillon **q )
{
    Maillon *p ;
    int val;
    p=tete;
    *max=1;
    while (p!=NULL)
    {
        val = freq(p, valeur(p))  ;
        if (val>*max)
        {
            *max=val ;
            *q=p;
        }
        p=suivant(p);
    }

}

void acces_val(Maillon *tete, int v , Maillon **p,Maillon **q)
{
  int trouv=0 ;
  *p=NULL ;
  *q=tete;
  while ((trouv==0)&&(q!=NULL))
  {
     if (valeur(q)==v) {trouv=1; }
     else {p=q;q=suivant(q);};
}
}

void acces_pos(Maillon *tete , int pos , Maillon **p,Maillon **q )
{
    int i=1 ;
    *p=NULL;
    *q=tete ;
    if (pos>=1)
    {
        while ((i<pos)&&(*q!=NULL))
        {
            *p=*q;
            *q=suivant(*q);
            i++;
        }
    }
}

void supp_val(int v, Maillon **tete) // a verifier//
{
    Maillon *p,*q;
    acces_val(*tete,v,&p,&q);
    if (q!=NULL)
    {
        if (p!=NULL) {aff_adr(p,suivant(q));}
        else *tete=suivant(q);
    }
     liberer(&q);
}

void supp_pos(int pos , Maillon **tete )
{
    Maillon *p,*q;
    acces_pos(pos,*tete,&p,&q);
    if (q!=NULL)
    {
        if (p!=NULL) {aff_adr(p,suivant(q));}
        else *tete=suivant(q);
    }
     liberer(&q);

}

void inter_class(Maillon *T1,Maillon *T2 , Maillon **T3 )
{
  Maillon *p,*q;
  if (T1==NULL) {*T3=T2;}
    else
    {
        if (T2==NULL) {*T3=T1;}
        else
        {
            if (valeur(T1)<valeur(T2)) {*T3=T1 ; T1=suivant(T1);}
            else { *T3=T1 ; T2=suivant(T2); }
            p=*T3;
            while ((T1!=NULL)&&(T2!=NULL))
            {
                if (valeur(T1)<valeur(T2)) {aff_adr(p,T1); p=T1 ; T1=suivant(T1);}
                else { aff_adr(p,T2) ; p=T2 ; T2=suivant(T2); }
            }
            if (T1==NULL) {aff_adr(p,T2); T2=NULL;}
            else {aff_adr(p,T1);T2=NULL;}
        }
    }
}

void   inv_llc(Maillon *tete, Maillon **nv_tete)
        {
            Maillon *p1,*p2,*p3,*q;
            p1=tete;p2=suivant(p1); p3=suivant(p2);
            if (p3==NULL) { aff_adr(p2,p1);aff_adr(p1,NULL); *nv_tete=p2; }
            else { inv_llc(p2,&q);*nv_tete=q; }
        }


int main()
{
int n , max ,pos,v, op; Maillon *p,*q;
Maillon *tete;
printf("donner la longueur de votre liste :");
scanf("%d",&n);
tete=creation(n);
afficher(tete);
printf("========= MENU LISTES ========\n");
printf("1.chercher l'element qui a le plus grand nombre d'occurence\n");
printf("2.acceder par position: afficher une valeur d'une position dans une liste \n");
printf("3.supprimer une valeur\n");
printf("4.supprimer une position\n");
printf("5.inserer une nouvelle position\n");
printf("5.interclassement de 2 listes \n");
printf("6.inverser une liste \n");
printf("veuillez effectuer votre choix: ");
scanf("%d",&op);
switch(op)
{
    case 1 :
afficher(tete);
pg_occ(tete,&max,&p);
printf("la valeur %d se repete %d fois dans la liste ", valeur(p) , max);
    break;
    case  2:
afficher(tete);
printf("donner la position: ");
scanf("%d",&pos);
acces_pos(tete,pos,&p,&q);
printf("%d",valeur(q));
    break;
    case 3 :
printf("entrer la valeur que vous voulez supprimer: ");
scanf("%d",&v);
supp_val(v,&tete);
afficher(tete);
    break;

    case 6:
        afficher(tete);
inv_llc(tete,&q);
afficher(q);

    break;
}
return 0;
}



