void TriRapide(float tab[],int debut,int taille)
{
	int pivot=debut,i=debut,j=taille-1;
	while(i<j)
	{
		if(tab[i]<tab[pivot]) i++;
		else if(tab[j]>tab[pivot]) j--;
		else
		{
			float a=tab[i];
			tab[i]=tab[j];
			tab[j]=a;
		}
		TriRapide(tab,deb,j-1);
		TriRapide(tab,j+1,taille);
	}
}

#include<stdio.h>
int main()
{
  int n,i,deb=0;
  printf("entrer la taille du tableau:");
  scanf("%d",&n);
  float tab[n];
  for(i=0; i<n; i++)
  {
    printf("tab[%d]=",i);
    scanf("%f",&tab[i]);
  }
  printf("Le trableau trier est:\n");
  TriRapide(tab,deb,n);
  for(i=0; i<n; i++)
  printf("%f\t",tab[i]);
}
