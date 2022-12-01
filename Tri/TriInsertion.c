void TriInsertion(float tab[],int n)
{
  int i,j;
  for(i=1; i<n; i++)
  {
    j=i;
    while(j>0 && tab[j-1]>tab[j])
    {
        float a=tab[j];
        tab[j]=tab[j-1];
        tab[j-1]=a;
        j--;
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
  printf("Le tableau trier est:\n");
  TriInsertion(tab,n);
  for(i=0; i<n; i++)
  {
    printf("%f\t",tab[i]);
  }
}
