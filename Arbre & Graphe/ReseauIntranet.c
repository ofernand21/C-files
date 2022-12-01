//Exercice 24.1 du cours dunond sur les graphes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*structure pour représenté un réseau intranet en mémoire*/
typedef struct
{
  /* les somme* correspond à la localisation géographique */
  char *local;
}Sommet;

typedef struct {
  /* structure connexion */
  int noeud1;
  int noeud2;
}TypeConnexion;

typedef struct {
  /* structure du resau */
  int n; // nombre de localité
  int m; // nobre de connexion
  Sommet *nom; // Nom des localité
  TypeConnexion *connexion; //tableau de connexion
}TypeReseau;

/* Fonction qui charge le reseau en mémoire, sachant que les données sont dans un fichier */
TypeReseau Chargement(char *NomFichier)
{
  TypeReseau reseau;
  char tmp[100];
  FILE *fp = NULL;
  fp = fopen(NomFichier, "r");
  if(fp == NULL)
    fprintf(stderr, "Erreur d'ouverture du fichier\n");
  else
  {
    fscanf(fp, "%d", &reseau.n);
    reseau.nom = (Sommet*)malloc(reseau.n*sizeof(Sommet));
    fscanf(fp, "%d", &reseau.m);
    reseau.connexion = (TypeConnexion*)malloc(reseau.m*sizeof(TypeConnexion));
    for (int i = 0; i < reseau.n; i++) {
      /* Recuperation des Noms */
      fscanf(fp, "%s", tmp);
      reseau.nom[i].local = (char*)malloc((strlen(tmp)+1)*sizeof(char));
      strcpy(reseau.nom[i].local, tmp);
    }

    for (int i = 0; i < reseau.m; i++) {
      /* Recuperation des connexion */
      fscanf(fp, "%d %d", &reseau.connexion[i].noeud1, &reseau.connexion[i].noeud2);
    }
  }
  fclose(fp);
  return reseau;
}


/* Fonction de sauvegarde su reseau en memoire */
void Sauvegarde(TypeReseau reseau, const char *MonFichier)
{
  FILE *fp = NULL;
  fp = fopen(MonFichier, "w");
  if(fp == NULL)
    fprintf(stderr, "Erreur d'ouverture du fichier\n");
  else
  {
    fprintf(fp, "%d\n", reseau.n);
    fprintf(fp, "%d\n", reseau.m);
    for (int i = 0; i < reseau.n; i++) {
      /* copie des noms en memoire */
      fprintf(fp, "%s\n", reseau.nom[i].local);
    }
    for (int i = 0; i < reseau.m; i++) {
      /* copie des connexion en mémoire */
      fprintf(fp, "%d %d\n", reseau.connexion[i].noeud2, reseau.connexion[i].noeud2);
    }
  }
  fclose(fp);
}


/* Fonction qui détermine si deux machines données sont connectées par un câble. */
int EStConnecte(int machine1, int machine2, TypeReseau reseau)
{
  /* La fonction retourne 1 si les deux machines sont connecté et 0 sinon */
  int oui = 0;
  for (int i = 0; i < reseau.m; i++) {
    /* Recherche si on a les 2 machines connecté */
    if(reseau.connexion[i].noeud1 == machine1 && reseau.connexion[i].noeud2 == machine2)
    {
      oui = 1; break;
    }
  }
  return oui;
}

/* Un chemin dans ce reseau est un suite de localité dont la localité précédente est connecté à la suite */

/* fonction qui prend en paramètre un tableau de numéros de noeuds du réseau et
qui détermine si chaque noeud du tableau est connecté au suivant par un câble.*/
int EstInterconnecte(TypeReseau reseau, int tableau[], int n)
{
  /* La fonction retu 1 si les éléments du tableau sont connecté et 0 sinon */
  int i = 0, oui = 1;
  while(i < n-1)
  {
    if(EStConnecte(tableau[i], tableau[i+1], reseau))
      i += 2;
    else
    {
      oui = 0; break;
    }
  }
  return oui;
}


/* Fonction principale */
int main(int argc, char const *argv[]) {
  system("clear"); // Effacer le shell
  /* Test des fonctions du reseau */
  TypeReseau reseau;
  int option;
  /* chargement du reseau */
  reseau = Chargement("reseau.txt");
  printf("Que voulez-Afficher ?\n1.Le nombre de localité\n2.Les localités\n3.Le nombre de connexion\n4.Les connexions\n");
  scanf("%d",&option);
  if(option == 1)
    printf("\nLe nombre de localité sur ce réseau est: %d\n\n", reseau.n);
  else if(option == 2)
  {
    for (int i = 0; i < reseau.n; i++) {
      /* code */
      printf("%s\n",reseau.nom[i].local);
    }
  }
  else if(option == 3)
    printf("\nLe nombre de connexion sur ce réseau est: %d\n\n", reseau.m);
  else if(option == 4)
  {
    for (int i = 0; i < reseau.m; i++) {
      /* code */
      printf("\nLe noeud %d et le noeud %d sont connectés\n\n",reseau.connexion[i].noeud1, reseau.connexion[i].noeud2);
    }
  }
  printf("Voulez-vous sauvegarde ce reseau ? : ");
  scanf("%d", &option);
  if(option == 1)
  {
    Sauvegarde(reseau,"save.txt");
    printf("\nSauvegarde reuissi au revoir\n");
  }
  else
    printf("Au revoir\n");
  return 0;
}
