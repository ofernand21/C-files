#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Fprojet/biblioSDD.h"
#include"Fprojet/ListeChainee.c"

//Fonction qui supprime une occurence
TypeCellule *SupprimeOccurence(TypeCellule *L, TypeDonnee donnee)
{
	TypeCellule *p;
	for(p = L; p->suivant->donnee != donnee && p != NULL; p = p->suivant);
	if(p->suivant->donnee == donnee)
	{
		TypeCellule *q;
		q = p->suivant;
		p->suivant = q->suivant;
		free(q);
	}
	return L;
}

//Fonction qui supprime toute occurence
TypeCellule *SupprimeTouteOccurence(TypeCellule *L,TypeDonnee donnee)  
{
	TypeCellule *p,*q,*sup;
	p=L;
	if(p == NULL)
		return L;
	else if(p->donnee = donnee)
	{
		L = L->suivant;
		free(p);
		return L;
	}
	else
	{
		q=p;
		p=p->suivant;
		while(p != NULL)
		{
			if(p->donnee == donnee)
			{
				sup=p;
				p=p->suivant;
				q->suivant=p;
				free(sup);
			}
			p=p->suivant;
			q=q->suivant;
		}
		return L;
	}
}

int main(char argc, int argv[])
{
	system("clear");
	TypeCellule *L=NULL;
	int choix, donnee;
	printf("Comment creer la liste ?\n1.En Tete\n2.En Queue\n");
	scanf("%d",&choix);
	if(choix == 1)
	{
		L = SaisirListeEnTete();
		printf("Voici votre Liste\n\n");
		AfficheListe(L);
		printf("1.Supprimer une occurence\n2.Supprimer toute occurence\n");
		scanf("%d",&choix);
		if(choix == 1)
		{
			printf("Entrer l'occurence a supprimer : ");
			scanf("%d",&donnee);
			L = SupprimeOccurence(L,donnee);
			printf("Voici votre nouvelle liste : \n");
			AfficheListe(L);
		}
		else if(choix == 2)
		{
			printf("Entrer l'occurence a supprimer : ");
			scanf("%d",&donnee);
			L = SupprimeTouteOccurence(L,donnee);
			printf("Voici votre nouvelle liste : \n");
			AfficheListe(L);
		}
	}
	else if(choix == 2)
	{
		L = SaisirListeEnQueue();
		printf("Voici votre Liste\n\n");
		AfficheListe(L);
		printf("1.Supprimer une occurence\n2.Supprimer toute occurence\n");
		scanf("%d",&choix);
		if(choix == 1)
		{
			printf("Entrer l'occurence a supprimer : ");
			scanf("%d",&donnee);
			L = SupprimeOccurence(L,donnee);
			printf("Voici votre nouvelle liste : \n");
			AfficheListe(L);
		}
		else if(choix == 2)
		{
			printf("Entrer l'occurence a supprimer : ");
			scanf("%d",&donnee);
			L = SupprimeTouteOccurence(L,donnee);
			printf("Voici votre nouvelle liste : \n");
			AfficheListe(L);
		}
	}
}
