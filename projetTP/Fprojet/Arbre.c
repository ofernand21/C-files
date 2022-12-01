//Fonction de arbre Binaire et Graph

//Fonction d'insère en tête
void InsereNoeud(TypeNoeud *racine, TypeDonnee donnee)
{
	if(racine == NULL)
	{
		TypeNoeud *N;
		N = (TypeNoeud*)malloc(sizeof(TypeNoeud));
		N->donnee = donnee;
		N->fg = NULL;
		N->fd = NULL;
		racine = N;
	}
	else
	{
		if(racine->donnee <= donnee)
		{
			TypeNoeud *N;
			N = (TypeNoeud*)malloc(sizeof(TypeNoeud));
			N->donnee = donnee;
			N->fg = NULL;
			N->fd = NULL;
			if(fd == NULL)
			{
				fd = N;
				oui = 1;
			}
			else if(fg == NULL)
			{
				fg = N;
				oui = 1;
			}
		}
		InsereNoeud(fg, donnee);
		InsereNoeud(fd, donnee);
	}
}

//Fonction d'affichage
void AfficheArbre(TypeNoeud *racine)
{
	if(racine != NULL)
	{
		printf("%d", racine->donnee);
		AfficheArbre(fg);
		AfficheArbre(fd);
	}
}

//Fonction de recherche dans un arbre
int Rechercher(TypeNoeud *racine, TypeDonnee donnee)   //retourne 1 en cas de succes et 0 sinon
{
	if(racine != NULL)
	{
		if(racine->donnee == donnee)
			return 1;
		Rechercher(fg, donnee);
		Rechercher(fd, donnee);
	}
}
