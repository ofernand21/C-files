#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include"biblioSDD.h"
#include"ListeChainee.c"

typedef struct poly
{
   int exp;
   float coef;
}TypeMonome;

typedef struct cellule
{
  TypeMonome m;
  struct cellule *suivant;
}TypePolynome;
 
TypePolynome *InserePolyEnTete(TypePolynome *poly,TypeMonome b)
{
  TypePolynome *autrePoly;
  autrePoly=(TypePolynome*)malloc(sizeof(TypePolynome));
  autrePoly->m.coef=b.coef;
  autrePoly->m.exp=b.exp;
  autrePoly->suivant=poly;
  return autrePoly;
}

TypePolynome *SommePoly(TypePolynome *poly1,TypePolynome *poly2)
{
   TypePolynome *P=NULL;
   TypeMonome r;
   while(poly1 != NULL && poly2 != NULL)
   {
      
      if(poly1->m.exp == poly2->m.exp)
      {
        r.coef=poly1->m.coef+poly2->m.coef;
        r.exp=poly1->m.exp;
        P=InserePolyEnTete(P,r);
        poly1=poly1->suivant;
        poly2=poly2->suivant;
      }
      else
      {
         if(poly1->m.exp < poly2->m.exp)
         {
             r.coef=poly1->m.coef;
             r.exp=poly1->m.exp;
             P=InserePolyEnTete(P,r);
             poly1=poly1->suivant;
         }
         else
         {
             r.coef=poly2->m.coef;
             r.exp=poly2->m.exp;
             P=InserePolyEnTete(P,r);
             poly2=poly2->suivant;
         }
      }
   }
   
   if(poly1 == NULL || poly2 == NULL)
   {
      if(poly1 == NULL)
         P=poly2;
      else
         P=poly2;
   }
} 

TypePolynome *CreerPolynome()
{
   TypePolynome *poly;
   TypeMonome b;
   choix='o';
   while(choix == 'o')
   {
      printf("Entrer l'exposant:");
      scanf("%d",&b.exp);
      printf("Entrer le coefficient:");
      scanf("%f",&b.coef);
      poly=InserePolyEnTete(P,b);
      puts("Voulez-vous inserer un monome? o/n");
      getchar();
      choix=getchar();
   }
   return poly;
}


void AffichePolynome(TypePolynome *P)
{
   TypePolynome *q;
   for(q=P; p != N      

int main()
{
   TypePolynome *p,*q,*R;
   printf("Creation du premier polynome");
   p=CreerPolynome();
   Affiche
