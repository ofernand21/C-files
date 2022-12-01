#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define couleur(param) printf("\033[%sm",param)

//vider le buffer
char c;
void ViderBuffer()
{
   while(c != '\n' && c != EOF)
      c=getchar();
}

//Lire une valeur
long Lecture()
{
   char chaine[100];
   unsigned long longeur,valeur=1,i;
   fgets(chaine,sizeof(chaine),stdin);
   longeur=strlen(chaine);
   for(i=0; i<longeur-1; i++)
   {
      if(!isdigit(chaine[i]))
      {
         valeur=0;
         break;
      }
   }
   if(valeur=0)
   {
      valeur=(long)strtol(chaine,NULL,10);
   }
   return valeur;
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
   choix=getchar();
   //choix=toupper(choix);
   
   while(choix=='o')
   {
      puts("saisissez une donnée:");
      scanf("%d",&donnee);
      ListeSaisi=InsereEnTete(ListeSaisi,donnee);
      couleur("1;34");
      puts("Voulez vous inserer une cellule. \no=OUI\nn=NON\n");
      couleur("0");
      getchar();
      choix=getchar();
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
