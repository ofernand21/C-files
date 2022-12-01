/* Reponses au question 
1) On gerera les tâches avec la file */

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

typedef struct
{
	TypeCellule *tete,*queue;
}File;

//Fonction Empiler
File Enfiler(File F, TypeTache tache)
{
	TypeCellule *pF;
	pF = (TypeCellule*)malloc(sizeof(TypeCellule));
	pF->tache.numero = tache.numero;
	pF->tache.priorite = tache.priorite;
	pF->suivant = NULL;
	if(F.tete == NULL)
		F.tete = F.queue = pF;
	else
	{
		F.queue->suivant = pF;
		F.queue = pF;
	}
	return F;
}

//Fonction de saisi de Tâche
File SaisiTache()
{
	File F;
	int oui = 1;
	printf("Vous entrerez les tâches suivant les priorités décroissante\n");
	while(oui == 1)
	{
		TypeTache tache;
		printf("Entrer la priorité : ");
		scanf("%d",&tache.priorite);
		printf("Entrer le numero de la tâche : ");
		scanf("%d",&tache.numero);
		F = Enfiler(F, tache);
		printf("Voulez-vous ajoutez une tâche ?\n1.Oui\n2.Non\n");
		scanf("%d",&oui);
	}
	return F;
}

//Fonction de traitement des tâches
void TraitementTache(File F)
{
	TypeCellule *p;
	for(p = F.tete; p != NULL; p = p->suivant)
		printf("Tâche N°%d, priorité %d\n", p->tache.numero, p->tache.priorite);
}

int main(char argc, int argv[])
{
	system("clear");
	File F;
	printf("Traitement de tâche\n\n");
	F = SaisiTache();
	TraitementTache(F);
}
