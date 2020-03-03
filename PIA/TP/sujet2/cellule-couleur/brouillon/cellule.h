#ifndef CELLULE_H
#define CELLULE_H

class Cellule {
 private:
  Couleur couleur;
  size_t x, y;
  
 public:
  enum Couleur {
    NOIRE, // Morte
    BLEU, // Vient de naître
    VERTE, // Pleine force de l'âge
    ROUGE, // Mourrante
    JAUNE }; // Vient de naître ET Mourrante
  
  // Constructeurs
  Cellule();
  Cellule(Couleur couleur, size_t x, size_t y);

  // Accesseurs en lecture  
  Couleur getCouleur() const;
  size_t getX() const;
  size_t getY() const;

  // Accesseurs en écriture
  void setCouleur(bool new_couleur);
  void setX(size_t new_x);
  void setY(size_t new_Y);
  
  // Autres méthodes
  bool estVoisine(const Cellule &c) const;
};
#endif
