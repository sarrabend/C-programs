#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "headers2.h"
#include "headers1.h"

///===========deuxieme partie========///
//machine abstraite de la structure voiture :
void allouer_v(pv *nouveau) { *nouveau=(pv)malloc(sizeof(struct voiture));}
void aff_adr_v(pv p,pv q) {p->next=q;}
void aff_num(pv p, ch20 num ) {strcpy(p->num,num ); }
void aff_marque(pv p, ch20 marque) { strcpy(p->marque,marque);}
pv suivant_v(pv p) {return p->next;}
char* marque(pv p) {return p->marque ;}
char* num(pv p) { return p->num;}
void liberer_v(pv *ancien) {free(*ancien); *ancien=NULL;}
void afficher_v(pv p) {while(p!=NULL) {printf("   Marque de la voiture :%s\n",marque(p)); printf("    Matricule:%s\n",num(p)); p=suivant_v(p);} }

//machine abstraite de la structure personne :
void allouer_p(pp *nouveau ) { *nouveau=(pp)malloc(sizeof(struct personne));}
void aff_adr_p(pp p,pp q) {p->next=q;}
void aff_nom_p(pp p, ch20 nom ) {strcpy(p->nom,nom ); }
void aff_sexe(pp p, char sx) { p->sexe=sx;}
pp suivant_p(pp p) {return p->next;}
char* nom_p(pp p) { return p->nom;}
char sexe(pp p) { return p->sexe;}
void afficher_p(pp p) {while(p!=NULL) {printf("   Prenom:%s\n    Sexe:%c\n",nom_p(p),sexe(p));p=suivant_p(p);}}
void liberer_p(pp *p) { free(*p); *p=NULL;}
int freq_nom_p(ch20 nom, pp t )
{
    int cpt=0;
    while (t!=NULL)
    {
       if (strcmp(nom,nom_p(t))==0) {cpt++;}
       t=suivant_p(t);
    }
    return cpt ;
}

//machine abstraite de la structure famille :
void allouer_f(pf *nouveau ) { *nouveau=(pf)malloc(sizeof(struct famille));}
void aff_adr_f(pf p,pf q) {p->next=q;}
void aff_nom_f(pf p, ch20 nom ) {strcpy(p->nom,nom ); }
void aff_parent(pf p, pp q) { p->parent=q;}
void aff_enfant(pf p, pp q) { p->enfant=q;}
void aff_voiture(pf p , pv q) { p->voiture=q ;}
pf suivant_f(pf p) {return p->next;}
char* nom_f(pf p) { return p->nom;}
pp parent(pf p) { return p->parent;}
pp enfant(pf p) { return p->enfant; }
pv voiture (pf p) { return p->voiture;}
void liberer_f(pf *p) { free(*p); *p=NULL;}
int freq_nom_f(ch20 nom, pf t )
{
    int cpt=0;
    while (t!=NULL)
    {
       if (strcmp(nom,nom_f(t))==0) {cpt++;}
       t=suivant_f(t);
    }
    return cpt ;
}
void afficher_f(pf p)
{
  while(p!=NULL)
 {
 printf("\nLe nom de la famille :%s\n",nom_f(p));
 printf("-------------------------------");
 printf("\n ->Les parents:\n");
 afficher_p(parent(p));
 printf("--------------------------------");
 printf("\n ->Les enfants :\n");
afficher_p(enfant(p));
  printf("--------------------------------");
 printf("\n ->Les voitures:\n");
 afficher_v(voiture(p));
 printf("\n\n         **********\n\n");
 p=suivant_f(p);
 }
}


 //creation des sous structures :

void random_num(ch20 num) // pour geneerer le matricule des voitures aleatoirement (10 chiffres)
{
    int i;char chiffre ;
    srand(rand()*time(NULL));
    for (i=0;i<10;i++)
    {
        chiffre=(rand()%10)+48;
        num[i]=chiffre;
    }
    num[i]='\0';
}

char random_sexe() // pour generer les sexes des enfants
{
    int s;char sx;
    srand(rand()*time(NULL));
    s=rand()%2;
    if (s==0 ) { sx='m';}
    else {sx='f';}
    return sx;
}

pv creer_voit(int n)
{
    int i  ; ch20 nom , num ;pv  p , q ,tete ;
    if (n==0) {tete=NULL;}
    if (n>=1)
    {
    allouer_v(&p);
    random_nom(5,15,nom);
    aff_marque(p,nom);
    random_num(num);
    aff_num(p,num);
    tete=p;
    for (i=1 ; i<n ; i++ )
    {
        allouer_v(&q);
        aff_adr_v(p,q);
        random_nom(5,15,nom);
        aff_marque(q,nom);
        random_num(num);
        aff_num(q,num);
        p=q;
    }
        aff_adr_v(p,NULL);
    }
    return tete;
}

