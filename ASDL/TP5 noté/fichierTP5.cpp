#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
//#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "progListeSC.h"
#include "fichierTP5.h"

using namespace std;


Dico creerDico(bool b, Dico G, Dico D){
  /* Res : renvoie une Dico dont la racine vaut e, le sag G et le sad D   */
  Dico A = new NoeudSC;
  A->info=b;  A->sag=G;  A->sad=D;
  return A;}

void codageABdot(ofstream& fichier, Dico A){
  if (A != NULL){ 
    fichier << (long) A << " [label=\""  << (A->info?"true":"false") << "\" ] ;\n";
    if (A->sag != NULL) {
      fichier << (long)A << " -> " << (long)(A->sag) <<  " [color=\"red\",label=\"0\" ] ;\n";
      codageABdot(fichier,A->sag);} 
    if (A->sad != NULL) {
      fichier << (long)A << " -> " << (long)(A->sad) << " [color=\"blue\",label=\"1\" ] ;\n";
      codageABdot(fichier,A->sad);}
  }
  return;}


void dessinerAB(Dico A, const char * nomFic, string titre){
  ofstream f(nomFic);
  if (!f.is_open()){
   cout << "Impossible d'ouvrir le fichier en écriture !" << endl;
  }
  else {
    f<< "digraph G {   label = \""<< titre << "\" \n";
    f<< "graph [ fontname=""fixed"", fontsize = 20];";
    f<< "node [ fontname=""fixed"", fontsize = 20];";
    f<< "edge [ fontname=""fixed"", fontsize = 20];";
    codageABdot(f,A);
    f << "\n }\n" ;
    f.close();}
  return;}


/* A COMPLETER */
int nbMots(Dico A){
  // renvoie le nombre de mots du dictionnaire A 
  /* A MODIFIER  */
  if (A == NULL){
    return 0;
  }
  else if (A->info == false){
    return nbMots(A->sag) + nbMots(A->sad);
  }
  else if (A->info == true){
    return 1 + nbMots(A->sag) + nbMots(A->sad);
  }
  return 0;
}


bool appMot(Dico D, ListeSC L){
  // teste si le mot L appartient au dictionnaire D
  /* A MODIFIER  */
  if (L == NULL and D == NULL){
    return false;
    if (L == NULL){
      return D->info;
    }
    else if (D == NULL){
      return false;
    }
    else if (L->info == 0){
      return appMot(D->sag, L->succ);
    }
    else if (L->info == 1){
      return appMot(D->sad, L->succ);
    }
  }
}

void ajouterMot(Dico &A,ListeSC L){
  // ajoute le mot L au dictionnaire A
  /* A MODIFIER  */
  if (A == NULL){
    A = creerDico(false, NULL, NULL);
  }
  if (L == NULL){
    A->info = true;
  }
  else if (L->info == 0){
    ajouterMot(A->sag, L->succ);
  }
  else{
    ajouterMot(A->sad, L->succ);
  }
}

void supprimerMot(Dico &A,ListeSC L){
  // supprime le mot L du dictionnaire A
  /* A MODIFIER  */
  if (A != NULL){
    if (L == NULL){
      A->info = false;
    }
    else if (L->info == 0){
      supprimerMot(A->sag, L->succ);
    }
    else{
      supprimerMot(A->sad, L->succ);
    }
  }
}

int lgMin(Dico A){
  // A un un arbre dictionnaire contenant au moins un mot
  // renvoie la longueur du plus petit mot du dictionnaire A
  //assert(nbMots(A)>0);
  /* A MODIFIER  */
  if (A != NULL){
    if (A->info == true){
      return 1 + min(lgMin(A->sag), lgMin(A->sad));
    } else {
      return 0 + min(lgMin(A->sag), lgMin(A->sad));
    }
  }
}

bool contientPrefixe(Dico A){
  // Renvoie true si le dictionnaire contient au moins un mot et l'un de ses préfixes, renvoie false sinon
  /* A MODIFIER  */
  
  if (A == NULL){
    return false;
  }
  else if (A->info == true){
    return true and (contientPrefixe(A->sag) or contientPrefixe(A->sad));
  }
  else {
    return contientPrefixe(A->sag) or contientPrefixe(A->sad);
  }
  
}

ListeSC motMin(Dico A){
  // A un Dictionnaire non vide
  // Renvoie le plus petit mot du dictionnaire dans l'ordre lexicographique (du dictionnaire)
  assert(nbMots(A)>0);
  /* A MODIFIER  */
  if (A != NULL){
    if (A->info == true){
      return NULL;
    }
    else {      
      if (lgMin(A->sag) < lgMin(A->sad)) {
	return creerLSC(0, motMin(A->sag));
      }
      else {
	return creerLSC(1, motMin(A->sad));
      }
    }
  }
  return NULL;
}

