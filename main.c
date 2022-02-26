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
    dicoInsererMot(buffer, &dico,strlen(buffer)-1,0);
    printPreorder(dico);
    printf("\n");
    strcpy(buffer, "labon");
    dicoInsererMot(buffer, &dico,strlen(buffer)-1,0);
    printPreorder(dico);
    printf("\n");
    strcpy(buffer, "babon");
    dicoInsererMot(buffer, &dico,strlen(buffer)-1,0);
    printPreorder(dico);
    printf("\n");
    strcpy(buffer, "balon");
    dicoInsererMot(buffer, &dico,strlen(buffer)-1,0);
    printPreorder(dico);
return 0;
}
