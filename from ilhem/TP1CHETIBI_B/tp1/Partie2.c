#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
/*Chetibi Bouchra G4 -monome-*/

/*Affin d'assurer le bon fonctionement du programme,certaines règles doivent etre respectées:
1)Assurez vous que les noms des fichiers téléchargés sont:  voiture.txt   prenom.txt  nom.txt (aucun caractere suplementaire).
2)Assurez vous que les fichiers sont dans le meme repertoire que le code source.
3)Les noms et les prenoms saisis doivent commencer par des majuscules.
4)Le genre saisis doit etre en minuscule.
5)Pour mieux comprendre le changement qu'apportent les modules sur la population, veuillez choissir un nombre petit de familles
  cree(20,30,40...)*/

typedef struct famille *pf ;
typedef struct personne *pp ;
typedef struct voiture *pv ;
typedef struct famille { char nom[21] ;pp parent ;pp enfant;pv voiture ; struct famille *next;} famille;
typedef struct personne { char prenom[21] ;char sexe;struct personne *next;} personne;
typedef struct voiture { char marque[21] ;char numero[21];struct voiture *next;} voiture;
/***************************************************************************************************************************************/
void creefamille(pf *nouveau) //Creer un maillon de famille >
{ *nouveau=(famille*)malloc(sizeof(famille));}
/***************************************************************************************************************************************/
void creepersonne(pp *nouveau) //creer un maillon de personne >
{ *nouveau=(personne*)malloc(sizeof(personne));}
/***************************************************************************************************************************************/
void creevoiture(pv *nouveau) //creer un maillon de voiture >
{ *nouveau = malloc(sizeof(voiture));}
/***************************************************************************************************************************************/
void aff_adrf(pf p,pf q) //Affecter l'adresse de suivant famille
{p->next=q;}
/***************************************************************************************************************************************/
void aff_adrp(pp p,pp q) //Affecter l'adresse de suivant personne
{p->next=q;}
/***************************************************************************************************************************************/
void aff_adrv(pv p,pv q) //Affecter l'adresse de suivant voiture
{p->next=q;}
/***************************************************************************************************************************************/
void aff_nom(pf p, char valeur[]) //Affecter le nom de famille au maillon(ici la valeur est une chaine de caractere) >
{ strcpy(p->nom, valeur);}
/***************************************************************************************************************************************/
void aff_prenom(pp p, char valeur[]) //Affecter le prenom de la personne au maillon(ici la valeur est une chaine de caractere) >
{ strcpy(p->prenom, valeur);}
/***************************************************************************************************************************************/
void aff_sexe(pp p, char valeur) //Affecter le sexe de la personne au maillon(ici la valeur est un caractere) >
{ p->sexe = valeur;}
/***************************************************************************************************************************************/
void aff_marque(pv p, char valeur[]) //Affecter la marque de la voiture au maillon(ici la valeur est une chaine de caractere) >
{ strcpy(p->marque, valeur);}
/***************************************************************************************************************************************/
void aff_numero(pv p, char valeur[]) //Affecter le matricule de la voiture au maillon(ici la valeur est une chaine de caractere) >
{ strcpy(p->numero, valeur);}
/***************************************************************************************************************************************/
pf suivantfamille(pf p) //afficher la famille suivante
{return p->next;}
/***************************************************************************************************************************************/
pp suivantpersonne(pp p) //afficher la personne suivante
{return p->next;}
/***************************************************************************************************************************************/
pv suivantvoiture(pv p) //afficher la voiture suivante
{return p->next;}
/***************************************************************************************************************************************/
char *valeurnom(pf p) //afficher le nom de la famille >
{return p->nom;}
/***************************************************************************************************************************************/
char *valeurprenom(pp p) //afficher le prenom de la personne >
{return p->prenom;}
/***************************************************************************************************************************************/
char valeursexe(pp p) //afficher le sexe de la personne >
{return p->sexe;}
/***************************************************************************************************************************************/
char* valeurmarque(pv p) //afficher la marque de la voiture >
{return p->marque;}
/***************************************************************************************************************************************/
char* valeurnumero(pv p) //afficher le numero de la voiture >
{return p->numero;}
/***************************************************************************************************************************************/
pp valeurptrparent(pf s) //atribuer des parents pour la famille
{return (s->parent);}
/***************************************************************************************************************************************/
pp valeurptrenfant(pf s) //atribuer des enfants pour la famille
{return (s->enfant);}
/***************************************************************************************************************************************/
pv valeurptrvoiture(pf s) //atribuer des voitures pour la famille
{return (s->voiture);}
/***************************************************************************************************************************************/
void aff_familleparent(pf p,pp q) //Affecter l'adresse des parents dans la case de la famille
{p->parent=q;}
/***************************************************************************************************************************************/
void aff_familleenfant(pf p,pp q) //Affecter l'adresse des enfants dans la case de la famille
{p->enfant=q;}
/***************************************************************************************************************************************/
void aff_famillevoiture(pf p,pv q) //Affecter l'adresse des voitures dans la case de la famille
{p->voiture=q;}
/***************************************************************************************************************************************/
void afficherpersonnes(pp p)  //Afficher la liste des personnes
{
  while(p!=NULL)
  {
     printf("Le prenom est %s et le genre est %c \n",valeurprenom(p),valeursexe(p));
     p=suivantpersonne(p);
  }
}
/***************************************************************************************************************************************/
void afficherfamilles(pf p)  //Afficher la liste des familles
{
   while(p!=NULL)
   {
      printf("Le nom de famille est %s", valeurnom(p));
      p=suivantfamille(p);
   }
}
/***************************************************************************************************************************************/
void affichervoitures(pv p)  //Afficher la liste des voitures
{
   while ( p != NULL )
   {
      printf("La voiture est de la marque %s et son numero de serie est %s \n",valeurmarque(p),valeurnumero(p));
      p = suivantvoiture(p);
   }
}
/***************************************************************************************************************************************/
pp personesss(int nn) /*creer une liste de personnes ,le principe conciste à compter le nombre de lignes dans un
                        fichier puis de choissir une ligne aleatoire dans le meme fichier*/
{
   pp s,tete,l ;
   int rndm,n = 0;
   int k;
    if (nn==0)
    {
        tete=NULL;
    }
  else
  {
      FILE* fichier=fopen("prenom.txt","r");

      //compter le nombre de lignes dans le fichier
      int nblignes = 0;
      char character[21],chara[21];

      while(!feof(fichier))
      {
          fgets(character,21,fichier);
          nblignes=nblignes+1;
      }

      //recuperer une ligne aléatoire
      rndm=(rand() % (nblignes - 1 + 1)) + 1 ;

      fseek(fichier, 0L, SEEK_SET);

      while (n != rndm)
      {
         fgets(chara,21,fichier);
         n++;
      }

      //separer le nom et le genre
      char nom[21] , genre;
      int i = 0;

      while ( chara[i] != ',' ) {
         nom[i] = chara[i];
         i++;
      }
      nom[i] = '\0';
      genre = chara[i+1];

      creepersonne( &s );
      aff_prenom(s,nom);
      aff_sexe(s,genre);
      tete=s;


      for (k=1; k <nn; k++) //creation des autres personnes
      {
       creepersonne(&l);
       rndm=(rand() % (nblignes - 1 + 1)) + 1 ;

       fseek(fichier, 0L, SEEK_SET);
       n = 0;
       while (n != rndm)
       {
          fgets(chara,21,fichier);
          n++;
       }

       i = 0;
       while ( chara[i] != ',' )
       {
           nom[i] = chara[i];
           i++;
       }
       nom[i] = '\0';
       genre = chara[i+1];

       aff_prenom(l,nom);
       aff_sexe(l,genre);
       aff_adrp(s,l);
       s=l;
      }

      aff_adrp(s,NULL);
      fclose(fichier);
   }
   return tete;

}
/***************************************************************************************************************************************/
pf famillesss(int nn) /*creer une liste de familles ,le principe conciste à compter le nombre de lignes dans un
                        fichier puis de choissir une ligne aleatoire dans le meme fichier*/
{
   pf s,tete,l ;
   int rndm,n = 0;
   int k;
    if (nn==0)
    {
        tete=NULL;
    }
  else
  {
   FILE* fichie=fopen("nom.txt","r");

   //compter le nombre de lignes dans le fichier
   int nblignes = 0;
   char character[21],chara[21];

   while(!feof(fichie))
   {
       fgets(character,21,fichie);
       nblignes=nblignes+1;
   }

   //recuperer une ligne aléatoire
   rndm=(rand() % (nblignes - 1 + 1)) + 1 ;

   fseek(fichie, 0L, SEEK_SET);

   while (n != rndm)
   {
      fgets(chara,21,fichie);
      n++;
   }


   creefamille( &s );
   aff_nom(s,chara);
   tete=s;


   for (k=1; k <nn; k++) //creer les autres familles
   {
       creefamille(&l);
       rndm=(rand() % (nblignes - 1 + 1)) + 1 ;

       fseek(fichie, 0L, SEEK_SET);
       n = 0;
       while (n != rndm)
       {
          fgets(chara,21,fichie);
          n++;
       }

       aff_nom(l,chara);
       aff_adrf(s,l);
       s=l;
   }

   aff_adrf(s,NULL);
    fclose(fichie);}
   return tete;

}
/***************************************************************************************************************************************/
pv voituresss(int nn)   /*creer une liste de voitures ,le principe conciste à compter le nombre de lignes dans un
                        fichier puis de choissir une ligne aleatoire dans le meme fichier,le matricule est generé aletoirement*/
{
   pv s,tete,l;
   int rndm,n = 0;
   int k;

   int i;

   char matricule[14];
    if (nn==0)
    {
        tete=NULL;
    }
    else
    {
      FILE* fichi=fopen("voiture.txt","r");

      //compter le nombre de lignes dans le fichier
      int nblignes = 0;
      char character[100],chara[100];

      while(!feof(fichi))
      {
	fgets(character,100,fichi);
        nblignes = nblignes + 1;
      }

      //recuperer une ligne aléatoire
      rndm=(rand() % (nblignes - 1 + 1)) + 1 ;

      fseek(fichi, 0L, SEEK_SET);

      while (n != rndm)
      {
	 fgets(chara,100,fichi);
         n++;
      }

      i = 0;
      while ( i < 20 && chara[i] != '\0' && chara[i] != '\r' && chara[i] != '\n' ) i++;
      chara[i] = '\0';

      matricule[0]=rand()% (57-(49)+1)+49;  //creation du matricule
      matricule[1]=rand()% (57-(48)+1)+48;
      matricule[2]=rand()% (57-(48)+1)+48;
      matricule[3]=rand()% (57-(48)+1)+48;
      matricule[4]=rand()% (57-(48)+1)+48;
      matricule[5]=rand()% (57-(48)+1)+48;
      matricule[6]=45;
      matricule[7]=49;
      matricule[8]=49;
      matricule[9]=rand()% (57-(48)+1)+48;
      matricule[10]=45;
      matricule[11]=rand()% (52-(48)+1)+48;
      matricule[12]=rand()% (56-(48)+1)+49;
      matricule[13]='\0';

      creevoiture(&s);
      aff_marque(s,chara);
      aff_numero(s,matricule);
      aff_adrv(s , NULL);
      tete=s;

      for (k=1; k <nn; k++) //creation des autres voitures
      {
         rndm=(rand() % (nblignes - 1 + 1)) + 1 ;
         fseek(fichi, 0L, SEEK_SET);
         n = 0;
         while (n != rndm)
         {
	   fgets(chara,100,fichi);
           n++;
         }

         i = 0; /*cette partie est utilisé pour regler un probleme lie à la difference entre les systemes de fichiers dans
                    les differents systemes d'exploitation*/
        while ( i < 20 && chara[i] != '\0' && chara[i] != '\r' && chara[i] != '\n' ) i++;
         chara[i] = '\0';



         matricule[0]=rand()% (57-(49)+1)+49;
         matricule[1]=rand()% (57-(48)+1)+48;
         matricule[2]=rand()% (57-(48)+1)+48;
         matricule[3]=rand()% (57-(48)+1)+48;
         matricule[4]=rand()% (57-(48)+1)+48;
         matricule[5]=rand()% (57-(48)+1)+48;
         matricule[6]=45;
         matricule[7]=49;
         matricule[8]=49;
         matricule[9]=rand()% (57-(48)+1)+48;
         matricule[10]=45;
         matricule[11]=rand()% (52-(48)+1)+48;
         matricule[12]=rand()% (56-(48)+1)+49;
         matricule[13]='\0';

         creevoiture(&l);
         aff_marque(l,chara);
         aff_numero(l,matricule);

         aff_adrv(s,l);
         s = l;

      }

      aff_adrv(s,NULL);
      fclose(fichi);
   }
   return tete;

}
/***************************************************************************************************************************************/
pp parentsss(int nn) //creer des parents de genres differents pour chaque famille a partir d'un fichier,
{
   pp s,tete,l ;
   int rndm,n = 0;
   int sauvrndm1;
   int k;

   if (nn==0)
    {
        tete=NULL;
    }
   else
   {
      FILE* fichier=fopen("prenom.txt","r");

      //compter le nombre de lignes dans le fichier
      int nblignes = 0;
      char character[21],chara[21];

      while(!feof(fichier))
      {
          fgets(character,21,fichier);
          nblignes=nblignes+1;
      }

      //recuperer une ligne aléatoire
      rndm=(rand() % (nblignes - 1 + 1)) + 1 ;
      sauvrndm1 = rndm;

      fseek(fichier, 0L, SEEK_SET);

      while (n != rndm)
      {
         fgets(chara,21,fichier);
         n++;
      }

      //separer le nom et le genre
      char nom[21] , genre;
      int i = 0;

      while ( chara[i] != ',' ) {
         nom[i] = chara[i];
         i++;
      }
      nom[i] = '\0';
      genre = chara[i+1];
      creepersonne( &s );
      aff_prenom(s,nom);
      aff_sexe(s,genre);
      tete=s;
      for (k=1; k <nn; k++)
      {
         creepersonne(&l);

         do 	//pour ne pas que le nombre aleatoire genere la deuxieme fois soit egal a celui de la deuxieme fois
          rndm = (rand() % (nblignes - 1 + 1)) + 1 ;
         while (rndm == sauvrndm1);

         fseek(fichier, 0L, SEEK_SET);
         n = 0;
         char noms[21];
         char genres='k';
         while (n != rndm)
         {
           fgets(chara,21,fichier);
           n++;
           i = 0;
           while ( chara[i] != ',' )
           {
             noms[i] = chara[i];
             i++;
           }
           noms[i] = '\0';
           genres = chara[i+1];
         }

         if (genre==genres) //si le genre de la 1ere personne est le meme que la 2eme
         {
           fseek(fichier, 0L, SEEK_SET);
           do
           {fgets(chara,21,fichier);
              i = 0;
              while ( chara[i] != ',' )
                    {
			noms[i] = chara[i];
                        i++;
                    }
               noms[i] = '\0';
               genres = chara[i+1];
           } while (genre==genres);

         };
         aff_prenom(l,noms);
         aff_sexe(l,genres);
         aff_adrp(s,l);
         s=l;
      }
      aff_adrp(s,NULL);
      fclose(fichier);
   }

   return tete;

}
/***************************************************************************************************************************************/
int nbenfant(pf f) //calculer le nombre d'enfants dans la population
{   int nb=0;
    pp p;
    while(f!=NULL)
    {   p=valeurptrenfant(f);
        while(p!=NULL)
          {   nb=nb+1;;
              p=suivantpersonne(p);
          }
        f=suivantfamille(f);
    }
return nb;
}
/***************************************************************************************************************************************/
int nbfamillesansparent(pf f) //calculer le nombre de familles sans parents
{   int fspar=0;
    pp p;
    while(f!=NULL)
    { p=valeurptrparent(f);
         if(p==NULL)
         {
             fspar=fspar+1;
         }
      f=suivantfamille(f);
    }
return fspar;}
/***************************************************************************************************************************************/
int nbenfnomfam(pf f, char nomf[21]) //Calculer le nombre d'enfans dans une famille precise
{   int nb=0;
    pp p;
    int boolean=0;

    while(f!=NULL)

    {if((strcmp(valeurnom(f),nomf)==1)&&(boolean==0))
                 {boolean=1;
                     p=valeurptrenfant(f);
                    while(p!=NULL )
                          {nb=nb+1;
                           p=suivantpersonne(p);
                           }
                 }
    f=suivantfamille(f);

    }
return nb;}
/***************************************************************************************************************************************/
pf Rechfamvoit_1(pf f, char *voit) //savoir la famille a qui apartient une voiture quelconque
{
    pv v;
    pf res=NULL;
    while( f!=NULL )
    {
         v=valeurptrvoiture(f);
    while(v!=NULL)
    {
        if ( strcmp(voit,valeurnumero(v))==0)
         {
              res=f;
         }
         v=suivantvoiture(v);
    }

    f=suivantfamille(f);
    }
return res;
}
/***************************************************************************************************************************************/
pf naissancetrie(pf f,char *nom,char *prenom,char genre) //ajouter un nouveau nee a la population dans une famille precise
{   pf s;
    pp p,k,m;
    creepersonne(&p);
    aff_prenom(p,prenom);
    aff_sexe(p,genre);
    int boolean=0;
    s=f;
    while (s!=NULL)
    {if ((strcmp(valeurnom(s),nom)==1)&&(boolean==0))
        {boolean=1;
        k=valeurptrenfant(s);
        if (k==NULL)
            {
                aff_familleenfant(s,p);
            }
        else
               {m=k;
                   while(suivantpersonne(k)!=NULL)
                    {
                        k=suivantpersonne(k);
                    }
                aff_adrp(k,p);
                trier_personnes(m);
                aff_familleenfant(s,m);
                }
        }
        s=suivantfamille(s);
    }

return f;}
/***************************************************************************************************************************************/
pf trier_familles(pf tete) // trier la liste des noms de familles par ordre alphabetique
{
    int boolean,i;
	pf sui,pre,inter;
	creefamille(&inter);
	do
	{ pre=tete;
	    boolean=0;

	    while(pre!=NULL)
         {sui=suivantfamille(pre);
             if (sui!=NULL)
              {if(strcmp(valeurnom(sui),valeurnom(pre))<0)
               { for(i=0;i<20;i++)
                  {inter->nom[i] = pre->nom[i];
                    pre->nom[i] = sui->nom[i];
                    sui->nom[i] = inter->nom[i];}
                    boolean=1;}}
            pre=suivantfamille(pre);
            }
     } while(boolean!=0);
return tete;}
/***************************************************************************************************************************************/
int trier_personnes(pp tete) // trier la liste des noms de personnes par ordre alphabetique
{
    int boolean,i;
	pp pre,sui,interm;
	creepersonne(&interm);
	do
	{  pre=tete;
	    boolean=0;

	    while(pre!=NULL)
         {sui=suivantpersonne(pre);
             if (sui!=NULL)
              {if(strcmp(valeurprenom(sui),valeurprenom(pre))<0)
               { for(i=0;i<20;i++)
                  {interm->prenom[i] = pre->prenom[i];
                    pre->prenom[i] = sui->prenom[i];
                    sui->prenom[i] = interm->prenom[i];}
                    (interm->sexe) = (pre->sexe);
                    (pre->sexe)= (sui->sexe);
                    (sui->sexe)= (interm->sexe);
                    boolean=1;}}
            pre=suivantpersonne(pre);}
     } while(boolean!=0);
return tete;}
/***************************************************************************************************************************************/
pf creer_pop(int nb) //creer une population qui est triée
{ int par,enf,vo;
pf r;
pp pars;
pp enfa;
pv voit;
pf fam;

fam=famillesss(nb);
r=fam;
fam=trier_familles(fam);
    while (fam!=NULL)
    {par=rand() % 3;
     enf=rand() % 11;
     vo=rand() % 6;

     pars=parentsss(par); //creer les parents(ils sont ordonnes)
     pars=trier_personnes(pars);
     aff_familleparent(fam,pars);

     enfa=personesss(enf); //creer les enfants(ils sont ordonnes)
     enfa=trier_personnes(enfa);
     aff_familleenfant(fam,enfa);

     voit=voituresss(vo); //creer des voitures
     aff_famillevoiture(fam,voit);

     fam=suivantfamille(fam);
    }
return r;
}
/***************************************************************************************************************************************/
void afficherpop(pf p)  //Afficher la population
{pp k,l;
 pv m;

   while(p!=NULL)
   {printf("\n********************************************************************************\n");
    printf("Le nom de famille:%s",valeurnom(p)); //affiche le nom de famille

    k=valeurptrparent(p); //afficher les parents
    printf("\nLes parents:\n");
    afficherpersonnes(k);

    l=valeurptrenfant(p); //afficher les enfants
    printf("\nLes enfants:\n");
    afficherpersonnes(l);

    m=valeurptrvoiture(p); //afficher les voitures
    printf("\nLes voitures:\n");
    affichervoitures(m);

    p=suivantfamille(p);
   }
  printf("\n********************************************************************************\n");
}
/***************************************************************************************************************************************/
int main()
{int nb,n,nombre,enf,choix;
pf popul,adr;
pp pa;
char fam[21],numeroo[21],nom[21],prenom[21],genre;
srand(time(NULL));

printf("Veuillez entrer le nombre de familles que vous desirez creer :");
scanf(" %d",&nb);
popul=creer_pop(nb);
afficherpop(popul);
printf("La population est cree et triee\n\n");
n=nbfamillesansparent(popul);
printf("Le nombre de familles sans parents est : %d\n\n",n);
nombre=nbenfant(popul);
printf("Le nombre d'enfants de la population est : %d\n\n",nombre);
printf("Veuillez entrer le nom de famille dont vous desirez avoir le nombre d'enfants \n");
scanf("%s",&fam);
enf=nbenfnomfam(popul,fam);
printf("\nLe nombre d'enfants dans la famille %s est : %d \n\n",fam,enf);


printf("\nVoulez-vous inserer un nouveau ne dans la population?\n");
printf("1)oui             2)non       Entrer le numero de votre choix\n");
printf("choix: ");

scanf("%d",&choix);
if (choix==1)
{printf("\nEntrer le nom de famille:");
scanf("%s",&nom);
printf("\nEntrer le prenom du nouveau ne(prenez compte de la majuscule):");
scanf("%s",&prenom);
printf("\nEntrer le genre du nouveau ne:");
scanf(" %c",&genre);
popul=naissancetrie(popul,nom,prenom,genre);
afficherpop(popul);}
printf("\n\nAfin de chercher les proprietaires d'une voiture volee\n");
printf("Veuillez entrer le matricule de la voiture : \n");
scanf("%s",&numeroo);
adr=Rechfamvoit_1(popul,numeroo);
if (adr!=NULL)
{printf("\nLe nom de la famille victime est : %s\n\n\n",valeurnom(adr));}
else
{printf("\nLa voiture n'appartient a aucune famille\n\n\n");}

return 0;}
