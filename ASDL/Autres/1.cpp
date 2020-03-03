using namespace std;
#include <iostream>

bool rechDicho2(int tab[], int n, int e) {
  int deb = 0, fin = n-1, mil;
  bool present = false;

  while (deb <= fin) {
    mil = (deb + fin) / 2;
    if (tab[mil] <= e) {
      deb = mil+1;
    } else {
      fin = mil-1;
    }
  }
  if (tab[fin] == e and fin > 0) {
    present = true;
  }
  return present;
}

int main(int argc, char** argv)
{
  int tab[4] = {6, 12, 42, 240};

  cout << boolalpha << rechDicho2(tab, 4, 43) << endl;
  cout << boolalpha << rechDicho2(tab, 4, 42) << endl;
  
  return 0;
}
