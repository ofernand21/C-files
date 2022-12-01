#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define couleur(param) printf("\033[%sm",param)
#include"biblioSDD.h"
#include"Pile.c"
#include"File.c"
#include"ListeChainee.c"

void AfficheFile(File F)
{
	TypeCellule *p;
	for(p = F.Tete; p != NULL; p = p->suivant)
		printf("%d",p->donnee);
}

int main(char argc, int argv[])
{
	File F;
	int c = 1, donnee;
	while(c)
	{
		printf("Donner a enfiler : ");
		scanf("%d",&donnee);
		F = Enfiler(F,donnee);
		printf("1.continuer\n0.Sortir\n");
		scanf("%5d",&c);
	}
	AfficheFile(F);
}
