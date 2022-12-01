float RechercheSequentielle(float Tab[],int n,float x)
{
   int i=0,oui=0;
   while(Tab[i]<=x && i<n)
   {
     if(Tab[i]==x)
     {
        oui=1;break;
     }
     else i++;
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
