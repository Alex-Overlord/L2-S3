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