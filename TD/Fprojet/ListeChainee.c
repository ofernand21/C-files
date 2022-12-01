#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define couleur(param) printf("\033[%sm",param)


//Fonction se saisi
void  ViderBuffer() // PERMET DE VIDER LE BUFFER EN CAS DE DEPASSEMENT DE MEMOIRE
{
	long c;
	while (c != '\n' && c != EOF) c = getchar();
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
long Lecture() // RETOURNE -1 EN CAS D'ERREUR SINON LA VALEUR ENTIERE POSITIVE
{
	char Chaine[100];
	unsigned long Longueur, Valeur=0,i;
	
	fgets(Chaine,sizeof(Chaine),stdin); // PERMET D'ENTRER UNE CHAINE DE CARACTERE
	Longueur=strlen(Chaine); // PERMET DE DONNER LA LONGUEUR D'UNE CHAINE DE CARACTERE

	for (i=0;i<Longueur-1;i++)
	{
        // RESULTAT PREND -1 SI LE CARACTERE N'EST PAS UN CHIFFRE
		if (!isdigit(Chaine[i]))
		{
			Valeur=-1;
			break;
		}
	}

    //  CONVERTIR LE CARACTERE EN LONG S'IL EST UN NOMBRE
	if(Valeur!=-1)
	{
		Valeur=(long)strtol(Chaine, NULL,10); // PERMET DE CONVERTIR LA CHAINE DE CARACTERE EN  UN ENTIER
	}

	return Valeur;
}
 
//Insere en tete de liste
TypeCellule *InsereEnTete(TypeCellule *ancienL, TypeDonnee donnee)
{
	TypeCellule *NouveauL;
	NouveauL=(TypeCellule*)malloc(sizeof(TypeCellule));
	NouveauL->donnee=donnee;
	NouveauL->suivant=ancienL;
	return NouveauL;
}

//Insere en queue de liste
TypeCellule *InsereEnQueue(TypeCellule *ancienL, TypeDonnee donnee)
{
	TypeCellule *NouveauL,*p;
	NouveauL=(TypeCellule*)malloc(sizeof(TypeCellule));
	NouveauL->donnee=donnee;
	NouveauL->suivant=NULL;
   
	if(ancienL == NULL)
		ancienL=NouveauL;
	else
	{
		for(p=ancienL; p->suivant != NULL; p=p->suivant);
		p->suivant = NouveauL;
	}
	return ancienL;
}

//Affichage de liste
void AfficheListe(TypeCellule *L)
{
	TypeCellule *p ;
	if(L == NULL)
	{
		couleur("1;32");
		printf("La liste est vide");
		couleur("0");
	}
	for(p=L; p != NULL; p=p->suivant)
	{
		couleur("1;32");
		printf("%10d",p->donnee);
		couleur("0");
	}
	printf("\n\n");
}

TypeCellule *SaisirListeEnTete()
{
	char choix;
	TypeDonnee donnee;
	TypeCellule *ListeSaisi=NULL;
	couleur("1;34");
	puts("Voulez vous inserer une cellule. \no=OUI\nn=NON:");
	couleur("0");
	getchar();
	choix=getchar();
	//choix=toupper(choix);
   
	while(choix=='o')
	{
		puts("saisissez une donnée:");
		scanf("%d",&donnee);
		ListeSaisi=InsereEnTete(ListeSaisi,donnee);
		couleur("1;34");
		puts("Voulez vous inserer une cellule. \no=OUI\nn=NON : ");
		//couleur("0");
		getchar();
		choix=getchar();
		couleur("0");
		//choix=toupper(choix);
	}
	return ListeSaisi;
}

TypeCellule *SaisirListeEnQueue()
{
	char choix;
	TypeDonnee donnee;
	TypeCellule *ListeSaisi=NULL;
	couleur("1;34");
	puts("Voulez vous inserer une cellule. \no=OUI\nn=NON:");
	couleur("0");
	getchar();
	choix=getchar();
	//choix=toupper(choix);
   
	while(choix=='o')
	{
		puts("saisissez une donnée:");
      scanf("%d",&donnee);
      ListeSaisi=InsereEnQueue(ListeSaisi,donnee);
      couleur("1;34");
      puts("Voulez vous inserer une cellule. \no=OUI\nn=NON\n");
      couleur("0");
      getchar();
      choix=getchar();
      //choix=toupper(choix);
   }
   return ListeSaisi;
}             
