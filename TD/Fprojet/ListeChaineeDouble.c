#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define couleur(param) printf("\033[%sm",param)

//Insertion en tête de liste
TypeCelluleDouble *InsereEnTeteDouble(TypeCelluleDouble *L, TypeDonnee donnee)
{
	TypeCelluleDouble *p;
	p = (TypeCelluleDouble*)malloc(sizeof(TypeCelluleDouble));
	p->donnee = donnee;
	p->precedent = NULL;
	p->suivant = NULL;
	if(L == NULL)
		L = p;
	else
	{
		L->precedent = p;
		p->suivant = L;
		L = p;
	}
	return L;
}

//Insertion en queue de liste
TypeCelluleDouble *InsereEnQueueDouble(TypeCelluleDouble *L, TypeDonnee donnee)
{
	TypeCelluleDouble *p;
	p = (TypeCelluleDouble*)malloc(sizeof(TypeCelluleDouble));
	p->donnee = donnee;
	p->precedent = NULL;
	p->suivant = NULL;
	if(L == NULL)
		L = p;
	else
	{
		TypeCelluleDouble *q;
		for(q = L; q->suivant != NULL; q = q->suivant);
		p->precedent = q;
		q->suivant = p;
	}
	return L;
}


//Fonction dans une liste double trier avec un resultat trié
TypeCelluleDouble *InsereTrierDouble(TypeCelluleDouble *L, TypeDonnee donnee)
{
	TypeCelluleDouble *p, *q;;
	p = (TypeCelluleDouble*)malloc(sizeof(TypeCelluleDouble));
	p->donnee = donnee;
	if(donnee <= L->donnee)
	{
		p->suivant = L;
		p->precedent = NULL;
		L->precedent = p;
		L = p;
	}
	else
	{
		for(q = L; q->suivant != NULL && q->suivant->donnee < donnee ; q = q->suivant);
		if(q->suivant->donnee >= donnee)
		{
			p->precedent = q;
			p->suivant = q->suivant;
			q->suivant = p;
		}
		else if(q->suivant == NULL)
		{
			q->suivant = p;
			p->precedent = q;
			p->suivant = NULL;
		}
	}
	return L;
}

//Suppression d'une occurence
TypeCelluleDouble *SupprimeOccurenceDouble(TypeCelluleDouble *L, TypeDonnee donnee)
{
	TypeCelluleDouble *p, *sup, *q;
	if(L->donnee == donnee)
	{
		sup = L;
		L = L->suivant;
		free(sup);
	}
	else
	{
		for(p = L; p->suivant != NULL && p->suivant->donnee != donnee; p = p->suivant);
		if(p->suivant->donnee == donnee)
		{
			 sup = p->suivant;
			 q = sup->suivant;
			 p->suivant = q;
			 q->precedent = p;
			 free(sup);
		}
	}
	return L;
}

//Suppression de toute occurence
TypeCelluleDouble *SupprimeTouteOccurenceDouble(TypeCelluleDouble *L, TypeDonnee donnee)
{
	TypeCelluleDouble *p = L, *sup, *q;
	if(p != NULL)
	{
		if(L->donnee == donnee)
		{
			sup = L;
			L = L->suivant;
			free(sup);
		}
		while(p->suivant != NULL)
		{
			if(p->suivant->donnee == donnee)
			{
				sup = p->suivant;
				q = sup->suivant;
				p->suivant = q;
				if(q != NULL)
					q->precedent = p;
				continue;
			}
			p = p->suivant;
		}
	}	
	return L;
}

//Saisir une liste
TypeCelluleDouble *SaisirListeTete(void)
{
	TypeCelluleDouble *L = NULL;
	int donnee;
	char oui = 'o';
	while(oui == 'o')
	{
		couleur("1;34");
		printf("Entrer la donnee a inserer : ");
		couleur("0");
		scanf("%d",&donnee);
		L = InsereEnTeteDouble(L, donnee);
		couleur("1;31");
		printf("Continuer ?\no.Oui\nn.Non\n");
		couleur("0");
		getchar();
		oui = getchar();
	}
	return L;
}

//Saisir une liste
TypeCelluleDouble *SaisirListeQueue(void)
{
	TypeCelluleDouble *L = NULL;
	int donnee;
	char oui = 'o';
	while(oui == 'o')
	{
		couleur("1;34");
		printf("Entrer la donnee a inserer : ");
		couleur("0");
		scanf("%d",&donnee);
		L = InsereEnQueueDouble(L, donnee);
		couleur("1;31");
		printf("Continuer ?\no.Oui\nn.Non\n");
		couleur("0");
		getchar();
		oui = getchar();
	}
	return L;
}

//Afficher la liste
void AfficheListeDouble(TypeCelluleDouble *L)
{
	TypeCelluleDouble *p;
	if(L == NULL)
	{
		couleur("1;32");
		printf("La liste est vide\n\n");
		couleur("0");
	}
	else
	{
		for(p = L; p != NULL; p = p->suivant)
		{
			couleur("1;32");
			printf("%d\t",p->donnee);
			couleur("0");
		}
		printf("\n\n");
	}
}
