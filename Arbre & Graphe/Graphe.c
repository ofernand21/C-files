#include "stdio.h"
#include "stdlib.h"
#include "TD.h"

//Exercice6: Parcours en profondeur de Graphe
void ParcoursProf(Graphe G, int numeroSommet)
{
  for(int i=0; i<= G.n; i++)
    G.tabSommet[i]->etiq == 0;
  Visiter(G,numeroSommet);
}

//La visite des sommet de Graphe
void Visiter(Graphe G, int sommet)
{
  G.tabSommet[sommet] = 1
  for(int i = 0; i <= G.n; i++)
  {
    if(G.matrice[sommet][i] == 1 && G.matrice[sommet].etiq == 0)
      Visiter(G, i);
  }
}

//Exercice7: Parcours en largeur de Graphe
//La fonction enfiler
void Enfiler(File *F, Sommet S)
{
  TypeCellule *q;
  q = (TypeCellule*)malloc(sizeof(TypeCellule));
  q->donnee = S;
  q->suivant = NULL;
  if(F->Tete == NULL)
  {
    F->Tete = F->Queue = q;
  }
  else
  {
    F->Queue->suivant = q;
    F->Queue = q;
  }
}

void Defiler(File *F, Sommet *elt)
{
  TypeCellule *sup;
  if(F->Tete != NULL)
  {
    *elt = F->Tete->sommet;
    sup = F->Tete;
    F->Tete = F->Tete->suivant;
    free(sup);
  }
}


void ParcoursLargeur(Graphe G, int sommet, File *F)
{
  F->Tete = NULL;
  Sommet s;
  for(int i = 0; i <= n; i++)
    G.tabSommet[i].etiq = 0;
  G.tabSommet[sommet].etiq = 1;
  Enfiler(F,G.tabSommet[sommet]);
  while(F->Tete != NULL)
  {
    Defiler(F,&s);
    for(int i = s.num; i < G.n; i++)
    {
      if(G.tabSommet[i].etiq == 0 && G.matrice[s.num][i] == 1)
      {
        G.tabSommet[i].etiq = 1;
        Enfiler(F,G.tabSommet[i])
      }
    }
  }
}
