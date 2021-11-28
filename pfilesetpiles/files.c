#include <stdio.h>
#include <stdlib.h>
#include "head_files.h"


void CreerFile ( File *pf ) {
pf->tete = N-1;
pf->queue = N-1;
}

int FileVide( File F )
{
 return (F.tete == F.queue);
}

int FilePleine( File F )
{
 return ( F.tete == (F.queue+1 % N) );
}

int Enfiler( int x, File *pf )
{
if ( FilePleine(*pf) ) return 0;
pf->queue = (pf->queue + 1) % N;
pf->tab[ pf->queue ] = x;
return 1;
}

int Defiler( int *x, File *pf )
{
if ( FileVide( *pf ) ) return 0;
*x = pf->tab[ pf->tete ];
pf->tete = (pf->tete+1) % N;
return 1;
}
