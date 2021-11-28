#include <stdio.h>
#include <stdlib.h>


int rech_dich(int t[] , int l ,int val )
{
    int d=0,f=l-1 , pos=-1 , m;
    do
    {
        m=(f+d)/2;
        if (t[m]==val)  pos=m;
        else
        {
            if (t[m]<val ) d=m+1;
            else f=m-1;
        }
    } while ( (pos==-1)&&(d<=f));
    return pos ;
}


int rech_seq(int t[],int l, int val)
{ int i=0;
  int pos=-1;
 while ( (i<l)&&(pos==-1) )
 {
   if (t[i]==val )
   {
       pos=i;
   }
   i++;


 }
 return pos ;

}



int main() // mise a jour d'un tableau ordonne //

{
    int   nb=10 , i=0 ,pos ,j ,val ,p, op , b=0 , typtab , t1[100]={1,2,3,4,5,7,8,10,22,30} , t2[100]={5,4,8,7,0,24,17,10,9,1};
    printf("1.tableau ordonne\n2.tableau non ordonne \n");
    scanf("%d",&typtab);
    switch(typtab)
    {

    case 1 :

    printf("=====menu tableau ordonne ======\n");
    printf("11.suppression d'un element\n");
    printf("12.insertion d'un element\n");
    printf("13.recherche d'un element\n");
    printf("option :");
    scanf("%d",&op);

    switch(op)
    {
    case 11 : //suppression de val de t //
        printf("donner la valeur a supprimer :");
        scanf("%d",&val);
        pos=rech_dich(t1,nb,val);
        if (pos!=-1)
        {
            i=pos;
            while (i<nb)
            {
                t1[i]=t1[i+1];
                i++;
            }
        }
        else printf("valeur non existante ");
         for (i=0;i<9;i++)
        {
        printf("%d | ",t1[i]);
        }
        break;

    case 12 : //insertion de val dans t1//
        printf("donner la valeur a inserer :");
        scanf("%d",&val);
        pos=rech_seq(t1,nb,val);
        if(pos==-1 )
        {
        t1[10]=val;
        i=9;
        while (t1[i]>val)
        {
        p=t1[i];
        t1[i]=t1[i+1];
        t1[i+1]=p;
        i--;
        }
        for (i=0;i<=10;i++)
        {
        printf("%d | ",t1[i]);
        }
        }
        else {printf("cette valeur existe deja dans votre tableau ");}
        break;

    case 13 ://recherche  d'un element //

        printf("donner la valeur a rechercher : \n ");
        scanf("%d",&val);
        pos =rech_dich(t1,nb,val);
        if (pos==-1 )
        {
            printf("valeur non trouvée ");

        }
        else
        {
            printf("valeur trouvee ");
        }
    break;

    }
    break;
    case 2 :

        printf("=====menu tableau non ordonne ======\n");
        printf("21.suppression d'un element\n");
        printf("22.insertion d'un element\n");
        printf("23.recherche d'un element\n");
        printf("option:");
        scanf("%d",&op);
        printf("\n");
        switch(op)
        {
        case 21 :
        printf("donner la valeur a supprimer :");
        scanf("%d",&val);
        pos=rech_seq(t2,nb,val);
        if (pos!=-1)
        {
            t2[pos]=t2[9];
             for (i=0;i<9;i++)
            {
                printf("%d | ",t2[i]);
            }
        }
        else printf("valeur non existante ");
        break;

        case 22 : //insertion de val dans t//
        printf("donner la valeur a inserer :");
        scanf("%d",&val);
        pos=rech_seq(t2,nb,val);
        if(pos==-1 )
        {
        t2[10]=val;
        for (i=0;i<=10;i++)
        {
        printf("%d | ",t2[i]);
        }
        }
        else {printf("cette valeur existe deja dans votre tableau ");}
        break;

        case 23 ://recherche  d'un element //

        printf("donner la valeur a rechercher : \n ");
        scanf("%d",&val);
        pos =rech_seq(t2,nb,val);
        if (pos==-1 )
        {
            printf("valeur non trouvee ");

        }
        else
        {
            printf("valeur trouvee dans la %d eme position ",pos+1 );
        }
        break;
        }


    }

    return 0;
}