pp creer_enf(int n)
{
    int i ;char sx ; ch20  nom; pp p , q , tete;
    if (n==0){tete =NULL;}
    else
    {
    random_nom(5,10,nom);
    allouer_p(&p);
    aff_nom_p(p,nom);
    sx=random_sexe();
    aff_sexe(p,sx);
    tete=p;
    for (i=1 ; i<n ; i++ )
    {
        allouer_p(&q);
        aff_adr_p(p,q);
        random_nom(5,10,nom);
        aff_nom_p(q,nom);
        sx=random_sexe();
        aff_sexe(q,sx);
        p=q;

    }
       aff_adr_p(p,NULL);
    }

    return tete;
}

pp creer_par() // limité a 2 , peut etre 1 ou 0
{
    pp p,q;ch20 nom1,nom2;char sx;int r;
    r=rand()%6;
    if (r==0){p=NULL;}
    else
    {
    allouer_p(&p);
    random_nom(5,10,nom1);
    aff_nom_p(p,nom1);
    sx=random_sexe();
    aff_sexe(p,sx);
    if (r!=1)
    {
        allouer_p(&q);
        aff_adr_p(p,q);
        do{random_nom(5,10,nom2);}while (strcpy(nom1,nom2)==0);
        aff_nom_p(q,nom2);
        if (sx=='f'){aff_sexe(q,'m');}
        else {aff_sexe(q,'f');}
        aff_adr_p(q,NULL);
    }
    else {aff_adr_p(p,NULL);}
    }
    return p;
}

pf creer_fam(int n)
{
    int i ,nbenf,nbvoit ; ch20  nom; pf p , q , tete;
    if (n==0){tete =NULL;}
    else
    {
    allouer_f(&p);
    random_nom(7,13,nom);
    aff_nom_f(p,nom);
    nbenf=rand()%10;
    aff_enfant(p,creer_enf(nbenf));
    aff_parent(p,creer_par());
    nbvoit=rand()%6;
    aff_voiture(p,creer_voit(nbvoit));
    tete=p;
    aff_adr_f(p,NULL);
    for (i=1 ; i<n ; i++ )
    {
        allouer_f(&q);
        do {random_nom(7,13,nom);} while (freq_nom_f(nom,tete)>1);
        aff_nom_f(q,nom);
        nbenf=rand()%10;
        aff_enfant(q,creer_enf(nbenf));
        aff_parent(q,creer_par());
        nbvoit=rand()%12;
        aff_voiture(q,creer_voit(nbvoit));
        aff_adr_f(p,q);
        aff_adr_f(q,NULL);
        p=q;
    }

    }

    return tete;
}


 //tri des listes
//pour le tri des enfants :

void permut_nom_p(pp p, pp q)
{
    ch20 inter;
    if ((q!=NULL)&&(p!=NULL))
    {
    strcpy(inter,nom_p(p));
    strcpy(nom_p(p),nom_p(q));
    strcpy(nom_p(q),inter);
    }

}

void permut_sexe(pp p, pp q)
{
    char  inter;
    if ((q!=NULL)&&(p!=NULL))
    {
    inter=sexe(q);
    aff_sexe(q,sexe(p));
    aff_sexe(p,inter);
    }

}

void trier_enf(pp *tete)
{
    pp t,p,q; ch20 min;
    t=*tete;
    while (t!=NULL)
    {
        p=t;
        strcpy(min,nom_p(t));
        while (p!=NULL)
        {
           if (strcmp(min,nom_p(p))>=0)
           {
               strcpy(min,nom_p(p));
               q=p;
           }
           p=suivant_p(p);
        }
        if (min!=nom_p(t)){permut_nom_p(t,q);permut_sexe(t,q);}
        t=suivant_p(t);
    }
}


//pour le tri de la pop:
pf creer_pop_2(int n)//genere aleatoirement une liste qui contient que les nomfam , utile pour effectuer le tri
{
    int i  ; ch20 nom; pf tete ,p , q ;
    random_nom(7,13,nom);
    allouer_f(&p);
    aff_nom_f(p,nom);
    aff_parent(p,NULL);
    aff_enfant(p,NULL);
    aff_voiture(p,NULL);
    tete=p;
    aff_adr_f(p,NULL);
    for (i=1 ; i<n ; i++ )
    {
        allouer_f(&q);
        do {random_nom(7,13,nom);} while (freq_nom_f(nom,tete)>1);
        aff_nom_f(q,nom);
        aff_parent(q,NULL);
        aff_enfant(q,NULL);
        aff_voiture(q,NULL);
        aff_adr_f(p,q);
        aff_adr_f(q,NULL);
        p=q;
    }
    return tete;
}

