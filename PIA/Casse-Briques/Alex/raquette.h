#ifndef RAQUETTE_H
#define RAQUETTE_H

#include <iostream>
#include "window.h"

class Raquette {
 private:
  size_t x, y; // coordonnées de la raquette dans la fenètre de jeu
  size_t lg; // longueur de la raquette
  Color colr;

 public:
  // Constructeur
  Raquette(); // par défaut devra être placé en bas au milieu

  // Accesseur en lecture
  size_t getX() const;
  size_t getY() const;
  size_t getLg() const;
  
  // Accesseur en écriture
  void setX(size_t x);
  void setY(size_t y);
  void setLg(size_t lg);

  // Autre méthode
  
  
};

#endif
