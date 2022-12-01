#include <stdio.h>
#include <stdlib.h>

#define couleur(param) printf("\033[%sm",param)

#include "biblio.h"

#include "liste.c"

int main(char argc, int argv[])
{
	int choix;
	TypeCellule *L=NULL;
	debut:
	printf("Veillez choisir une action\n");
	printf("1.Creer une liste chaînee\n2.Afficher la liste chînee\n3.Quitté\n");
	scanf("%d",&choix);
	if(choix == 1)
	{
		int c;
		L = CreerListe(L);
		printf("\n\n");
		printf("Voullez-vous continuer ?\n1.Oui\n2.Non\n");
		scanf("%d",&c);
		if(c == 1)
			goto debut;
		goto debut;
	}
	else if(choix == 2)
	{
		int c;
		AfficheListe(L);
		printf("\n\n");
		printf("Voullez-vous continuer ?\n1.Oui\n2.Non\n");
		scanf("%d",&c);
		if(c == 1)
			goto debut;
	}
}
