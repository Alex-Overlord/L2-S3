using namespace std;
#include <iostream>
#include "livre.h"

// Constructeur
Livre::Livre(string titre, string auteur, int annee)
  : titre(titre), auteur(auteur), annee(annee), genre(ROMAN), succ(NULL) {
  
}

// Accesseur en lecture
string Livre::getTitre() const { return titre; }
string Livre::getAuteur() const { return auteur; }
int Livre::getAnnee() const { return annee; }
Livre::Genre Livre::getGenre() const { return genre; }
Livre* Livre::getSucc() const { return succ; }

// Accesseur en écritre
void Livre::setSucc(Livre* succ) { this->succ = succ; }
