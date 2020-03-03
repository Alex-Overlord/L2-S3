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
  struct noeud* sag;
  struct noeud* sad;
} NoeudSC;
typedef NoeudSC* ArbreBin;

ArbreBin creerArbreBin(int e, ArbreBin G, ArbreBin D){
  /* Res : renvoie une ArbreBin dont la racine vaut e, le sag G et le sad D   */
  ArbreBin A = new NoeudSC;
  A->info=e;  A->sag=G;  A->sad=D;
  return A;}

bool appartient(ListeSC M, ArbreBin D){
  if (M==NULL and D==NULL){
    return false;
    if (M==NULL){
      return D->info;
    }
    else if (D==NULL){
      return false;
    }
    else if (M->info == 0){
      return appartient(M->succ, D->sag);
    }
    else if (M->info == 1){
      return appartient(M->succ, D->sad);
    }
  }
}

void supprimer(ListeSC M, ArbreBin D){
  if (D != NULL){
    if (M == NULL){
      D->info = false;
    }
    else if (M->info == 1){
      supprimer(M->succ, D->sag);
    }
    else{
      supprimer(M->succ, D->sad);
    }
  }
}

int main(){
  ListeSC M1, M2, M3, M4, M5, M6;
  ArbreBin D1;
  
  M1 = creerLSC(0,creerLSC(1,NULL));
  M2 = NULL;
  M3 = creerLSC(0,NULL);
  insererFinLSC(M3,1);
  M4 = creerLSC(0,NULL);
  M5 = creerLSC(1,NULL);
  
  D1 = creerArbreBin(true,
		     creerArbreBin(true,
				   creerArbreBin(true,NULL,NULL),
				   creerArbreBin(true,NULL,NULL)),
		     creerArbreBin(true,NULL,NULL));

  /*
  cout << boolalpha << appartient(M1,D1) << endl;
  cout << boolalpha << appartient(M2,D1) << endl;
  cout << boolalpha << appartient(M3,D1) << endl;
  cout << boolalpha << appartient(M4,D1) << endl;
  afficherLSC();
  cout << boolalpha << appartient(M5,D1) << endl;
  */

  M6 = lireLSC();
  afficherLSC(M6);
  cout << "Valeur de la racine " << (D1->sag)->info << endl;
  cout << "Valeur de la racine " << (D1->sad)->info << endl;
  supprimer(M6, D1);
  afficherLSC(M6);
  cout << "Valeur de la racine " << (D1->sag)->info << endl;
  cout << "Valeur de la racine " << (D1->sad)->info << endl;
  
  

  return 0;
}
