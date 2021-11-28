#ifndef HEADERS1_H_INCLUDED
#define HEADERS1_H_INCLUDED

typedef char ch20[20] ;

///======fonctions utilisees dans les deux parties====== //
void random_nom(int MIN ,int MAX,ch20 nom);


///====== premiere partie======//
        //structure:
typedef struct pop{ch20 nomfam ; struct pop *next ;} pop ;
        //machine abstraite :
void allouer(pop **nouveau);
void aff_adr(pop *p,pop *q);
void aff_nom(pop *p, ch20 nom);
pop *suivant(pop *p);
char *nom_fam(pop *p);
void liberer(pop**ancien);
void afficher_pop(pop *p);
        //fonctions demandees
int freq_nom(ch20 nom, pop* t );//utilisee pour traiter les doublons
void permut_nom(pop* p, pop* q);// utilisee dans trier_pop
            //a:
void creer_pop(int n, pop **tete);
            //b:
void trier_pop(pop** tete );
            //c:
int nb_famille(pop *tete);
            //d:
void present(ch20 nom ,pop *tete , pop **p, pop **q);
            //e:
void inser_nom(ch20 nom , pop **tete );
            //f:
void supp_nom(ch20 nom, pop** tete );
///=======fin de la premiere partie ======//




#endif // HEADERS1_H_INCLUDED
