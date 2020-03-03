/**
 * \file huf.h
 * \brief Fichier d'en-tête
 * \author Ambre.Lamouchi Alexandre.Canton.Condes
 * \version 1.0
 * \date 7 décembre 2018
 *
 * En-tête du compresseur Huffman
 *
 */

#ifndef HUF_H
#define HUF_H

typedef struct {
  int fd, fg, pere; /*!< Indices des noeuds fils droit, fils gauche et père. */
  double fr; /*!< Fréquence du caractère. */
} Noeud;
int nbCar=0;
int nbDiff=0;
double freq[256] = {0}; /*!< Liste les fréquences */
Noeud arbre[511]; /*!< Arbre binaire. */
char* codes[256] = {NULL}; /*!< Tableau du code Huffman de chaque charactère */

// Etape 1
void calculFreq(char* fichier);
void afficheFreq();
// Etape 2
void initArbre();
void afficheArbre();
void constructArbre();
// Etape 3
void parcours(int indiceNoeud, char* code);

#endif

