  /**--------------------------------------------------------**/
  /**       C o n v e r s i o n   Z vers C (Standard)        **/
  /**             Réalisée par Pr D.E ZEGOUR                 **/
  /**             E S I - Alger                              **/
  /**             Copywrite 2014                             **/
  /**--------------------------------------------------------**/

  #include <stdio.h>
  #include <stdlib.h>

  typedef int bool ;
  typedef char * string255 ;
  typedef char * string2 ;

  #define True 1
  #define False 0

  /** Implémentation **\: TABLEAU DE ARBRES BINAIRES DE STRUCTURES**/

  /** Structures statiques **/

  typedef struct Tssic Type_Tssic  ;
  typedef Type_Tssic * Typestr_Tssic ;
  typedef string255 Type1_Tssic  ;
  typedef string255 Type2_Tssic  ;
  typedef int Type3_Tssic  ;
  typedef string2 Type4_Tssic  ;
  struct Tssic
    {
      Type1_Tssic Champ1 ;
      Type2_Tssic Champ2 ;
      Type3_Tssic Champ3 ;
      Type4_Tssic Champ4 ;
    };

  Type1_Tssic Struct1_Tssic ( Typestr_Tssic S)
    {
      return  S->Champ1 ;
    }

  Type2_Tssic Struct2_Tssic ( Typestr_Tssic S)
    {
      return  S->Champ2 ;
    }

  Type3_Tssic Struct3_Tssic ( Typestr_Tssic S)
    {
      return  S->Champ3 ;
    }

  Type4_Tssic Struct4_Tssic ( Typestr_Tssic S)
    {
      return  S->Champ4 ;
    }

  void Aff_struct1_Tssic ( Typestr_Tssic S, Type1_Tssic Val )
    {
      strcpy( S->Champ1 , Val );
    }

  void Aff_struct2_Tssic ( Typestr_Tssic S, Type2_Tssic Val )
    {
      strcpy( S->Champ2 , Val );
    }

  void Aff_struct3_Tssic ( Typestr_Tssic S, Type3_Tssic Val )
    {
       S->Champ3 = Val ;
    }

  void Aff_struct4_Tssic ( Typestr_Tssic S, Type4_Tssic Val )
    {
      strcpy( S->Champ4 , Val );
    }


  /** Arbres de recherche binaire **/

  typedef Typestr_Tssic Typeelem_ATssic   ;
  typedef struct Noeud_ATssic * Pointeur_ATssic ;

  struct Noeud_ATssic
    {
      Typeelem_ATssic  Val ;
      Pointeur_ATssic Fg ;
      Pointeur_ATssic Fd ;
      Pointeur_ATssic Pere ;
     } ;

  Typeelem_ATssic Info_ATssic( Pointeur_ATssic P )
    { return P->Val;   }

  Pointeur_ATssic Fg_ATssic( Pointeur_ATssic P)
    { return P->Fg ; }

  Pointeur_ATssic Fd_ATssic( Pointeur_ATssic P)
    { return P->Fd ; }

  Pointeur_ATssic Pere_ATssic( Pointeur_ATssic P)
    { return P->Pere ; }

  void Aff_info_ATssic ( Pointeur_ATssic P, Typeelem_ATssic Val)
    {
      Typeelem_ATssic _Temp ;
      _Temp = malloc(sizeof(Typestr_Tssic));
      _Temp->Champ1 = malloc(255 * sizeof(string255));
      _Temp->Champ2 = malloc(255 * sizeof(string255));
      _Temp->Champ4 = malloc(2 * sizeof(string2));
      /* Affectation globale de structure */
      strcpy(_Temp->Champ1, Val->Champ1);
      strcpy(_Temp->Champ2, Val->Champ2);
      _Temp->Champ3 = Val->Champ3;
      strcpy(_Temp->Champ4, Val->Champ4);
      Val = _Temp ;
       P->Val = Val ;
    }

  void Aff_fg_ATssic( Pointeur_ATssic P, Pointeur_ATssic Q)
    { P->Fg =  Q;  }

  void Aff_fd_ATssic( Pointeur_ATssic P, Pointeur_ATssic Q)
    { P->Fd =  Q ; }

  void Aff_pere_ATssic( Pointeur_ATssic P, Pointeur_ATssic Q)
    { P->Pere =  Q ; }

  void Creernoeud_ATssic( Pointeur_ATssic *P)
    {
      *P = (struct Noeud_ATssic *) malloc( sizeof( struct Noeud_ATssic))   ;
      (*P)->Val = malloc(sizeof(Typestr_Tssic));
      (*P)->Val->Champ1 = malloc( 255 * sizeof(string255));
      (*P)->Val->Champ2 = malloc( 255 * sizeof(string255));
      (*P)->Val->Champ4 = malloc( 2 * sizeof(string2));
      (*P)->Fg = NULL;
      (*P)->Fd = NULL;
      (*P)->Pere = NULL;
    }

  void Liberernoeud_ATssic( Pointeur_ATssic P)
    { free( P ) ; }


  /** Tableaux **/

  typedef Pointeur_ATssic Typeelem_V100ATssic ;
  typedef Typeelem_V100ATssic * Typevect_V100ATssic ;

  Typeelem_V100ATssic Element_V100ATssic ( Typevect_V100ATssic V , int I1  )
    {
      return  *(V + I1-1 ) ;
    }

  void Aff_element_V100ATssic ( Typevect_V100ATssic V  , int I1 ,  Typeelem_V100ATssic Val )
    {
      *(V + I1-1 ) = Val ;
    }


  /** Implémentation **\: ARBRE BINAIRE DE STRUCTURES**/

  /** Structures statiques **/

  typedef struct Tiic Type_Tiic  ;
  typedef Type_Tiic * Typestr_Tiic ;
  typedef int Type1_Tiic  ;
  typedef int Type2_Tiic  ;
  typedef string2 Type3_Tiic  ;
  struct Tiic
    {
      Type1_Tiic Champ1 ;
      Type2_Tiic Champ2 ;
      Type3_Tiic Champ3 ;
    };

  Type1_Tiic Struct1_Tiic ( Typestr_Tiic S)
    {
      return  S->Champ1 ;
    }

  Type2_Tiic Struct2_Tiic ( Typestr_Tiic S)
    {
      return  S->Champ2 ;
    }

  Type3_Tiic Struct3_Tiic ( Typestr_Tiic S)
    {
      return  S->Champ3 ;
    }

  void Aff_struct1_Tiic ( Typestr_Tiic S, Type1_Tiic Val )
    {
       S->Champ1 = Val ;
    }

  void Aff_struct2_Tiic ( Typestr_Tiic S, Type2_Tiic Val )
    {
       S->Champ2 = Val ;
    }

  void Aff_struct3_Tiic ( Typestr_Tiic S, Type3_Tiic Val )
    {
      strcpy( S->Champ3 , Val );
    }


  /** Arbres de recherche binaire **/

  typedef Typestr_Tiic Typeelem_ATiic   ;
  typedef struct Noeud_ATiic * Pointeur_ATiic ;

  struct Noeud_ATiic
    {
      Typeelem_ATiic  Val ;
      Pointeur_ATiic Fg ;
      Pointeur_ATiic Fd ;
      Pointeur_ATiic Pere ;
     } ;

  Typeelem_ATiic Info_ATiic( Pointeur_ATiic P )
    { return P->Val;   }

  Pointeur_ATiic Fg_ATiic( Pointeur_ATiic P)
    { return P->Fg ; }

  Pointeur_ATiic Fd_ATiic( Pointeur_ATiic P)
    { return P->Fd ; }

  Pointeur_ATiic Pere_ATiic( Pointeur_ATiic P)
    { return P->Pere ; }

  void Aff_info_ATiic ( Pointeur_ATiic P, Typeelem_ATiic Val)
    {
      Typeelem_ATiic _Temp ;
      _Temp = malloc(sizeof(Typestr_Tiic));
      _Temp->Champ3 = malloc(2 * sizeof(string2));
      /* Affectation globale de structure */
      _Temp->Champ1 = Val->Champ1;
      _Temp->Champ2 = Val->Champ2;
      strcpy(_Temp->Champ3, Val->Champ3);
      Val = _Temp ;
       P->Val = Val ;
    }

  void Aff_fg_ATiic( Pointeur_ATiic P, Pointeur_ATiic Q)
    { P->Fg =  Q;  }

  void Aff_fd_ATiic( Pointeur_ATiic P, Pointeur_ATiic Q)
    { P->Fd =  Q ; }

  void Aff_pere_ATiic( Pointeur_ATiic P, Pointeur_ATiic Q)
    { P->Pere =  Q ; }

  void Creernoeud_ATiic( Pointeur_ATiic *P)
    {
      *P = (struct Noeud_ATiic *) malloc( sizeof( struct Noeud_ATiic))   ;
      (*P)->Val = malloc(sizeof(Typestr_Tiic));
      (*P)->Val->Champ3 = malloc( 2 * sizeof(string2));
      (*P)->Fg = NULL;
      (*P)->Fd = NULL;
      (*P)->Pere = NULL;
    }

  void Liberernoeud_ATiic( Pointeur_ATiic P)
    { free( P ) ; }


  /** Implémentation **\: PILE DE ARBRES BINAIRES DE STRUCTURES**/
  /** Piles **/

  typedef Pointeur_ATssic Typeelem_PATssic ;
  typedef struct Maillon_PATssic * Pointeur_PATssic ;
  typedef   Pointeur_PATssic  Typepile_PATssic  ;

  struct Maillon_PATssic
    {
      Typeelem_PATssic  Val ;
      Pointeur_PATssic Suiv ;
    } ;

  void Creerpile_PATssic( Pointeur_PATssic *P )
    { *P = NULL ; }

  bool Pilevide_PATssic ( Pointeur_PATssic P )
    { return  (P == NULL ); }

  void Empiler_PATssic ( Pointeur_PATssic *P,  Typeelem_PATssic Val )
    {
      Pointeur_PATssic Q;

      Q = (struct Maillon_PATssic *) malloc( sizeof( struct Maillon_PATssic))   ;
      Q->Val = Val ;
      Q->Suiv = *P;
      *P = Q;
    }

  void Depiler_PATssic ( Pointeur_PATssic *P,  Typeelem_PATssic *Val )
    {
      Pointeur_PATssic Sauv;

      if (! Pilevide_PATssic (*P) )
        {
          *Val = (*P)->Val ;
          Sauv = *P;
          *P = (*P)->Suiv;
          free(Sauv);
        }
      else printf ("%s \n", "Pile vide");
    }


  /** Implémentation **\: PILE DE ARBRES BINAIRES DE STRUCTURES**/
  /** Piles **/

  typedef Pointeur_ATiic Typeelem_PATiic ;
  typedef struct Maillon_PATiic * Pointeur_PATiic ;
  typedef   Pointeur_PATiic  Typepile_PATiic  ;

  struct Maillon_PATiic
    {
      Typeelem_PATiic  Val ;
      Pointeur_PATiic Suiv ;
    } ;

  void Creerpile_PATiic( Pointeur_PATiic *P )
    { *P = NULL ; }

  bool Pilevide_PATiic ( Pointeur_PATiic P )
    { return  (P == NULL ); }

  void Empiler_PATiic ( Pointeur_PATiic *P,  Typeelem_PATiic Val )
    {
      Pointeur_PATiic Q;

      Q = (struct Maillon_PATiic *) malloc( sizeof( struct Maillon_PATiic))   ;
      Q->Val = Val ;
      Q->Suiv = *P;
      *P = Q;
    }

  void Depiler_PATiic ( Pointeur_PATiic *P,  Typeelem_PATiic *Val )
    {
      Pointeur_PATiic Sauv;

      if (! Pilevide_PATiic (*P) )
        {
          *Val = (*P)->Val ;
          Sauv = *P;
          *P = (*P)->Suiv;
          free(Sauv);
        }
      else printf ("%s \n", "Pile vide");
    }


  /** Implémentation **\: TABLEAU DE STRUCTURES**/

  /** Tableaux **/

  typedef Typestr_Tiic Typeelem_V1000Tiic ;
  typedef Typeelem_V1000Tiic * Typevect_V1000Tiic ;

  Typeelem_V1000Tiic Element_V1000Tiic ( Typevect_V1000Tiic V , int I1  )
    {
      return  *(V + I1-1 ) ;
    }

  void Aff_element_V1000Tiic ( Typevect_V1000Tiic V  , int I1 ,  Typeelem_V1000Tiic Val )
    {
      Typeelem_V1000Tiic _Temp ;
      _Temp = malloc(sizeof(Typestr_Tiic));
      _Temp->Champ3 = malloc(2 * sizeof(string2));
      /* Affectation globale de structure */
      _Temp->Champ1 = Val->Champ1;
      _Temp->Champ2 = Val->Champ2;
      strcpy(_Temp->Champ3, Val->Champ3);
      Val = _Temp ;
      *(V + I1-1 ) = Val ;
    }


  /** Variables du programme principal **/
  Typevect_V100ATssic T;
  int N;
  int I;
  int Age;
  int Nb;
  string2 Res;
  Pointeur_ATssic R;
  Pointeur_ATiic A;

  /** Fonctions standards **/

  int Aleanombre( int N )
    { return ( rand() % N ); }

  char  *Aleachaine ( int N )
    {
      int k;
      char  * Chaine = malloc(N+1);

      char Chr1[26] = "abcdefghijklmnopqrstuvwxyz";
      char Chr2[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

      for (k=0;k<N; k++)
        switch ( rand() % 2 ){
        case 0 :  *(Chaine+k) = Chr1[rand() % 26] ; break ;
        case 1 :  *(Chaine+k) = Chr2[rand() % 26] ; break ;
        }
      Chaine[k] =  '\0' ;

      return (Chaine);
    }


  /** Prototypes des fonctions **/

  void Aleacar (string2 *C);
  Pointeur_ATssic Creer_arb1 (int *M) ;
  void Creer_struct1 (int *N , Typevect_V100ATssic *T);
  void Afficher_arb1 (Pointeur_ATssic *R);
  void Afficher_struct1 (Typevect_V100ATssic *T , int *N);
  int  Occ_arb (Pointeur_ATssic *R , int *Age , string2 *Res) ;
  int  Occ_tab (Typevect_V100ATssic *T , int *I , int *N , int *Age , string2 *Res) ;
  void Parcours (Pointeur_ATssic *R , Typevect_V100ATssic *T , int *I , int *N , Pointeur_ATiic *A);
  Pointeur_ATiic Creer_struct2 (Typevect_V100ATssic *T , int *N) ;
  void Afficher_arb2 (Pointeur_ATiic *R);
  void Creer_tableau (Pointeur_ATiic *R , Typevect_V1000Tiic *T , int *Taille);
  int  Intervalle (Typevect_V1000Tiic *T , int *Taille , int *A , int *B , string2 *Res) ;
  int  Sup (Typevect_V1000Tiic *T , int *Taille , int *A , string2 *Res) ;
  int  Inf (Typevect_V1000Tiic *T , int *Taille , int *B , string2 *Res) ;
  void Pourcent (Pointeur_ATiic *R);

  void Aleacar (string2 *C)
    {
      /** Variables locales **/
      int A;

      /** Corps du module **/
     A  =  Aleanombre(2 ) ;
     if( A == 1)   {
       strcpy (*C,   "D") ;
       }
     else
       {
       strcpy (*C,   "R") ;

     } ;

    }
  /*1ere question*/
  Pointeur_ATssic Creer_arb1 (int *M)
    {
      /** Variables locales **/
      Pointeur_ATssic Creer_arb12 ;
      Pointeur_ATssic R;
      Pointeur_ATssic P;
      Pointeur_ATssic Q;
      Typestr_Tssic S;
      int Ag;
      int I;
      string2 Res;
      string255 Ch;

      /** Corps du module **/
     S = malloc(sizeof(Typestr_Tssic));
     S->Champ1 = malloc(255 * sizeof(string255));
     S->Champ2 = malloc(255 * sizeof(string255));
     S->Champ4 = malloc(2 * sizeof(string2));
     Res = malloc(2 * sizeof(string2));
     Ch = malloc(255 * sizeof(string255));
     Creernoeud_ATssic(&P ) ;
     Ag  =  Aleanombre(80 ) + 1 ;
     Aff_struct1_Tssic(S  , Aleachaine(7 ) ) ;
     Aff_struct2_Tssic(S  , Aleachaine(5 ) ) ;
     Aff_struct3_Tssic(S  , Ag ) ;
     Aleacar ( & Res ) ;
     Aff_struct4_Tssic(S  , Res ) ;
     R  =  P ;
     Aff_info_ATssic(P , S ) ;
     for( I  =  2 ;I <=  *M ; ++I){
       Ag  =  Aleanombre(80 ) + 1 ;
       Aff_struct1_Tssic(S  , Aleachaine(5 ) ) ;
       Aff_struct2_Tssic(S  , Aleachaine(7 ) ) ;
       Aff_struct3_Tssic(S  , Ag ) ;
       Aleacar ( & Res ) ;
       Aff_struct4_Tssic(S  , Res ) ;
       Q  =  R ;
       P  =  R ;
       while( ( Q != NULL ) && ( Ag != Struct3_Tssic(Info_ATssic(P )  ) ))  {
         P  =  Q ;
         if( Ag < Struct3_Tssic(Info_ATssic(P )  )) {
           Q  =  Fg_ATssic(Q ); }
         else
           {
           Q  =  Fd_ATssic(Q );
         }
       } ;
       if( Ag != Struct3_Tssic(Info_ATssic(P )  )) {
         Creernoeud_ATssic(&Q ) ;
         Aff_info_ATssic(Q , S ) ;
         if( ( Ag < Struct3_Tssic(Info_ATssic(P )  ) )) {
           Aff_fg_ATssic(P , Q ); }
         else
           {
           Aff_fd_ATssic(P , Q );
         } ;

       } ;

     } ;
     Creer_arb12  =  R ;

     return Creer_arb12 ;
    }
  void Creer_struct1 (int *N , Typevect_V100ATssic *T)
    {
      /** Variables locales **/
      int I;
      Pointeur_ATssic R;
      int _Px1;

      /** Corps du module **/
     for( I  =  1 ;I <=  *N ; ++I){
       _Px1 =  5 ;
       R  =  Creer_arb1 ( &_Px1) ;
      /* on a pris le nombre de personne de chaque pays=20*/
       Aff_element_V100ATssic(*T , I   , R ) ;

     }
    }
  /* 2eme question :*/
  void Afficher_arb1 (Pointeur_ATssic *R)
    {
      /** Variables locales **/
      Pointeur_ATssic N;
      Pointeur_PATssic P;
      bool F;

      /** Corps du module **/
     N  =  *R ;
     F  =  False ;
     Creerpile_PATssic(&P ) ;
     while( ( ! F ))  {
       while( ( N != NULL ))  {
         Empiler_PATssic(&P , N ) ;
         N  =  Fg_ATssic(N ) ;

       } ;
       if( ( ! Pilevide_PATssic(P ) ))   {
         Depiler_PATssic(&P , &N ) ;
         printf ( " %s", "NOM:" ) ;
         printf ( " %s", Struct1_Tssic(Info_ATssic(N)) ) ;
         printf ( " %s", "PRENOM:" ) ;
         printf ( " %s", Struct2_Tssic(Info_ATssic(N)) ) ;
         printf ( " %s", "AGE:" ) ;
         printf ( " %d", Struct3_Tssic(Info_ATssic(N)) ) ;
         printf ( " %s", "ETAT:" ) ;
         printf ( " %s", Struct4_Tssic(Info_ATssic(N)) ) ;
         N  =  Fd_ATssic(N ) ;
         }
       else
         {
         F  =  True ;

       } ;

     } ;

    }
  void Afficher_struct1 (Typevect_V100ATssic *T , int *N)
    {
      /** Variables locales **/
      int I;
      Pointeur_ATssic _Px1;

      /** Corps du module **/
     for( I  =  1 ;I <=  *N ; ++I){
       printf ( " %d", I ) ;
       _Px1 =  Element_V100ATssic(*T , I   ) ;
       Afficher_arb1 ( &_Px1) ;
       printf ( " %s", " " ) ;

     } ;

    }
  /*3eme question*/
  int  Occ_arb (Pointeur_ATssic *R , int *Age , string2 *Res)
    {
      /** Variables locales **/
      int  Occ_arb2 ;
      Pointeur_ATssic _Px1;
      Pointeur_ATssic _Px2;
      Pointeur_ATssic _Px3;
      Pointeur_ATssic _Px4;

      /** Corps du module **/
     if( ( *R == NULL )) {
       Occ_arb2  =  0 ;
       }
     else
       {
       if( ( ( Struct3_Tssic(Info_ATssic(*R )  ) == *Age ) && (strcmp( Struct4_Tssic(Info_ATssic(*R )  ), *Res) == 0  ) )) {
         _Px1 =  Fg_ATssic(*R ) ;
         _Px2 =  Fg_ATssic(*R ) ;
         Occ_arb2  =  Occ_arb ( &_Px1, & *Age , & *Res ) + Occ_arb ( &_Px2, & *Age , & *Res ) + 1 ;
         Aff_struct3_Tssic(Info_ATssic(*R )  , 0 ) ;
         }
       else
         {
         _Px3 =  Fg_ATssic(*R ) ;
         _Px4 =  Fg_ATssic(*R ) ;
         Occ_arb2  =  Occ_arb ( &_Px3, & *Age , & *Res ) + Occ_arb ( &_Px4, & *Age , & *Res ) ;

       } ;

     } ;

     return Occ_arb2 ;
    }
  int  Occ_tab (Typevect_V100ATssic *T , int *I , int *N , int *Age , string2 *Res)
    {
      /** Variables locales **/
      int  Occ_tab2 ;
      int J;
      int Occ;
      Pointeur_ATssic R;

      /** Corps du module **/
     Occ  =  1 ;
     for( J  =  *I ;J <=  *N ; ++J){
       R  =  Element_V100ATssic(*T , J   ) ;
       Occ  =  Occ + Occ_arb ( & R , & *Age , & *Res ) ;

     } ;
     Occ_tab2  =  Occ ;

     return Occ_tab2 ;
    }
  /*on parcours la structure1 et on cree les noeuds du nouvel arbre a au fur et a mesur */

  void Parcours (Pointeur_ATssic *R , Typevect_V100ATssic *T , int *I , int *N , Pointeur_ATiic *A)
    {
      /** Variables locales **/
      Pointeur_ATiic P;
      Pointeur_ATiic Q;
      int J;
      int Occ;
      int Age;
      string2 Res;
      Typestr_Tiic Sn;
      int _Px1;
      Pointeur_ATssic _Px2;
      Pointeur_ATssic _Px3;

      /** Corps du module **/
     Res = malloc(2 * sizeof(string2));
     Sn = malloc(sizeof(Typestr_Tiic));
     Sn->Champ3 = malloc(2 * sizeof(string2));
     if( ( *R != NULL )) {
       Age  =  Struct3_Tssic(Info_ATssic(*R )  ) ;
       strcpy (Res,   Struct4_Tssic(Info_ATssic(*R )  )) ;
       if( ( Age != 0 )) {
         _Px1 =  *I + 1 ;
         Occ  =  Occ_tab ( & *T , &_Px1, & *N , & Age , & Res ) ;
         Aff_struct1_Tiic(Sn  , Age ) ;
         Aff_struct2_Tiic(Sn  , Occ ) ;
         Aff_struct3_Tiic(Sn  , Res ) ;
        /*condition de remplissage de la racine */
         if( ( Struct1_Tiic(Info_ATiic(*A )  ) == 0 )) {
           Aff_info_ATiic(*A , Sn ) ;
           }
         else
           {
           P  =  *A ;
           Q  =  *A ;
           while( ( P != NULL ))  {
             Q  =  P ;
             if( ( Age > Struct1_Tiic(Info_ATiic(P )  ) )) {
               P  =  Fd_ATiic(P ) ;
               }
             else
               {
               P  =  Fg_ATiic(P ) ;

             } ;

           } ;
           Creernoeud_ATiic(&P ) ;
           Aff_info_ATiic(P , Sn ) ;
           if( ( Age > Struct1_Tiic(Info_ATiic(Q )  ) )) {
             Aff_fd_ATiic(Q , P ) ;
             }
           else
             {
             Aff_fg_ATiic(Q , P ) ;

           } ;
           Aff_struct3_Tssic(Info_ATssic(*R )  , 0 ) ;

         } ;
         _Px2 =  Fg_ATssic(*R ) ;
         Parcours ( &_Px2, & *T , & *I , & *N , & *A ) ;
         _Px3 =  Fd_ATssic(*R ) ;
         Parcours ( &_Px3, & *T , & *I , & *N , & *A ) ;

       } ;

     } ;

    }
  Pointeur_ATiic Creer_struct2 (Typevect_V100ATssic *T , int *N)
    {
      /** Variables locales **/
      Pointeur_ATiic Creer_struct22 ;
      Pointeur_ATiic A;
      int I;
      int J;
      Pointeur_ATssic R;
      Typestr_Tiic S;

      /** Corps du module **/
     S = malloc(sizeof(Typestr_Tiic));
     S->Champ3 = malloc(2 * sizeof(string2));
     Creernoeud_ATiic(&A ) ;
     Aff_struct1_Tiic(S  , 0 ) ;
     Aff_struct2_Tiic(S  , 0 ) ;
     Aff_struct3_Tiic(S  , "o" ) ;
    /*on initialise l'age  de la racine a zero afin de */
    /*pouvoir ajouter une condition dans le module   */
    /* d'insertion pour remplir la racine            */
     Aff_info_ATiic(A , S ) ;
     for( I  =  1 ;I <=  *N ; ++I){
       R  =  Element_V100ATssic(*T , I   ) ;
       Parcours ( & R , & *T , & I , & *N , & A ) ;

     } ;
     Creer_struct22  =  A ;

     return Creer_struct22 ;
    }
  /*question 4*/
  void Afficher_arb2 (Pointeur_ATiic *R)
    {
      /** Variables locales **/
      Pointeur_ATiic N;
      Pointeur_PATiic P;
      bool F;

      /** Corps du module **/
     N  =  *R ;
     F  =  False ;
     Creerpile_PATiic(&P ) ;
     while( ( ! F ))  {
       while( ( N != NULL ))  {
         Empiler_PATiic(&P , N ) ;
         N  =  Fg_ATiic(N ) ;

       } ;
       if( ( ! Pilevide_PATiic(P ) ))   {
         Depiler_PATiic(&P , &N ) ;
         printf ( " %s", "age:" ) ;
         printf ( " %d", Struct1_Tiic(Info_ATiic(N)) ) ;
         printf ( " %s", "occurance" ) ;
         printf ( " %d", Struct2_Tiic(Info_ATiic(N)) ) ;
         printf ( " %s", "etat" ) ;
         printf ( " %s", Struct3_Tiic(Info_ATiic(N)) ) ;
         N  =  Fd_ATiic(N ) ;
         }
       else
         {
         F  =  True ;

       } ;

     } ;

    }
  /* question 5 */
  /* copier les donnees de l'arbre dans un tableau ordonne selon lage */
  void Creer_tableau (Pointeur_ATiic *R , Typevect_V1000Tiic *T , int *Taille)
    {
      /** Variables locales **/
      Pointeur_ATiic N;
      Pointeur_PATiic P;
      Typestr_Tiic S;
      bool F;
      int I;
      int _Izw;  /** Variable de contrôle **/

      /** Corps du module **/
     S = malloc(sizeof(Typestr_Tiic));
     S->Champ3 = malloc(2 * sizeof(string2));
     I  =  1 ;
     N  =  *R ;
     F  =  False ;
     Creerpile_PATiic(&P ) ;
     while( ( ! F ))  {
       while( ( N != NULL ))  {
         Empiler_PATiic(&P , N ) ;
         N  =  Fg_ATiic(N ) ;

       } ;
       if( ( ! Pilevide_PATiic(P ) ))   {
         Depiler_PATiic(&P , &N ) ;
         Aff_element_V1000Tiic(*T , I   , Info_ATiic(N ) ) ;
         I  =  I + 1 ;
         N  =  Fd_ATiic(N ) ;
         }
       else
         {
         F  =  True ;

       } ;

     } ;
     *Taille  =  I - 1 ;

    }

int main
{
 scanf("%d",&N);


}

