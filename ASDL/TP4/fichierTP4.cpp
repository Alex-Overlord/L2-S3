#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
//#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "progListeSC.h"
using namespace std;

typedef struct noeud {
  int info;
  struct noeud *sag;
  struct noeud *sad;} NoeudSC;
typedef NoeudSC *ArbreBin;

ArbreBin creerArbreBin(int e, ArbreBin G, ArbreBin D){
  /* Res : renvoie une ArbreBin dont la racine vaut e, le sag G et le sad D   */
  ArbreBin A = new NoeudSC;
  A->info=e;  A->sag=G;  A->sad=D;
  return A;}
  
void codageABdot(ofstream& fichier, ArbreBin A){
  if (A != NULL){ 
    fichier << (long) A << " [label=\""  << A->info << "\" ] ;\n";
    if (A->sag != NULL) {
      fichier << (long)A << " -> " << (long)(A->sag) <<  " [color=\"red\",label=\"g\" ] ;\n";
      codageABdot(fichier,A->sag);} 
    if (A->sad != NULL) {
      fichier << (long)A << " -> " << (long)(A->sad) << " [color=\"blue\",label=\"d\" ] ;\n";
      codageABdot(fichier,A->sad);}
  }
  return;}
    

void dessinerAB(ArbreBin A, const char * nomFic, string titre){
  ofstream f(nomFic);
  if (!f.is_open()){
    cout << "Impossible d'ouvrir le fichier en écriture !" << endl;
  }
  else {
    f<< "digraph G { label = \""<< titre << "\" \n";
    codageABdot(f,A);
    f << "\n }\n" ;
    f.close();}
  return;}


/* A COMPLETER */
int sommeNoeuds(ArbreBin A){
  /* renvoie la somme des etiquettes des noeuds de l arbre binaire A */
  /* A COMPLETER */
  return A == NULL ? 0 : A->info + sommeNoeuds(A->sag) + sommeNoeuds(A->sad);}

int profMinFeuille(ArbreBin A){
  /* renvoie la profondeur minimum des feuilles de l'arbre A ; A est non vide */
  assert(A!=NULL);
  /* A COMPLETER */
  return A->sag == NULL and A->sad == NULL ? 0 
    : 1 + min(profMinFeuille(A->sag), profMinFeuille(A->sad));}
    
ListeSC parcoursInfixe(ArbreBin A){
  /* renvoie la liste composee des etiquettes des noeuds de l'arbre A ordonnée
     selon l'ordre infixe */
  /* A COMPLETER */
  ListeSC L;
  if (A == NULL){
    return NULL;
  } else {
    L = parcoursInfixe(A->sag);
    insererFinLSC(L, A->info);
    concatLSC(L, parcoursInfixe(A->sad));
  }
  return L;}

void effeuiller(ArbreBin& A){
  /* modifie l'arbre A en supprimant ses feuilles */
  /* A COMPLETER */
  if (A == NULL){}
  else if (A->sag == NULL and A->sad == NULL){
    A = NULL;
  } else {
    effeuiller(A->sag);
    effeuiller(A->sad);
  }
  return;}

void tailler(ArbreBin& A, int p){
  /* modifie l'arbre A, en supprimant ses noeuds de profondeur au moins p ; p est un entier positif ou nul */
  /* A COMPLETER */
  if (A == NULL){}
  else if (p == 0) {
    A = NULL;
  }
  else {
    tailler(A->sag, p-1);
    tailler(A->sad, p-1);
  }
  return;}

void tronconner(ArbreBin& A){
  /* modifie l'arbre A, en supprimant les noeuds dont un seul sous-arbre est vide */
  /* A COMPLETER */
  if (A != NULL){
    if ((A->sag == NULL) xor (A->sad == NULL)){
      A = NULL;
    } else {
      tronconner(A->sag);
      tronconner(A->sad);
    }
  }
  return;}

ArbreBin genereAB(int n){
  /* A COMPLETER */
  ArbreBin A = NULL;
  if (n == 1){
    A = creerArbreBin(n,NULL,NULL);
  } else {
    A = creerArbreBin(n, genereAB(n-n/2), genereAB(n/2));
  }
  return A;}

bool estFeuille(ArbreBin A){
  return A != NULL and A->sag == NULL and A->sad == NULL;
}

