// The fonctions prototypes for arbre.c
// Date: 17 nov 2021

// structure de l'arbre
typedef int TypeDonnee;

typedef struct cell
{
  TypeDonnee donnee;
  struct cell *fg, *fd;
}TypeNoeud;

//structure de graphe
typedef struct
{
  int num;
  int etiq;
}Sommet;

typedef struct
{
  int n;
  sommet *tabSommet;
  int **matrice;
}Graphe;

//Definition de file
typedef struct cell2
{
  Sommet donnee;
  struct cell2 *suivant;
}TypeCellule;

typedef struct {
  TypeCellule *Tete, *Queue;
}File;


//Rechercher d'un entier
int Rechercher(TypeNoeud *racine, int n);
//Calcul de somme des valeures d'un arbre
void Somme(TypeNoeud *racine, int *somme);
//Calcul du maximum
void Maximum(TypeNoeud *racine, int *max);
