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