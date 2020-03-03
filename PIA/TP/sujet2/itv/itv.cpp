using namespace std;
#include <iostream>
#include "itv.h"

Itv::Itv() : bi(0.0), bs(0.0) { }
Itv::Itv(double binf, double bsup) : bi(binf), bs(bsup) {
  if (binf > bsup) {
    cout << "Avertissement : les valeurs fournies (bi = " << bi << ", bs = " << bs
	 << ") pour la création de l'intervalle ont été inversées." << endl;
    bi = bsup;
    bs = binf;
  }
}
double Itv::getBorneInf() const { return bi; }
double Itv::getBorneSup() const { return bs; }
void Itv::setBorneInf(double v) {
  if (v > bs) {
    cerr << "Avertissement : la valeur de la borne inférieur (bi = " << bi
	 << ") n'a pas été mise à jour car supérieur à la borne sup." << endl;
  } else {
    bi = v;
  }
}
void Itv::setBorneSup(double v) {
  if (v < bi) {
    cerr << "Avertissement : la valeur de la borne suppérieur (bs = " << bs
	 << ") n'a pas été mise à jour car inférieur à la borne inf." << endl;
  } else {
    bs = v;
  }
}
void Itv::afficher() const { cout << "[" << bi << ", " << bs << "]"; }
double Itv::longueur() const { return bs - bi; }
bool Itv::appartient(double v) const { return v >= bi and v <= bs; }

bool Itv::estEgal(const Itv &I) const {
  return bi == I.bi and bs == I.bs;
}
bool Itv::estInclus(const Itv &I) const {
  return (bi != I.bi or bs != I.bs) and (bi == I.bi or bs == I.bs);
}

bool Itv::estDisjoint(const Itv &I) const {
  return bi > I.bs or bs < I.bi;
}
bool Itv::estAccole(const Itv &I) const {
  return bi == I.bs or bs == I.bi;
}
bool Itv::estImbrique(const Itv &I) const {
  return bi > I.bi and bs < I.bs;
}
