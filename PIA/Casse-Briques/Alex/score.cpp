#include <iostream>
#include "score.h"

Score::Score() : pts(0) {}
Score::Score(size_t pts) : pts(pts) {}

Score::size_t getPts() const { return pts; }

Score::void setPts(size_t pts) { this->pts = pts; }

Score::void ajouter(size_t pts) { this->pts += pts; }
Score::void reset() { pts = 0; }
Score::void sauvegarder(); // Sauvegarde le score dans un fichier
Score::void affiche(); // Affiche le score, peu utile (devra être déplacé dans la classe "Message") 
