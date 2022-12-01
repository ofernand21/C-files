#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Fprojet/biblioSDD.h"
#include"Fprojet/ListeChainee.c"

int EstTrierCroissant(TypeCellule *L)
{
	int oui = 0;
	TypeCellule *p;
	if(L == NULL)
		printf("La liste est vide\n");
	else
	{
		for(p = L; p->suivant != NULL && p->donnee <= p->suivant->donnee; p = p->suivant);
		if(p->suivant == NULL)
			oui = 1;
	}
	return oui;
}

TypeCellule *InsereElement(TypeCellule *L,TypeDonnee donnee)
{
	if(EstTrierCroissant(L) == 0)
		printf("La liste n'est pas trier");
	else if(EstTrierCroissant(L) == 1)
	{
		TypeCellule *p,*q;
		q = (TypeCellule*)malloc(sizeof(TypeCellule));
		q->donnee = donnee;
		if(donnee <= L->donnee)
		{
			q->suivant = L;
			L = q;
		}
		else
		{
			for(p = L; p->suivant->suivant != NULL && donnee > p->suivant->donnee; p = p->suivant);
			if(donnee <= p->suivant->donnee)
			{
				q->suivant = p->suivant;
				p->suivant = q;
			}
			else if(p->suivant->suivant == NULL)
			{
				p->suivant->suivant = q;
				q->suivant = NULL;
			}	
		}
		return L;
	}
}

int main(char argc, int argv[])
{
	system("clear");
	int choix;
	TypeCellule *L = NULL;
	printf("Comment creer la liste ?\n1.En Tete\n2.En Queue\n");
	scanf("%d",&choix);
	if(choix == 1)
	{
		L = SaisirListeEnTete();
		printf("1.Verifier si la liste est trier\n2.Afficher la liste\n");
		scanf("%d",&choix);
		if(choix == 1)
		{
			if(EstTrierCroissant(L) == 1)
			{
				printf("La liste est trier est la voici : \n");
				AfficheListe(L);
				printf("Voulez-vous inserer un element dans la liste ?\n1.Oui\n2.Non\n");
				scanf("%d",&choix);
				if(choix == 1)
				{
					TypeDonnee donnee;
					printf("Entrer la valeur a inserer : ");
					scanf("%d",&donnee);
					L = InsereElement(L,donnee);
					printf("La nouvelle liste est : \n");
					AfficheListe(L);
				}
			}
			else
				printf("La liste n'est pas trier\n");
		}
		else if(choix == 2)
			AfficheListe(L);
	}
	else if(choix == 2)
	{
		L = SaisirListeEnQueue();
		printf("1.Verifier si la liste est trier\n2.Afficher la liste\n");
		scanf("%d",&choix);
		if(choix == 1)
		{
			if(EstTrierCroissant(L) == 1)
			{
				printf("La liste est trier est la voici : \n");
				AfficheListe(L);
				printf("Voulez-vous inserer un element dans la liste ?\n1.Oui\n2.Non\n");
				scanf("%d",&choix);
				if(choix == 1)
				{
					TypeDonnee donnee;
					printf("Entrer la valeur a inserer : ");
					scanf("%d",&donnee);
					L = InsereElement(L,donnee);
					printf("La nouvelle liste est : \n");
					AfficheListe(L);
				}
			}
			else
				printf("La liste n'est pas trier\n");
		}
		else if(choix == 2)
			AfficheListe(L);
	}
}
