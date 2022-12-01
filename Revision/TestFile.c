#include <stdio.h>
#include <stdlib.h>

#define couleur(param) printf("\033[%sm",param)

#include "biblio.h"

#include "file.c"

int main(char argc, int argv[])
{
	int choix;
	File F;
	debut:
	printf("Veillez choisir une action\n\n");
	printf("1.Initialiser\n2.EstVide\n3.EstPleine\n4.Acceder à la tête de la file\n5.Enfiler\n6.Defiler\n7.Detruire\nAutre.Quitté\n\n");
	scanf("%d",&choix);

	if(choix == 1)
	{
		InitialiserF(F);
		printf("La file a été initialiser\n\n");
		goto debut;
	}
	else if(choix == 2)
	{
		if(EstVideF(F) == 0)
			printf("La file est vide\n\n");
		else
			printf("La file n'est pas vide\n\n");
		goto debut;
	}
	else if(choix == 3)
	{
		if(EstPleineF(F) == 1)
			printf("La file est pleine\n\n");
		else
			printf("La file n'est pas pleine\n\n");
		goto debut;
	}
	else if(choix == 4)
	{
		TypeDonnee *elt;
		if(AccederTete(F,elt) == 0)
			printf("On a acceder à la tête de la file et sa valeur est %d\n\n",*elt);
		else
			printf("On n'a pas pu acceder à la tête de file\n\n");
		goto debut;
	}
	else if(choix == 5)
	{
		TypeDonnee donnee;
		printf("Entrer la donnee a enfiler : ");
		scanf("%d",&donnee);
		Enfiler(F, donnee);
		goto debut;
	}
	else if(choix == 6)
	{
		TypeDonnee *elt;
		if(Defiler(F,elt) == 0)
			printf("La file à été defiler avec succes, sa valeur est %d\n\n",*elt);
		else
			printf("La file n'a pas pu être defiler\n\n");
		goto debut;
	}
	else if(choix == 7)
	{
		DetruireF(F);
		printf("La file a été detruite\n\n");
		goto debut;
	}
}
