#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"headers.h"
#include<conio.h>
#include<ctype.h>
#include<time.h>

int main()
{
    int choix=0 , nbcoups=0 ;
    char mot[10];
    choix_mot(mot );
    printf("***BIENVENUE DANS LE PENDU*** \n\n");
    printf("=> PRINCIPE DU JEU : \n VOUS AVEZ UN MOT CHOISIS AU HAZARD , ESSAYER DE DEVOILER CE MOT LETTRE PAR LETTRE EN SUIVANT LES CONSIGNES \n" );
    printf("\nVOUS AVEZ DONC 3 NIVEAUX DE DIFFICULTE :\n");
    printf("    1.FACILE : ECHEC APRES 50 TENTATIVES \n");
    printf("     2.MOYEN : ECHEC APRES 30 TENTATIVES\n");
    printf("       3.DIFFICILE : ECHEC APRES 10 TENTATIVES \n");
    printf("\n CHOISISSEZ VOTRE NIVEAU  :\n");
    do
    {
    scanf("%d",&choix);
    } while ((choix<0)&&(choix>3));
    switch (choix)
    {
    case 1:
        nbcoups=50;
        jeu(nbcoups,mot);
     break;
    case 2:
        nbcoups=30;
        jeu(nbcoups,mot);
     break;
    case 3:
        nbcoups=10;
        jeu(nbcoups,mot);
    break;
    }

    return 0;
}
