#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"biblioSDD.h"
#include"Pile.c"

int main()
{
  Pile *L=NULL;
  
  L=SaisirPile(L);
  
  AffichePile(L);
} 
