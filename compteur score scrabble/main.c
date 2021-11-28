#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<conio.h>

int main()
{
   int s=0,j1=0,j2=0,score;
   /*char* joueur1,joueur2;
   printf("\njoueur 1:");
   scanf("%s",joueur1);
   printf("\njoueur 2:");
   scanf("%s",joueur2); */
   printf ("\nBienvenus dans notre application !\n");
   while  (s!=2)
   {
      printf("\nscore de djawad : ");
      scanf("%d",&score);
      j1=j1+score;
      printf("\nscore de sarra : ");
      scanf("%d",&score);
      j2=j2+score;
      printf("\ndjawad  : %d       sarra :  %d",j1,j2);
      printf("\n entrer: 1-tour suivant    2-pour terminer et quitter lapplication \n");
      scanf("%d",&s);
      getch();
      system("cls");
   }
    return 0;
}
