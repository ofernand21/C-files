void TriBulle(float tab[],int n)
{
  int i,j;
  float a;
  for (i=n-1; i>=0; i--)
  {
    for (j=0; j<=i; j++)
    {
        if (tab[j]>tab[i])
        {
            a=tab[j];
            tab[j]=tab[i];
            tab[i]=a;
        }
    }
}
}

#include<stdio.h>
int main()
{
    int n,i,j;
    float a;
    printf("entrer la taille du tableau:");
    scanf("%d",&n);
    float tab[n];
    printf("entrer les elements du tableau:\n");
    for (i=0; i<n; i++)
    {
        printf("tab[%d]=",i);
        scanf("%f",&tab[i]);
    }
    TriBulle(tab,n);
    for(i=0; i<n; i++)
    {
       printf("%f\t",tab[i]);
    }
}
