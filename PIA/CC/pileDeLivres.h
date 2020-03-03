#ifndef PILEDELIVRES_H
#define PILEDELIVRES_H

#include <iostream>
#include "livre.h"

classe PileDeLivres {
 private:
  Livre* sommet;

  public:
  // Constructeur
  PileDeLivres();

  // Destructeur
  ~PileDeLivres();

  // Accesseur en lecture
  Livre* getSommet() const;

  // Accesseur en écriture
  void setSommet(Livre* sommet);

  // Autres méthodes
  void empiler(Livre* L);
  void depiler();
};

void suppress(Livre* L);
Livre* duplicate(Livre* L);

#endif
