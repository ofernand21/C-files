/* Reponses au question 
1) On gerera les tâches avec les piles */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define couleur(param) printf("\033[%sm",param)

typedef struct
{
   int numero, priorite;
}Tache;

typedef struct cell
{
   Tache tache;
   struct cell *suivant;
}TypeTache;

typedef TypeTache Pile;

void Empiler(Pile *P,Tache t)
{
   TypeTache *T;
   T=(TypeTache*)malloc(sizeof(TypeTache));
   T->tache.numero=t.numero;
   T->tache.priorite=t.priorite;
   T->suivant=P;
   P=T;
}

int Depiler(Pile *P, Tache *t)
{
   TypeTache *q;
   if(P == NULL)
      return 1;
   t->numero=P->tache.numero;
   t->priorite=P->tache.priorite;
   q=P;
   free(q);
   return 0;
}

Pile *SaisirTache()
{
   Pile *P;
   Tache tache;
   int i,n;
   printf("Entrer le nombre de tâche:");
   scanf("%d",&n);
   printf("\nEntrer les priorités de façon croissante\n\n");
   for(i=1; i<=n; i++)
   {
      int d;
      printf("Entrer la priorité de la tâche %d:",i);
      scanf("%d",&d);
      tache.priorite=d;
      tache.numero=i;
      Empiler(P,tache);
   }
   return P;
}

void TraitementTache(Pile *P)
{
   TypeTache *p;
   if(P == NULL)
      printf("Aucune Tâche\n");
   else
   {
      for(p=P; p!=NULL; p=p->suivant)
         printf("Tâche N°%d, priorité %d\n",p->tache.numero,p->tache.priorite);
   }
}

int main()
{
    system("clear");
    Pile *P;
    P=SaisirTache();
    TraitementTache(P);
}
