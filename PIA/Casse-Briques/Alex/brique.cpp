#include <iostream>
#include "brique.h"

Brique::Brique() : x(0), y(0), lg(1), ht(1), pdv(1) {}//si tu mets x et y à 0 par defaut ils seront afficher en haut à gauche d'apres le pdf :)
Brique::Brique(size_t x, size_t y, size_t lg, size_t ht, size_t pdv)
  : x(x), y(y), lg(lg), ht(ht), pdv(pdv) {}

Brique::size_t getX() const { return x; }
Brique::size_t getY() const { return y; }
Brique::size_t getLg() const { return lg; }
Brique::size_t getHt() const { return ht; }
Brique::size_t getPdv() const { return pdv; }

Brique::void setX(size_t x) { this->x = x; }
Brique::void setY(size_t y) { this->y = y; }
Brique::void setLg(size_t lg) { this->lg = lg; }
Brique::void setHt(size_t ht) { this->ht = ht; }
Brique::void setPdv(size_t pdv) { this->pdv = pdv; }
