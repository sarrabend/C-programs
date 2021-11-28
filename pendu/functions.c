#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#include<time.h>
#include"headers.h"

void choix_mot(char mot [])
{
    FILE* fichier = NULL;
int nb,i=0,n;
srand(time(NULL));
n=rand()%21+1;
fichier = fopen("mots.txt", "r");
if (fichier != NULL)
{
    fscanf(fichier,"%d",&nb);
    while ((fgets(mot,nb,fichier)!=NULL)&&(i<=n))
    {
        i++;
    }

fclose(fichier);
}
int l=strlen(mot);
mot[l-1]='\0';

    }

char lireCar()
{
    char c = 0 ;
    c = getchar();
    c = toupper (c);
    while ( getchar() != '\n') ;
    return c ;

}

void rechCar( char c , char  const mot[] , int *exist , int *pos )
{
    int i=0;
    int l=strlen(mot);
    *exist=0;
    for (i=0;i<l;i++)
    {
        if ( mot[i]==c ) {  *exist=1; *pos=i;}

    }
    if  ( *exist==0 ) { *pos=-1; }
}

void jeu(int n , char  mot[] )
{

    char car=0,motInter [10] ,motTrouve [10] ;
    strcpy(motInter,mot);
    int i=0 ,l=strlen(mot) ;
    for(i=0;i<l;i++)
    {
        motTrouve[i]='*';
    }
    motTrouve[l]='\0';
    printf("\n CLIQUEZ SUR C POUR COMMENCER :");
    getch();
    car = lireCar();
    int trouv=0;
    while (( n>=0 )&&( trouv==0 ))
    {
        int pos=-1;
        int exist=0;
        printf("\nESSAYER UNE LETTRE :");
        car = lireCar();
        rechCar(car,motInter,&exist,&pos);
        if (exist==1)
        {
            motTrouve[pos]=car;
            motInter[pos]='*';
            printf("%s\n",motTrouve);
            printf("\nBRAVO! VOUS AVEZ DEVOILE UNE LETTRE DU MOT  : %s :) \n",motTrouve) ;
            if ( strcmp(motTrouve,mot) == 0){ trouv =1  ;}
        }
        else
        {
            n--;
            printf("\nFAUSSE LETTRE :( IL VOUS RESTE  %d COUPS \n" ,n);
        }


    }
    if (trouv==1) {printf("\nGENIAAL ! VOUS AVEZ GAGNE ET DECOUVERT LE MOT %s \n",mot);}
}
