struct Node {
char c ;
int x ;
struct Node* FG;
struct Node* FD;
};

typedef struct Node Node ;
typedef Node* Arbre ;

    Arbre arbreConsVide(void);
    int arbreEstVide(Arbre a);
    Arbre arbreCons(char c, int n, Arbre fg, Arbre fd);
    char arbreRacineLettre(Arbre a);
    int arbreRacineNbOcc(Arbre a);
    Arbre arbreFilsGauche(Arbre a);
    Arbre arbreFilsDroit(Arbre a);
    void arbreSuppr(Arbre a);
