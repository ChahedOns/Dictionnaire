#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "dico.h"


int main()
{
    Arbre dico; char buffer[100];
    dico = arbreConsVide();
    strcpy(buffer, "gallon");
    dicoInsererMot(buffer, &dico);
    dicoAfficher(dico); printf("\n");
    strcpy(buffer, "munier");
    dicoInsererMot(buffer, &dico);
    dicoAfficher(dico); printf("\n");
    strcpy(buffer, "abenia");
    dicoInsererMot(buffer, &dico);
     dicoAfficher(dico); printf("\n");
    strcpy(buffer, "munier");
    dicoInsererMot(buffer, &dico);
    dicoAfficher(dico); printf("\n");
    strcpy(buffer, "mumu");
    dicoInsererMot(buffer, &dico);
    dicoAfficher(dico); printf("\n");
    strcpy(buffer, "alpha");
    dicoInsererMot(buffer, &dico);
    strcpy(buffer, "alphabeta");
    dicoInsererMot(buffer, &dico);
    strcpy(buffer, "al");
    dicoInsererMot(buffer, &dico);
    dicoAfficher(dico); printf("\n");
    printf("\"%s\" \t -> %d\n", "gallon", dicoNbOcc("gallon",dico));
    printf("\"%s\" \t\t -> %d\n", "mumu", dicoNbOcc("mumu",dico));
    printf("\"%s\" \t -> %d\n", "munier", dicoNbOcc("munier",dico));
    printf("\"%s\" \t -> %d\n", "gastro", dicoNbOcc("gastro",dico));
    printf("\"%s\" \t -> %d\n", "lespine", dicoNbOcc("lespine",dico));
    printf("\"%s\" \t\t -> %d\n", "aaa", dicoNbOcc("aaa",dico)); printf("\n");
return 0;
}
