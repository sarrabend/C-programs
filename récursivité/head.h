#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED
//===modele llc===
typedef struct Maillon { int val; struct Maillon *next;} Maillon;
void allouer(Maillon **nouveau);
void aff_adr(Maillon *p,Maillon *q);
void aff_val(Maillon *p, int valeur);
Maillon *suivant(Maillon *p);
int valeur(Maillon *p);
void liberer(Maillon**ancien);
Maillon *creation(int n);
void afficher(Maillon *p);
//===============

int som_n(int n);
int quot(int a,int b);
int reste(int a,int b);
int pgcd(int a,int b);
int som(int a,int b);
int MAX_tab(int tab[20],int l);
int min_tab(int tab[20],int l);
void inv_llc(Maillon **l);
void rech_val(Maillon *tete,int val,Maillon **q);
#endif // HEAD_H_INCLUDED
