#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
#define EVAL(v) cout << "l" << __LINE__ << ": " << #v << " = " << v << endl

#include "1.hpp" 
#include "2.hpp" 
#include "3.hpp"

void exo1() {
	int x[10];
	size_t i, j, k;
	srand(19);
	j = rand() % 10;
	k = rand() % 10;
	for (i = 0; i < 10; i++) {
		x[i] = rand() % 100 + 1;
	}
	EVAL(j); EVAL(k); EVAL(x);
	EVAL(x[j]); EVAL(x[k]);
	cout << "===== ech1 :" << endl;
	ech1(x[j], x[k]);
	EVAL(x[j]); EVAL(x[k]);
	cout << "===== ech2 :" << endl;
	ech2(x+j, &x[k]);
	EVAL(x[j]); EVAL(x[k]);
	cout << "===== ech3 :" << endl;
	ech3(x[j], x[k]);
	EVAL(x[j]); EVAL(x[k]);
	cout << "===== ech4 :" << endl;
	ech4(j, k, x);
	EVAL(x[j]); EVAL(x[k]);
	cout << "=====" << endl << "Fin du programme" << endl << endl;
}

void exo2() {
	int a = 2, b = -5;

	EVAL(a); EVAL(b);

	EVAL(mini1(a,b));
	EVAL(mini2(a,b));
	EVAL(mini3(a,b));

	EVAL(mini1(2,3));
	// EVAL(mini2(2,3));
	// EVAL(mini3(2,3));

	EVAL(mini1(0,mini1(a,b)));
	// EVAL(mini2(0,mini2(a,b)));
	// EVAL(mini3(0,mini3(a,b)));

	// mini1(a,b) = 10;
	// mini2(a,b) = 10;
	mini3(a,b) = 10;

	EVAL(a); EVAL(b);
	cout << endl;
}

void exo3() {
	EVAL(Puissance(2,2));
	EVAL(Puissance(1,5));

	EVAL(PuissanceRec(2,2));
	EVAL(PuissanceRec(1,5));

	cout << endl;
}

int main (int argc, char** argv) {

	exo1();
	exo2();
	exo3();

   return 0;
}