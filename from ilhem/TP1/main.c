#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "headers1.h"
#include "headers2.h"

// BENDAHO SARRA
// BEKKAR ILHEM
// GROUPE 5


void menu_partie1()
{
    printf("\nPARTIE 1:\n");
    printf("==========\n");
    int n , partie1=0; pop *p;ch20 NOM ;pop *q;pop *l;
    printf("\nveuillez entrer le nombre de familles de votre population:");
    scanf("%d",&n);creer_pop(n,&p);
    printf("\nOn considere la population composee de %d familles\n",n);
    afficher_pop(p);
    printf("\n\npour un affichage meilleure , on a trie votre population , voici le resultat:\n");
    trier_pop(&p);
    afficher_pop(p);
    printf("\nvous pouvez effectuer les traitements suivants :\n");
    printf("    1 - Verifier si une famille appartient a la population .\n");
    printf("    2 - Ajouter une nouvelle famille dans votre population si elle n'y etait pas deja.\n");
    printf("    3 - Supprimer une  famille de votre population si elle  y etait deja.\n");
    printf("\n->Choisissez un traitement :");
    scanf("%d",&partie1);
    switch(partie1)
    {
    case 1:
        printf("\n\nDonnez le nom de famille a rechercher (en MAJUSCULE) : ") ; scanf("%s",NOM) ;
        present(NOM,p,&q,&l);
        if (l!=NULL){printf("\n  Effectivement, ce nom existe  dans votre population ");}
        else{printf("\n  Cette famille n'appartient  pas a votre population!\n");}
        printf("\ncliquer sur entrer pour revenir au menu principal...");
        getch();
        system("cls");
    break;
    case 2:
        printf("\nDonnez le nom de famille a inserer (en MAJUSCULE): ") ; scanf("%s",NOM) ;
        present(NOM,p,&q,&l);
        if (l==NULL)
        {inser_nom(NOM,&p);
        printf("\nVoici votre population apres avoir insere %s :\n",NOM);
        afficher_pop(p);}
        else { printf("   Ce nom existe deja dans votre population!");}
        printf("\n\ncliquer sur entrer pour revenir au menu principal...");
        getch();
        system("cls");
    break;
    case 3:
        printf("\n\n  Donner le nom de famille a supprimer (en MAJUSCULE) : ") ; scanf("%s",NOM) ;
        present(NOM,p,&q,&l);
        if (l!=NULL)
        {
            supp_nom(NOM,&p);
            printf("        Voici votre population apres avoir supprime %s\n",NOM);
            afficher_pop(p);
        }
        else { printf("   Ce nom n'existe pas dans votre population !");}
        printf("\n\ncliquer sur entrer pour revenir au menu principal...");
        getch();
        system("cls");
    break;
    }


}







void menu_partie2()
{   pf f,q,p;
    int partie2=0 ,n ,nbenfnmfm;
    ch20 nomfam,nomne,voit;
    char s ;
    printf("\nPARTIE 2:\n");
    printf("==========\n");
    printf("\nveuillez entrer le nombre de familles de votre population:");
    scanf("%d",&n);
    f=creer_fam_triee(n);
    printf("Voici votre liste de familles trie par ordre alphabetique ");
    afficher_f(f);
    printf("Vous avez le choix aux traitements suivants :\n");
    printf("    1 - Le nombre de familles   dont les parents sont decedes.\n");
    printf("    2 - Le nombre d'enfants de la communautee.\n");
    printf("    3 - Le nombre d'enfants d'une famille donnee .\n");
    printf("    4 - Inserer le prenom et le sexe d'un nouveau-ne d'une famille donnee.\n");
    printf("    5 - Rechercher le nom de la famille qui possede la voiture du matricule donne .\n");
    printf("\n->choisissez un traitement:");
    scanf("%d",&partie2);
    switch(partie2)
    {
        case 1:
        printf("\nle nombre de familles dont les parents sont decedes est : %d ",nbfamillesansparent(f) );
        printf("\n\ncliquer sur entrer pour revenir au menu principal...");
        getch();
        system("cls");
        break;
        case 2:
        printf("\nle nombre d'enfants de la communautee est : %d",nbenfant(f) );
        printf("\n\ncliquer sur entrer pour revenir au menu principal...");
        getch();
        system("cls");
        break;
        case 3:
        printf("\ndonner le nom de famille (en MAJUSCULE):"); scanf("%s",nomfam);
        nbenfnmfm=nbenfnomfam(nomfam,f);
        if (nbenfnmfm==-1){printf("la famille %s n'existe pas dans la caumunaute .",nomfam);}
        else{printf("\nla famille %s a %d enfants ",nomfam,nbenfnmfm);}
        printf("\n\ncliquer sur entrer pour revenir au menu principal...");
        getch();
        system("cls");
        break;
        case 4:
        printf("\ndonner le nom de famille (en MAJUSCULE) :"); scanf("%s",nomfam);
        p=present_f(nomfam,f);
        if (p!=NULL)
        {
         printf("on felicite la famille %s pour leur nouveau-ne ",nomfam);
         printf("\nentrer le prenom du nouveau-ne (en MAJUSCULE)  ainsi que son sexe ('m' ou 'f') :\n");
         printf("   le prenom :");
         scanf("%s",nomne);
         printf("   le sexe :");
         while(getchar()!='\n');
         scanf("%c",&s);
         naissancetriee(&p,nomne,s);
         afficher_f(f);
        }
        else {printf("cette famille n'existe pas dans la liste des familles . "); }
        printf("\n\ncliquer sur entrer pour revenir au menu principal...");
        getch();
        system("cls");
          break;

        case 5:
         printf("\nentrer le numero de la voiture a rechercher :");
         scanf("%s",voit);
         q=Rechfamvoit_1(voit,f);
         if (q!=NULL) {printf(" cette voiture appartient a la famille %s\n",nom_f(q));}
         else { printf("cette voiture n'appartient a aucune famille dans cette population");}
        printf("\n\ncliquer sur entrer pour revenir au menu principal...");
        getch();
        system("cls");
        break;
        case 6:

        break;
    }

}












