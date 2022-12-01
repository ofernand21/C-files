typedef int TypeDonnee;

typedef struct cell
{
	TypeDonnee donnee;
	struct cell *suivant;
}TypeCellule;

TypeCellule *InsereEnTete(TypeCellule *L,TypeDonnee donnee);

TypeCellule *InsereEnQueue(TypeCellule *L,TypeDonnee donnee);

void AfficheListe(TypeCellule *L);

TypeCellule* CreerListe(TypeCellule *L);

/*🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️  PILE  🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️*/
typedef TypeCellule Pile;

TypeCellule *Initialiser(void);

int EstVide(Pile *P);

int EstPleine(Pile *P);

int AccederSommet(Pile *P, TypeDonnee *elt);

Pile *Empiler(Pile *P, TypeDonnee donnee);

int Depiler(Pile *P);

void Detruire(Pile *P);

void Vider(Pile *P);

//*🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️  FILE  🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️*/

typedef struct 
{
   TypeCellule *tete, *queue;
}File;   

//Initialisation
void InitialiserF(File F);   

//EstPleine
int EstPleineF(File F);

//EstVide
int EstVideF(File F);

//AccederTete
int AccederTete(File F,TypeDonnee *donnee);     
 
//Enfiler
void Enfiler(File F, TypeDonnee elt);

int Defiler(File F,TypeDonnee *elt);

//Detruire
void DetruireF(File F);
