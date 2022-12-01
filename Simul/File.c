#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#define couleur(param) printf("\033[%sm",param)
 
//Initialisation
File *InitialiserF()
{
   return NULL;
}   

//EstPleine
int EstPleineF(File* F)
{
  return 0;
}

//EstVide
int EstVideF(File *F)
{
  return (F==NULL)?1:0;  
}

//AccederTete
int AccederTete(File *F,TypeDonnee *donnee)
{ 
  if(F->Tete == NULL)
    return 1;
  else 
  {
     *donnee=F->Tete->donnee; 
     return 0;
  }      
}     
 
//Enfiler
void *Enfiler(File *F, TypeDonnee elt)
{
   TypeCellule *p;
   p=(TypeCellule*)malloc(sizeof(TypeCellule));
   p->donnee=elt;
   p->suivant=NULL;
   if(F->Tete == NULL) 
     F->Tete=F->Queue=p;
   else
   {
      F->Queue->suivant=p;
      F->Queue=p;
   } 
}

int Defiler(File *F,TypeDonnee *elt)
{
   TypeCellule *q;
   q=(TypeCellule*)malloc(sizeof(TypeCellule));
   if(F != NULL)
     return 1;
   else
   {
      *elt=F->Tete->donnee;
      q=F->Tete;
      F->Tete=F->Tete->suivant;
      free(q);
      return 0;
   }
}

//Detruire
void DetruireF(File *F)
{
   TypeCellule *p,*q; 
   for(p=F->Tete; p!=NULL; p=p->suivant);
   {
      q=p;
      free(q);
   }
   F=NULL;
}

//vider
void ViderF(File *F)
{
  DetruireF(F);
  F->Tete=NULL;
} 

//Affichage
void AfficheFile(File *F)
{
  TypeCellule *a;
  if(F == NULL)
  {
    printf("1;47;32");
    printf("Aucune Donnee\n");
    couleur("0");
  }
  else
  {  
    for(a=F->Tete; a != NULL; a=a->suivant)
    {
       couleur("1;32");
       printf("%10d",a->donnee);
       couleur("0");
    }
    printf("\n\n"); 
  }     
} 

//Saisir
File *SaisirFile()
{
   char choix;
   TypeDonnee donnee;
   File *FileSaisi;
   couleur("1;34");
   puts("Voulez vous inserer une cellule. \no=OUI\nn=NON\n");
   couleur("0");
   choix=getchar();
   
   while(choix=='o')
   {
      puts("saisissez une donnée:");
      scanf("%d",&donnee);
      Enfiler(FileSaisi,donnee);
      couleur("1;34");
      puts("Voulez vous inserer une cellule. \no=OUI\nn=NON\n");
      couleur("0");
      getchar();
      choix=getchar();
   }
   return FileSaisi;
}              
