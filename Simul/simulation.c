#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"biblioSDD.h"
#include"ListeChainee.c"
#include"Pile.c"
#include"File.c"
#define couleur(param) printf("\033[%sm",param)

int main()
{
   system("clear");
   printf("\tšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļø\n");
   printf("\tšļøšļøšļøšļøšļøšļøšļø  SIMULATION LISTE PILE ET FILE  šļøšļøšļøšļøšļøšļøšļøšļøšļø\n");
   printf("\tšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļø\n");
   printf("\n");
   int choix;
   char valeur[10];
   menu:printf("āļøāļøāļøāļøāļøāļøāļøāļøāļøāļøāļøāļøāļø   MENU PRINCIPAL  āļøāļøāļøāļøāļøāļøāļøāļøāļøāļøāļøāļø\n\n");
  couleur("1;34");
  printf("Veillez faire un choix:");
  couleur("0");
  printf("\n\n1.Liste\n2.Pile\n3.File\n4.Stopper\n\n");
  fgets(valeur,sizeof(valeur),stdin);
  if(sscanf(valeur,"%d",&choix) == 1)
  {
      switch(choix)
      {
         case 1:
         {
            printf("\nš»ļøš»ļøš»ļøš»ļøš»ļøš»ļøš»ļø TRAITEMENT DE LISTE š»ļøš»ļøš»ļøš»ļøš»ļøš»ļø\n\n");
         
            TypeCellule *L=NULL;
            
            int vouloir1;
            debut1:printf("\n1.Creer Liste en Tete\n2.Creer Liste en Queue\n3.Afficher liste\n4.Initialiser\n5.Quitter\n6.Menu principal\n");
            fgets(valeur,sizeof(valeur),stdin);
            sscanf(valeur,"%d",&vouloir1);
            switch(vouloir1)
            {
               case 1:
               {
                  L=SaisirListeEnTete();
                  ViderBuffer();
                  goto debut1;
               }break;
               case 2:
               {
                  L=SaisirListeEnQueue();
                  ViderBuffer();
                  goto debut1;
               }break;
               case 3:
               {
                  AfficheListe(L);
                  goto debut1;
               }break;
               case 4:
               {
                  L=NULL;
                  goto debut1;
               }break;
               case 5:
               {
                  goto fin; 
               }break;
               case 6:
               {
                  goto menu;
               }break;
               default:
               {
                  couleur("1;43;31;5");
                  printf("Choix invalide veillez choisir Ć  nouveau:");
                  couleur("0");
                  printf("\n\n");
                  goto debut1;
               }break;
            }
            
         } break;
         case 2:
         {
            printf("\nš»ļøš»ļøš»ļøš»ļøš»ļøš»ļøš»ļø TRAITEMENT DE PILE š»ļøš»ļøš»ļøš»ļøš»ļøš»ļø\n\n");
            
            Pile *L=NULL;
            
            int vouloir2;
            debut2:printf("\n1.Creer Pile\n2.Afficher Pile\n3.Initialiser\n4.Quitter\n5.Menu principal\n");
            fgets(valeur,sizeof(valeur),stdin);
            sscanf(valeur,"%d",&vouloir2);
            switch(vouloir2)
            {
               case 1:
               {
                  L=SaisirPile();
                  ViderBuffer();
                  goto debut2;
               }break;
               case 2:
               {
                  AffichePile(L);
                  goto debut2;
               }break;
               case 3:
               {
                  L=Initialiser();
                  goto debut2;
               }break;
               case 4:
               {
                  goto fin;
               }break;
               case 5:
               {
                  goto menu;
               }break;
               default:
               {
                  couleur("1;43;31;5");
                  printf("Choix invalide veillez choisir Ć  nouveau:");
                  couleur("0");
                  printf("\n\n");
                  goto debut2;
               } 
            }
               
         }break;
         case 3:
         {
            printf("\nš»ļøš»ļøš»ļøš»ļøš»ļøš»ļøš»ļø TRAITEMENT DE FILE š»ļøš»ļøš»ļøš»ļøš»ļøš»ļø\n\n");
         
            File *L=NULL;
            
            int vouloir3;
            debut3:printf("\n1.Saisir File\n2.Afficher File\n4.Quitter\n5.Menu principal\n");
            fgets(valeur,sizeof(valeur),stdin);
            sscanf(valeur,"%d",&vouloir3);
            switch(vouloir3)
            {
               case 1:
               {
                  L=SaisirFile();
                  ViderBuffer();
                  goto debut3;
               }break;
               case 2:
               {
                  AfficheFile(L);
                  goto debut3;
               }break;
               case 3:
               {
                  L=InitialiserF();
                  goto debut3;
               }break;
               case 4:
               {
                  goto fin;
               }break;
               case 5:
               {
                  goto menu;
               }break;
               default:
               {
                  couleur("1;43;31;5");
                  printf("Choix invalide veillez choisir Ć  nouveau:");
                  couleur("0");
                  printf("\n\n");
                  goto debut3;
               }break;
            }
         }break;
         case 4:
            goto fin; break;
         default:
         {
            couleur("1;43;31;5");
            printf("Choix invalide veillez choisir Ć  nouveau:");
            couleur("0");
            printf("\n\n");
            goto menu;
         }break;
      }
    }
   else
   {
      couleur("1;43;31;5");
      printf("Erreur de saisi, faite un nouveau choix");
      couleur("0");
      printf("\n\n");
      goto menu;
   }
   fin:printf("\n\n");
   couleur("1;47;32");
  printf("\tā¤ļøā¤ļøā¤ļøā¤ļøā¤ļøā¤ļø Merci pour l'utilisation au revoir šļø šļø šļø ā¤ļøā¤ļøā¤ļøā¤ļø");
  couleur("O");
  printf("\n\n");
     printf("šļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļøšļø");
  
  printf("\n\n");
}
