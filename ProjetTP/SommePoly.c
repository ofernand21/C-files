#include <stdio.h>
#include <stdlib.h>
#define couleur(param) printf("\033[%sm",param)

int main()
{
  int taille1,taille2,i;
  
  couleur("1,7");
  printf("Informations sur le 1er polynôme\n\n");
  couleur("0");
  printf("Entrer le plus grand degrée du polynône 1:");
  scanf("%d",&taille1);
  int poly1[taille1];
  for(i=taille1; i>=0; i--)
  {
    printf("Entrer le coefficient du monome X^%i:",i);
    scanf("%d",&poly1[i]);
  }
  
  printf("\n\n");
  printf("Informations sur le 2e polynôme\n\n");
  couleur("0");
  printf("Entrer le plus grand degrée du polynône 2:");
  scanf("%d",&taille2);
  int poly2[taille2];
  printf("\n");
  for(i=taille2; i>=0; i--)
  {
    printf("Entrer le coefficient du monome X^%i:",i);
    scanf("%d",&poly2[i]);
  }
  
  int n;
  if(taille1>taille2)
  {
     n=taille2;
     int poly[n],a=0;

     for(i=n; i>=0; i--)
        poly[i] = poly1[i]+poly2[i];
     for(i=taille1; i>taille2; i--)
        poly[i]=poly1[i];
     
     printf("Resultat:\n\n");
     printf("P(X)=");
     for(i=taille1; i>=0; i--)
     {
       if(a!=0) printf("+");
       printf("%dX^%d",poly[i],i);
       a++;
     }
  }
  else
  {
     n=taille1;
     int poly[n],a=0;

     for(i=n; i>=0; i--)
        poly[i] = poly1[i]+poly2[i];
     for(i=taille2; i>taille1; i--)
        poly[i]=poly2[i];
        
      printf("Resultat:\n\n");
      printf("P(X)=");
      for(i=taille2; i>=0; i--)
      {
         if(a!=0) printf("+");
         printf("%dX^%d",poly[i],i);
         a++;
      }
   }

printf("\n\n");
}
