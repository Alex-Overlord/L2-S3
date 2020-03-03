#ifndef LIVRE_H
#define LIVRE_H

#include <iostream>
#include <string>

class Livre {
  
 public:
  enum Genre {
    ROMAN,
    FANTASY,
    SF,
    BD,
    AUTRE
  };

 private:
  string titre;
  string auteur;
  int annee;
  Genre genre;
  Livre* succ;

 public:
  // Constructeur
  Livre(string titre, string auteur, int annee);

  // Accesseur en lecture
  string getTitre() const;
  string getAuteur() const;
  int getAnnee() const;
  Genre getGenre() const;
  Livre* getSucc() const;

  // Accesseur en écritre
  void setSucc(Livre* succ);
};

#endif
