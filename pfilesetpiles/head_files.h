#ifndef HEAD_FILES_H_INCLUDED
#define HEAD_FILES_H_INCLUDED

# define N 10000
typedef struct {
int tab[N];
int tete, queue;
} File;

void CreerFile ( File *pf );
int FileVide( File F );
int FilePleine( File F );
int Enfiler( int x, File *pf );
int Defiler( int *x, File *pf );

#endif // HEAD_FILES_H_INCLUDED
