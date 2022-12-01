#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//Initialiser
Pile *Initialiser()
{
	return NULL;
}

//EstVide
int EstVide(Pile *p)
{
	return (p == NULL) ? 1 : 0;
}

//EstPleine
int EstPleine(Pile *p)
{
	return 0;
}

//AccederSmmet
int AccederSommet(Pile *p,TypeDonnee *elt)
{
	if(p == NULL)
  	     return 1;
	else
	{
		*elt=p->donnee;
		return 0;
	}
}

//Empiler
Pile *Empiler(Pile *P,TypeDonnee elt)
{
	TypeCellule *q;
	q=(TypeCellule*)malloc(sizeof(TypeCellule));
	q->donnee=elt;
	q->suivant=P;
	return q;
}

//DEpiler
int Depiler(Pile *pt,TypeDonnee *elt)
{
	TypeCellule *q;
	if(EstVide(pt)) 
		return 1;
	else
	{
		*elt=pt->donnee;
		q=pt;  
		pt=pt->suivant;
		free(q);
		return 0;
	}
}

//detruire
void Detruire(Pile *p)
{
	TypeCellule *q;
	while(p != NULL)
	{
		q=p;
		p=p->suivant;
		free(q);
	}
	p=NULL;
}       

//vider
void Vider(Pile *P)
{
	Detruire(P);
	P=NULL;
} 
