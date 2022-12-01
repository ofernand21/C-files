typedef int TypeDonnee;

void  ViderBuffer();
long Lecture();

/*🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️  Liste  🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️*/

typedef struct cell
{
  TypeDonnee donnee;
  struct cell *suivant;
}TypeCellule;

//Insere en tete de liste
TypeCellule *InsereEnTete(TypeCellule *ancienL, TypeDonnee donnee);

//Insere en queue de liste
TypeCellule *InsereEnQueue(TypeCellule *ancienL, TypeDonnee donnee);

//Affichage de liste
void AfficheListe(TypeCellule *L);

//Creation de liste
TypeCellule *SaisirListeEnTete();

TypeCellule *SaisirListeEnQueue();



/*🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️  PILE  🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️*/

typedef TypeCellule Pile;

//Initialiser
Pile *Initialiser();

//EstVide
int EstVide(Pile *p);

//EstPleine
int EstPleine(Pile *p);

//AccederSmmet
int AccederSommet(Pile *p,TypeDonnee *elt);

//Empiler
Pile *Empiler(Pile *pt,TypeDonnee elt);

//DEpiler
int Depiler(Pile *pt,TypeDonnee *elt);

//detruire
void Detruire(Pile *p);       

//vider
void Vider(Pile *P); 

 

/*🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️  FILE  🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️*/

typedef struct 
{
   TypeCellule *Tete, *Queue;
}File;   

//Initialisation
void InitialiserF(File F);   

//EstPleine
int EstPleineF(File F);

//EstVide
int EstVideF(File F);

//AccederTete
int AccederTeteF(File F,TypeDonnee *donnee);     
 
//Enfiler
File EnfilerF(File F, TypeDonnee elt);

int DefilerF(File F,TypeDonnee *elt);

//Detruire
void DetruireF(File F);

//vider
void ViderF(File F);


/*🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️  LISTE DOUBLEMENT CHAÎNEE  🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️*/

typedef struct cell2
{
	TypeDonnee donnee;
	struct cell2 *precedent, *suivant;
}TypeCelluleDouble;

//Insertion en tête de liste
TypeCelluleDouble *InsereEnTeteDouble(TypeCelluleDouble *L, TypeDonnee donnee);

//Insertion en queue de liste
TypeCelluleDouble *InsereEnQueueDouble(TypeCelluleDouble *L, TypeDonnee donnee);

//Fonction dans une liste double trier avec un resultat trié
TypeCelluleDouble *InsereTrierDouble(TypeCelluleDouble *L, TypeDonnee donnee);

//Suppression d'une occurence
TypeCelluleDouble *SupprimeOccurenceDouble(TypeCelluleDouble *L, TypeDonnee donnee);

//Suppression de toute occurence
TypeCelluleDouble *SupprimeTouteOccurenceDouble(TypeCelluleDouble *L, TypeDonnee donnee);

//Saisir une liste
TypeCelluleDouble *SaisirListeTete(void);

//Saisir une liste
TypeCelluleDouble *SaisirListeQueue(void);

//Afficher la liste
void AfficheListeDouble(TypeCelluleDouble *L);
