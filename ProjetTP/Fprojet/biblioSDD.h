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
