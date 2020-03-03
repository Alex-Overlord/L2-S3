using namespace std;
#include <iostream>
#include "pileDeLivres.h"

// Constructeur et Destructeur
PileDeLivres::PileDeLivres() : sommet(NULL) {}
PileDeLivres::~PileDeLivres() { delete sommet; }

// Accesseurs en lecture et ceux en écriture
Livre* getSommet() const { return this->sommet; }
void setSommet(Livre* sommet) { this->sommet = sommet; }

// Autres méthodes
void PileDeLivres::empiler(Livre* L) {
  this->succ = L;
}
void PileDeLivres::depiler() {
  if (this->sommet != NULL) {
    this->sommet = this->succ;
  }
}

// Fonctions
void suppress(Livre* L) {
  
}
Livre* duplicate(Livre* L) {
  
}
