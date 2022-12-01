//Prototype des fonctions de l'arbre

typedef int TypeDonnee;

typedef struct cell
{
	TypeDonnee donnee;
	struct cell *fg, *fd;
}TypeNoeud;

//Fonction d'insère en tête
void InsereNoeud(TypeNoeud *racine, TypeDonnee donnee);

//Fonction d'affichage
void AfficheArbre(TypeNoeud *racine);

//Fonction de recherche dans un arbre
int Rechercher(TypeNoeud *racine, TypeDonnee donnee);
