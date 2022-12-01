#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"Fprojet/biblioSDD.h"
#include"Fprojet/ListeChaineeDouble.c"
#define couleur(param) printf("\033[%sm",param)

int main(int argc, char **argv)
{
	system("clear");
	TypeCelluleDouble *L = NULL;
	int choix, donnee;
	printf("Comment creer la liste ?\n1.En tête\n2.En queue\n");
	scanf("%d",&choix);
	if(choix == 1)
	{
		L = SaisirListeTete();
	}
	else if(choix == 2)
	{
		L = SaisirListeQueue();
	}
	printf("Entrer la donnee a supprimer dans la liste : ");
	scanf("%d",&donnee);
	L = SupprimeTouteOccurenceDouble(L, donnee);
	printf("Voici la nouvelle liste :\n");
	AfficheListeDouble(L);
}
