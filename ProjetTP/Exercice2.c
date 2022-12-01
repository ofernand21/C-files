#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Fprojet/biblioSDD.h"
#include"Fprojet/ListeChainee.c"

TypeCellule *SupprimeOccurence(TypeCellule *L,TypeDonnee donnee)
{
  TypeCellule *p,*s,*q;
  p=L;
  if(p==NULL)
     return L;
  else if(p->donnee == donnee)
  {
     L=L->suivant;
     free(p);
     return L;
  }
  else
  {
     s=p->suivant;
     while(s->suivant != NULL && s->donnee != donnee)
     {
        p=p->suivant;
        s=s->suivant;
     }
     if(s->donnee=donnee)
     {
        q=s;
        p->suivant=s->suivant;
        free(q);
     }
     return L;
  }
}

/*TypeCellule *SupprimeTouteOccurence(TypeCellule *L,TypeDonnee donnee)  
{
   TypeCellule *p,*q,*sup;
   p=L;
   if(p == NULL)
     return L;
   else
   {
      q=p;
      p=p->suivant;
      while(p != NULL)
      {
         if(p->donnee=donnee)
         {
            sup=p;
            p=p->suivant;
            q->suivant=p;
            free(sup);
         }
         q=q->suivant;
         p=p->suivant;
       }
       return L; 
    }
}*/

/*TypeCellule *SupprimeTouteOccurence(TypeCellule *L,TypeDonnee donnee)
{
    TypeCellule *p,*sup;
    p=L;
    if(p->donnee == donnee)
    {
       sup=p;
       p=p->suivant;
       L=p;
       L->suivant=p->suivant;
       return L;
    }
    else
       return SupprimeTouteOccurence(L,donnee);
}*/      

int main()
{
   system("clear");
   TypeDonnee d;
   TypeCellule *L;
   L=SaisirListeEnQueue();
   printf("Voici votre Liste:");
   AfficheListe(L);
   printf("\n\nEntrer la donnée dont vous voulez supprimer l'occurence:");
   scanf("%d",&d);
   L=SupprimeOccurence(L,d);
   //L=SupprimeTouteOccurence(L,d);
   printf("\nAprès suppression voici votre nouvelle liste:\n");
   AfficheListe(L); 
}                         
