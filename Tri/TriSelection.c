void TriSelection(float tab[],int n)
{
  int i,j;
  for(i=0; i<n; i++)
  {
    int min=i;
    for(j=i+1; j<n; j++)
    {
       if(tab[j]<tab[min])
       {
          min=j;
       }
    }
    if(i!=min)
    {
       int echange=tab[i];
       tab[i]=tab[min];
       tab[min]=echange;
    }
  }
}

#include<stdio.h>
int main()
{
  int n,i;
  printf("Entrer la taille du tableau:");
  scanf("%d",&n);
  float tab[n];
  for(i=0; i<n; i++)
  {
    printf("tab[%d]=",i);
    scanf("%f",&tab[i]);
  }
  TriSelection(tab,n);
  for(i=0; i<n; i++)
  { 
     printf("%f\t",tab[i]);
  }
}
