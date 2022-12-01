#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct
{
	int degree;
	float coef;
}Poly;

typedef struct cell
{
	Poly monome;
	struct cell *suivant;
}TypeCellule;

typedef TypeCellule *TypePolynome;

Poly SaisirMonome(void) //Fonctionn de saisi d'un monome
{
	Poly m;
	printf("Entrer le coefficient du monome:");
	scanf("%f", &m.coef);
	printf("Entrer le degree du monome: ");
	scanf("%d",&m.degree);
	return m;
}

TypePolynome InsereMonome(TypePolynome P, Poly m)
{
        TypeCellule *q,*b, *q2;
        q = (TypeCellule*)malloc(sizeof(TypeCellule));
        q->monome.coef = m.coef;
        q->monome.degree = m.degree;
        if(P == NULL)
        {
                q->suivant = NULL;
                P = q;
        }
        else if(P->suivant == NULL)
        {
                if(m.degree > P->monome.degree)  
                {
                        q->suivant = P;
                        P = q;
                }
                else if(m.degree < P->monome.degree)  
                {
                        q->suivant = NULL;
                        P->suivant = q;
                }
                else if(m.degree == P->monome.degree)
                	P->monome.coef += m.coef;
	}
	else if(P != NULL && P->suivant != NULL)
	{
		for(b = P; b->suivant != NULL && b->suivant->monome.degree > m.degree; b = b->suivant); 
		if(b->suivant->monome.degree == m.degree)
		{
			b = b->suivant;
			b->monome.coef += m.coef;
		}
		else if(b->suivant->monome.degree < m.degree)
		{
			q2 = b->suivant;
			q->suivant = q2;
			b->suivant = q;
		}
		else if(b->suivant == NULL)
		{
			q->suivant = NULL;
			b->suivant = q;
		}
        }
        return P;
}

//Affichage de polynôme
void AffichePolynome(TypePolynome P)
{
	TypePolynome p;
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
		printf("\n");
	}
}

//Fonction qui creer et renvoi la somme de deux polynome
TypePolynome CreerSomme(void)
{
        TypePolynome P1= NULL, P2 = NULL,P, b;
        Poly m;
        int oui = 1;
        printf("Creation du premier polynome\n");
        while(oui == 1)
        {
                m = SaisirMonome();
                P1 = InsereMonome(P1,m); 
                printf("Ajoutez un Monome ?\n");
                printf("1.OUI\n2.NON\n");
                scanf("%d",&oui);
        }
        printf("\nVoici le polynome:\n");
        AffichePolynome(P1);
        oui = 1;
        printf("Creation du deuxième polynome\n");
        while(oui == 1)
        {
                m = SaisirMonome();
                P2 = InsereMonome(P2,m); 
                printf("Ajoutez un Monome ?\n");
                printf("1.OUI\n2.NON\n");
                scanf("%d",&oui);
        }
        printf("\nVoici le polynome:\n");
        AffichePolynome(P2);
        P = P1;
        for(b = P2; b != NULL; b = b->suivant)
                P = InsereMonome(P, b->monome);
                // La fontion fera la somme des deux polynôme
        return P;
}

// Fonction qui creer et renvoi le polynôme derivé
TypePolynome CreerDerive(void)
{
        TypePolynome P = NULL, b;
        Poly m;
        int oui = 1;
        printf("Creation du polynome\n");
        while(oui == 1)
        {
                m = SaisirMonome();
                P = InsereMonome(P,m);
                printf("Ajoutez un Monome ?\n");
                printf("1.OUI\n2.NON\n");
                scanf("%d",&oui);
        }
        printf("\nVoici le polynome:\n");
        AffichePolynome(P);
        // Gestion de la derivé
        for(b = P; b != NULL; b = b->suivant)
        {
                b->monome.coef *= b->monome.degree;
                b->monome.degree--;
        }
        return P;
}



/* Fonction principale */
int main(int argc, char **argv)
{
	system("clear");
	int choix;
	TypePolynome  P = NULL; 
	printf("#################  TRAITEMENT POLYNOME ################\n\n");
	printf("###### MENU ######\n");
	printf("1.Somme de deux polynomes\n2.Dérivé d'un polynôme\n");
	scanf("%d",&choix);
	if(choix == 1)
	{
	        P = CreerSomme();
	        printf("Voici la somme des deux polynome:\n");
	        AffichePolynome(P);
        }
       else if(choix == 2)
       {
                P = CreerDerive();
                printf("Voici la dérivé du polynome:\n");
	        AffichePolynome(P);
        }
	return 0;
}
