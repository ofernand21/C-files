#include <stdio.h>
#include <stdlib.h>
#include "TD.h"

/* Parcours en profondeur du graph a partir de 2 puis 7
pf1 = 2,3,1,6,5,4
pf2 = 7,8,4,2,3,1,6,5,0,9 */

/* Implemation du Parcours en profondeur d'un graphe */
void ParcoursProndeurs(Graphe G, Sommet D)
{
  for (int i = 0; i < G.n; i++)
    G.tabSommet[i].etiq = 0;
  Visiter(G,D.etiq);
}

void Visiter(Graphe G, int etiq)
{
  G.tabSommet[etiq] = 1;
  for (int i = 0; i < G.n; i++) {
    if(matrice[etiq][i] == 1 && G.tabSommet[i] == 0)
      Visiter(G,i);
  }
}

/* Fonction qui prend en paramètre deux sommets s1 et s2 dans un graphe donné sous forme
 de martrice d’adjacence, et qui renvoie 1 s’il existe un chemin de s1 à s2 et renvoie 0 sinon */
int ExisteChemin(Graphe G, int s1, int s2)
{
  if (matrice[s1][s2] == 1) {
    return 1;
  }
  else {
    return 0;
  }
}

/* le parcours en largeur au graphe de la figure 25.2 en prenantpour sommet de départ le sommet 4 puis le sommet 7
pl1 = 4,2,1,3,5,6   et   pl2 = 7,8,9,0,4,2,1,3,5,6  */

/* Implémentation en C du parcours en largeur. */
/* La file */
void Enfiler(File *F, Sommet S)
{
  TypeCellule *q;
  q = (TypeCellule*)malloc(sizeof(TypeCellule));
  q->donnee = S;
  q->suivant = NULL;
  if(F->Tete == NULL)
    F->Tete = F->Queue = q;
  else
  {
    F->Queue->suivant = q;
    F->Queue = q;
  }
}

int Defiler(File *F, Sommet *S)
{
  if(F->Tete == NULL)
    return 1;
  *S = F->Tete->donnee;
  F->Tete = F->Tete->suivant;
  return 0;
}

/* Le parcour */
void ParcoursLargeur(Graphe G, Sommet D)
{
  File F;
  F.Tete = NULL;
  Sommet S;
  for (int i = 0; i < G.n; i++)
    G.tabSommet[i].etiq = 0;
  G.tabSommet[D.num].etiq = 1;
  Enfiler(&F,D);
  while(F->Tete != NULL)
  {
    Defiler(&F, &S);
    for (int i = 0; i < G.n; i++) {
      if(matrice[S.numero][i] == 1 && G.tabSommet[i].etiq == 0) {
        G.tabSommet[i].etiq = 1;
        Enfiler(&F,G.tabSommet[i]);
      }
    }
  }
}
