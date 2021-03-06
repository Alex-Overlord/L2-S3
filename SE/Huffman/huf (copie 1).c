#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "huf.h"					

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
    nbCar++;
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

    freqDernierNoeud = freqMin1 + freqMin2;
    arbre[dernierNoeud].fr = freqDernierNoeud;
    arbre[dernierNoeud].fg = indMin1;
    arbre[dernierNoeud].fd = indMin2;
    arbre[indMin1].pere = dernierNoeud;
    arbre[indMin2].pere = dernierNoeud;
    ++dernierNoeud;
    indMin1 = -1; freqMin1 = 1;
    indMin2 = -1; freqMin2 = 1;
  }
  parcours(dernierNoeud-1, "");
}

// Etape 3
/* Production des codes binaires (sous forme de chaînes de caractères. 
   Créer (globalement) "char* codes[256];".
   Créer une fonction doublement récursive.
*/

void parcours(int indiceNoeud, char* code) {
  
  if (arbre[indiceNoeud].fg != -1) { // Le noeud a des fils, la fonction va être rappelée sur ses deux fils.
    int taille = strlen(code);
    char* ncode = (char*) malloc(taille+1);
    strcpy(ncode,code); // après, strcpy de code dans ncode
    ncode[taille] = '0'; // on, ajoute a la fin de ncode un '0' ncode[strlen]='0'
    codes[taille+1] = '\0'; // après, on ajoute a ncode[strlen+1] '\0'
    parcours(arbre[indiceNoeud].fg, ncode); // on appelle parcours a gauche(ou droite)
    ncode[taille] = '1'; // on, ajoute a la fin de ncode un '1' ncode[strlen]='1'
    parcours(arbre[indiceNoeud].fd, ncode); // on appelle parcours a droite(ou gauche)
  } 
  else { // On est sur une feuille, càd sur un caractère
    codes[indiceNoeud] = malloc(strlen(code)); // strdup() fait un mallac, puis un strcpy
    strcpy(codes[indiceNoeud], code);
    printf("%i %c %s %s\n", indiceNoeud, indiceNoeud, code, codes[indiceNoeud]);    
    nbDiff++;
    // codes est une variable globale définie au début du programme: code[256]={}   
  }
}

//Etape 4
/*Production du fichier compresser
*/
void del_char(char* str, char c) //Enleve tous les c de str 
{ int id_read, id_write; 
  id_read = 0; id_write = 0; 
  while (str[id_read] != '\0') { 
    if (str[id_read] != c) {
     str[id_write] = str[id_read];
      id_write++; } id_read++; 
    } 
    str[id_write] = '\0'; 
  }

void creeFiche(char* fichier){
  FILE* fc;
  fc = fopen("test.txt.huf","w");
  FILE* fd = fopen(fichier, "r");
  char car[1];
  char buffer[263];
  buffer[0] = '\0';
  int lg = 0; //longueur
  char temp[10];
  temp[0]= '\0';
  int i=0;
  char cAscii;
  printf("nbCar :%i , nbDiff :%i\n",nbCar, nbDiff );
  fprintf(fc, "%i",nbCar );
  fprintf(fc, "%i",nbDiff );
  printf("Affichage des codes :\n");
  for (int i=0; i < 256; i++) {
    if (codes[i]) {
      lg= strlen(codes[i]);
      printf("%c : %s : %i\n", i, codes[i], lg);
      fprintf(fc, "%c%i%s",i, lg, codes[i]);
      
    }
  }
  
  while (fread (car, 1, 1, fd)) {
    printf("%c %i = %s\n",car[0], (int)car[0], codes[(int)car[0]]);
    
    strcat(buffer, codes[(int)car[0]]);
    printf("Buffer = %s\n", buffer);
      

    if (strlen(buffer) >= 8){
        strncpy(temp,buffer,8);
        temp[8]='\0';
      for (int i = 0; i < 8; i++)
      {
        //strcat(temp, buffer[i]);
        temp[i]=buffer[i];
        buffer[i]='m';
      }
      del_char(buffer,'m');
      printf("NewBuffer = %s\n", buffer);


      // Calculer la valeur des 8 premiers caractères
      cAscii = strtol(temp,0,2);
      // Ajouter le caractère de ce code ASCII dans le fich compressé
      printf("temp = %s et ASCII= %c\n",temp, cAscii );
      fprintf(fc, "%c",cAscii);
      // Décaler buffer de 8 caractères

    }
         printf("------------------\n");
  }

  if (buffer[0]!='\0')
  {
    printf("jfhslj\n");
    while(strlen(buffer)!=8){
      strcat(buffer,"0");

    }
    printf("Buffer=%s\n",buffer );
    cAscii = strtol(temp,0,2);
    fprintf(fc, "%c",cAscii);
    printf("buffer = %s et ASCII= %c\n",buffer, cAscii );
    // for (int i = 0; i < strlen(buffer); ++i)
    // {
    //     temp[i]=buffer[i];
     
    // }
    // for (int i = strlen(buffer); i < 8; ++i)
    // {
    //   temp[i]='0';
    // }
    //  cAscii = strtol(temp,0,2);
    // printf("temp = %s et ASCII= %c\n",temp, cAscii );
    // fprintf(fc, "%c",cAscii); 
  }

}


int main(int argc, char** argv)
{
  if (argc != 2) {
    printf("Ecrivez: ./huff test.txt \n");
  }
  else {
    calculFreq(argv[1]);
    printf("############################\n");
    afficheFreq();
    printf("############################\n");
    initArbre();
    printf("############################\n");
    afficheArbre();
    printf("############################\n");
    constructArbre();
    printf("############################\n");
    afficheArbre();
    printf("############################\n");
    creeFiche(argv[1]);
    printf("############################\n");
    printf("FINNNNN\n");
    printf("############################\n");
    //char a[10];
    // a = "12345";
    // String a = "1234";
// 
    // a[2]='\0';
    // printf("%s\n",a );
  
  char ambre[] = "chercher";
  del_char(ambre, 'c');
  printf("%s\n",ambre );
 }
  return 0;
}