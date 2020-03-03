#include <iostream>
#include <fstream>
#include <stdlib.h>  // pour rand
#include <assert.h>
#include "outilsTab6.h"

using namespace std;

int* copieTab(int* T, int t){
  int* Tc;
  Tc=new int[t];
  for( int i=0;i<t;i++)Tc[i]=T[i];
  return Tc;
}

int* genTab(int n){
  int* T; 
  T=new int[n];
  for (int i=0;i<n;i++) T[i]=rand()%10;
  return T;
}

void afficheTab(int* T,	int taille){
  cout << "\n[ ";
  for (int i=0;i<taille;i++) cout << T[i] << " ";
  cout << "]\n";
}

void echanger(int& a, int& b){int aux=a; a=b; b=aux; return;}

void fichierTemps(const char *  nomFic, int tMaxTab, int pas, void (*fTri)(int*,int))
{
  int taille;
  int* Tab;
  clock_t t1, t2;    
  ofstream fichier(nomFic,ios::out);

  if (fichier)
    {
      for (taille=pas; taille<=tMaxTab; taille=taille+pas){
	Tab=genTab(taille);
	t1=clock();
	(*fTri)(Tab,taille);
	t2=clock();
	fichier << taille <<" "<< (double)(t2-t1)/ CLOCKS_PER_SEC << endl;
      }
      fichier.close();
    }
  else cerr << " Problème ouverture fichier"<< endl;

  return ;
}

/* ********************** Les Tris *********************** */

/* Tri par insertion */
void triInsertion(int* T, int taille) { /* A COMPLETER */
  /*
    int i = taille, j, x;
    x = T[i];
    j = i-1;
    while (j>=0 and T[j]>x) {
    T[j+1] = T[j];
    j = j-1;
    }
    T[j+1] = x; 
  */
  int x = 0, j = 0;
  for (int i=1 ; i<=taille-1 ; i++) {
    x = T[i]; // mémoriser T[i] dans x
    j = i; // décaler vers la droite les éléments de T[0]..T[i-1] qui sont plus grands que x (en partant de T[i-1]) 
    while (j>0 and T[j-1]>x) {
      T[j] = T[j-1];
      j = j-1;
    } // placer x dans le "trou" que ça a laissé
    T[j] = x;
  }
}

/* Tri par Sélection */
void triSelection(int* T, int taille) { /* A COMPLETER */
  int min, tmp;
  for (int i=0 ; i<=taille-1 ; i++) {
    min = i;
    for (int j=i+1 ; j<=taille ; j++) {
      if (T[j]<T[min]) {
	min = j;
      }
    }
    if (min != i) {
      tmp = T[i];
      T[i] = T[min];
      T[min] = tmp;
    }
  }  
}

/* Tri par Tas */
int filsMax(int* T, int i, int iMax)
{
  if ((i*2+2>iMax) || (T[2*i+1]>T[2*i+2])) return 2*i+1;
  else return 2*i+2;
}
void triParTas(int* T, int taille)
{
  int i,j,k; 
  for (i=1;i<taille;i++){
    j=i;
    while(j>0 && T[(j-1)/2]<T[j]){
      echanger(T[j],T[(j-1)/2]);
      j=(j-1)/2;}}
  for (i=taille-1;i>0;i--){
    echanger(T[0],T[i]);
    j=0;
    while( (2*j+1<i) && T[filsMax(T,j,i-1)]>T[j]){
      k=filsMax(T,j,i-1);
      echanger(T[j],T[k]);
      j=k;} }
  return;
}


/*
void tri_rapide (int *tableau, int taille) {
  int mur, courant, pivot, tmp;
  if (taille < 2) return;
  // On prend comme pivot l element le plus a droite
  pivot = tableau[taille - 1];
  mur  = courant = 0;
  while (courant<taille) {
    if (tableau[courant] <= pivot) {
      if (mur != courant) {
	tmp=tableau[courant];
	tableau[courant]=tableau[mur];
	tableau[mur]=tmp;              
      }
      mur ++;
    }
    courant ++;
  }
  tri_rapide(tableau, mur - 1);
  tri_rapide(tableau + mur - 1, taille - mur + 1);
}
*/


/* Tri Rapide */
/* trie le sous-tableau T[g..d] selon le tri rapide */
void triRapInd1(int* T, int deb, int fin) { /* A COMPLETER */
  int pivot = T[deb], pos = deb;
  if (deb >= fin) { return; }
  for (int i=deb ; i<=fin ; i++) {
    if (T[i] < pivot) {
      T[pos] = T[i];
      pos++;
      T[i] = T[pos];
      T[pos] = pivot;
    }
  }
  triRapInd1(T, deb, pos);
  triRapInd1(T, pos+1, fin);
}

void triRapide1(int* T, int taille)
{
  triRapInd1(T,0,taille-1);
  return;
}

/* tri par Fusion */
void triFusionBis(int* T, int g, int d)
/* trie le sous-tableau T[g..d] par fusion */
{
  /* A COMPLETER */
  
  return;
}
void triFusion(int* T, int taille)
{
  triFusionBis(T,0,taille-1);
  return;
}

/* Nombre de valeurs différentes dans un tableau */
int nbValDiff(int T[], int taille)
// Complexité : ?????
{
  /* A COMPLETER */

  return 0;
}
