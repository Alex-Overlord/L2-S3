#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "progListeSC.h"
#include "fichierTP3.h"
using namespace std;

bool estTrieeLSC(ListeSC L){
  //   Res : Renvoie true si L est une ListeSC triée, false sinon 

  if (estVideLSC(L) || estVideLSC(L->succ))
    return true;
  else
    return (L->info < (L->succ)->info) &&  estTrieeLSC(L->succ);
}

bool estListeIntervalle(ListeSC L){ // exo 1
  //   Res : renvoie true si L est une Liste intervalle, renvoie false sinon 
  // A COMPLETER
  return L == NULL or L->succ == NULL ? true
    : (L->succ)->info - L->info == 1 and estListeIntervalle(L->succ) ? true 
      : false;
}

ListeSC consListeIntervalle1(int l, int p){
  //     Donnée : l>0 
  //     Res : renvoie une liste intervalle de longueur l et dont le premier élément a pour valeur p 
  //     Complexité : O(n^2) 
  assert(l>0);
  
  int i; ListeSC L;
  L=NULL;
  for(i=0;i<l;i++)    
    insererFinLSC(L,p+i);
  return L;
}

ListeSC consListeIntervalle2(int l, int p){ // exo 2.a
  //     Donnée : l>0 
  //     Res : renvoie une liste intervalle de longueur l et dont le premier élément a pour valeur p 
  //     Complexité : O(n)
  //     Version non récursive
  assert(l>0); 
  // A COMPLETER
  l--;
  ListeSC li = creerLSC(p+l,NULL);
  while (l > 0) {
    insererDebutLSC(li, p+(--l));
  }
  return li;
}

ListeSC consListeIntervalle3(int l, int p){ // exo 2.b
  //     Donnée : l>0 
  //     Res : renvoie une liste intervalle de longueur l et dont le premier élément a pour valeur p 
  //     Complexité : O(n)
  //     Version récursive
  assert(l>=0);
  if (l == 0) {
    return NULL;
  } else {
    ListeSC L = NULL;
    L = creerLSC(p, NULL);
    L->succ = consListeIntervalle3(l-1, p+1);
    return L;
  }
}

// Temps de construction d'une liste intervalle de taille 50000 :
// avec consListeIntervalle1 : 8.25266 sec
// avec consListeIntervalle2 : 0.001431 sec
// avec consListeIntervalle3 : 0.001802 sec

void transfListeIntervalle(ListeSC L){
  //     Donnée : L est une liste triée non vide  
  //     Res : modifie L en y inserant des éléments de sorte qu'elle soit une Liste Intervalle
  //     Complexité : ???? 
  assert((L!=NULL));
  assert(estTrieeLSC(L));
  // A COMPLETER

  while (L->succ != NULL and (L->succ)->info - L->info == 1) {
    transfListeIntervalle(L->succ);
  }
  while (L->succ != NULL and (L->succ)->info - L->info  != 1) {
    insererDebutLSC(L->info, )
  }

  return;
}

ListeSC intersectionListesIntervalles(ListeSC l1, ListeSC l2){
  //     Donnée : l1 et l2 2 listes intervalles
  //     Res : Renvoie l'intersection de l1 et l2; les éléments de la liste résultat sont recopiés
  //     Complexité : ????
  assert(estListeIntervalle(l1));
  assert(estListeIntervalle(l2));
  // A COMPLETER
  ListeSC l3 = NULL;
  while (l1->info < l2->info) {
    l1 = l1->succ;
  }
  while (l2->info < l1->info) {
    l2 = l2->succ;
  }
  while (l2->info == l1->info) {
    insererDebutLSC(l3, l1->info);
    l1 = l1->succ;
    l2 = l2->succ;
  }
  return NULL;
}
  
void plusLgSsLiInterv(ListeSC &L){
  //     Donnée : L liste
  //     Res : L est modifiee, elle est la plus longue sous-liste intervalle de la liste en entrée
  //     Complexité : ????
  // A COMPLETER
}





