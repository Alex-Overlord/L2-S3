#ifndef SCORE_H
#define SCORE_H

#include <iostream>

class Score {
 private:
  size_t pts; // Le nombre de points
  
 public:
  // Constructeurs
  Score();
  Score(size_t pts);

  // Accesseurs en lecture
  size_t getPts() const;

  // Accesseur en écriture
  void setPts(size_t pts);
  
  // Autres méthodes
  void ajouter(size_t pts); // Ajoute "pts" points au score
  void reset(); // Remet le score à 0
  void sauvegarder(); // Sauvegarde le score dans un fichier
  void affiche(); // Affiche le score (devra être déplacé dans la classe "Message")  
};

#endif
