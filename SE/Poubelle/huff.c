#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "huff.h"					

// Etape 1
void calculFreq(char* fichier) {
  printf("Calcules des fréquences. \n");
  FILE* fd = fopen(fichier, "r");
  unsigned char buffer[1];
  int lg = 0;
      
  // Compte la fréquence des caractères : (tableau freq)
  // Ainsi que la longueur du fichier : (lg)
  while (fread (buffer, 1, 1, fd)) {
    // printf( "freq[%i] (caractère : %c) " , buffer[0], buffer[0]);
    freq[buffer[0]]++;
    ++lg;
    // printf("lg = %d \n", lg);
  }
  for (int i=0 ; i<256 ; i++) {
    freq[i] /= lg;
  }
}

void afficheFreq() {
  printf("Affichage du tableau de fréquences. \n");
  for (int i=0 ; i<256 ; i++) {
    if (freq[i] > 0) {
      printf("A l'indice %d fréquence : %f \n", i, freq[i]);
    }
  }
}

// Etape 2
void initArbre() {
  printf("Initialisation de l'arbre. \n");
  for (int i  = 0; i < 511; i++){
    arbre[i].pere = -1;
    arbre[i].fg = -1;
    arbre[i].fd = -1;
    if (i<256) {
      arbre[i].fr = freq[i];
    } else {
      arbre[i].fr = 0;
    }
  }
}

void afficheArbre() {
  printf("Affichage de l'arbre. \n");
  for (int i=0 ; i<511 ; i++) {
    if (arbre[i].fr > 0) {
      printf("c: %c | ", i);
      printf("i: %d | ", i);
      printf("fr: %f | ", arbre[i].fr);
      printf("fg: %d | ", arbre[i].fg);
      printf("fd: %d | ", arbre[i].fd);
      printf("pere: %d \n", arbre[i].pere);
    }
  }
}
void constructArbre() {
  printf("Construction de l'arbre. \n");
  int indMin1 = 0; double freqMin1 = 1.0;
  int indMin2 = 0; double freqMin2 = 1.0;
  int dernierNoeud = 256; double freqDernierNoeud = 0;
  
  while (freqDernierNoeud < 1) {
    for (int i=0 ; i < dernierNoeud ; ++i) {
      if (arbre[i].fr > 0 && freqMin1 > arbre[i].fr && arbre[i].pere == -1) { 
	freqMin1 = arbre[i].fr;
	indMin1 = i;
      }
    }
    for (int i=0 ; i < dernierNoeud ; ++i) {
      if (arbre[i].fr > 0 && freqMin2 > arbre[i].fr && arbre[i].pere == -1 && indMin1 != i) { 
	freqMin2 = arbre[i].fr;
	indMin2 = i;
      }
    }
    /*
      printf("DEBUG(l%d): indMin1 = %d | ", __LINE__, indMin1);
      printf("DEBUG(l%d): freqMin1 = %f \n", __LINE__, freqMin1);
      printf("DEBUG(l%d): indMin2 = %d | ", __LINE__, indMin2);
      printf("DEBUG(l%d): freqMin2 = %f \n", __LINE__, freqMin2);
    */
    freqDernierNoeud = freqMin1 + freqMin2;
    arbre[dernierNoeud].fr = freqDernierNoeud;
    arbre[dernierNoeud].fg = indMin1;
    arbre[dernierNoeud].fd = indMin2;
    arbre[indMin1].pere = dernierNoeud;
    arbre[indMin2].pere = dernierNoeud;
    /*
      printf("DEBUG(l%d): %d \n", __LINE__, arbre[indMin1].pere);
      printf("DEBUG(l%d): %d \n\n", __LINE__, arbre[indMin2].pere);
    */
    ++dernierNoeud;
    indMin1 = 0; freqMin1 = 1;
    indMin2 = 0; freqMin2 = 1;
  }
  parcours(dernierNoeud, ' ');
}

// Etape 3
/* Production des codes binaires (sous forme de chaînes de caractères. 
   Créer (globalement) "char* codes[256];".
   Créer une fonction doublement récursive.
*/
void parcours(int indiceNoeud, char code) {
  
  if (arbre[indiceNoeud].fg != -1) { // Le noeud a des fils, la fonction va être rappelée sur ses deux fils.
    char* ncode = (char*) malloc (strlen(code)+1);
    
    strcpy(ncode,code); // après, strcpy de code dans ncode
    
    ncode[strlen(code)] = '0'; // on, ajoute a la fin de ncode un '0' ncode[strlen]='0'
    
    code[strlen(code)+1] = '\0'; // après, on ajoute a ncode[strlen+1] '\0'
    
    parcours(arbre[indiceNoeud].fg, ncode); // on appelle parcours a gauche(ou droite)
    
    ncode[strlen(code)] = '1'; // on, ajoute a la fin de ncode un '1' ncode[strlen]='1'
    
    parcours(arbre[indiceNoeud].fd, ncode); // on appelle parcours a droite(ou gauche)
    
  } else { // On est sur une feuille, càd sur un caractère
    codes[indiceNoeud] = strdup(code); // strdup() fait un mallac, puis un strcpy
    
    // codes est une variable globale définie au début du programme: code[256]={}
    
  }
}
  
int main(int argc, char** argv)
{
  if (argc != 2) {
    printf("Ecrivez: ./huff test.txt \n");
  }
  else {
    calculFreq(argv[1]);
    afficheFreq();
    initArbre();
    afficheArbre();
    constructArbre();
    afficheArbre();
  }
  return 0;
}
  
