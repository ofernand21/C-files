#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <TD.h>

// Exercice 1: Recherche d'un entier
void Rechercher2(TypeNoeud *racine, int n, int *retour)
{
  /* Pour utiliser cette fonction il faut initialiser retour a 0 */
  if(racine != NULL)
  {
    if(racine->donnee == n)
      *retour = 1;
    else {
      Rechercher(racine->fg);
      Rechercher(racine->fd);
    }
  }
}

// Exercice 1: Recherche d'un entier
int Rechercher2(TypeNoeud *racine, int n)
{
  if(racine != NULL)
  {
    if(racine->donnee == n)
      return 1;
    Rechercher(racine->fg);
    Rechercher(racine->fd);
  }
  return 0; // return 0 if tree is empty
}

//Exercice2: Calcul de somme des valeures d'un arbre
void Somme(TypeNoeud *racine, int *somme)
{
  if(racine != NULL)
  {
    *somme += racine->donnee;
    Somme(racine->fg, somme);
    Somme(racine->fd, somme);
  }
}

//Exercice3: Calcul du maximum
void Maximum(TypeNoeud *racine, int *max)
{
  if(racine != NULL)
  {
    if(racine->donnee > *max)
      max = racine->donnee;
    Maximum(racine->fg, max);
    Maximum(racine->fd, max);
  }
}