void permut_nom_f(pf p, pf q)//utilisee dans trier_pop_2
{
    ch20 inter;
    if ((q!=NULL)&&(p!=NULL))
    {
    strcpy(inter,nom_f(p));
    strcpy(nom_f(p),nom_f(q));
    strcpy(nom_f(q),inter);
    }

}

void trier_pop_2(pf *tete )//effectue le tri de la liste cree par la fonction creer_pop_2 ,utilisee dans creer_fam_triee
{
    pf t,p,q; ch20 min;
    t=*tete;
    while (t!=NULL)
    {
        p=t;
        strcpy(min,nom_f(t));
        while (p!=NULL)
        {
           if (strcmp(min,nom_f(p))>=0)
           {
               strcpy(min,nom_f(p));
               q=p;
           }
           p=suivant_f(p);
        }
        if (min!=nom_f(t)){permut_nom_f(t,q);}
        t=suivant_f(t);
    }
}


pf creer_fam_triee(int n) //fonction principale : genere une population triee par les nomfam ( avec engants et voitures ; les enfants ne sont pas tries)
{
    int nbenf,nbvoit ; pf  q , tete; pp enf ;
    if (n<=0){tete =NULL;}
    else
    {
    tete=creer_pop_2(n);
    trier_pop_2(&tete);
    q=tete;
    while(q!=NULL)
    {
        nbenf=rand()%10;
        enf=creer_enf(nbenf);
        trier_enf(&enf);
        aff_enfant(q,enf);
        aff_parent(q,creer_par());
        nbvoit=rand()%6;
        aff_voiture(q,creer_voit(nbvoit));
        q=suivant_f(q);
    }
    }

    return tete;
}

        //a:
int nbfamillesansparent(pf p)
{
    pp q;int cpt=0;
    while (p!=NULL)
    {
        q=parent(p);
        if (q==NULL) {cpt++;}
        p=suivant_f(p);
    }
    return cpt;
}

        //b:
int nbenfant(pf p)
{
    int cpt=0; pp q;
    while (p!=NULL)
    {
        q=enfant(p);
        while(q!=NULL){cpt++;q=suivant_p(q);}
        p=suivant_f(p);
    }
    return cpt ;
}


pf present_f(ch20 nom , pf tete )//utilisee dans les fonctions qui suivent
{
    int trouv=0 ;pf p;
    p=tete;
    while ((p!=NULL)&&(trouv==0))
    {
        if (strcmp(nom,nom_f(p))==0){trouv=1;}
        else {p=suivant_f(p);}
    }
    return p;
}

        //c:
 int nbenfnomfam(ch20 nomfam,pf tete)
 {
     pp p;pf f;int cpt=-1;
     f=present_f(nomfam,tete);
     if (f!=NULL)
     {
     cpt=0;
     p=enfant(f);
     while (p!=NULL){cpt++;p=suivant_p(p);}
     }
     return cpt;
 }


 void inser_enf_trie(pp *tete, ch20 nom , char sexe )//utilisee dans naissancetriee
 {
     pp p,q,l; int b=0  ;
    allouer_p(&q);aff_nom_p(q,nom);aff_sexe(q,sexe);aff_adr_p(q,NULL);
    if (*tete!=NULL)
    {
    if (strcmp(nom, nom_p(*tete))==-1) { aff_adr_p(q,*tete);*tete=q;}
    else
    {
    p=*tete;
    l=suivant_p(p);
    while ((b==0)&&(l!=NULL))
    {   if (strcmp(nom_p(p),nom)==0) {b=2;}
        else {
        if ((strcmp(nom_p(p),nom)==-1)&&(strcmp(nom,nom_p(l))==-1))
        {
            b=1;
            aff_adr_p(q,l);
            aff_adr_p(p,q);
        }
        else { p=l;l=suivant_p(l); }
            }
    }
    if ((l==NULL)&&(b==0)) { aff_adr_p(p,q);}
    }
    if(b==2){printf("le nom existe deja");}
    }
    else {*tete=q;}


 }

        //d:
 void naissancetriee( pf *p , ch20 nouveau_ne , char sexe )
 {
     pp q;
     q=enfant(*p);
     inser_enf_trie(&q,nouveau_ne,sexe);



 }


        //e:
pf Rechfamvoit_1(ch20 numero , pf tete)
 {
     pf p ; int trouv = 0 ; pv q ;
     p=tete ;
     while ((p!=NULL)&&(trouv==0))
    {
        q=voiture(p);
        while((q!=NULL)&&(trouv==0))
            { if (strcmp(numero,num(q))==0){trouv=1;}
              else {q=suivant_v(q);}
        }
     if (trouv==0) {p=suivant_f(p);}
    }
     return p ;
 }

        //f:


///=======fin de la deuxieme partie========//

