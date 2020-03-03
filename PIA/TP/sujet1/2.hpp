// Prend la copie de deux variables et retourne le minimum.
int mini1(int a, int b) { return a<b ? a : b; }

// Prend l'adresse de deux variables, 
// compare les deux variables via leur valeur et retourne le minimum.
int mini2(int &a, int &b) { return a<b ? a : b; }

// Prend l'adresse de deux variables,
// compare les deux variables via leur valeur et retourne l'adresse du minimum.
int& mini3(int &a, int &b) { return a<b ? a : b; }