int main()
{
    int partie=0;

        printf("  ______   ______     _\n");
    printf(" | _____| / _____|   |_|  Ecole Nationale\n ");
    printf("| |____  | /_____    _       \n ");
    printf("|  ____| |______ |  | |  superieure  \n");
    printf(" | _____   _____| |  | |\n");
    printf(" |______| |______/   |_|  d'informatique   \n");
    printf("\n\n          Premier TP d'algorithmique et structure de donnees dynamiques\n");
    printf(" ____                                                                         _\n");
    printf("|  _ \\    ___    ___    ___   _ __    ___    ___   _ __ ___     ___   _ __   | |_\n");
    printf("| |_) |  / _ \\  / __|  / _ \\ | '_ \\  / __|  / _ \\ | '_ ` _ \\   / _ \\ | '_ \\  | __|\n");
    printf("|  _ <  |  __/ | (__  |  __/ | | | | \\__ \\ |  __/ | | | | | | |  __/ | | | | | |_\n");
    printf("| _| \_\\  \\___|  \\___|  \\___| |_| |_| |___/  \\___| |_| |_| |_|  \\___| |_| |_|  \\__|\n\n");

    printf("                   _    _                      \n");
printf("                __| | /_/  _   _   _ __     ___  \n");
printf("               / _` |     | | | | | '_ \\   / _ \\ \n");
printf("              | (_| |     | |_| | | | | | |  __/ \n");
printf("               \\__,_|      \\__,_| |_| |_|  \\___| \n\n");

printf("                                  _            _     _   \n");
printf("  _ __     ___    _ __    _   _  | |    __ _  | |_  (_)    ___    _ __ \n");
printf(" | '_ \\   / _ \\  | '_ \\  | | | | | |  / _`  | | __| | |   / _ \\  | '_ \\ \n");
printf(" | |_) | | (_) | | |_) | | |_| | | |  | (_| | | |_  | |  | (_) | | | | |\n");
printf(" | .__/   \\___/  | .__/   \\__,_| |_|   \\__,_|  \\__| |_|   \\___/  |_| |_|\n");
printf(" |_|             |_|                                                          \n\n");
printf("_______________________________________________________________________________________\n");

printf("                                 REALISE PAR :\n");
printf("                         BEKKAR Ilhem | BENDAHO Sarra\n");
printf("                            Section B | Groupe 05\n\n");
printf("                                                          ANNEE UNIVERSITAIRE : 2019/2020");
getch();
system("cls");
    printf("\n*************************** Bienvenus dans notre application de gestion ****************************************\n ");
    printf("\n\nOn s'interessera a une communaute algerienne composee de plusieurs familles  limitees a deux generations.\nOn a deux parties : \n ");
    printf("\n1 - On se limitera a des familles composees uniquement des noms de familles dans la PREMIERE PARTIE.\n ");
    printf("2 - On ajoutera dans la DEUXIEME PARTIE les parents, les enfants et les voitures possedees par une famille.  ");
    printf("\n\nCliquer sur entrer pour lancer l'application ...\n");
    getch();
    do
    {
    printf("\n\n==========MENU PRINCIPAL=========\n");
    printf("1.PARTIE 1.\n");
    printf("2.PARTIE 2.\n");
    printf("3.TERMINER ET QUITTER L'APPLICATION.\n");
    printf("\n\nVeuillez effectuer votre choix :  ");
    scanf("%d",&partie) ;
    system("cls");
    switch(partie){

        case 1:menu_partie1()      ;
         break;
        case 2: menu_partie2() ;
         break ;
        case 3: return 0;

                    }
    } while (partie!=3);
    return 0;
}

