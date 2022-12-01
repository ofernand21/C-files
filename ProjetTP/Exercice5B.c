/* Reponses au question 
1) On gerera les tâches avec les piles */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define couleur(param) printf("\033[%sm",param)

typedef struct
{
	int numero, priorite;
}TypeTache;

typedef struct cell
{
	TypeTache tache;
	struct cell *suivant;
}TypeCellule;

typedef TypeCellule Pile;

//Fonction Empiler
Pile *Empiler(Pile *P, TypeTache tache)
{
	Pile *pP;
	pP = (Pile*)malloc(sizeof(Pile));
	pP->tache.numero = tache.numero;
	pP->tache.priorite = tache.priorite;
	pP->suivant = P;
	return pP;
}

//Fonction de saisi de Tâche
Pile *SaisiTache()
{
	Pile *P = NULL;
	TypeTache tache;
	int numero, priorite, nbre = 0, oui = 1;
	//tache = (TypeTache*)malloc(sizeof(TypeTache));
	printf("Vous entrerez les tâches suivant les priorités croissante\n");
	while(oui == 1)
	{
		printf("Entrer la priorité : ");
		scanf("%d",&priorite);
		tache.priorite = priorite;
		printf("Entrer le numero de la tâche : ");
		scanf("%d",&numero);
		tache.numero = numero;
		P = Empiler(P, tache);
		nbre++;
		printf("Voulez-vous ajoutez une tâche ?\n1.Oui\n2.Non\n");
		scanf("%d",&oui);
	}
	return P;
}

//Fonction de traitement des tâches
void TraitementTache(Pile *P)
{
	Pile *pP;
	for(pP = P; pP != NULL; pP = pP->suivant)
		printf("Tâche N°%d, priorité %d\n", pP->tache.numero, pP->tache.priorite);
}

int main(char argc, int argv[])
{
	Pile *P = NULL;
	printf("Traitement de tâche\n\n");
	P = SaisiTache();
	TraitementTache(P);
}
