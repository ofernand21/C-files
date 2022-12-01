#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define couleur(param) printf("\033[%sm",param)


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
     *elt=p->Tete->donnee;
     return 0;
   }
}

//Empiler
void *Empiler(Pile *pt,TypeDonnee elt)
{
  TypeCellule *q;
  q=(TypeCellule*)malloc(sizeof(TypeCellule));
  q->donnee=elt;
  q->suivant=pt->Tete;
  pt->Tete=q; 
}

//DEpiler
int Depiler(Pile *pt,TypeDonnee *elt)
{
   TypeCellule *q;
   if(EstVide(pt)) 
     return 1;
   else
   {
     *elt=pt->Tete->donnee;
     q=pt->Tete;  
     pt->Tete=pt->Tete->suivant;
     free(q);
     return 0;
   }
}

//detruire
void Detruire(Pile *p)
{
  TypeCellule *a,*q;
  for(a=p->Tete; a != NULL; a=a->suivant)
  {
     q=a;
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

//Affichage
void AffichePile(Pile *p)
{
  TypeCellule *a;
  if(p == NULL)
     printf("Aucune Donnee\n");
  else
  {    
     for(a=p->Tete; a != NULL; a=a->suivant)
     {
        couleur("1;32");
        printf("%10d",a->donnee);
        couleur("0");
     }
     printf("\n\n");
  }       
}

//Saisir Pile
Pile *SaisirPile()
{
   char choix;
   TypeDonnee donnee;
   Pile *FileSaisi;
   couleur("1;34");
   puts("Voulez vous inserer une cellule. \no=OUI\nn=NON\n");
   couleur("0");
   choix=getchar();
   
   while(choix=='o')
   {
      puts("saisissez une donnée:");
      scanf("%d",&donnee);
      Empiler(FileSaisi,donnee);
      couleur("1;34");
      puts("Voulez vous inserer une cellule. \no=OUI\nn=NON\n");
      couleur("0");
      getchar();
      choix=getchar();
   }
   return FileSaisi;
}
