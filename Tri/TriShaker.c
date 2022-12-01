void TriShaker(float tab[],int n)
{
  int k,i=0,j=n-1;
  while(i<j)
  {
     for(k=i; k<j; k++)
     {
       if(tab[k]<tab[i])
       {
         float a=tab[i];
         tab[i]=tab[k];
         tab[k]=a;
       }
       else if(tab[k]>tab[j])
       {
         float a=tab[j];
         tab[j]=tab[k];
         tab[k]=a;
       }
     }
     i++;
     j--;
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
  printf("Le tableaun trier est:\n");
  TriShaker(tab,n);
  for(i=0; i<n; i++)
  {
    printf("%f\t",tab[i]);
  }
}
