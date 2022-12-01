#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"biblioSDD.h"
#include"File.c"

int main()
{
  File *L=NULL;
  
  L=SaisirFile(L);
  
  AfficheFile(L);
} 
