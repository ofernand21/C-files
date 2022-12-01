#include <stdio.h>
#include <stdlib.h>

#define couleur(param) printf("\033[%sm",param)

#include "biblio.h"

#include "pile.c"

int main(char argc, int argv[])
{
	int choix;
	Pile *P=NULL;
	debut:
	printf("Veillez choisir une action\n\n");
	printf("1.Initialiser\n2.EstVide\n3.EstPleine\n4.Acceder au sommet de la pile\n5.Empiler\n6.Depiler\n7.Detruire\n8.Vider\nAutre.Quitté\n\n");
	scanf("%d",&choix);

	if(choix == 1)
	{
		P = Initialiser();
		goto debut;
	}
	else if(choix == 2)
	{
		if(EstVide(P) == 1)
			printf("La pile est vide\n\n");
		else
			printf("La pile n'est pas vide\n\n");
		goto debut;
	}
	else if(choix == 3)
	{
		if(EstPleine(P) == 1)
			printf("La pile est pleine\n\n");
		else
			printf("La pile n'est pas pleine\n\n");
		goto debut;
	}
	else if(choix == 4)
	{
		TypeDonnee *elt;
		if(AccederSommet(P,elt) == 0)
			printf("On a acceder à l'element du sommet et cette valeur est %d\n\n",*elt);
		else
			printf("On n'a pas pu acceder au somment\n\n");
		goto debut;
	}
	else if(choix == 5)
	{
		TypeDonnee donnee;
		printf("Entrer la donnee a empiler : ");
		scanf("%d",&donnee);
		P = Empiler(P, donnee);
		goto debut;
	}
	else if(choix == 6)
	{
		if(Depiler(P) == 0)
			printf("La pile à été depiler avec succes\n\n");
		else
			printf("La pile n'a pas pu être depiler\n\n");
		goto debut;
	}
	else if(choix == 7)
	{
		Detruire(P);
		goto debut;
	}
	else if(choix == 8)
	{
		Vider(P);
		goto debut;
	}
}
