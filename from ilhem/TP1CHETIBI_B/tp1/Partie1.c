#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*Chetibi Bouchra G4 -monome- */


typedef struct Maillon { char val[21]; struct Maillon *next;} Maillon;

void allouer(Maillon **nouveau)  //Allouer un espace memoire
{ *nouveau=(Maillon*)malloc(sizeof(Maillon));}
//************************************************************
void aff_adr(Maillon *p,Maillon *q) //Affecter une adresse memoire
{p->next=q;}
//*******************************************************************
void aff_val(Maillon *p, char valeur[]) //Affecter une valeur au maillon(ici la valeur est une chaine de caractere)
{ strcpy(p->val, valeur);}
//***************************************************
char* valeur(Maillon *p) //Acceder a la valeur du maillon
{return p->val;}
//****************************************************************
Maillon *suivant(Maillon *p) //Acceder au maillon qui suit un maillon
{return p->next;}
//****************************************************************************
void liberer(Maillon** ancien) //liberer un maillon

{free(*ancien); *ancien=NULL;}
//******************************************************************

Maillon *creer_pop(int N) // creer une population a partir d'un nombre donné
{
Maillon *tete,*p,*q;
int i,k,r;
char nom[21];
const int A=97 , Z=122;
allouer(&p);
k=(rand() % (20 - 3+ 1)) + 3;
for(r=0 ; r<k ; r++)    //generation des noms
    {  nom[r] = rand() % (Z - A + 1) + A ;  }
    nom[k]='\0' ;
    aff_val(p,nom);
    tete=p;

for (i=1; i<N; i++)
    {allouer(&q);
    k=(rand() % (20 - 3+ 1)) + 3;
    for(r=0;r<k;r++)
        {nom[r] = rand() % (Z - A + 1) + A ;}
nom[k]='\0';
    aff_val(q,nom);
    aff_adr(p,q);
    p=q;}
aff_adr(p,NULL);
return tete;
}
//***********************************************************************
void afficher(Maillon *p)  //Afficher une liste
{
while(p!=NULL)
{printf(" {%s} ",valeur(p));
 p=suivant(p);}
}
//************************************************************************
 Maillon *inser(Maillon *p, char val[21])
{
    Maillon *suiv,*pre,*inseree;
    allouer(&inseree);
    aff_val(inseree,val);
    pre=p;
    suiv=suivant(pre);
    while(suiv!=NULL)
    {
      if (strcmp(val,valeur(p))<0)
        {
        aff_adr(inseree,p);
        p=inseree;
        }
      if((strcmp(valeur(pre),val)<0) && (strcmp(val,valeur(suiv))<0))
       {
        aff_adr(pre,inseree);
        aff_adr(inseree,suiv);
       }
     pre=suiv;
     suiv=suivant(suiv);
    }
  if (strcmp(val,valeur(pre))>0)
   {
       aff_adr(pre,inseree);
       aff_adr(inseree,NULL);
   }
  return p;
}
//***************************************************************************
int nbfamille(Maillon *t)
{int r=0;
Maillon *k;

k=t;
while (k!=NULL)
{r=r+1;
    if ((suivant(k)!=NULL)&&(valeur(k)==valeur(suivant(k)))) //Si deux maillons ont le meme nom
        {k=suivant(suivant(k));}
    else
    {
        k=suivant(k);
    }
}
return r;
}
//*****************************************************************************
Maillon *present(Maillon *t, char cher[21])
{
    Maillon *p,*k;
    k=NULL;
    p=t;
    while( p!=NULL)
    {if (strcmp(valeur(p),cher)==0)
         {k=p;}
         p=suivant(p);
    }
return k;
}
//***************************************************************************
int supp(Maillon *p, char val[21])
{
    Maillon *pre,*suiv,*reche;
    reche=p;
    suiv=suivant(reche);
    if (reche==p)
        {
            p=suiv;
        }
    while( suiv!=NULL && strcmp(val,valeur(reche))!=0 )
        {
            if (strcmp(val,valeur(reche))!=0)
            {
            pre=reche;
            suiv=suivant(reche);
            reche=suiv;
            }
        }
            if (reche==NULL)
            {
                pre=NULL;
                liberer(&reche);
            }
            else
            {suiv=suivant(reche);
            aff_adr(pre,suiv);
            liberer(&reche);
            }
return p;
}
//************************************************************************
Maillon *trier_pop(Maillon *tete)

