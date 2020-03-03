#include <iostream>
#include "raquette.h"

Raquette::Raquette() : x(31), y(15), lg(8), colr(BGREEN) {}; // par défaut devra être placé en bas au milieu

size_t Raquette::getX() const { return x; }
size_t Raquette::getY() const { return y; }
size_t Raquette::getLg() const { return lg; }
  
void Raquette::setX(size_t x) { this->x = x; }
void Raquette::setY(size_t y) { this->y = y; }
void Raquette::setLg(size_t lg) { this->lg = lg; }
