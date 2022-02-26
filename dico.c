#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "dico.h"



void dicoAfficher(Arbre a){
    char ch[]="";
    int i=0;
    Arbre p=NULL , aux ;
    ch[i]=a->c;
    i++;
    p= a->FG;
    while (p!= NULL){
        if ( p->FD !=NULL )
        {//partie gauche existatnte
            if ( p->FG != NULL){
                ch[i]=p->c;
                i++;
                aux=p->FG;
                //affichage de la partie gauche !
                while ( aux->c !='\0' ){
                    *(ch+i) = aux->c;
                    i++;
                    aux= aux->FG;
                }
                printf("%s",ch);
                p=p->FG;
                //initialiser la chaine
                for (int j=1;j<i;j++){
                     *(ch+j) =' ' /*(char)""*/;
                }

            }else
            {   for (int j=1;j<i;j++){
                    *(ch+j) = ' '/*(char)""*/;}
                p=p->FD;
            }
        }else{
            for (int j=0;j<i;j++){
                *(ch+j) = ' '/*(char)""*/;}
            p=a->FD;}
    }
}

void dicoInsererMot(char mot[], Arbre* a,int len,int cpt){

Arbre aux = *a;

if(len == -1){
    aux->FD = arbreCons('\0', 0, NULL, NULL);
    return;
}else if(cpt == 0){
    if(aux->c != mot[0]){
    Arbre tracker;
    while(aux->c != mot[0] && aux->FD != NULL && mot[0] > aux->c){
        tracker = aux;
        aux = aux->FD;
    }

    if(aux->c < mot[0] && aux->FD == NULL){
        aux->FD = arbreCons(mot[cpt],0,NULL,NULL);
        dicoInsererMot(mot,&aux->FD,len-1,cpt+1);

    }else if(aux->c > mot[0]){
         Arbre temp = arbreCons(mot[cpt],0,NULL,NULL);
         tracker->FD = temp;
         temp->FD = aux;
         dicoInsererMot(mot,&temp,len-1,cpt+1);

    }else{
        dicoInsererMot(mot,&aux,len-1,cpt+1);
    }

    }
}else{
        if(aux->FG==NULL){
            aux->FG = arbreCons(mot[cpt],0,NULL,NULL);
            dicoInsererMot(mot,&aux->FG,len-1,cpt+1);
        }else if(aux->FG->c == mot[cpt]){
            dicoInsererMot(mot,&aux->FG,len-1,cpt+1);
        }else{
            aux->FD = arbreCons(mot[cpt],0,NULL,NULL);
            dicoInsererMot(mot,&aux->FD,len-1,cpt+1);
        }
    }
}

void printPreorder(Arbre a)
{
    if (a == NULL)
        return;

    printf("%c", a->c);

    printPreorder(a->FG);

    printPreorder(a->FD);
}


int dicoNbOcc(char mot[], Arbre a){
char rest[strlen(mot)];
   if (strcmp(mot,"")==0)
        return 1;
   else{
        if ( a->c == mot[0]){
            //strncpy(rest,mot+1,strlen(mot)-1);
            return dicoNbOcc(rest,a->FG);}
        else if (a->c < mot[0]){
            return dicoNbOcc(mot , a->FD);
            }
        else return 0;
        }
}

//non compléte!
//int dicoNbMotsDifferents(Arbre a){
//}
int dicoNbMotsTotal(Arbre a){
    if (a->c == '\0')
        return 1;
    else
        return (dicoNbMotsTotal(a->FG)+dicoNbMotsTotal(a->FD));
}
int nombreAleatoire(int nombreMax)
{
 srand(time(NULL));
 return (rand() % nombreMax);
}

int piocherMot(char *motPioche)
{
     FILE* dico = NULL; // Le pointeur de fichier qui va contenir notre fichier
     int nombreMots = 0, numMotChoisi = 0;
     int caractereLu = 0;
     dico = fopen("dico.txt", "r"); // On ouvre le dictionnaire en lecture seule
     // On vérifie si on a réussi à ouvrir le dictionnaire
     if (dico == NULL) // Si on n'a PAS réussi à ouvrir le fichier
     {
         printf("\nImpossible de charger le dictionnaire de mots");
         return 0; // On retourne 0 pour indiquer que la fonction a échoué
         // À la lecture du return, la fonction s'arrête immédiatement.
     }
     // On compte le nombre de mots dans le fichier (il suffit de compter les
     // entrées \n
     do
     {
         caractereLu = fgetc(dico);
         if (caractereLu == '\n')
         nombreMots++;
     } while(caractereLu != EOF);
     numMotChoisi = nombreAleatoire(nombreMots); // On pioche un mot au hasard
     // On recommence à lire le fichier depuis le début. On s'arrête lorsqu'on est arrivé au bon mot
     rewind(dico);
     while (numMotChoisi > 0)
     {
        caractereLu = fgetc(dico);
        if (caractereLu == '\n')
            numMotChoisi--;
     }
     /* Le curseur du fichier est positionné au bon endroit.
     On n'a plus qu'à faire un fgets qui lira la ligne */
     fgets(motPioche, 100, dico);
     // On vire le \n à la fin
     motPioche[strlen(motPioche) - 1] = '\0';
     fclose(dico);
     return 1; // Tout s'est bien passé, on retourne 1
}
