/* BENDAHO SARRA  */
/* BEKKAR ILHEM  */
/*TP Z */
   SOIENT
       T UN VECTEUR ( 100 ) DE ARB DE ( CHAINE , CHAINE , ENTIER , CAR ) ;
       N DES ENTIERS ;
       A UN ARB DE ( ENTIER , ENTIER , CAR ) ;
       Aleacar , Creer_struct1 , Afficher_arb1 , Afficher_struct1 DES ACTIONS ;
       Creer_arb1 : FONCTION ( ARB DE ( CHAINE , CHAINE , ENTIER , CAR ) ) ;
       Creer_struct2 : FONCTION ( ARB DE ( ENTIER , ENTIER , CAR ) ) ;
       Occ_arb , Occ_tab : FONCTION ( ENTIER ) ;
       Parcours , Afficher_arb2 , Creer_tableau , Pourcent DES ACTIONS ;
       Sup , Inf , Intervalle : FONCTION ( ENTIER ) ;
      
   DEBUT
       LIRE ( N ) ;
       APPEL Creer_struct1 ( N , T ) ;
       APPEL Afficher_struct1 ( T , N ) ;
       A := Creer_struct2 ( T , N ) ;
       APPEL Afficher_arb2 ( A ) ;
       APPEL Pourcent ( A ) ;
       ECRIRE ( 'done' ) ;
      
   FIN
   ACTION Aleacar ( C ) ;
   SOIENT
       A UN ENTIER ;
       C UN CAR ;
      
   DEBUT
       A := ALEANOMBRE ( 2 ) ;
       SI A = 1 :
           C := 'D' ;
          
       SINON
           C := 'R' ;
          
       FSI ;
      
   FIN
  /*1ere question*/
   FONCTION Creer_arb1 ( M ) : ARB DE ( CHAINE , CHAINE , ENTIER , CAR )
   SOIENT
       R , P , Q DES POINTEURS VERS ARB DE ( CHAINE , CHAINE , ENTIER , CAR ) ;
       S UN ( CHAINE , CHAINE , ENTIER , CAR ) ;
       Ag , M , I DES ENTIERS ;
       Res UN CAR ;
       Ch UNE CHAINE ;
      
   DEBUT
       CREERNOEUD ( P ) ;
       Ag := ALEANOMBRE ( 80 ) + 1 ;
       AFF_STRUCT ( S , 1 , ALEACHAINE ( 7 ) ) ;
       AFF_STRUCT ( S , 2 , ALEACHAINE ( 5 ) ) ;
       AFF_STRUCT ( S , 3 , Ag ) ;
       APPEL Aleacar ( Res ) ;
       AFF_STRUCT ( S , 4 , Res ) ;
       R := P ;
       AFF_INFO ( P , S ) ;
       POUR I := 2 , M
           Ag := ALEANOMBRE ( 80 ) + 1 ;
           AFF_STRUCT ( S , 1 , ALEACHAINE ( 5 ) ) ;
           AFF_STRUCT ( S , 2 , ALEACHAINE ( 7 ) ) ;
           AFF_STRUCT ( S , 3 , Ag ) ;
           APPEL Aleacar ( Res ) ;
           AFF_STRUCT ( S , 4 , Res ) ;
           Q := R ;
           P := R ;
           TANTQUE ( Q <> NIL )  :
               P := Q ;
               SI Ag < STRUCT ( INFO ( P ) , 3 )
                   Q := FG ( Q )
               SINON
                   Q := FD ( Q )
               FSI
           FTQ ;
               CREERNOEUD ( Q ) ;
               AFF_INFO ( Q , S ) ;
               SI ( Ag < STRUCT ( INFO ( P ) , 3 ) )
                   AFF_FG ( P , Q )
               SINON
                   AFF_FD ( P , Q )
               FSI ;

          
       FPOUR ;
       Creer_arb1 := R ;
      
   FIN
   ACTION Creer_struct1 ( N , T )
   SOIENT
       T UN VECTEUR ( 100 ) DE ARB DE ( CHAINE , CHAINE , ENTIER , CAR ) ;
       N , I DES ENTIERS ;
       R UN POINTEUR VERS ARB DE ( CHAINE , CHAINE , ENTIER , CAR ) ;
      
   DEBUT
       POUR I := 1 , N
           R := Creer_arb1 ( 20 ) ;
          { on a pris le nombre de personne de chaque pays=20}
           AFF_ELEMENT ( T [ I ] , R ) ;
          
       FPOUR
   FIN
  /* 2eme question :*/
   ACTION Afficher_arb1 ( R )
   SOIENT
       R UN ARB DE ( CHAINE , CHAINE , ENTIER , CAR ) ;
       N UN POINTEUR VERS ARB DE ( CHAINE , CHAINE , ENTIER , CAR ) ;
       P UNE PILE DE ARB DE ( CHAINE , CHAINE , ENTIER , CAR ) ;
       F UN BOOLEEN ;
   DEBUT
       N := R ;
       F := FAUX ;
       CREERPILE ( P ) ;
       TQ ( NON F ) :
           TQ ( N <> NIL ) :
               EMPILER ( P , N ) ;
               N := FG ( N ) ;
              
           FTQ ;
           SI ( NON PILEVIDE ( P ) ) :
               DEPILER ( P , N ) ;
               ECRIRE ( 'NOM:' ) ;
               ECRIRE ( STRUCT ( INFO ( N ) , 1 ) ) ;
               ECRIRE ( 'PRENOM:' ) ;
               ECRIRE ( STRUCT ( INFO ( N ) , 2 ) ) ;
               ECRIRE ( 'AGE:' ) ;
               ECRIRE ( STRUCT ( INFO ( N ) , 3 ) ) ;
               ECRIRE ( 'ETAT:' ) ;
               ECRIRE ( STRUCT ( INFO ( N ) , 4 ) ) ;
               N := FD ( N ) ;
              
           SINON
               F := VRAI ;
              
           FSI ;
          
       FTQ ;
   FIN
   ACTION Afficher_struct1 ( T , N )
   SOIENT
       T UN VECTEUR ( 100 ) DE ARB DE ( CHAINE , CHAINE , ENTIER , CAR ) ;
       I , N DES ENTIERS ;
      
   DEBUT
       POUR I := 1 , N
           ECRIRE ( I ) ;
           APPEL Afficher_arb1 ( ELEMENT ( T [ I ] ) ) ;
           ECRIRE ( ' ' ) ;
          
       FPOUR ;
      
   FIN
  /*3eme question*/
   FONCTION Occ_arb ( R , Age , Res ) : ENTIER
   SOIENT
       R UN POINTEUR VERS ARB DE ( CHAINE , CHAINE , ENTIER , CAR ) ;
       Age UN ENTIER ;
       Res UN CAR ;
      
   DEBUT
       SI ( R = NIL )
           Occ_arb := 0 ;
          
       SINON
           SI ( ( STRUCT ( INFO ( R ) , 3 ) = Age ) ET ( STRUCT ( INFO ( R ) , 4 ) = Res ) )
               Occ_arb := Occ_arb ( FG ( R ) , Age , Res ) + Occ_arb ( FD ( R ) , Age , Res ) + 1 ;
               AFF_STRUCT ( INFO ( R ) , 3 , 0 ) ;
              
           SINON
               Occ_arb := Occ_arb ( FG ( R ) , Age , Res ) + Occ_arb ( FD ( R ) , Age , Res ) ;
              
           FSI ;
          
       FSI ;
      
   FIN
   FONCTION Occ_tab ( T , I , N , Age , Res ) : ENTIER
   SOIENT
       T UN VECTEUR ( 100 ) DE ARB DE ( CHAINE , CHAINE , ENTIER , CAR ) ;
       I , N , Age , J , Occ DES ENTIERS ;
       Res UN CAR ;
       R UN POINTEUR VERS ARB DE ( CHAINE , CHAINE , ENTIER , CAR ) ;
      
   DEBUT
       Occ := 0 ;
       POUR J := I , N
           R := ELEMENT ( T [ J ] ) ;
           Occ := Occ + Occ_arb ( R , Age , Res ) ;
          
       FPOUR ;
       Occ_tab := Occ ;
      
   FIN
   ACTION Parcours ( R , T , I , N , A )
  /*on parcours la structure1 et on cree les noeuds du nouvel arbre  au fur et a mesur */
   SOIENT
       T UN VECTEUR ( 100 ) DE ARB DE ( CHAINE , CHAINE , ENTIER , CAR ) ;
       R UN POINTEUR VERS ARB DE ( CHAINE , CHAINE , ENTIER , CAR ) ;
       A , P , Q DES POINTEURS VERS ARB DE ( ENTIER , ENTIER , CAR ) ;
       J , Occ , I , N , Age DES ENTIERS ;
       Res UN CAR ;
       Sn UN ( ENTIER , ENTIER , CAR ) ;
      
   DEBUT
       SI ( R <> NIL )
           Age := STRUCT ( INFO ( R ) , 3 ) ;
           Res := STRUCT ( INFO ( R ) , 4 ) ;
           SI ( Age <> 0 )
               Occ := Occ_tab ( T , 1 , N , Age , Res ) ;
               AFF_STRUCT ( Sn , 1 , Age ) ;
               AFF_STRUCT ( Sn , 2 , Occ ) ;
               AFF_STRUCT ( Sn , 3 , Res ) ;
               SI ( STRUCT ( INFO ( A ) , 1 ) = 0 )
              /*condition de remplissage de la racine */
                   AFF_INFO ( A , Sn ) ;
                  
               SINON
                   P := A ;
                   Q := A ;
                   TQ ( P <> NIL ) :
                       Q := P ;
                       SI ( Age > STRUCT ( INFO ( P ) , 1 ) )
                           P := FD ( P ) ;
                          
                       SINON
                           P := FG ( P ) ;
                          
                       FSI ;
                      
                   FTQ ;
                   CREERNOEUD ( P ) ;
                   AFF_INFO ( P , Sn ) ;
                   SI ( Age > STRUCT ( INFO ( Q ) , 1 ) )
                       AFF_FD ( Q , P ) ;
                      
                   SINON
                       AFF_FG ( Q , P ) ;
                      
                   FSI ;
                   AFF_STRUCT ( INFO ( R ) , 3 , 0 ) ;
                  
               FSI ;
           FSI ;
           APPEL Parcours ( FG ( R ) , T , I , N , A ) ;
           APPEL Parcours ( FD ( R ) , T , I , N , A ) ;
       FSI ;
      
   FIN
   FONCTION Creer_struct2 ( T , N ) : ARB DE ( ENTIER , ENTIER , CAR )
   SOIENT
       A UN POINTEUR VERS ARB DE ( ENTIER , ENTIER , CAR ) ;
       T UN VECTEUR ( 100 ) DE ARB DE ( CHAINE , CHAINE , ENTIER , CAR ) ;
       N , I , J DES ENTIERS ;
       R UN POINTEUR VERS ARB DE ( CHAINE , CHAINE , ENTIER , CAR ) ;
       S UN ( ENTIER , ENTIER , CAR ) ;
      
   DEBUT
       CREERNOEUD ( A ) ;
       AFF_STRUCT ( S , 1 , 0 ) ;
       AFF_STRUCT ( S , 2 , 0 ) ;
       AFF_STRUCT ( S , 3 , 'o' ) ;
      /*on initialise l'age  de la racine a zero afin de */
      /*pouvoir ajouter une condition dans le module   */
      /* d'insertion pour remplir la racine            */
       AFF_INFO ( A , S ) ;
       POUR I := 1 , N
           R := ELEMENT ( T [ I ] ) ;
           APPEL Parcours ( R , T , I , N , A ) ;
          
       FPOUR ;
       Creer_struct2 := A ;
      
   FIN
  /*question 4*/
   ACTION Afficher_arb2 ( R )
   SOIENT
       R UN ARB DE ( ENTIER , ENTIER , CAR ) ;
       N UN POINTEUR VERS ARB DE ( ENTIER , ENTIER , CAR ) ;
       P UNE PILE DE ARB DE ( ENTIER , ENTIER , CAR ) ;
       F UN BOOLEEN ;
      
   DEBUT
       N := R ;
       F := FAUX ;
       CREERPILE ( P ) ;
       TQ ( NON F ) :
           TQ ( N <> NIL ) :
               EMPILER ( P , N ) ;
               N := FG ( N ) ;
              
           FTQ ;
           SI ( NON PILEVIDE ( P ) ) :
               DEPILER ( P , N ) ;
               ECRIRE ( 'age:' ) ;
               ECRIRE ( STRUCT ( INFO ( N ) , 1 ) ) ;
               ECRIRE ( 'occurance' ) ;
               ECRIRE ( STRUCT ( INFO ( N ) , 2 ) ) ;
               ECRIRE ( 'etat' ) ;
               ECRIRE ( STRUCT ( INFO ( N ) , 3 ) ) ;
               N := FD ( N ) ;
              
           SINON
               F := VRAI ;
              
           FSI ;
          
       FTQ ;
      
   FIN
  /* question 5 */
  /* copier les donnees de l'arbre dans un tableau ordonne selon lage */
   ACTION Creer_tableau ( R , T , Taille )
   SOIENT
       R UN ARB DE ( ENTIER , ENTIER , CAR ) ;
       N UN ARB DE ( ENTIER , ENTIER , CAR ) ;
       P UNE PILE DE ARB DE ( ENTIER , ENTIER , CAR ) ;
       S UN ( ENTIER , ENTIER , CAR ) ;
       F UN BOOLEEN ;
       T UN VECTEUR ( 1000 ) DE ( ENTIER , ENTIER , CAR ) ;
       I , Taille UN ENTIER ;
      
   DEBUT
       I := 1 ;
       N := R ;
       F := FAUX ;
       CREERPILE ( P ) ;
       TQ ( NON F ) :
           TQ ( N <> NIL ) :
               EMPILER ( P , N ) ;
               N := FG ( N ) ;
              
           FTQ ;
           SI ( NON PILEVIDE ( P ) ) :
               DEPILER ( P , N ) ;
               AFF_ELEMENT ( T [ I ] , INFO ( N ) ) ;
               I := I + 1 ;
               N := FD ( N ) ;
              
           SINON
               F := VRAI ;
              
           FSI ;
          
       FTQ ;
       Taille := I - 1 ;
      
   FIN
   FONCTION Intervalle ( T , Taille , A , B , Res ) : ENTIER
   SOIENT
       Res_tr , Res DES CAR ;
       T UN VECTEUR ( 1000 ) DE ( ENTIER , ENTIER , CAR ) ;
       Nb_tot , Nb , A , B , I , Taille , Pourcent , Age DES ENTIERS ;
      
   DEBUT
       Nb_tot := 0 ;
       Nb := 0 ;
       I := 1 ;
       TQ ( I <= Taille ) :
           Nb_tot := Nb_tot + STRUCT ( ELEMENT ( T [ I ] ) , 2 ) ;
           Age := STRUCT ( ELEMENT ( T [ I ] ) , 1 ) ;
           Res_tr := STRUCT ( ELEMENT ( T [ I ] ) , 3 ) ;
           SI ( ( Age > A ) ET ( Age < B ) ET ( Res = Res_tr ) )
               Nb := Nb + STRUCT ( ELEMENT ( T [ I ] ) , 2 ) ;
              
           FSI ;
           I := I + 1 ;
          
       FINTANTQUE ;
       Intervalle := ( Nb * 100 ) / Nb_tot ;
      
   FIN
   FONCTION Sup ( T , Taille , A , Res ) : ENTIER
   SOIENT
       T UN VECTEUR ( 1000 ) DE ( ENTIER , ENTIER , CAR ) ;
       Nb_tot , Nb , A , I , Taille , Pourcent , Age DES ENTIERS ;
       Res , Res_tr UN CAR ;
      
   DEBUT
       Nb_tot := 0 ;
       Nb := 0 ;
       I := 1 ;
       TQ ( I <= Taille ) :
           Nb_tot := Nb_tot + STRUCT ( ELEMENT ( T [ I ] ) , 2 ) ;
           Age := STRUCT ( ELEMENT ( T [ I ] ) , 1 ) ;
           Res_tr := STRUCT ( ELEMENT ( T [ I ] ) , 3 ) ;
           SI ( ( Age > A ) ET ( Res = Res_tr ) )
               Nb := Nb + STRUCT ( ELEMENT ( T [ I ] ) , 2 ) ;
              
           FSI ;
           I := I + 1 ;
          
       FTQ ;
       Pourcent := ( Nb * 100 ) / ( Nb_tot ) ;
       Sup := Pourcent ;
      
   FIN
   FONCTION Inf ( T , Taille , B , Res ) : ENTIER
   SOIENT
       T UN VECTEUR ( 1000 ) DE ( ENTIER , ENTIER , CAR ) ;
       Nb_tot , Nb , B , I , Taille , Pourcent , Age DES ENTIERS ;
       Res , Res_tr UN CAR ;
      
   DEBUT
       Nb_tot := 0 ;
       Nb := 0 ;
       I := 1 ;
       TQ ( I <= Taille ) :
           Nb_tot := Nb_tot + STRUCT ( ELEMENT ( T [ I ] ) , 2 ) ;
           Age := STRUCT ( ELEMENT ( T [ I ] ) , 1 ) ;
           Res_tr := STRUCT ( ELEMENT ( T [ I ] ) , 3 ) ;
           SI ( ( Age < B ) ET ( Res = Res_tr ) )
               Nb := Nb + STRUCT ( ELEMENT ( T [ I ] ) , 2 ) ;
              
           FSI ;
           I := I + 1 ;
          
       FTQ ;
       Pourcent := ( Nb * 100 ) / Nb_tot ;
       Inf := Pourcent ;
      
   FIN
   ACTION Pourcent ( R )
   SOIENT
       R UN ARB DE ( ENTIER , ENTIER , CAR ) ;
       T UN VECTEUR ( 1000 ) DE ( ENTIER , ENTIER , CAR ) ;
       Choix , A , B , Taille DES ENTIERS ;
       Res UN CAR ;
      
   DEBUT
       APPEL Creer_tableau ( R , T , Taille ) ;
       ECRIRE ( 'veulliez choisir un traitement : ' ) ;
       ECRIRE ( '1 - intervalle    2 -superieur   3 - inferieur  4< - exit ' ) ;
       LIRE ( Choix ) ;
       TQ ( Choix < 4 )
           SI ( Choix = 1 ) :
               ECRIRE ( 'donnez l intervalle ' ) ;
               LIRE ( A , B ) ;
               ECRIRE ( 'choisissez : -D- death    -R- recovery ' ) ;
               LIRE ( Res ) ;
               ECRIRE ( 'le pourcentage est :' ) ;
               ECRIRE ( Intervalle ( T , Taille , A , B , Res ) ) ;
              
           SINON
               SI ( Choix = 2 ) :
                   ECRIRE ( 'donnez le seuil ' ) ;
                   LIRE ( A ) ;
                   ECRIRE ( 'choisissez : -D- death    -R- recovery ' ) ;
                   LIRE ( Res ) ;
                   ECRIRE ( 'le pourcentage est :' ) ;
                   ECRIRE ( Sup ( T , Taille , A , Res ) ) ;
                  
               SINON
              {i.e choix=3}
                   ECRIRE ( 'donnez le seuil ' ) ;
                   LIRE ( B ) ;
                   ECRIRE ( 'choisissez : -D- death    -R- recovery ' ) ;
                   LIRE ( Res ) ;
                   ECRIRE ( 'le pourcentage est :' ) ;
                   ECRIRE ( Inf ( T , Taille , B , Res ) ) ;
                  
               FSI ;
              
           FSI ;
           ECRIRE ( 'veulliez choisir un traitement : ' ) ;
           ECRIRE ( '1 - intervalle    2 -superieur   3 - inferieur  4< - exit ' ) ;
           LIRE ( Choix ) ;
          
       FTQ ;
      
   FIN
