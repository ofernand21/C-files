#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>

#define INTERVALLE_MAX 300
#define DUREE_TRAITEMENT_MAX 150

typedef int TypeDonnee;

typedef struct cell
{
	TypeDonnee arrivee, traitement;
	struct cell *suivant;
}TypeClient;

typedef struct
{
	TypeClient *Tete, *Queue;
}File;

void Enfiler(File *F, TypeClient client)
{
	TypeClient *q;
	q = (TypeClient*)malloc(sizeof(TypeClient));
	q->arrivee = client.arrivee;
	q->traitement = client.traitement;
	q->suivant = NULL;
	if(F->Tete == NULL)
		F->Tete = F->Queue = q;
	else
	{
		F->Queue->suivant = q;
		F->Queue = q;
	}
}

void CreerListeClients(File *F)
{
	int nbre;
	printf("Entrer le nombre de clients a traiter");
	scanf("%d",&nbre);
	TypeClient donnee;
	donnee.arrivee = 8*3600;
	donnee.traitement = rand()%DUREE_TRAITEMENT_MAX;
	Enfiler(F,donnee);
	for(int i = 1; i <= nbre; i++)
	{
		donnee.arrivee += rand()%INTERVALLE_MAX;
		donnee.traitement = rand()%DUREE_TRAITEMENT_MAX;
		Enfiler(F,donnee);
	}
}

void AfficheClients(File F)
{
	TypeClient *p;
	TypeDonnee numero = 1, date; 
	for(p = F.Tete; p != NULL; p = p->suivant)
	{
		date = p->arrivee + p->traitement;
		printf("Client N°%d, est arriver à %d h %d min %d sec et a eu traiter à %d h %d min %d sec\n",numero, p->arrivee/3600, (p->arrivee%3600)/60, ((p->arrivee%3600)%60)/60, date/3600, (date%3600)/60, ((date%3600)%60)/60);
		numero++;
		sleep(((p->arrivee%3600)%60)/60);
	}
}


int main(int argc, char **argv)
{
	system("clear");
	printf("\t********************* BIENVENU A LA GARE ********************************\t\n");
	File F;
	CreerListeClients(&F);
	AfficheClients(F);
}
