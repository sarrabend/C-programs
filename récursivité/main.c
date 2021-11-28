#include <stdio.h>
#include <stdlib.h>
#include "head.h"

int main()
{
    int a,b,op,i,n,tab[20],val; Maillon *tete,*q;
    printf("\n====MENU RECURSIVITE====\n");
    printf("1.somme de deux entiers .\n");
    printf("2.pgcd de deux entiers positifs .\n");
    printf("6.maximum d'une table\n");
    printf("6.minimum d'une table\n");
    printf("7.inverser une llc\n");
    printf("8.rechercher une valeur dans une llc\n");
    scanf("%d",&op);
    switch(op)
{
    case 1:
    printf("entrer les deux nombres que vous voulez additionner :");
    scanf("%d%d",&a,&b);
    printf("%d+%d=%d",a,b, som(a,b));
    break;
    case 2 :
    printf("entrer les deux nombres que vous voulez calculer le pgcd :");
    scanf("%d%d",&a,&b);
    printf("pgcd(%d,%d)=%d",a,b, pgcd(a,b));
    break;
    case 6:

    for (i=0;i<10;i++)
    {
        scanf("%d",&tab[i]);
    }
    printf("%d",MAX_tab(tab,10));
    break;
    case 7:
        scanf("%d",&n);
        tete=creation(n);
        afficher(tete);
        inv_llc(&tete);
        afficher(tete);
        break;
    case 8 :
        scanf("%d",&n);
        scanf("%d",&val);
        tete=creation(n);
        rech_val(tete,val,&q);
        if (q!=NULL) { printf("valeur gtrouvee");}
        else { printf("non trouvee");}
    break;
}
    return 0;
}
