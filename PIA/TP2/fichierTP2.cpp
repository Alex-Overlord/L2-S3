#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "progListeSC.h"
using namespace std;

//  DERNIERLSC ET ESTTRIEELSC 
// Res : Renvoie l'adresse de la derniere cellule de la liste non vide L 
ListeSC dernierLSC(ListeSC L){
  assert(L != NULL);
  
  if (L->succ == NULL) {
    return L;
  } else {
    return dernierLSC(L->succ);
  }
  
  return L;
}

//   Res : Renvoie 1 si L est une ListeSC triee, 0 sinon 
bool estTrieeLSC_Croissant(ListeSC L){
  if (L == NULL or L->succ == NULL) {
    return true;
  }
  
  return (L->info <= (L->succ)->info) and (estTrieeLSC_Croissant(L->succ));
}
bool estTrieeLSC_Decroissant(ListeSC L){
  if (L == NULL or L->succ == NULL) {
    return true;
  }
  
  return (L->info >= (L->succ)->info) and (estTrieeLSC_Decroissant(L->succ));
}
bool estTrieeLSC(ListeSC L) {
  
  return estTrieeLSC_Croissant(L) or estTrieeLSC_Decroissant(L) ;
}


//  OTERREPETITION 
//    Res : Supprime de la ListeSC L tous les elements consecutifs egaux 
//          Opere en modifiant le chainage de la ListeSC L 
// version iterative 
void oterRepetitionLSC(ListeSC L) {
  ListeSC Q;
  
  while (L != NULL and L->succ != NULL) { // tant qu'il y a au moins 2 éléments
    Q = L->succ;
    while (Q != NULL and L->info == Q->info) { // tant qu'il y a 2 éléments consécutifs égaux
      L->succ = (L->succ)->succ;
      Q = Q->succ;
    }
    L = L->succ;
  }  
}

//    Res : Supprime de la ListeSC L tous les elements consecutifs egaux 
//          Opere en modifiant le chainage de la ListeSC L 
//    version recursive 
void oterRepetitionLSCR(ListeSC L){
  if (L != NULL and L->succ != NULL) { 
    while (L->succ != NULL and L->info == (L->succ)->info) {
      L->succ = (L->succ)->succ;
    }
    oterRepetitionLSCR(L->succ);
  }
}

//   CONCATENATION DE 2 LISTES  
//   Res : Modifie la liste L1 en la concatenant avec la liste l2 
//         Opere en modifiant le chainage de la listeSC L1 
//   Version utilisant la fonction dernierLSC 
void concatLSC(ListeSC& L1,ListeSC L2){
  ListeSC D = dernierLSC(L1);
  
  D->succ = L2;
}

//   Res : Renvoie la ListeSC obtenue par concatenation des ListeSC L1 et L2 
//         Opere en recopiant les elements des 2 listeSC L1 et L2 
//   complexite : ??? 
ListeSC concatLSCCopie(ListeSC L1,ListeSC L2){
  ListeSC L3 = NULL;
  
  while (L1 != NULL) {
    insererFinLSC(L3, L1->info);
    L1 = L1->succ;
  }
  while (L2 != NULL) {
    insererFinLSC(L3, L2->info);
    L2 = L2->succ;
  }
  
  return L3;
}

bool estListeIntervalle(ListeSC L) {
	return L == NULL or L->succ == NULL ? true
		: (L->succ)->info - L->info == 1 and estListeIntervalle(L->succ) ? true 
			: false;
}
// Complexité : O(n^2)
ListeSC creerListeIntervalle(int l, int p) {
	ListeSC li = creerLSC(p,NULL);
	while(l > 1) {
		insererFinLSC(li, p+1);
		l--;
		p++;
	}
	return li;
}

ListeSC creerListeIntervalle2(int l, int p) {
	ListeSC li = creerLSC(p+l-2,NULL);
	while (l > 1) {
		insererDebutLSC(li, p+l-1);
		l--;
	}
	return li;
}

