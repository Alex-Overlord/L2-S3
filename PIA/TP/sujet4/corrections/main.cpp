#include <iostream>
#include <string>
#include "option.h"

using namespace std;

int main(int argc, char** argv)
{
  Option tab[5];

  for(size_t i=0 ; i < 5 ; ++i) {
    cout << "Option[" << i << "]:";
    tab[i].print();
  }

  tab[0] = Option(Option::HELP, "help", 'h', Option::AUCUN, "Affiche cette description.");
  tab[1] = Option(Option::VERSION, "version", 'v', Option::AUCUN, "Affiche cette version.");
  tab[2] = Option(Option::DIMENSION, "dimension", 'd', Option::AUCUN, "Affiche cette dimension.");
  tab[3] = Option(Option::PROBABILITY, "probabilité", 'p', Option::AUCUN, "Affiche cette probabilité.");
  tab[4] = Option(Option::CONFIG, "config", 'c', Option::AUCUN, "Affiche cette config.");
    

  return 0;
}
