#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Initialiser
TypeCellule *Initialiser(void)
{
	return NULL;
}

//Est vide
int EstVide(Pile *P)
{
	return (P == NULL) ? 1 : 0;
}

//Est pleine
int EstPleine(Pile *P)
{
	return 0;
}

//Acceder au sommet de la pile
int AccederSommet(Pile *P, TypeDonnee *elt)
{
	if(P == NULL)
		return 1;
	else
	{
		*elt = P->donnee;
		return 0;
	}
}

//Empiler
Pile *Empiler(Pile *P, TypeDonnee donnee)
{
	Pile *pP;
	pP = (Pile*)malloc(sizeof(Pile));
	pP->donnee = donnee;
	pP->suivant = P;
	return pP;
}

//Depiler
int Depiler(Pile *P)
{
	if(P == NULL)
		return 1;
	else
	{
		Pile *pP=NULL;
		pP=P;
		P = P->suivant;
		free(pP);
		return 0;
	}
}

//Destruction
void Detruire(Pile *P)
{
	while(P != NULL)
	{
		Pile *q;
		q = P;
		P = P->suivant;
		free(q);
	}
	P = Initialiser();
}

//Vider
void Vider(Pile *P)
{
	Detruire(P);
}