int main(int argc, char *argv[]){
	// Exo 2
	// ListeSC l4 = creerListeIntervalle(3,4);
	// afficherLSC(l4);
	ListeSC l5 = creerListeIntervalle2(3,4);
	afficherLSC(l5);

	// Exo 1
	// ListeSC l1, l2, l3;
	// l1 = creerLSC(1,creerLSC(2,creerLSC(3,NULL)));
	// l2 = creerLSC(3,creerLSC(2,creerLSC(1,NULL)));
	// l3 = creerLSC(7,NULL);
	// afficherLSC(l1);
	// afficherLSC(l2);
	// afficherLSC(l3);
	// cout << estListeIntervalle(l1) << endl;
	// cout << estListeIntervalle(l2) << endl;
	// cout << estListeIntervalle(l3) << endl;

	/*
  ListeSC l1,l2,l3;
  int q, tmp;
  ListeSC p1, p2;
  
  cout << "Numero de la question traitee (1/2/3/4/5) ? ";
  cin >> q;
  switch (q){
  case 1 :  // Test des operations de base sur les listes 
    l1 = lireLSC();
    
    // insertion d'un element de valeur 11 en derniere position de la liste l1 
    // en utilisant insererFinLSC 
    // Completez
    insererFinLSC(l1,11);
    
    cout << "Insertion de 11 en derniere position "; afficherLSC(l1);
    
    // insertion d'un element de valeur 22 en 2eme position de la liste l1 
    // en utilisant insererApresLSC 
    // Completez
    insererApresLSC(l1,l1,22);
    
    cout << "Insertion de 22 en 2eme position ";afficherLSC(l1);
    
    // insertion d'un element de valeur 33 en 2eme position de la liste l1 
    // sans utiliser insererApresLSC 
    // Completez
    l1 = creerLSC(l1->info, creerLSC(33, l1->succ));
    
    cout << "Insertion de 33 en 2eme position ";afficherLSC(l1);
    
    // Suppression du 2eme element de la liste en utilisant supprimerLSC
    // Completez
    supprimerLSC(l1, l1->succ);

    cout << "Suppression du 2eme element "; afficherLSC(l1);
    
    // Suppression du 2eme element de la liste sans utiliser supprimerLSC
    // Completez
    l1 = creerLSC(l1->info, (l1->succ)->succ);

    cout << "Suppression du 2eme element "; afficherLSC(l1);
    
    // Inversion des valeurs des 2 premiers elements 
    // en modifiant les champs info (sans modifier le chainage)
    // Completez
    tmp = l1->info;
    l1->info = (l1->succ)->info;
    (l1->succ)->info = tmp;
 
    cout << "Inversion des valeurs des 2 premiers elements " ; afficherLSC(l1);
    
    // Inversion des 2 premiers elements 
    // en modifiant les champs succ (le chainage)
    // Completez l1 [1]     l1->succ [2]    (l1->succ)->succ [3] 
    p1 = l1;
    p2 = l1->succ;
    l1 = l1->succ;
    p1->succ = (p1->succ)->succ;
    p2->succ = p1;

    cout << "Inversion des 2 premiers elements "; afficherLSC(l1);
    break;
    
  case 2 : // Test des fonctions  estTrieeLSC et dernierLSC 
    l1 = lireLSC();
    if (estTrieeLSC(l1))  cout << "Cette liste est triee\n";
    else cout << "Cette liste n'est pas triee\n";
    if (l1 != NULL)
      cout << "La valeur de son dernier element est " << dernierLSC(l1)->info << endl;
    break;
    
  case 3: // Test des fonctions oterRepetitionLSC 
    l1 = lireLSC();
    oterRepetitionLSC(l1);
    cout << "Liste sans repetition (version iterative) :\n";
    afficherLSC(l1);
    l1 = lireLSC();
    oterRepetitionLSCR(l1);
    cout << "Liste sans repetition (version recursive) :\n";
    afficherLSC(l1);
    break;
    
  case 4 :  // Test de la premiere fonction  de concatenation de listes 
    l1 = lireLSC();
    l2 = lireLSC();
    concatLSC(l1,l2);
    cout << "Concatenation des 2 listes (en modifiant le chainage) :\n"; afficherLSC(l1);
    if ((l1 != NULL) && (l2 != NULL) )
      cout << "Adresse derniere cellule de l1 : " << (void *) dernierLSC(l1) << ", de l2 : "<< (void *) dernierLSC(l2) << endl;
    cout << " Ajout de 44 en fin de la liste l1\n";
    insererFinLSC(l1,44);
    cout << "Nouvelle valeur de l1:"; afficherLSC(l1); cout << endl;
    cout << "Nouvelle valeur de l2: "; afficherLSC(l2); cout << endl;
    break;
    
  case 5 :  // Test des fonctions  de concatenation de listes 
    l1 = lireLSC();
    l2 = lireLSC();
    l3 = concatLSCCopie(l1,l2);
    cout << "Concatenation des 2 listes (par recopie des listes) : "; afficherLSC(l3); cout << endl;
    if ((l1 != NULL) && (l2 != NULL) )
      cout << "Adresse derniere cellule de l1 : " << (void *) dernierLSC(l1) << " , de l2 : "  << (void *) dernierLSC(l2) << ", de l3 : " << (void *) dernierLSC(l3) << endl;
    cout << " Ajout de 55 en fin de la liste l1\n";
    insererFinLSC(l1,55);
    cout << "Nouvelle valeur de l1: "; afficherLSC(l1);  cout << endl;
    cout << "Nouvelle valeur de l2: "; afficherLSC(l2); cout << endl;
    cout << "Nouvelle valeur de l3: "; afficherLSC(l3); cout << endl;
    break;
  }
  */
  return 0;
}
