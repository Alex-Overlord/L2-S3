using namespace std;
#include <iostream>
#include "cellule.h"

Cellule::Cellule() : couleur(NOIRE), x(0), y(0) {}
Cellule::Cellule(Couleur couleur, size_t x_, size_t y_) : couleur(couleur_), x(x_), y(y_) {}

Couleur Cellule::getCouleur() const { return couleur; }
size_t Cellule::getX() const { return x; }
size_t Cellule::getY() const { return y; }

void Cellule::setVivante(bool new_vivante) { vivante = new_vivante; }
void Cellule::setX(size_t new_x) { this->x = new_x; }
void Cellule::setY(size_t new_y) { this->y = new_y; }

bool Cellule::estVoisine(const Cellule &c) const {
  return vivante and
    ((x - c.x) * (x - c.x) + (y - c.y) * (y - c.y) <= 2);
}