bool estParfait(ArbreBin A){
  // Vérifie si A est un arbre binaire parfait
  // if (A != NULL){
  // 	if (A->sag == NULL and A->sad == NULL){

  // 	}
  // }

  return A != NULL // si non vide
    ? (A->sag != NULL) and (A->sad == NULL) // si n'a qu'un fils
    ? false
    : estFeuille(A->sag) != estFeuille(A->sad) // si l'un est uen feuille et pas l'autre
    ? false
    : estParfait(A->sag) and estParfait(A->sad) 
    : true;
}

/*****************************************************************************/
/*                                                                           */
/*                              main                                         */
/*                                                                           */
/*****************************************************************************/
int main(int argc, char *argv[]){
  int q,i;
  ArbreBin A,B,C;
  ostringstream stre;
  ListeSC L;
  string  chaine;
  A=creerArbreBin(8,
		  creerArbreBin(7,
				creerArbreBin(4,NULL,NULL),
				creerArbreBin(9,NULL,NULL)),
		  creerArbreBin(3,NULL,NULL));

  B=creerArbreBin(8,
		  creerArbreBin(2,
				creerArbreBin(4,NULL,NULL),
				creerArbreBin(9,
					      NULL,
					      creerArbreBin(1,
							    NULL,
							    creerArbreBin(7,
									  creerArbreBin(11,NULL,NULL),
									  creerArbreBin(5, 
											NULL,
											NULL))))),
		  creerArbreBin(3,
				creerArbreBin(12,
					      creerArbreBin(6,NULL,NULL),
					      NULL),
				creerArbreBin(9,NULL,NULL)));
  C=NULL;
  C= creerArbreBin(1,C,C);
  cout << "Numero de la question traitee (1/2/3/4/5/6/7) ? ";
  cin >> q;
  switch (q){
  case 1 :
    dessinerAB(A,"arbre.dot","Arbre Bin");
    cout << "Somme des noeuds de l'arbre :"<< sommeNoeuds(A) << endl;
    cout << "Profondeur minimum des feuilles de l'arbre : " << profMinFeuille(A) << endl;
    system("dotty arbre.dot");
    break;
  case 2 :
    dessinerAB(A,"arbre.dot","Arbre Bin");    
    L=parcoursInfixe(A);
    cout << "Liste des noeuds de l'arbre en ordre infixe : ";
    afficherLSC(L);
    system("dotty arbre.dot");
    break;
  case 3 :
    dessinerAB(B,"arbre.dot","Arbre Bin");
    system("dotty arbre.dot&");
    effeuiller(B);
    dessinerAB(B,"arbre2.dot","Arbre Bin effeuille");
    system("dotty arbre2.dot");
    break;
  case 4 :
    dessinerAB(B,"arbre.dot","Arbre Bin");
    system("dotty arbre.dot&");
    cout << " Donner une profondeur (entier positif) :";
    cin >> i;
    tailler(B,i);
    stre << i;
    chaine = stre.str();
    chaine = "Arbre Bin taille a la profondeur " + chaine;
    dessinerAB(B,"arbre2.dot",chaine);
    system("dotty arbre2.dot&");
    break;
  case 5 :
    cout << " Donner un entier positif :";
    cin >> i;
    stre << i;
    chaine = "Arbre Bin  " + stre.str();
    dessinerAB(genereAB(i),"arbre.dot", "Arbre Bin  " + stre.str());
    system("dotty arbre.dot&");
    break;
  case 6 :
    dessinerAB(B,"arbre.dot","Arbre Bin");
    system("dotty arbre.dot&");
    tronconner(B);
    dessinerAB(B,"arbre2.dot","Arbre tronconne");
    system("dotty arbre2.dot&");
    break;
  case 7 :
    A=genereAB(7);
    chaine= estParfait(A) ? "Arbre parfait" : "Arbre non parfait";
    dessinerAB(A,"arbre.dot",chaine);
    system("dotty arbre.dot");

    B=genereAB(8);
    chaine= estParfait(B) ? "Arbre parfait" : "Arbre non parfait";
    dessinerAB(B,"arbre2.dot",chaine);
    system("dotty arbre2.dot&");
    break;
  }
  return 0;
}
