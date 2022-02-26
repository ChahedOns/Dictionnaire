
#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"


Arbre arbreConsVide()
{
    Arbre A ;

    A= malloc(sizeof(Arbre));
    A->c='a';
    A->FD =NULL;
    A->FG =NULL;
    return A;
}


int arbreEstVide(Arbre a)
{
    if (a == NULL)
    {
        return 1;
    }
    else
        return 0;
}

Arbre arbreCons(char c, int n, Arbre fg, Arbre fd)
{
    Arbre A ;
    A= arbreConsVide();
    A->c=c;
    A->FD=fd;
    A->FG=fg;
    return A;

}

char arbreRacineLettre(Arbre a)
{
    return a->c;
}

/*int nboccur ( Arbre a,char c )
{
    if (a == NULL)
        return 0;
    else if ( a->c == c )
        return ( 1+ nboccur(a->FD, c)+ nboccur(a->FG, c));
    else
        return ( nboccur(a->FD, c)+ nboccur(a->FG, c));
}*/
int arbreRacineNbOcc(Arbre a)
{
    return a->x;
}

Arbre arbreFilsGauche(Arbre a)
{
    return a->FG;
}

Arbre arbreFilsDroit(Arbre a)
{
    return a->FD;
}

void arbreSuppr(Arbre a)
{   if (a==NULL)
        printf("Suppréssion effectuée avec succées!");
    else{
            arbreSuppr(a->FD);
            arbreSuppr(a->FD);
            free(a);
    }
}

