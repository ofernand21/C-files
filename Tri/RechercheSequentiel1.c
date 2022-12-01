float RechercheSequentielle(float Tab[],int n,float x)
{
   int i,oui=0;
   for(i=0; i<n; i++)
   {
     if(Tab[i]==x)
     {
        oui=1;break;
     }
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
  float Tab[n];
  for(i=0; i<n; i++)
  {
     printf("Tab[%d]=",i);
     scanf("%f",&Tab[i]);
  }
  printf("Entrer l'element rechercher:");
  scanf("%f",&x);
  int Reponse=RechercheSequentielle(Tab,n,x);
  if(Reponse==1)
     printf("Recherche avec succes");
  else
     printf("Recherche avec echec");
}
