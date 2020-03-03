#ifndef ITV_H
#define ITV_H

class Itv {
 private:
  // Attributs
  double bi, bs;

 public:
  // Constructeurs
  Itv();
  Itv(double bi, double bs);

  // Accesseurs en lecture
  double getBorneInf() const;
  double getBorneSup() const;

  // Accesseurs en écriture
  void setBorneInf(double new_bi);
  void setBorneSup(double new_bs);

  // Autres méthodes
  void afficher() const;
  double longueur() const;
  bool appartient(double val) const;

  // Méthodes complémentaires
  bool estEgal(const Itv &I) const;
  bool estInclus(const Itv &I) const;
  bool estDisjoint(const Itv &I) const;
  bool estAccole(const Itv &I) const;
  bool estImbrique(const Itv &I) const;
};
#endif
