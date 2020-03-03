#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Exercice 10 : Soit une chaîne de caractères C contenant 
   un nombre entier positif en représentation décimale. 
   On veut écrire une fonction convertissant cette chaîne en entier. 
   (algo itératif de conversion) similaire à atoi */

int stringToInt(const char* s) {
  int res = 0, lg = strlen(s);

  for (int i=0; i<lg; i++) {
    res *= 10;
    res += s[i]-'0';
  }  

  return res;
}

#define affiche(x) printf("%d\n", x);

int main(int argc, char** argv, char** env)
{
  const char* s = "42";

  affiche(stringToInt(s));

  return 0;
}
