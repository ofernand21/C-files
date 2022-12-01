int RechercheDichotomique(float tab[],int n, float x)
{
  int oui=0,inf=0,sup=n-1,milieu;
  while(inf<=sup)
  {
    milieu=(sup+inf)/2;
    if(tab[milieu]==x)
    {
      oui=1; break;
    }
    else if(x>tab[milieu])
      inf=milieu+1;
    else
      sup=milieu-1;
  }
  return oui;
}

#include<stdio.h>
int main()
{
  int n,i;
  float x;
  printf("Entrer la taille du tableau:");
  scanf("%d",&n);
  float tab[n];
  for(i=0; i<n; i++)
  {
     printf("Tab[%d]=",i);
     scanf("%f",&tab[i]);
  }
  printf("Entrer l'element rechercher:");
  scanf("%f",&x);
  int Reponse=RechercheDichotomique(tab,n,x);
  if(Reponse==1)
     printf("Recherche avec succes");
  else
     printf("Recherche avec echec");
}
