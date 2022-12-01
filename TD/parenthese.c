#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//20.2) Programme qui verifie les parenthèses
typedef struct cell
{
	char donnee;
	struct cell *suivant;
}TypeCellule;

typedef TypeCellule Pile;

Pile *Empiler(Pile *P, char donnee)
{
	Pile *q;
	q = (Pile*)malloc(sizeof(Pile));
	q->donnee = donnee;
	q->suivant = P;
	return q;
}

int Depiler(Pile *P)
{
	if(P == NULL)
		return 1;
	else
	{
		Pile *p;
		p = P;
		P = P->suivant;
		free(p);
		return 0;
	}
}

//Verification du texte # return -1 en cas d'erreur d'ouverture du fichier, 0 si le fichier est bien parenthésé et 1 sinon
int CorrectementParentheser(const char *NomFichier)
{
	Pile *P = NULL;
	FILE *fiche = fopen("NomFichier", "r");
	if(fiche == NULL)
	{
		printf("Erreur d'ouverture du fichier ou de droit insuffisant\n");
		return -1;
	}
	else
	{
		while(!feof(fiche))
		{
			char c;
			c = fgetc(fiche);
			switch(c)
			{
				case '{' :
				{
					P = Empiler(P, c);
					break;
				}
				case '(' :
				{
					P = Empiler(P, c);
					break;
				}
				case '[' :
				{
					P = Empiler(P, c);
					break;
				}
				case '}' :
				{
					if(P == NULL && P->donnee == '{')
						Depiler(P);
					else
					{
						fclose(fiche);
						return 1;
					}
					break;
				}
				case ']' :
				{
					if(P == NULL && P->donnee == '[')
						Depiler(P);
					else
					{
						fclose(fiche);
						return 1;
					}
					break;
				}
				case ')' :
				{
					if(P == NULL && P->donnee == '(')
						Depiler(P);
					else
					{
						fclose(fiche);
						return 1;
					}
					break;
				}
				default:
					break;
			}
		}
		fclose(fiche);
		if(P == NULL)
			return 0;
		else
			return 1;
	}
}


//Le main
int main()
{
	system("clear");
	int oui = CorrectementParentheser("text.txt");
	if(oui == 0)
		printf("Texte bien parenthès\n");
	else if(oui == 1)
		printf("Texte mal parenthès\n");
}
