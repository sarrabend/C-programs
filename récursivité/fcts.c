#include <stdio.h>
#include <stdlib.h>
#include "head.h"



//===modele llc ====//



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

//========================


int som_n(int n)
{
    if (n==0) { return 0;}
    else { return (som_n(n-1)+n);}
}

int quot(int a,int b)
{
    if(a<b) {return 0;}
    else {return (quot(a-b,b)+1);}
}

int reste(int a,int b)
{
    if (a<b){return a;}
    else {return reste(a-b,b);}
}


int pgcd(int a,int b)
{
    if ((a==0)||(b==0))
    {
        if (a==0) {return b;}
        else { return a;}
    }
    else { return pgcd(b,reste(a,b));}
}

int som(int a,int b)
{
    if (b==0) { return a ;}
    else { return (som(a,b-1)+1);}
}

int MAX_tab(int tab[20],int l)
{
    int M;
   if (l==1) { return tab[l];}
   else
   {
       M=MAX_tab(tab,l-1);
       if (M>tab[l]) { return M;}
       else { return tab[l];}
   }
}

int min_tab(int tab[20],int l)
{
    int m;
   if (l==1) { return tab[l];}
   else
   {
       m=min_tab(tab,l-1);
       if (m>tab[l]) { return m;}
       else { return tab[l];}
   }
}

void inv_llc(Maillon **l)
{
    Maillon *q;
    if (*l!=NULL)
    {
        if (suivant(*l)!=NULL)
        {
            q=*l;
            *l=suivant(*l);
            inv_llc(&*l);
            aff_adr(suivant(q),q);
            aff_adr(q,NULL);
        }
    }
}


void rech_val(Maillon *tete,int val,Maillon **q)
{
    Maillon *p,*sp;
    if (tete!=NULL)
    {
        p=tete;sp=suivant(tete);
        if (sp==NULL)
        {
            if (valeur(p)==val) { *q=p; }
            else { *q=NULL ; }
        }
        else
        {
            if (valeur(p)==val) { *q=p;}
            else { rech_val(sp,val,&*q);}

        }
    }
    else { *q=NULL;}
}
