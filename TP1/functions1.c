#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include "headers1.h"

///==== fonctions utilisees dans les deux parties ====//
void random_nom(int MIN ,int MAX ,char nom[])
{
    int i,nblettres ;char lettre ;
    srand(rand()*time(NULL));
    nblettres=(rand()%(MAX-MIN+1))+MIN;
    for (i=0;i<nblettres;i++)
    {
        lettre=(rand()%26)+65;
        nom[i]=lettre;
    }
    nom[i]='\0';
}

///==========premiere partie=======///
//machine abstraite
void allouer(pop **nouveau) { *nouveau=(pop*)malloc(sizeof(pop));}

void aff_adr(pop *p,pop *q) {p->next=q;}

void aff_nom(pop *p, ch20 nom) { strcpy(p->nomfam,nom);}

pop *suivant(pop *p) {return p->next;}

char *nom_fam(pop *p) {return p->nomfam;}

void liberer(pop**ancien) {free(*ancien); *ancien=NULL;}

void afficher_pop(pop *p) {  while(p!=NULL){printf("%s\n",nom_fam(p)); p=suivant(p);} }


//fonctions demandees :
int freq_nom(ch20 nom, pop *t )//utilisee pour traiter les doublons
{
    int cpt=0;
    while (t!=NULL)
    {
       if (strcmp(nom,nom_fam(t))==0) {cpt++;}
       t=suivant(t);
    }
    return cpt ;
}

void permut_nom(pop* p, pop* q)// utilisee dans trier_pop
{
    char inter[20];
    if ((q!=NULL)&&(p!=NULL))
    {
    strcpy(inter,nom_fam(p));
    strcpy(nom_fam(p),nom_fam(q));
    strcpy(nom_fam(q),inter);
    }

}

void creer_pop(int n, pop **tete)
{
    int i  ; ch20  nomfam; pop *p , *q ;
    if (n>=1)
    {
    random_nom(7,13,nomfam);
    allouer(&p);
    aff_nom(p,nomfam);
    aff_adr(p,NULL);
    *tete=p;
    for (i=1 ; i<n ; i++ )
    {
        allouer(&q);
        aff_adr(p,q);
        do
        {
            random_nom(7,13,nomfam);
        }while (freq_nom(nomfam,&*tete)>0);
        aff_nom(q,nomfam);
        p=q;
        aff_adr(p,NULL);
    }
    }
    else { *tete=NULL;}
}

void trier_pop(pop** tete )
{
    pop *t,*p,*q; ch20 min;
    t=*tete;
    while (t!=NULL)
    {
        p=t;
        strcpy(min,nom_fam(t));
        while (p!=NULL)
        {
           if (strcmp(min,nom_fam(p))>=0)
           {
               strcpy(min,nom_fam(p));
               q=p;
           }
           p=suivant(p);
        }
        if (min!=nom_fam(t)){permut_nom(t,q);}
        t=suivant(t);
    }
}

int nb_famille(pop *tete)
{
    int cpt=0 ;
    while (tete!=NULL) {
        cpt=cpt+1 ;
        tete = suivant(tete);
    }
    return cpt ;
}

void present(ch20 nom ,pop *tete , pop **p, pop **q)
{
    int trouv=0 ;
    *p=NULL;
    *q=tete ;
    while ((*q!=NULL)&&(trouv==0))
    {
        if (strcmp(nom,nom_fam(*q))==0){trouv=1;}
        else {  *p=*q;
                *q=suivant(*q);
             }
    }
}

void inser_nom(ch20 nom, pop **tete )
{
    pop *p,*q,*l; int b=0  ;
    allouer(&q);aff_nom(q,nom);aff_adr(q,NULL);
    if (*tete!=NULL)
    {
    p=*tete;
    l=suivant(p);
    if (strcmp(nom, nom_fam(p))==-1) { aff_adr(q,*tete);*tete=q;}
    else
    {
    while ((b==0)&&(l!=NULL))
    {   if (strcmp(nom_fam(p),nom)==0) {b=2;}
        else {
        if ((strcmp(nom_fam(p),nom)==-1)&&(strcmp(nom_fam(l),nom)==1))
        {
            b=1;
            aff_adr(q,l);
            aff_adr(p,q);
        }
        else { p=l;l=suivant(l); }
            }
    }
    if ((l==NULL)&&(b==0)) { aff_adr(p,q);}
    }
    if(b==2){printf("le nom existe deja");}
    }
    else { *tete=q;}

}

void supp_nom(ch20 nom, pop** tete )
{
    pop *p , *q;
    present(nom,*tete,&p,&q);
    if (q!=NULL)
    {
        if (p!=NULL) { aff_adr(p,suivant(q));}
        else {*tete=suivant(q);}
        liberer(&q);

    }

}




