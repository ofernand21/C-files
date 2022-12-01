#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"Fprojet/biblioSDD.h"
#include"Fprojet/ListeChainee.c"

//Exercice 1 : somme d'element d'une liste
int Somme(TypeCellule *L)
{
	int somme = 0;
	TypeCellule *p;
	for(p = L; p != NULL; p = p->suivant)
		somme = somme + p->donnee;
	return somme;
}

//Exercice 2 (Recherche adresse d'un element)
TypeCellule *RechercheElement(TypeCellule *L,int n)
{
	TypeCellule *p, *q = NULL;
	for(p = L; p != NULL; p = p->suivant)
	{
		if(p->donnee == n)
		{
			q = p; break;
		}
	}
	return q;
}

//Exercice 3 a) (creation de liste avec tableau)
TypeCellule *CreerListeAvecTableau(int tab[], int n)
{
	TypeCellule *L = NULL;
	for(int i = 0; i < n; i++)
		L = InsereEnQueue(L, tab[i]);
	return L;
}

//Exercice 3 b) (creation de tableau avec liste)
int *CreerTableauAvecListe(TypeCellule *L)
{
	TypeCellule *p;
	int n=0, *tab;
	for(p = L; p != NULL; p = p->suivant)
		n++;
	tab = (int*)malloc(n*sizeof(int));
	int i = 0;
	for(p = L; p != NULL; p = p->suivant)
	{
		tab[i] = p->donnee;
		i++;
	}
	return tab;
}

//Exercice 4 (creation de liste inverse d'une autre)
TypeCellule *CreerListeEnvers(TypeCellule *L)
{
	TypeCellule *p, *L1 = NULL;
	for(p = L; p != NULL; p = p->suivant)
		L1 = InsereEnTete(L1, p->donnee);
	return L1;
}

//Exercice 5 (recopie de liste)
TypeCellule *RecopieListe(TypeCellule *L)
{
	TypeCellule *p, *L1 = NULL;
	for(p = L; p != NULL; p = p->suivant)
		L1 = InsereEnQueue(L1, p->donnee);
	return L1;
}

//Exercice 6
//Fonction qui supprime une occurence
TypeCellule *SupprimeOccurence(TypeCellule *L, TypeDonnee donnee)
{
	TypeCellule *p, *q;
	if(L->donnee == donnee)
	{
		q = L;
		L = L->suivant;
		free(q);
	}
	else
	{
		for(p = L; p->suivant->donnee != donnee && p->suivant != NULL; p = p->suivant);
		if(p->suivant->donnee == donnee)
		{
			q = p->suivant;
			p->suivant = q->suivant;
			free(q);
		}
	}
	return L;
}

//Fonction qui supprime toute occurence
TypeCellule *SupprimeTouteOccurence(TypeCellule *L,TypeDonnee donnee)  
{
	TypeCellule *p = L,*q,*sup;
	if(p != NULL)
	{
		if(p->donnee == donnee)
			L = L->suivant;
		while(p->suivant != NULL && p != NULL)
		{
			if(p->suivant->donnee == donnee)
			{
				sup=p->suivant;
				q=sup->suivant;
				p->suivant=q;
				free(sup);
				continue;
			}
			p=p->suivant;
		}
	}
	return L;
}

//Supprime toute occurence dans un tableau
void SupprimeTouteOccurenceTab(int tab[],int n,int donnee)
{
	int N = 0, nbre = 0;
	while(N < n)
	{
		if(tab[N] == donnee)
			N++;
		else
		{
			tab[nbre] = tab[N];
			N++;
			nbre++;
		}
	}
	n = nbre;
}

//Exercice 8 (trie d'une liste chainée)
TypeCellule *TriListe(TypeCellule *L)
{
	TypeCellule *p = L;
	while(p != NULL)
	{
		int d = p->donnee;
		TypeCellule *pP, *La = p;
		for(pP = p; pP != NULL; pP = pP->suivant)
		{
			if(pP->donnee < d)
			{
				d = pP->donnee;
				La = pP;
			}
		}
		if(d < p->donnee)
		{
			La->donnee = p->donnee;
			p->donnee = d;
		}
		p = p->suivant;
	}
	return L;
}

//Exercice 9 : Fusion alterner de deux liste
TypeCellule *FusionListeDestructive(TypeCellule *L1,TypeCellule *L2)
{
	TypeCellule *L = L1, *q, *p;
	while(L2 != NULL)
	{
		p = L1->suivant;
		q = L2->suivant;
		L2->suivant = L1->suivant;
		L1->suivant = L2;
		
		L1 = p; L2 = q;
	}
	return L;
}

TypeCellule *FusionListeNonDestructive(TypeCellule *L1,TypeCellule *L2)
{
	int n=0;
	TypeCellule *L = NULL;
	while(L2 != NULL)
	{
		if(n % 2 == 0)
		{
			L = InsereEnQueue(L, L1->donnee);
			L1 = L1->suivant;
			n++;
		}
		else
		{
			L = InsereEnQueue(L, L2->donnee);
			L2 = L2->suivant;
			n++;
		}
	}
	return L;
}

