#ifndef HEADERS2_H_INCLUDED
#define HEADERS2_H_INCLUDED


///=======deuxieme partie========//

typedef char ch20[20] ;

    // structure  voiture :
struct voiture  { ch20 marque ; ch20 num ; struct voiture *next ; } ;
typedef struct voiture  *pv;
        //machine abstraite :
void allouer_v(pv *nouveau);
void aff_adr_v(pv p,pv q);
void aff_num(pv p, ch20 num );
void aff_marque(pv p, ch20 marque);
pv suivant_v(pv p);
char* marque(pv p) ;
char* num(pv p);
void liberer_v(pv *ancien);
void afficher_v(pv p) ;

    //structure  personne :
 struct personne { ch20 nom ; char sexe ; struct personne *next ;  };
typedef struct personne  *pp;
        //machine abstraite:
void allouer_p(pp *nouveau );
void aff_adr_p(pp p,pp q) ;
void aff_nom_p(pp p, ch20 nom ) ;
void aff_sexe(pp p, char sx) ;
pp suivant_p(pp p) ;
char* nom_p(pp p);
char sexe(pp p) ;
void afficher_p(pp p) ;
void liberer_p(pp *p);
int freq_nom_p(ch20 nom, pp t );

    //structure famille :
 struct famille { ch20 nom ; pp parent ; pp enfant ; pv voiture ; struct famille *next ; } ;
typedef struct famille  *pf ;
        //machine abstraite :
void allouer_f(pf *nouveau ) ;
void aff_adr_f(pf p,pf q) ;
void aff_nom_f(pf p, ch20 nom );
void aff_parent(pf p, pp q);
void aff_enfant(pf p, pp q) ;
void aff_voiture(pf p , pv q);
pf suivant_f(pf p) ;
char* nom_f(pf p) ;
pp parent(pf p);
pp enfant(pf p) ;
pv voiture (pf p) ;
void afficher_f(pf p) ;
int freq_nom_f(ch20 nom, pf t );
void liberer_f(pf *p);

    //creation des sous structures :
void random_num(ch20 num);//pour generer les matricules
char random_sexe();// pour generer les sexes des enfants
pv creer_voit(int n);
pp creer_enf(int n);
pp creer_par(); // limité a 2 , peut etre 1 ou 0
    //creation da la structure globale
pf creer_fam(int n);//creer une pop non triee
    //tri des listes
//pour le tri des enfants :
void permut_nom_p(pp p, pp q);
void permut_sexe(pp p, pp q);
void trier_enf(pp *tete);
// pour generer une population triee par les nomfam :
pf creer_pop_2(int n);//genere une liste qui contient que les nomfam , utile pour effectuer le tri
void permut_nom_f(pf p, pf q);//utililsee dans trier_pop_2
void trier_pop_2(pf *tete );//effectue le tri de la liste cree par la fonction creer_pop_2 ,utilisee dans creer_fam_triee
pf creer_fam_triee(int n); //fonction principale : genere une population triee par les nomfam ( avec engants et voitures ; les enfants ne sont pas tries)
            //a:
int nbfamillesansparent(pf p);
            //b:
int nbenfant(pf p);

pf present_f(ch20 nom , pf tete );// utilisee dans les fonctions qui suivent
            //c:
int nbenfnomfam(ch20 nomfam,pf tete);

void inser_enf_trie(pp *tete, ch20 nouveau_nom , char sexe );// utilisee dans naissance_triee
            //d:
void naissancetriee(pf* p  , ch20 nouveau_ne , char sexe );
            //e:
pf Rechfamvoit_1(ch20 numero , pf tete);

#endif // HEADERS2_H_INCLUDED
