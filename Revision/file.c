#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Initialisation
void InitialiserF(File F)
{
	F.tete = NULL;
}

//Voir si vide
int EstVideF(File F)
{
	return (F.tete == NULL) ? 1 : 0;
}

//Voir si pleine
int EstPleineF(File F)
{
	return 0;
}

//Acceder a la Tête de file
int AccederTete(File F, TypeDonnee *elt)
{
	if(F.tete == NULL)
		return 1;
	else
	{
		*elt = F.tete->donnee;
		return 0;
	}
}

//Enfiler
void Enfiler(File F, TypeDonnee donnee)
{
	TypeCellule *pF;
	pF = (TypeCellule*)malloc(sizeof(TypeCellule));
	pF->donnee = donnee;
	pF->suivant = NULL;
	if( F.tete == NULL)
		F.tete = F.queue = pF;
	else
	{
		F.queue->suivant = pF;
		F.queue = pF;
	}
}

//Defiler
int Defiler(File F, TypeDonnee *elt)
{
	if(F.tete == NULL)
		return 1;
	else
	{
		TypeCellule *pF;
		*elt = F.tete->donnee;
		//pF = (TypeCellule*)malloc(sizeof(TypeCellule));
		pF = F.tete;
		F.tete = F.tete->suivant;
		free(pF);
		return 0;
	}
}

//Detruire la file
void DetruireF(File F)
{
	while(F.tete != NULL)
	{
		TypeCellule *pF;
		pF = F.tete;
		F.tete = F.tete->suivant;
	}
	F.tete = NULL;
}