{int boolean,i;
Maillon *t,*p,*r;
allouer(&r);
do
{p=tete;
 boolean=0;
    while(p!=NULL)
        {t=suivant(p);
        if (t!=NULL)
            {
    if(strcmp(valeur(p),valeur(t))>0)
    {for (i=0;i<21;i++)
        {r->val[i]=p->val[i];
        p->val[i]=t->val[i];
        t->val[i]=r->val[i];
                }
                 boolean=1;
              }
            }
                 p=suivant(p);
        }
}
while(boolean!=0);
return tete ;   }
//*******************************************************************************

int main()
{srand(time(NULL));
    int choix=0,nombre,nb,n;
char nom[20];
Maillon *tete;
Maillon *adresse;

    printf("Bonjour!Ce programme va vous permettre de creer une population et de lui effectuer certaines modifications comme inserer un nouveau nom ou supprimer un autre.\n\ncommencons d'abord par creer la population,choissisez un nombre (supperieur à 1 bien evidement).\n");
    printf("votre nombre est: ");
    scanf("%d",&nombre);

    while (nombre<1)
    {printf("La population ne peut pas etre creer,veuillez entrer votre nombre de nouveau\n\n");
    scanf("%d",&nombre);};

    tete=creer_pop(nombre);
    tete=trier_pop(tete);
    afficher(tete);
    n=nbfamille(tete);
    printf("\n\nLe nombre de familles est:");
    printf("%d",n);

    printf("\n\nLa population a bien ete cree,nous avons aussi pris la peine de la trier pour vous!\n\nMaintenant,essayons d'effectuer quelques changements dans cette population\n\n");

    printf("Voulez-vous savoir si une famille precise est presente dans la population?\n\n");
    printf("1)oui       2)non           ecrivez le numero du choix\nVotre choix: ");
    scanf("%d",&choix);

    while ((choix>2)||(choix<1))
    {printf("Le choix que vous avez choisit n'ai pas valide,veuillez entrer votre choix de nouveau\n\n");
    scanf("%d",&choix);};

   if (choix==1)
    {printf("\nEntrez donc le nom que vous voulez savoir s'il est present dans la population(le nom doit contenir entre 3 et 20 caracteres)\n");
     printf("Le nom: ");
    scanf("%s",&nom);

    adresse=present(tete,nom);

    if (adresse==NULL)
    {printf("\nLa famille n'existe pas dans la population\n");}
    else
    {printf("\nLa famille est presente dans la populatin\n");}}


    printf("\n\nVoulez-vous maintenant inserer un nom precis?\n\n");
    printf("1)oui      2)non         ecrivez le numero du choix\nVotre choix: ");
    scanf("%d",&choix);

    while ((choix>2)||(choix<1))
    {printf("Le choix que vous avez choisit n'ai pas valide,veuillez entrer votre choix de nouveau\n\n");
    scanf("%d",&choix);}

     if (choix==1)
        {printf("Entrez le nom que vous voulez inserer(le nom doit contenir entre 3 et 20 caracteres)\n");
         printf("Le nom: ");
        scanf("%s",&nom);

        if (present(tete,nom)!=NULL)
        {printf("\nLe nom que vous essayez d'inserer existe deja");}

        else
        {tete=inser(tete,nom);
        afficher(tete);}}


    printf("\n\nVoulez-vous maintenant supprimer un nom precis?\n\n");
    printf("1)oui      2)non         ecrivez le numero du choix\nVotre choix: ");
    scanf("%d",&choix);

    while ((choix>2)||(choix<1))
    {printf("Le choix que vous avez choisit n'ai pas valide,veuillez entrer votre choix de nouveau\n\n");
    scanf("%d",&choix);}

     if (choix==1)
        {printf("Entrez le nom que vous voulez supprimer(le nom doit contenir entre 3 et 20 caracteres)\n");
         printf("Le nom: ");
        scanf("%s",&nom);
        if (present(tete,nom)==NULL)
        {printf("\nLe nom que vous essayez de supprimer n'existe pas");}

        else
        {tete=supp(tete,nom);
        afficher(tete);}}

        printf("\n\n\nmerci\n\n\n");
        return 0;}
