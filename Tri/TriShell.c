void TriShell(float tab[], int n)
{
  int i,pas=n/2;
  while(pas!=0)
  {
    for(i=0; i<n-pas; i++)
    {
      if(tab[i]>tab[i+pas])
      { 
        int a=tab[i+pas];
        tab[i+pas]=tab[i];
        tab[i]=tab[i+pas];
      }
    }
    pas=pas/2;
  }
}

#include<stdio.h>
int main()
{
  int n,i;
  printf("entrer la taille du tableau:");
  scanf("%d",&n);
  float tab[n];
  for(i=0; i<n; i++)
  {
    printf("tab[%d]=",i);
    scanf("%f",&tab[i]);
  }
  printf("Le trableau trier est:\n");
  TriShell(tab,n);
  for(i=0; i<n; i++)
  printf("%f",tab[i]);
}
