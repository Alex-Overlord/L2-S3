#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
#define EVAL(v) cout << "l" << __LINE__ << ": " << #v << " = " << v << endl

// Prend la copie de deux variables et retourne le minimum.
int mini1(int a, int b) { return a<b ? a : b; }

// Prend l'adresse de deux variables, 
// compare les deux variables via leur valeur et retourne le minimum.
int mini2(int &a, int &b) { return a<b ? a : b; }

// Prend l'adresse de deux variables,
// compare les deux variables via leur valeur et retourne l'adresse du minimum.
int& mini3(int &a, int &b) { return a<b ? a : b; }

int main (int argc, char** argv) {
	int x = 2, y = -5;

	EVAL(x); EVAL(y);

	EVAL(mini1(x,y));
	EVAL(mini2(x,y));
	EVAL(mini3(x,y));

	EVAL(mini1(2,3));
	// EVAL(mini2(2,3));
	// EVAL(mini3(2,3));

	EVAL(mini1(0,mini1(x,y)));
	// EVAL(mini2(0,mini2(x,y)));
	// EVAL(mini3(0,mini3(x,y)));

	// mini1(x,y) = 10;
	// mini2(x,y) = 10;
	mini3(x,y) = 10;

	EVAL(x); EVAL(y);

    return 0;
}