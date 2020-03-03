#ifndef BALLE_H
#define BALLE_H

#include <iostream>
#include <string>

class Balle {
 public:
  enum Direction {
    HAUT_GAUCHE,
    HAUT_DROIT,
    BAS_GAUCHE,
    BAS_DROIT
  };
  
 private:
  size_t x, y; // coordonnées de la balle dans la fenètre de jeu
  size_t speed; // vitesse de la balle
  Direction dir; // ça sera plus facile pour gérer les collisions

 public:
  // Constructeurs
  Balle(); // initialisée sur la raquette, suit celle-ci jusqu'à qu'elle soit lancée

  // Accesseur en lecture
  size_t getX() const;
  size_t getY() const;
  Direction getDir() const;

  // Accesseur en écriture
  void setX(size_t x);
  void setY(size_t y);
  void setDir(Direction dir);

  // Autres méthodes
  void reset(); // replace la balle sur la raquette
  
};

#endif
