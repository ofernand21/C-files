int main()
{
  	int n1, n2, *n, *tab;
  	printf("entrer la taille du 1er tableau:");
  	scanf("%d",&n1);
  	int tab1[n1];
  	for(int i=0; i<n1; i++)
  	{
		printf("tab[%d]=",i);
		scanf("%d",&tab1[i]);
  	}
	/*printf("entrer la taille du 2e tableau:");
  	scanf("%d",&n2);
  	int tab2[n2];
  	for(int i=0; i<n2; i++)
  	{
    		printf("tab[%d]=",i);
    		scanf("%d",&tab2[i]);
  	}*/
  	printf("Le trableau trier est:\n");
  	tab = TriInterclassementTab(tab1, n1);
  	for(int i=0; i<*n; i++)
  		printf("%d\t",tab[i]);
}

int main(char argc, int argv[])
{
	system("clear");
	TypeCellule *L1 = NULL, *L2 = NULL, *L = NULL;
	int somme,choix;
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
	printf("voici les deux nouvelles listes : \n");
	PairsImpairs(L, &L1, &L2);
	AfficheListe(L1);
	AfficheListe(L2);
}
