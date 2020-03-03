using namespace std;
#include <iostream>
#include "itv.cpp"
/*
#define TestVoidMethod(obj, name, param) \
  cout << "Test de " \
  << #obj << "." << #name << "(" << #param << ")" \
  << endl; \
  obj.name(param); \
  obj.affiche(); \
  cout << endl;

#define TestVoidMethodWithRetValue(obj, name, param) \
  cout << "Test de " \
  << #obj << "." << #name << "(" << #param << ")" \
  << endl; \
  cout << "=>"
  obj.name(param); \
  cout << obj.affiche() << endl;
*/

#define EMPTY

int main(int argc, char** argv) {
  Itv I1, I2(3, 1), I3(5, 5), I4(5, 5), I5(1, 4), I6(1, 2), I7(5, 8);

  cout << "I1.getBorneInf() : " << I1.getBorneInf() << endl;
  cout << "I1.getBorneSup() : " << I1.getBorneSup() << endl;
  cout << "Appel de I1.setBorneInf(3)" << endl; I1.setBorneInf(3);
  cout << "Appel de I1.setBorneSup(2)" << endl; I1.setBorneSup(2);
  cout << "I1.Afficher() : "; I1.afficher(); cout << endl; 
  cout << "I2.Afficher() : "; I2.afficher(); cout << endl;
  cout << "I1.Longueur() = " << I1.longueur() << endl;
  cout << "I2.Longueur() = " << I2.longueur() << endl;
  cout << "I1.Appartient(2.5) = " << I1.appartient(2.5) << endl; 
  cout << "I2.Appartient(2.5) = " << I2.appartient(2.5) << endl; 
  I2.setBorneSup(4);
  I2.setBorneInf(3);
  cout << "I2.Afficher() : "; I2. afficher(); cout << endl;
  cout << "I2.Appartient(2.5) = " << I2.appartient(2.5) << endl; 
  cout << boolalpha << "I1.estEgal(I2) = " << I1.estEgal(I2) << endl;
  cout << boolalpha << "I3.estEgal(I4) = " << I3.estEgal(I4) << endl;
  cout << boolalpha << "I1.estInclus(I2) = " << I1.estInclus(I2) << endl;
  cout << boolalpha << "I5.estInclus(I6) = " << I5.estInclus(I6) << endl;
  cout << boolalpha << "I5.estDisjoint(I6) = " << I5.estDisjoint(I6) << endl;
  cout << boolalpha << "I5.estDisjoint(I7) = " << I5.estDisjoint(I7) << endl;
  cout << boolalpha << "I1.estAccole(I2) = " << I1.estAccole(I2) << endl;
  cout << boolalpha << "I1.estImbrique(I2) = " << I1.estImbrique(I2) << endl;
   
  return 0;
}
