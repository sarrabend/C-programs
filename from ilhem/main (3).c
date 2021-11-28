#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct pop{char nomfam[16] ; struct pop *next ;} pop ;

//****************machine abstraite*****************************//

void allouer(pop **nouveau)
{ *nouveau=(pop*)malloc(sizeof(pop));}

void aff_adr(pop *p,pop *q)
{p->next=q;}

void aff_nom(pop *p, char nom[16])
{ strcpy(p->nomfam,nom);}

pop *suivant(pop *p)
{return p->next;}

char *nom_fam(pop *p)
{return p->nomfam;}

void liberer(pop**ancien)
{free(*ancien); *ancien=NULL;}

void afficher_pop(pop *p)
{
while(p!=NULL)
{printf("%s\n",nom_fam(p)); p=suivant(p);}
}


//***********************fonctions de la 1ere partie*********************//

void random_nom(char nom[])
{
    int i,nblettres ;char lettre ;
    srand(rand()*time(NULL));
    nblettres=(rand()%7)+7;
    for (i=0;i<nblettres;i++)
    {
        lettre=(rand()%26)+65;
        nom[i]=lettre;
    }
    nom[i]='\0';
}

void creer_pop(int n , pop **tete)
{
    int i  ; char  nomfam[20]; pop  *p , *q ;
    random_nom(nomfam);
    allouer(&p);
    aff_nom(p,nomfam);
    *tete=p;
    for (i=1 ; i<n ; i++ )
    {
        allouer(&q);
        aff_adr(p,q);
        random_nom(nomfam);
        aff_nom(q,nomfam);
        p=q;
    }
    aff_adr(p,NULL);
    return 0;
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

pop *present(char nom[] ,pop *tete )
{
    int trouv=0 ; pop *p ;
    p=tete ;
    while ((p!=NULL)&&(trouv==0)){
        if (nom==p->nomfam){trouv=1;}
        else {p=suivant(p);};
    }
    return p ;
}

//***************test main ****************************//

int main()
{
    int n,m  ; pop *p,*q;char  nm[20];
    srand(time(NULL));
    scanf("%d",&n);
    creer_pop(n,&p);
    afficher_pop(p);
    scanf("%s",&nm);
    q=present(nm,p);
    if (q!=NULL) {printf("%s est present ",nm);}
    else {printf("%s nest pas present ",nm);}
    return 0;
}
