#ifndef HUFF_H
#define HUFF_H

typedef struct {
  int fd, fg, pere;
  double fr;
} Noeud;

double freq[256] = {0};
Noeud arbre[511];
char* codes[256];

// Etape 1
void calculFreq(char* fichier);
void afficheFreq();
// Etape 2
void initArbre();
void afficheArbre();
void constructArbre();
// Etape 3
void parcours(int indiceNoeud, char code);

#endif

