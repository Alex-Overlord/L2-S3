#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
#define EVAL(v) cout << "l" << __LINE__ << ": " << #v << " = " << v << endl

// Copie la valeur des paramètres et échange leur valeur. NE FONCTIONNE PAS.
void ech1(int a, int b) {
	int c;
	c = a; a = b; b = c;
}

// Prend l'adresse de deux variables et échange leur valeur
void ech2(int *a, int *b) {
	int c;
	c = *a; *a = *b; *b = c;
}

// Prend deux variables et échange leur adresse
void ech3(int &a, int &b) {
	int c;
	c = a; a = b; b = c;
}

/* Prend deux valeur positives et une adresse et échange deux valeurs 
	en utilisant cette adresse et ces deux valeurs positives */
void ech4(size_t u, size_t v, int *t){
	int c;
	c = t[u]; t[u] = t[v]; *(t + v) = c;
}

int main (int argc, char** argv) {
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
	cout << "=====" << endl << "Fin du programme" << endl;

	return 0;
}