#include "arbre.h"
/*struct Node {
char c ;
int x ;
struct Node* FG;
struct Node* FD;
};
typedef struct Node Node ;
typedef Node* Arbre ;
*/
void dicoAfficher(Arbre a);
void dicoInsererMot(char mot[], Arbre* a);
int dicoNbOcc(char mot[], Arbre a);
int dicoNbMotsDifferents(Arbre a);
int dicoNbMotsTotal(Arbre a);
void printArbre(Arbre a);
