#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strsplit(char* s, char c)
{
  int i = 0, nb_mot = 0, lg_mot = 0, lg_mot_max = 0, ligne = 0, colonne = 0;
  char** tab;
  
  // Compte le nombre de cases à alloués (nb_mot et lg_mot_max)
  while (s[i] != '\0') {
    if (s[i] == c) { // si séparateur rencontré
      nb_mot++;
      lg_mot = 0;    }
    else {
      lg_mot++;
      if (lg_mot > lg_mot_max) {
	lg_mot_max = lg_mot;
      }
    }
    i++;  
  }
  
  // Alloue l'espace nécessaire pour le tableau de pointeur sur char* (nb_mot)
  tab = (char**) malloc((nb_mot+1) * sizeof(char*));
  if (tab == NULL) {
    printf("Echec de l'allocation de tab !\n");
  }

  // Alloue l'espace nécessaire pour chaque mots (lg_mot_max)
  for (int mot=0; mot<nb_mot+1; mot++) {
    tab[mot] = (char*) malloc((lg_mot_max+1) * sizeof(char));
  }
  
  // Rempli les cases lignes avec les mots, les un après les autres
  i = 0;
  while (s[i] != '\0') {
    if (s[i] != c) {
      tab[ligne][colonne] = s[i];
      colonne++;
    } else {
      ligne++;
      colonne = 0;
    }
    i++;
  }
  // Affiche le tableau de char* tab
  for (int mot=0; mot < nb_mot+1; mot++) {
    for (int lettre=0; lettre < (int)strlen(tab[mot]); lettre++) {
      printf("%c", tab[mot][lettre]);
    }
    printf("\n");
  }
}

int main(int argc, char** argv, char** env)
{
  char* s = (char*) "a:bb:ccc:trdfgyh:kljhdf:zeherh:::::melvin:fait:caca:   :hohoho:";
  char c = ':';
  
  strsplit(s,c); 
  
  return 0;
}
