#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define couleur(param) printf("\033[%sm",param)
#include"biblioSDD.h"
#include"Pile.c"
#include"File.c"
#include"ListeChainee.c"

int main()
{
  printf("\033[H\033[2J");
  char valeur[1000];
  int choix;
  printf("\n");
  printf("\t🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️\n");
  printf("\t🌍️🌍️🌍️🌍️🌍️🌍️🌍️  TRAITEMENT DE LISTE PILE ET FILE   🌍️🌍️🌍️🌍️🌍️🌍️🌍️\n");
  printf("\t🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️🌍️\n\n\n");
  debut:
  printf("Ⓜ️Ⓜ️Ⓜ️Ⓜ️Ⓜ️Ⓜ️Ⓜ️Ⓜ️Ⓜ️Ⓜ️Ⓜ️Ⓜ️Ⓜ️   MENU PRINCIPAL  Ⓜ️Ⓜ️Ⓜ️Ⓜ️Ⓜ️Ⓜ️Ⓜ️Ⓜ️Ⓜ️Ⓜ️Ⓜ️Ⓜ️\n\n");
  couleur("1;34");
  printf("Veillez faire un choix:");
  couleur("0");
  printf("\n\n1.Liste\n2.Pile\n3.File\n4.Stopper\n");
  //fgets(valeur,sizeof valeur,stdin);
  choix=Lecture();
  if(choix<4 || choix>0)
  {
    switch(choix)
    {
     case 1:
     {
        printf("\033[H\033[2J");
        printf("💻️💻️💻️💻️💻️💻️💻️ TRAITEMENT DE LISTE 💻️💻️💻️💻️💻️💻️\n\n");
        int vouloir1;
        TypeCellule *L;
        printf("Que voulez-vous faire de votre liste ?\n\n");
        debut1: printf("\n1.InsereEntete\n2.InsereEnqueue\n3.AfficheListe\n4.Creer Liste en Tete\n5.Creer Liste en queue\n6.Sortir\n7.Aller au menu principal\n\n");
        //fgets(valeur,sizeof valeur,stdin);
        vouloir1=Lecture();
        if(vouloir1<8 || vouloir1>0)
        {
           switch(vouloir1)
           {
             case 1:
             {
                TypeDonnee d;
                printf("Entrer la donnee a inserer en tete de liste:");
                fgets(valeur,sizeof valeur,stdin);
                sscanf(valeur,"%d",&d);
                L=InsereEnTete(L,d);
                couleur("1;47;32"); 
                printf("\nVous avez inserer %d dans la liste avec succes",d);
                couleur("0");
                printf("\n\n");
                goto debut1;
             };break;
             case 2:
             {
                TypeDonnee d;
                printf("Entrer la donnee a inserer en queue de liste:");
                fgets(valeur,sizeof valeur,stdin);
                sscanf(valeur,"%d",&d);
                L=InsereEnQueue(L,d);
                couleur("1;47;32"); 
                printf("\nVous avez inserer %d dans la liste avec succes",d);
                couleur("0");
                printf("\n\n");
                goto debut1;
             };break;
             case 3:
             {
                AfficheListe(L);
                goto debut1;
             };break;
             case 4:
             {
                L=SaisirListeEnTete();
                ViderBuffer();
                printf("\033[H\033[2J");
                goto debut1;
             }break;
             case 5:
             {
                L=SaisirListeEnQueue();
                ViderBuffer();
                printf("\033[H\033[2J");
                goto debut1;
             }break;
             case 6:
             {
                printf("\033[H\033[2J");
                printf("\n\n");
                goto fin;
             };break;
             case 7:
             {
                printf("\033[H\033[2J");
                goto debut;
             };break; 
          }
        }
        else
        {
            printf("\033[H\033[2J");
            couleur("1;43;31;5");
            printf("Choix erronee⛔️");
            couleur("0");
            printf("\nFaite autre choix\n\n");
            goto debut;
        }
     };break;           
     case 2:
     {
       printf("\033[H\033[2J");
       int vouloir2;
       Pile *P=NULL;
       printf("\n💻️💻️💻️💻️💻️💻️💻️ TRAITEMENT DE PILE 💻️💻️💻️💻️💻️💻️\n\n");
       printf("Que voulez-vous faire ?\n\n");
       debut2:printf("\n1.Initialiser\n2.Verifier si la pile est vide\n3.Verifier si la pile est pleine\n4.Acceder Au sommet de la pile\n5.Empiler\n6.Depiler\n7.Detruire la pile\n8.Vider la pile\n9.Fermer\n10.Aller au menu principal\n\n");
       vouloir2=Lecture();
       if(vouloir2<11 || vouloir2>0)
       {
         switch(vouloir2)
         {
            case 1:
            {
               printf("\033[H\033[2J");
               P=Initialiser();
               couleur("1;47;32");
               printf("La pile a été initialiser");
               couleur("0");
               printf("\n\n");
               goto debut2;
            };break;
            case 2:
            { 
                printf("\033[H\033[2J");
                if(EstVide(P) == 1)
                {
                   couleur("1;47;32");
                   printf("La pile est bien vide");
                   couleur("0");
                   printf("\n\n");
                }
                else
                {
                   couleur("1;47;32");
                   printf("La pile n'est pas vide");
                   couleur("0");
                   printf("\n\n");
                }
                goto debut2;
            };break;
            case 3:
            {
               printf("\033[H\033[2J");
               if(EstPleine(P)==1)
               {
                  couleur("1;47;32");
                  printf("La pile est Pleine");
                  couleur("0");
                  printf("\n\n");
               }
               else
               {
                  couleur("1;47;32");
                  printf("La pile n'est pas pleine");
                  couleur("0");
                  printf("\n\n");
               }
               goto debut2;
            };break;
            case 4:
            {
               printf("\033[H\033[2J");
               TypeDonnee *donnee;
               if(AccederSommet(P,donnee) == 0)
               {
                 couleur("1;47;32");
                 printf("La donnee de la pile a été recuperer est %d",*donnee);
                 couleur("0");
                 printf("\n\n");
               }
               else
               {
                 couleur("1;47;32");
                 printf("La pile contient rien");
                 couleur("0");
                 printf("\n\n");
               }
               goto debut2;
            };break;
            case 5:
            {
               printf("\033[H\033[2J");
               TypeDonnee d;
               printf("Entrer l'element a empiler\n");
               fgets(valeur,sizeof(valeur),stdin);
               sscanf(valeur,"%d",&d);
               printf("\n");
               P = Empiler(P,d);
               couleur("1;47;32");
               printf("%d a été ajouter avec succes",d);
               couleur("0");
               printf("\n\n");
               goto debut2;
            };break;
            case 6:
            {
               printf("\033[H\033[2J");
               TypeDonnee *elt;
               if(Depiler(P,elt) == 0)
               {
                 couleur("1;47;32");
                 printf("La Pile a été depiler avec succes 😊️");
                 couleur("0");
                 printf("\n\n");
               }
               else
               {
                 couleur("1;47;32");
                 printf("La pile est vide");
                 couleur("0");
                 printf("\n\n");
               }
               goto debut2;
            };break;
            case 7:
            {
               printf("\033[H\033[2J");
               Detruire(P);
               couleur("1;47;32");
               printf("La pile est detruite avec succes 😊️");
               couleur("0");
               printf("\n\n");
               goto debut2;
            };break;
            case 8:
            {
               printf("\033[H\033[2J");
               Vider(P);
               couleur("1;47;32");
               printf("La pile est vider avec succes 😊️");
               couleur("0");
               printf("\n\n");
               goto debut2;
            };break;
            case 9:
            {
               printf("\033[H\033[2J");
               printf("\n\n");
               goto fin;
            };break;
            case 10:
            { 
               printf("\033[H\033[2J");
               goto debut;
            };break;
         }
       }
       else
       {
            printf("\033[H\033[2J");
            couleur("1;43;31;5");
            printf("Choix erronee⛔️");
            couleur("0");
            printf("\nFaite autre choix\n\n");
            goto debut2;
       }
     };break;
     case 3:
     {
       printf("\033[H\033[2J"); 
       int vouloir3;
       File F;
       printf("\n💻️💻️💻️💻️💻️💻️💻️ TRAITEMENT DE FILE 💻️💻️💻️💻️💻️💻️\n\n");
       printf("Que voulez-vous faire ?\n\n");
       debut3:printf("\n1.Initialiser\n2.Verifier si la file est vide\n3.Verifier si la file est pleine\n4.Acceder Au tete de la file\n5.Emfiler\n6.Defiler\n7.Detruire la file\n8.Vider la file\n9.Fermer\n10.Aller au menu principal\n\n");
       //fgets(valeur,sizeof valeur,stdin);
       vouloir3=Lecture();
       if(vouloir3<11 || vouloir3>0)
       {
         switch(vouloir3)
         {
            case 1:
            {
               printf("\033[H\033[2J");
               InitialiserF(F);
               couleur("1;47;32");
               printf("La file a été initialiser avec sucess 😊️");
               couleur("0");
               printf("\n\n");
               goto debut3;
            };break;
            case 2:
            {
                printf("\033[H\033[2J");
                if(EstVideF(F))
                {
                   couleur("1;47;32");
                   printf("La file est bien vide");
                   couleur("0");
                   printf("\n\n");
                }
                else
                {
                   couleur("1;47;32");
                   printf("La file n'est pas vide");
                   couleur("0");
                   printf("\n\n");
                }
                goto debut3;
            };break;
            case 3:
            {
               printf("\033[H\033[2J");
               if(EstPleineF(F) == 1)
               {
                  couleur("1;47;32");
                  printf("La file est Pleine");
                  couleur("0");
                  printf("\n\n");
               }
               else
               {
                  couleur("1;47;32");
                  printf("La file n'est pas pleine");
                  couleur("0");
                  printf("\n\n"); 
               }
               goto debut3;
            };break;
            case 4:
            {
               printf("\033[H\033[2J");
               TypeDonnee *elt;
               if(AccederTete(F,elt) == 0)
               {
                  couleur("1;47;32");
                  printf("Nous avons la donnee et elle est %d",*elt);
                  couleur("0");
                  printf("\n\n");
               }
               else
               {
                  couleur("1;47;32");
                  printf("La file est vide");
                  couleur("0");
                  printf("\n\n"); 
               }   
               goto debut3;
            };break;
            case 5:
            {
               printf("\033[H\033[2J");
               TypeDonnee d;
               printf("Entrer l'element a emfiler\n\n");
               fgets(valeur,sizeof(valeur),stdin);
               sscanf(valeur,"%d",&d);
               F = Enfiler(F,d);
               couleur("1;47;32");
               printf("%d a été ajouter avec succes",d);
               couleur("0");
               printf("\n\n");
               goto debut3;
            };break;
            case 6:
            {
               printf("\033[H\033[2J");
               TypeDonnee *elt;
               if(Defiler(F,elt) == EXIT_SUCCESS)
               {
                 printf("La File a été defiler avec succes");
                 couleur("0");
                 printf("\n\n");
               }
               else
               {
                 couleur("1;47;32");
                 printf("La file est vide");
                 couleur("0");
                 printf("\n\n");
               }
               goto debut3;
            };break;
            case 7:
            {
               printf("\033[H\033[2J");
               DetruireF(F);
               couleur("1;47;32");
               printf("La file est detruite avec succes");
               couleur("0");
               printf("\n\n");
               goto debut3;
            };break;
            case 8:
            {
               printf("\033[H\033[2J");
               ViderF(F);
               couleur("1;47;32");
               printf("La file est vider avec succes");
               couleur("0");
               printf("\n\n");
               goto debut3;
            };break;
            case 9:
            {
               printf("\033[H\033[2J");
               printf("\n\n");
               goto fin;
            };break;
            case 10:
            {
               printf("\033[H\033[2J");
               goto debut;
            };break;
         }
       }
       else
       {
            printf("\033[H\033[2J");
            couleur("1;43;31;5");
            printf("Choix erronee⛔️");
            couleur("0");
            printf("\nFaite autre choix\n\n");
            goto debut3;
       }
    };break;
    case 4:
    {
       printf("\033[H\033[2J");
       printf("\n\n");
       goto fin;
    }break;
  }
 } 
 else
  {
      printf("\033[H\033[2J");
      couleur("1;43;31;5");
      printf("Choix invalide veillez choisir une option");
      couleur("0");       
      printf("\n\n");
      goto debut; 
  }
  fin:printf("\n\n");
  couleur("1;47;32");
  printf("\t❤️❤️❤️❤️❤️❤️ Merci pour l'utilisation au revoir 👍️ 👋️ 👋️ ❤️❤️❤️❤️");
  couleur("O");
  printf("\n\n");
printf("🔚️🔚️🔚️🔚️🔚️🔚️🔚️🔚️🔚️🔚️🔚️🔚️🔚️🔚️🔚️🔚️🔚️🔚️🔚️🔚️🔚️🔚️🔚️🔚️🔚️🔚️🔚️🔚️🔚️🔚️🔚️🔚️🔚️🔚️🔚️🔚️🔚️🔚️🔚️🔚️🔚️🔚️🔚️🔚️🔚️");
  
  printf("\n\n");
}
