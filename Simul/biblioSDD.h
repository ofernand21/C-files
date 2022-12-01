typedef int TypeDonnee;

void ViderBuffer();
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

/*🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️  FILE  🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️*/

typedef struct 
{
   TypeCellule *Tete, *Queue;
}File;   

//Initialisation
File *InitialiserF();   

//EstPleine
int EstPleineF(File *F);

//EstVide
int EstVideF(File *F);

//AccederTete
int AccederTeteF(File *F,TypeDonnee *donnee);     
 
//Enfiler
void *EnfilerF(File *F, TypeDonnee elt);

int DefilerF(File *F,TypeDonnee *elt);

//Detruire
void DetruireF(File *F);

//vider
void ViderF(File *F);

//Affichage
void AfficheFile(File *F);

//Saisir File
File *SaisirFile();



/*🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️  PILE  🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️*/

typedef struct
{
  TypeCellule *Tete,*Queue;
}Pile;

//Initialiser
Pile *Initialiser();

//EstVide
int EstVide(Pile *p);

//EstPleine
int EstPleine(Pile *p);

//AccederSmmet
int AccederSommet(Pile *p,TypeDonnee *elt);

//Empiler
void *Empiler(Pile *pt,TypeDonnee elt);

//DEpiler
int Depiler(Pile *pt,TypeDonnee *elt);

//detruire
void Detruire(Pile *p);       

//vider
void Vider(Pile *P); 

//Affichage
void AffichePile(Pile *p); 

TypeCellule *SaisirListe();
