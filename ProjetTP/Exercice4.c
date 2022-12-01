#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Fprojet/biblioSDD.h"
#include"Fprojet/ListeChainee.c"
#define couleur(param) printf("\033[%sm",param)

TypeCellule *Concatenation1(TypeCellule *L1,TypeCellule *L2)
{
	TypeCellule *p;
	for(p=L1; p->suivant != NULL; p=p->suivant);
	p->suivant=L2;
	return L1;
}

TypeCellule *Concatenation2(TypeCellule *L1,TypeCellule *L2)
{
	TypeCellule *p, *L = NULL;
	for(p=L1; p != NULL; p=p->suivant)
		L = InsereEnQueue(L,p->donnee);
	for(p=L2; p != NULL; p=p->suivant)
		L = InsereEnQueue(L,p->donnee);
	return L;
}

int main()
{
   system("clear");
   TypeCellule *A,*B,*L;
   int choix;
   
   couleur("1;31");
   printf("Creation de la premiere liste\n");
   couleur("0");
   printf("Comment creer votre liste ?\n1.Tête\n2.Queue\n");
   scanf("%d",&choix);
   if(choix == 1)
   {
   	A=SaisirListeEnTete();
   	ViderBuffer();
   }
   else if(choix == 2)
   {
   	A=SaisirListeEnQueue();
   	ViderBuffer();
   }
   
   couleur("1;31");
   printf("Creation de la deuxime Liste\n");
   couleur("0");
   printf("Comment creer votre liste ?\n1.Tête\n2.Queue\n");
   scanf("%d",&choix);
   if(choix == 1)
   {
   	B=SaisirListeEnTete();
   	ViderBuffer();
   }
   else if(choix == 2)
   {
   	B=SaisirListeEnQueue();
   	ViderBuffer();
   }
   printf("Comment concatener les 2 listes ?\n1.Destructive\n2.Non destructive\n");
   scanf("%d",&choix);
   if(choix == 1)
   {
   	couleur("1;33");
   	printf("\n\nVoici la concatenation des deux liste\n");
   	couleur("0");
   	L=Concatenation1(A,B);
   	AfficheListe(L);
   }
   else if(choix == 2)
   {
   	printf("Voici votre premiere liste\n");
   	AfficheListe(A);
   	printf("Voici votre deuxieme liste\n");
   	AfficheListe(B);
   	couleur("1;33");
   	printf("\n\nVoici la concatenation des deux liste\n");
   	couleur("0");
   	L=Concatenation2(A,B);
   	AfficheListe(L);
   }
}      
