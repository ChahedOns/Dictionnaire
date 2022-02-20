
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "dico.h"


void dicoAfficher(Arbre a){

    char ch[]= "";
    int i=0;
    Arbre p , aux ;
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
                while ( aux->c !="\0" ){
                    *(ch+i) = aux->c;
                    i++;
                    aux= aux->FG;
                }
                printf("%s",ch);
                p=p->FG;
                //initialiser la chaine
                for (int j=1;j<i;j++){
                     *(ch+j) = (char)"";
                }

            }else
            {   for (int j=1;j<i;j++){
                    *(ch+j) = (char)"";}
                p=p->FD;
            }
        }else{
            for (int j=0;j<i;j++){
                *(ch+j) = (char)"";}
            p=a->FD;}
    }
}

void dicoInsererMot(char mot[], Arbre a /*passage par variable*/ ){
    char rest[strlen(mot)];
    Arbre m=arbreCons(mot[1],0,NULL,NULL);
        if ( a->c == m->c){
            //m�me lettre je passe  gauche
            strncpy(rest,mot+1,strlen(mot)-1);
            free(m);
            dicoInsererMot(rest , a->FG);}
        else if (a->c < m->c){
                //Recherche la bonne place � droite!
            if (a->FD == NULL){
                    //Nouvelle mot a droite!
                    a->FD=m;
                    Arbre c =m;
                    //Place bien trouv�e! j'ajoute le rest !
                    while (strcmp(rest,"") != 0){
                        strncpy(rest,mot+1,strlen(mot)-1);
                        Arbre aux = arbreCons(rest[1],0,NULL,NULL);
                        c->FG = aux;
                        c=aux;
                        }
                    //dernier noeud doit �tre \0
                    Arbre last =arbreCons("\0",1,NULL,NULL);
                    c->FG = last;}
            else{
                //supp�ieur et not �gal la racine je passe a droite(recherche la bonne place)
                a=a->FD;}
        }
}

int dicoNbOcc(char mot[], Arbre a){
char rest[strlen(mot)];
   if (mot == "")
        return 1;
   else{
        if ( a->c == mot[1]){
            strncpy(rest,mot+1,strlen(mot)-1);
            return dicoNbOcc(rest,a->FG);}
        else if (a->c < mot[1]){
            return dicoNbOcc(mot , a->FD);}
    }
}

//non compl�te!
int dicoNbMotsDifferents(Arbre a){
}
dicoNbMotsTotal(Arbre a){
    if (a->c == "\0")
        return 1;
    else
        return (dicoNbMotsTotal(a->FG)+dicoNbMotsTotal(a->FD));
}

int piocherMot(char *motPioche)
{
     FILE* dico = NULL; // Le pointeur de fichier qui va contenir notre fichier
     int nombreMots = 0, numMotChoisi = 0, i = 0;
     int caractereLu = 0;
     dico = fopen("dico.txt", "r"); // On ouvre le dictionnaire en lecture seule
     // On v�rifie si on a r�ussi � ouvrir le dictionnaire
     if (dico == NULL) // Si on n'a PAS r�ussi � ouvrir le fichier
     {
         printf("\nImpossible de charger le dictionnaire de mots");
         return 0; // On retourne 0 pour indiquer que la fonction a �chou�
         // � la lecture du return, la fonction s'arr�te imm�diatement.
     }
     // On compte le nombre de mots dans le fichier (il suffit de compter les
     // entr�es \n
     do
     {
         caractereLu = fgetc(dico);
         if (caractereLu == '\n')
         nombreMots++;
     } while(caractereLu != EOF);
     numMotChoisi = nombreAleatoire(nombreMots); // On pioche un mot au hasard
     // On recommence � lire le fichier depuis le d�but. On s'arr�te lorsqu'on est arriv� au bon mot
     rewind(dico);
     while (numMotChoisi > 0)
     {
        caractereLu = fgetc(dico);
        if (caractereLu == '\n')
            numMotChoisi--;
     }
     /* Le curseur du fichier est positionn� au bon endroit.
     On n'a plus qu'� faire un fgets qui lira la ligne */
     fgets(motPioche, 100, dico);
     // On vire le \n � la fin
     motPioche[strlen(motPioche) - 1] = '\0';
     fclose(dico);
     return 1; // Tout s'est bien pass�, on retourne 1
}
int nombreAleatoire(int nombreMax)
{
 srand(time(NULL));
 return (rand() % nombreMax);
}