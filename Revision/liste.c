// Fonctions de liste chainee
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Insère en tête
TypeCellule *InsereEnTete(TypeCellule *L,TypeDonnee donnee)
{
	TypeCellule *p;
	p=(TypeCellule*)malloc(sizeof(TypeCellule));
	p->donnee = donnee;
	p->suivant = L;
	return p;
}

//Insere en Queue
TypeCellule *InsereEnQueue(TypeCellule *L, TypeDonnee donnee)
{
	TypeCellule *p;
	p=(TypeCellule*)malloc(sizeof(TypeCellule));
	p->donnee = donnee;
	p->suivant = NULL;
	if(L == NULL)
		L = p;
	TypeCellule *l;
	for(l=L; l->suivant != NULL; l=l->suivant);
	l->suivant = p;
	return L;
}

//Affiche liste
void AfficheListe(TypeCellule *L)
{
	if(L == NULL)
		printf("La liste est vide\n");
	else
	{
		for(TypeCellule *p=L; p != NULL; p=p->suivant)
			printf("%5d",p->donnee);
	}
	printf("\n");
}

//Creation de Liste
TypeCellule* CreerListe(TypeCellule *L)
{
	int type;
	debut:
	printf("Quelle type d'insertion voulez-vous pour la creation de cette liste ?\n1.Insertion en tête\n2.Insertion en queue\n3.Arrêté\n\n");
	scanf("%d",&type);
	if(type == 1)
	{
		char choix;
		puts("Voulez-vous inserer une valeure dans la liste ? appuyez 'o' pour OUI et 'n' pour NON");
		getchar();
		choix = getchar();
		while(choix == 'o')
		{
			int donnee;
			printf("Entrer la valeur à inserer : ");
			scanf("%d",&donnee);
			L=InsereEnTete(L,donnee);
			puts("Voulez-vous inserer une valeure dans la liste ? appuyez 'o' pour OUI et 'n' pour NON");
			getchar();
			choix = getchar();
		}
		goto debut;
	}
	else if(type == 2)
	{
		char choix;
		puts("Voulez-vous inserer une valeure dans la liste ? appuyez 'o' pour OUI et 'n' pour NON");
		getchar();
		choix = getchar();
		while(choix == 'o')
		{
			int donnee;
			printf("Entrer la valeur à inserer : ");
			scanf("%d",&donnee);
			L=InsereEnQueue(L,donnee);
			puts("Voulez-vous inserer une valeure dans la liste ? appuyez 'o' pour OUI et 'n' pour NON");
			getchar();
			choix = getchar();
		}
		goto debut;
	}
	else if(type == 3)
		return L;
	else
		goto debut;
}
