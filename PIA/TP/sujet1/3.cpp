#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
#define EVAL(v) cout << "l" << __LINE__ << ": " << #v << " = " << v << endl

int Puissance(int x, unsigned int n) {
	int result = 1;

	for (unsigned int i = 0; i < n; i++) {
		result = result * x;
	}

	return result;
}

int PuissanceRec(int x, unsigned int n) {
	return n == 0
		? 1
		: PuissanceRec(x, n-1) * x;
}

int main(int argc, char** argv) {
	EVAL(Puissance(2,2));
	EVAL(Puissance(1,5));

	EVAL(PuissanceRec(2,2));
	EVAL(PuissanceRec(1,5));

   return 0;
}