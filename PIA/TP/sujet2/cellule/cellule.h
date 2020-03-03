#ifndef CELLULE_H
#define CELLULE_H

class Cellule {
 private:
  bool vivante;
  size_t x, y;

 public:
  // Constructeurs
  Cellule();
  Cellule(bool vivante, size_t x, size_t y);

  // Accesseurs en lecture
  size_t getX() const;
  size_t getY() const;
  bool getVivante() const;

  // Accesseurs en écriture
  void setX(size_t new_x);
  void setY(size_t new_Y);
  void setVivante(bool new_vivante);
  
  // Autres méthodes
  bool estVoisine(const Cellule &c) const;
};
#endif
