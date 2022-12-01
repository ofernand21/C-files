#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"biblioSDD.h"
#include"ListeChainee.c"

int main()
{
  TypeCellule *L=NULL;
  
  L=SaisirListeEnTete();
  
  AfficheListe(L);
}  