/*Exercice 10
a) fonction Interclassement*/
TypeCellule *Interclassement(TypeCellule *L1, TypeCellule *L2)
{
	TypeCellule *L = NULL;
	while(L1 != NULL || L2 != NULL)
	{
		if(L1 != NULL && L2 != NULL)
		{
			if(L1->donnee <= L2->donnee)
			{
				L = InsereEnQueue(L,L1->donnee);
				L1 = L1->suivant;
			}
			else
			{
				L = InsereEnQueue(L,L2->donnee);
				L2 = L2->suivant;
			}
		}
		else if(L1 != NULL)
		{
			L = InsereEnQueue(L,L1->donnee);
			L1 = L1->suivant;
		}
		else if(L2 != NULL)
		{
			L = InsereEnQueue(L,L2->donnee);
			L2 = L2->suivant;
		}
	}
	return L;
}

//b) TriInterclassement
TypeCellule *TriInterclassement(TypeCellule *L)
{
	TypeCellule *L1 = L, *L2, *R1, *R2;
	if(L == NULL || L->suivant == NULL)
		return L;
	else
	{
		TypeCellule *p;
		int n=0;
		for(p = L->suivant->suivant; p != NULL && p->suivant != NULL; p = p->suivant->suivant)
			L = L->suivant;
		L2 = L->suivant; 
		L->suivant = NULL;
		R1 = TriInterclassement(L1);
		R2 = TriInterclassement(L2);
		return Interclassement(R1, R2);
	}
}

//a) Interclassement avec tableau
int *InterclassementTab(int tab1[], int n1, int tab2[], int n2, int *N)
{
	int *tab;
	*N = n1+n2;
	tab = (int*)malloc((*N)*sizeof(int));
	int i = 0, j = 0, k = 0;
	while(i < n1 || j<n2)
	{
		if(i < n1 && j < n2)
		{
			if(tab1[i] <= tab2[j])
			{
				tab[k] = tab1[i];
				k++; i++;
			}
			else
			{
				tab[k] = tab2[j];
				k++; j++;
			}
		}
		else if(i < n1)
		{
			tab[k] = tab1[i];
			k++; i++;
		}
		else if(j < n2)
		{
			tab[k] = tab2[j];
			k++; j++;
		}
	}
	return tab;
}

//d) TriInterclassement avec tableau
int *TriInterclassementTab(int tab[], int n)
{
	int *tab1, *tab2, *Tab1, *Tab2, *Tab, *N;
	if(n == 0 || n == 1)
		return tab;
	else
	{
		int j = 0, k = 0, n1 = n/2, n2 = n-n1;
		tab1 =(int*)malloc(n1*sizeof(int));
		tab2 =(int*)malloc(n2*sizeof(int));
		for(int i = 0; i<n; i++)
		{
			if(j < n1)
			{
				tab1[j] = tab[i];
				j++;
			}
			else
			{
				tab2[k] = tab[i];
				k++;
			}
		}
		Tab1 = TriInterclassementTab(tab1, n1);
		Tab2 = TriInterclassementTab(tab2, n2);
		return InterclassementTab(Tab1, n1, Tab2, n2, N);
	}
}


//Exercice 11 : Fonction qui prend une liste et renvoi deux listes l'une pairs et l'autre impair
void PairsImpairs(TypeCellule *L, TypeCellule **L1, TypeCellule **L2)
{
	while(L != NULL)
	{
		if(L->donnee % 2 == 0)
			*L1 = InsereEnQueue(*L1, L->donnee);
		else
			*L2 = InsereEnQueue(*L2, L->donnee);
		L = L->suivant;
	}
}

int main(int argc, char **argv)
{
	system("clear");
	TypeCellule *L = NULL;
	int donnee,choix;
	printf("Creation de la 1ère liste \n");
	printf("Comment creer la liste ?\n1.En Tête\n2.En Queue\n");
	scanf("%d",&choix);
	if(choix == 1)
	{
		L = SaisirListeEnTete();
	}
	else if(choix == 2)
	{
		L = SaisirListeEnQueue();
	}
	/*printf("Creation de la 2e liste \n");
	printf("Comment creer la liste ?\n1.En Tête\n2.En Queue\n");
	scanf("%d",&choix);
	if(choix == 1)
	{
		L2 = SaisirListeEnTete();
	}
	else if(choix == 2)
	{
		L2 = SaisirListeEnQueue();
	}*/
	printf("Entrer la donnee a supprimer : ");
	scanf("%d",&donnee);
	printf("voici les deux nouvelles listes : \n");
	L = SupprimeTouteOccurence(L,donnee);
	printf("Voici la nouvelle liste : \n");
	AfficheListe(L);
}
