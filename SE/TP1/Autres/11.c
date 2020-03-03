#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Exercice 11 : On veut réaliser la conversion inverse de l'exercice précédent. 
   Soit un nombre entier positif que l'on veut convertir en une chaîne de caractères C 
   contenant sa représentation décimale. (Similaire à itoa) */

char* intToString(const int x) {
  char* s;
  int tmp = x, lg = 1;
  
  // Compte le nombre de chiffres
  while (tmp/10 >= 1) {
    tmp=tmp/10;
    lg++;
  }

  // Alloue la chaîne de caractères
  s = (char*) malloc((lg+1)*sizeof(char));

  // Rempli la chaîne de caractère, chiffre après chiffre
  tmp=x;
  
  for(;lg>0; lg--) {
    s[lg-1] = tmp%10 + '0';
    tmp /= 10;
  }
  return s;
}

#define affiche(s) printf("%s\n", s);

int main(int argc, char** argv, char** env)
{
  int x = 91254;
  printf("C CONVERTIE MDR\n");
  affiche(intToString(x));
  
  return 0;
}
