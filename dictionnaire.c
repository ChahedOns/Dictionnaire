#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Node {
char c ;
int x ;
struct Node* FG;
struct Node* FD;
};

typedef struct Node Node ;
typedef Node* Arbre ;

Arbre arbreConsVide()
{
    Arbre A ;

    A= malloc(sizeof(Arbre));
    A->c='$';
    A->FD =NULL;
    A->FG =NULL;
    return A;
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

void dicoInsererMot(char mot[], Arbre* a,int len,int cpt){

Arbre aux = *a;

if(len == -1){
    aux->FG = arbreCons('\0', 0, NULL, NULL);
    return;
}
else if(aux->c == '$'){
    aux->c = mot[cpt];
    dicoInsererMot(mot,&aux,len-1,cpt+1);
}
 else if(aux->FG ==NULL){
    aux->FG = arbreCons(mot[cpt],0,NULL,NULL);
    dicoInsererMot(mot,&aux->FG,len-1,cpt+1);
 }else if(aux->c == mot[cpt]){
    dicoInsererMot(mot,&aux->FG,len-1,cpt+1);
 }else if(aux->FD==NULL && aux->c != mot[cpt] ){
    aux->FD = arbreCons(mot[cpt],0,NULL,NULL);
    dicoInsererMot(mot,&aux->FD,len-1,cpt+1);
}else if(aux->c != mot[cpt] && aux->FD->c == mot[cpt]){
    dicoInsererMot(mot,&aux->FD,len-1,cpt+1);
}else if(aux->FG->c != mot[cpt] && aux->FD->c != mot[cpt]){
    if(aux->FD->c > mot[cpt]){
        Arbre temp = arbreCons(mot[cpt],0,NULL,NULL);
        temp ->FD = aux->FD;
        aux->FD = temp;
        dicoInsererMot(mot,&temp,len-1,cpt+1);
    }else{
        dicoInsererMot(mot,&aux->FD,len,cpt);
    }
}
}
int checkIfExist(char mot[], Arbre a,int len,int cpt){
if(len == -1){
    if(a->c =='\0')
        return 1;
    return 0;
}

  if(a->c == mot[cpt] && a->FG!=NULL){
    if(a->FG->c == mot[cpt+1])
        checkIfExist(mot,a->FG,len-1,cpt+1);
    else if(a->FD == NULL){
        checkIfExist(mot,a->FG,len-1,cpt+1);
    }
    else
        checkIfExist(mot,a->FD,len-1,cpt+1);
  }

  else if(a->c != mot[cpt] && a->FD != NULL){
   checkIfExist(mot,a->FD,len,cpt); 
    }
else{
    return 0;
}
}



void printPreorder(Arbre a)
{
    if (a == NULL)
        return;

    printf("%c ", a->c);

    printPreorder(a->FG);   

    printPreorder(a->FD);
}
void menu(){
      printf("\t ---- MENU ---- \n\n");
        printf("1) Inserer un mot \n");
        printf("2) Chercher un mot \n");
        printf("3) Afficher les mots de dictionnaire \n");
        printf("4) Inserer un ficiher (Working on it) \n \n");
        printf("0) Exit \n");


}
int main()
{
    Arbre dico; char buffer[100];
    dico = arbreConsVide();
    char word[50]; 
    int choice = -1;
    system("clear");
    menu();
    printf(">");
    scanf("%d",&choice);
    while(choice != 0){
        switch(choice)
        {
            case 1:
                printf("Entrer votre mot:\n");
                scanf("%s",&word);
                dicoInsererMot(word, &dico,strlen(word)-1,0);
                printf(">");
                scanf("%d",&choice);
                break;
            case 2:
                if(dico->c =='$'){
                    printf("le dictionnaire est vide \n");
                    printf(">");
                    scanf("%d",&choice);
                }else{
                printf("Entrer votre mot:\n");
                scanf("%s",&word);
                if(checkIfExist(word,dico,strlen(word)-1,0))
                    printf("existe \n");
                else
                    printf("n'existe pas\n");
                printf(">");
                scanf("%d",&choice);
                }
                break;
            case 3:
                if(dico->c == '$'){
                    printf("le dictionnaire est vide \n");
                    printf(">");
                    scanf("%d",&choice);
                }else{
                  printPreorder(dico);//not working as intended
                 printf(">");
                 scanf("%d",&choice);   
                }
                
                 break;
            case 4:
                printf("i'm still working hard on it please choose another option ^^\n");
                printf(">");
                scanf("%d",&choice);
                break;
        }

    }
return 0;
}
