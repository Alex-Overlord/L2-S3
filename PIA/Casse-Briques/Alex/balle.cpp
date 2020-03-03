#include <iostream>
#include "balle.h"

Balle::Balle() : x(0), y(0), dir(HAUT_DROIT) {} // initialisée sur la raquette, suit celle-ci jusqu'à qu'elle soit lancée

Balle::size_t getX() const { return x; }
Balle::size_t getY() const { return y; }
Balle::Direction getDir() const { return dir; }

Balle::void setX(size_t x) { this->x = x; }
Balle::void setY(size_t y) { this->y = y; }
Balle::void setDir(Direction dir) { this->dir = dir; }

Balle::void reset() {} // replace la balle sur la raquette
