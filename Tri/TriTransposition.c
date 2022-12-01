void TriTransposition(float tab[],int n)
{
  int i=0;
  while(i<n-1)
  {
    if(tab[i]>tab[i+1])
    {
      float a=tab[i];
      tab[i]=tab[i+1];
      tab[i+1]=a;
      i=0; //retour en arriere
    }
    else i++;
  }
}

#include<stdio.h>
int main()
{
  int n,i;
  printf("Enter la taille du tableau:");
  scanf("%d",&n);
  float tab[n];
  for(i=0; i<n; i++)
  {
    printf("tab[%d]=",i);
    scanf("%f",&tab[i]);
  }
  printf("Le tableau trier est:\n");
  TriTransposition(tab,n);
  for(i=0; i<n; i++)
  {
    printf("%f\t",tab[i]);
  }
}
