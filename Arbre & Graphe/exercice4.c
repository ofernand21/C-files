#include "stdio.h"
#include "stdlib.h"
#include "string.h"

// structure de l'arbre
typedef struct cell2
{
  char donnee[10];
  struct cell2 *fg, *fd;
}TypeNoeud;

typedef struct cell
{
  char donnee[10];
  struct cell *suivant;
}TypeCellule;

typedef TypeCellule *Pile;

void Empiler(Pile *P, char donnee[])
{
  TypeCellule *q;
  q = (TypeCellule*)malloc(sizeof(TypeCellule));
  strcpy(q->donnee, donnee);
  if(*P == NULL)
  {
    q->suivant = NULL;
    *P = q;
  }
  else
  {
    q->suivant = *P;
    *P = q;
  }
}

void Depiler(Pile *P, char elt[])
{
  TypeCellule *Sup;
  if(*P != NULL)
  {
    strcpy(elt, (*P)->donnee);
    Sup = *P;
    *P = (*P)->suivant;
    free(Sup);
  }
}

void Detruire(Pile *P)
{
  TypeCellule *q,*sup;
  for(q = *P; q != NULL; q = q->suivant)
  {
    sup = q;
    q = q->suivant;
    free(sup);
  }
  *P = NULL;
}

//Affichage des élément d'une Pile
void AffichePile(Pile P)
{
  TypeCellule *q;
  if(q == NULL)
    printf("Aucune valeur dans la Pile");
  else{
    for(q = P; q != NULL; q = q->suivant)
      printf("%s\n", q->donnee);
  }
}

void Evaluation(TypeNoeud *racine, Pile *P)
{
  char x[10], y[10], c[10];
  long resultat;
  float resultat2;
  if(racine != NULL)
  {
    Evaluation(racine->fg, P);
    Evaluation(racine->fd, P);
    if(strncmp(racine->donnee,"*",1) == 0)
    {
      Depiler(P,x);
      Depiler(P,y);
      resultat = atol(x)*atol(y);
      sprintf(c,"%ld",resultat);
      Empiler(P,c);
    }
    else if(strncmp(racine->donnee,"/",1) == 0)
    {
      Depiler(P,x);
      Depiler(P,y);
      resultat2 = atol(x)/atol(y);
      sprintf(c,"%f",resultat2);
      Empiler(P,c);
    }
    else if(strncmp(racine->donnee,"+",1) == 0)
    {
      Depiler(P,x);
      Depiler(P,y);
      resultat = atol(x)+atol(y);
      sprintf(c,"%ld",resultat);
      Empiler(P,c);
    }
    else if(strncmp(racine->donnee,"-",1) == 0)
    {
      Depiler(P,x);
      Depiler(P,y);
      resultat = atol(x)-atol(y);
      sprintf(c,"%ld",resultat);
      Empiler(P,c);
    }
    else
      Empiler(P,racine->donnee);
  }
}

void Generer(TypeNoeud *racine, Pile *P)
{
  if(racine != NULL)
  {
    Generer(racine->fd,P);
    Generer(racine->fg,P);
    Empiler(P,racine->donnee);
  }
}

void CreationPrefixer(TypeNoeud **racine, Pile *P)
{
  // Pour utiliser cette fonction faudra faudra faire une allocation pour la racine
  char valeur[10];
  TypeNoeud *noeud;
  if(P != NULL)
  {
    Depiler(P,valeur);
    strcpy((*racine)->donnee, valeur);
    if(strcmp(valeur,"*") == 0 || strcmp(valeur,"/") == 0 || strcmp(valeur,"+") == 0 || strcmp(valeur,"-") == 0)
    {
      (*racine)->fd = (TypeNoeud*)malloc(sizeof(TypeNoeud));
      (*racine)->fd = (TypeNoeud*)malloc(sizeof(TypeNoeud));
      CreationPrefixer(&(*racine)->fg, P);
      CreationPrefixer(&(*racine)->fd, P);
    }
    else
    {
      (*racine)->fg = NULL;
      (*racine)->fd = NULL;
    }
  }
}

void EcritureParentheser(TypeNoeud *racine, Pile *P)
{
  if(racine != NULL)
  {
    EcritureParentheser(racine->fd, P);
    if(racine->fg != NULL && racine->fd != NULL)
    {
      Empiler(P,"(");
      Empiler(P,racine->fg->donnee);
      Empiler(P,racine->donnee);
      Empiler(P,racine->fd->donnee);
      Empiler(P,")");
      racine = NULL;
    }
    else if(racine->fg == NULL || racine->fd == NULL)
      Empiler(P,racine->donnee);
    EcritureParentheser(racine->fg, P);
  }
}

void PilePrefixer(Pile *Principal, Pile *inter, Pile *Final)
{
  char donnee[10];
  TypeCellule *q = *Principal;
  while(q != NULL)
  {
    if(strcmp(q->donnee,")") == 0)
    {
      Depiler(inter, donnee);
      Empiler(Final,donnee);
    }
    else if(strcmp(q->donnee,"/") == 0 || strcmp(q->donnee,"*") == 0 || strcmp(q->donnee,"-") == 0 || strcmp(q->donnee,"+") == 0)
      Empiler(inter,q->donnee);
    else
      Empiler(Final,q->donnee);
    q = q->suivant;
  }
  while(inter != NULL)
  {
    Depiler(inter, donnee);
    Empiler(Final,donnee);
  }
  Detruire(inter);
  Detruire(Principal);
}

void SaisirOperation(Pile *P)
{
  char enc = 'o';
  char *Operation;
  printf("Saisir l'operation avec les parenthèse en validant par entrée à chaque fois\nPuis taper le caractère 'n' pour terminer\n\n");
  while(enc != 'n')
  {
    Operation = (char*)malloc(10*sizeof(char));
    scanf("%s", Operation);
    if(strcmp(Operation, "n") != 0)
      Empiler(P, Operation);
    else
      enc = 'n';
  }
}

void CreationArbre(TypeNoeud **racine)
{
  Pile *P = NULL, *Or = NULL, *inter = NULL;
  SaisirOperation(Or);
  PilePrefixer(Or, inter, P);
  CreationPrefixer(racine, P);
}

//La fonction principale
int main(int argc, char **argv)
{
  TypeNoeud *racine;
  racine = (TypeNoeud*)malloc(sizeof(TypeNoeud));
  Pile *P = NULL;
  CreationArbre(&racine);
  printf("Voulez vous afficher l'operation de l'arbre\n");
  int oui;
  scanf("%d\n", &oui);
  if(oui == 1)
  {
    EcritureParentheser(racine,P);
    AffichePile(*P);
  }
  return 0;
}
