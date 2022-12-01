/* Fonction qui prend en paramètre un graphe donné sous forme de matrice
d’adjacence, et qui renvoie 1 si le graphe est non orienté, et 0 sinon. */

/* Les structures */
typedef struct
{
  int numero;
}Sommet;

typedef struct
{
  int n; // Nombre de Sommet
  Sommet *TabSomment;
  int **matrice;
}Graphe;

/* Soit M[m][n] la matrice d'adjacence d'un graphe non orienté, si M[i][j] = 1 alos M[j][i] = 1 */

/* La fonction */
int EstOriente(Graphe G)
{
  for(int i = 0; i < G.n; i++)
  {
    for (int j = 0; j < G.n ; i++) {
      /* code */
      if(matrice[i][j] == 1 && matrice[j][i] != 1 && i != j)
        return 0;
    }
  }
  return 1;
}

/* Fonction qui prend en paramètre un graphe G représenté sous forme de matrice
d’adjacence et un coloriage, et qui renvoie 1 si le coloriage de G est correct et 0 sinon. */

int ColoriageCorrect(Graphe G, int *coloriage)
{
  for (int i = 0; i < G.n; i++)
  {
    /* code */
    for (int j = 0; j < G.n; j++) {
      /* code */
      if(matrice[i][j] == 1 && coloriage[i] == coloriage[j] && i != j)
        return 0;
    }
  }
  return 1;
}
