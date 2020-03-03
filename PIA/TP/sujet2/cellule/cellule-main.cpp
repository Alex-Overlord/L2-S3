using namespace std;
#include <iostream>
#include "cellule.cpp"

void test_cell(Cellule &c) {
  cout << "(" << c.getX() << ", " << c.getY()
       << ") est " << (c.getVivante() ? "vivante." : "morte.") << endl;
}

#define PrintCell(c)				    \
  cout << "L'objet " #c " est à l'adresse mémoire " \
       << &c << endl

#define PrintVoisines(c1, c2)				\
  cout << "La cellule " #c1 " "				\
       << (c1.estVoisine(c2) ? "est" : "n'est pas")	\
       << " voisine de " #c2 "." << endl

int main(int argc, char** argv) {
  Cellule c1(true, 1, 2), c2;
  c2.setVivante(!c2.getVivante());
  c2.setX(c1.getX());
  c2.setY(c1.getX() + c1.getY());
  PrintCell(c1); PrintCell(c2);
  test_cell(c1); test_cell(c2);
  PrintVoisines(c1, c2); PrintVoisines(c2, c1);

  
  
  /*Cellule c1(0,0,true), c2(0,1,true), c3(1,1,true), c4(1,0,false);

  cout << "L'objet c1 est à l'adresse mémoire " << &c1 << endl;
  cout << "L'objet c4 est à l'adresse mémoire " << &c4 << endl;
  cout << "La cellule (à l'adresse mémoire " << &c1 << ") = ";
  c1.test_cell();
  cout << "La cellule (à l'adresse mémoire " << &c4 << ") = ";
  c4.test_cell();
  cout << "La cellule c1 " << (c1.estVoisin(c4) ? "est voisine" : "n'est pas voisine")
       << " de c4." << endl;
  
  cout << "L'objet c2 est à l'adresse mémoire " << &c2 << endl;
  cout << "L'objet c3 est à l'adresse mémoire " << &c3 << endl;
  cout << "La cellule (à l'adresse mémoire " << &c2 << ") = ";
  c2.test_cell();
  cout << "La cellule (à l'adresse mémoire " << &c3 << ") = ";
  c3.test_cell();
  cout << "La cellule c2 " << (c2.estVoisin(c3) ? "est voisine" : "n'est pas voisine")
  << " de c3." << endl; */
  
  return 0;
}
