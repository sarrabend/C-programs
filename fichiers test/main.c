#include <stdio.h>
#include<time.h>
#define N 20
typedef struct statpays
{
    char nompays[20];
    int ND;
    int NR;
} statpays ;

int main(int argc, char *argv[])
{
FILE* fichier = NULL;
int nb,i=0,n;
char mot[10];
srand(time(NULL));
n=rand()%21+1;
printf("%d\n",n);
fichier = fopen("mots.txt", "r");
if (fichier != NULL)
{
    fscanf(fichier,"%d",&nb);
    printf("ce fichier contient %d mots \n",nb);
    while ((fgets(mot,nb,fichier)!=NULL)&&(i<=n))
    {
        i++;
        printf("\nle mot : %s",mot);
    }

    printf("le mot choisis :%s",mot);



fclose(fichier);
}



return 0;
}




