#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct
{
	int degree;
	float coef;
}TypeMonome;

typedef struct cell
{
	TypeMonome monome;
	struct cell *suivant;
}TypePoly;

//Fonction d'ajout d'un polynome en tête (insertions en tête)
TypePoly *InsereMonomeEnTete(TypePoly *P, TypeMonome m)
{
	TypePoly *q;
	q = (TypePoly*)malloc(sizeof(TypePoly));
	q->monome.degree = m.degree;
	q->monome.coef = m.coef;
	q->suivant = NULL;
	if(P == NULL)
		return q;
	q->suivant = P;
	return q;
}

//Fonction d'ajout d'un polynome en queue (insertions en queue)
TypePoly *InsereMonomeEnQueue(TypePoly *P, TypeMonome m)
{
	TypePoly *q, *p;
	q = (TypePoly*)malloc(sizeof(TypePoly));
	q->monome.degree = m.degree;
	q->monome.coef = m.coef;
	q->suivant = NULL;
	if(P == NULL)
		return q;
	for(p = P; p->suivant != NULL; p = p->suivant);
	p->suivant = q;
	return P;
}

//Additioner deux polynomes
TypePoly *SommePoly(TypePoly *P1, TypePoly *P2)
{
	TypePoly *P = NULL, *p;
	TypeMonome m;
	while(P1 != NULL && P2 != NULL)
	{
		if(P1->monome.degree == P2->monome.degree)
		{
			int coef = P1->monome.coef + P2->monome.coef;
			m.coef = coef; m.degree = P1->monome.degree;
			P = InsereMonomeEnTete(P, m);
			P1 = P1->suivant;
			P2 = P2->suivant;
		}
		else
		{
			if(P1->monome.degree > P2->monome.degree)
			{
				m.coef = P1->monome.coef; m.degree = P1->monome.degree;
				P = InsereMonomeEnQueue(P, m);
				P1 = P1->suivant;
			}
			else
			{
				m.coef = P1->monome.coef; m.degree = P1->monome.degree;
				P = InsereMonomeEnQueue(P, m);
				P2 = P2->suivant;
			}
		}
	}
	if(P1 == NULL || P2 == NULL)
	{
		if(P1 != NULL)
		{
			while(P1 != NULL)
			{
				m.coef = P1->monome.coef; m.degree = P1->monome.degree;
				P = InsereMonomeEnQueue(P, m);
				P1 = P1->suivant;
			}
		}
		else if(P2 != NULL)
		{
			while(P2 != NULL)
			{
				m.coef = P2->monome.coef; m.degree = P2->monome.degree;
				P = InsereMonomeEnQueue(P, m);
				P2 = P2->suivant;
			}
		}
	}
	return P;
}

//Affichage de polynôme
void AffichePolynome(TypePoly *P)
{
	TypePoly *p;
	if(P == NULL)
		printf("P(x) = 0\n");
	else
	{
		int signe = 0;
		printf("P(x) = ");
		for(p = P; p != NULL; p = p->suivant)
		{
			if(signe != 0)
				printf(" + ");
			if(p->monome.degree > 0 || p->monome.degree < 0)
				printf("%fx^%d",p->monome.coef, p->monome.degree);
			else
				printf("%f",p->monome.coef);
			signe++;
		}
	}
}

TypePoly *CreerPolynome(void)
{
	int choix, enc = 1;;
	TypePoly *P = NULL;
	TypeMonome m;
	printf("Coment voulez-vous inserer vos polynome ? \n1.En Tête\n2.En Queue\n");
	scanf("%d",&choix);
	if(choix == 1)
	{
		while(enc == 1)
		{
			printf("Entrer le coefficient puis le degree : \n");
			scanf("%f%d", &m.coef, &m.degree);
			P = InsereMonomeEnTete(P, m);
			printf("Ajouter monome ?\n1.oui\n2.non : ");
			scanf("%d",&enc);
		}
	}
	else if(choix == 2)
	{
		while(enc == 1)
		{
			printf("Entrer le coefficient puis le degree : \n");
			scanf("%f%d", &m.coef, &m.degree);
			P = InsereMonomeEnQueue(P, m);
			printf("Ajouter monome ?\n1.oui\n2.non : ");
			scanf("%d",&enc);
		}
	}
	return P;
}

/* Fonction principale */
int main(int argc, char **argv)
{
	system("clear");
	TypePoly *P1 = NULL, *P2 = NULL, *P = NULL;
	printf("Creation du premier polynome\n");
	P1 = CreerPolynome();
	printf("Creation du deuxieme polynome\n");
	P2 = CreerPolynome();
	P = SommePoly(P1, P2);
	AffichePolynome(P);
	return 0;
}
