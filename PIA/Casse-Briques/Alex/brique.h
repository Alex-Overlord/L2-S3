#ifndef BRIQUE_H
#define BRIQUE_H

#include <iostream>

class Brique {
 private:
  size_t x, y; // coordonnées de la brique dans la fenètre de jeu
  size_t lg, ht; // longueur et hauteur des briques (minimum 1)
  size_t pdv; // point de vie (résistance de la brique)
  
 public:
  // Constructeur
  Brique(); // par défaut est en (0,0), de longueur 1, hauteur 1 et ayant 1 pdv
  Brique(size_t x, size_t y, size_t lg, size_t ht, size_t pdv);
  
  // Accesseur en lecture
  size_t getX() const;
  size_t getY() const;
  size_t getLg() const;
  size_t getHt() const;
  size_t getPdv() const;

  // Accesseur en écriture
  void setX(size_t x);
  void setY(size_t y);
  void setLg(size_t lg);
  void setHt(size_t ht);
  void setPdv(size_t pdv);
};

#endif
