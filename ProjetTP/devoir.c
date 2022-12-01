#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"Fprojet/biblioSDD.h"
#include"Fprojet/File.c"
#include"Fprojet/Pile.c"

/* Exercie 5 session de rattrapage  aa : 2018-2019
1) La pile
2) La file

3) LE code (On supposera que la file A est deja constituer) */

void TraitementChaine(File F, Pile *P)
{
	//clock_t temps = clock();
	int *elt, *elt1;
	TypeCellule *p;
	for(p = F.Tete; p != NULL; p = p->suivant)
	{
		if(EstVide(P) == 0)
		{
			if(Defiler(F,elt) == 0 && Depiler(P, elt1) == 0)
				printf("Au suivant svp !!");
		}
		else
		{
			printf("Plus d'assiètte, dommage !!");
			break;
		}
	}
	if(p == NULL)
		printf("Tout le monde est cervi, bon appetit !!");
} 

//Ces fonctions ne fait pas partie du devoir mais pour tester
Pile *SaisirPile()
{
	Pile *P;
	int c=1, donnee;
	while(c)
	{
		printf("Entrer la donner a empiler : ");
		scanf("%d",&donnee);
		P = Empiler(P,donnee);
		printf("Continuer ?\n1.Oui\n0.Non\n");
		scanf("%d",&c);
	}
	return P;
}

File SaisirFile()
{
	File F;
	int c=1, donnee;
	while(c)
	{
		printf("Entrer la donner a enfiler : ");
		scanf("%d",&donnee);
		F = Enfiler(F,donnee);
		printf("Continuer ?\n1.Oui\n0.Non\n");
		scanf("%d",&c);
	}
	return F;
}

int main(char argc, int argv[])
{
	File F;
	Pile *P = NULL;
	printf("Saisir Pile\n");
	P = SaisirPile();
	printf("Saisir File\n");
	F = SaisirFile();
	TraitementChaine(F,P);
}
