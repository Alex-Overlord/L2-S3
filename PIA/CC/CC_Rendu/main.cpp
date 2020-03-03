using namespace std;
#include <iostream>
#include "livre.h"

int main (){
  Livre L1("titre1","auteur1",2001);
  Livre L2("titre2","auteur2",2002);
  Livre L3("titre3","auteur3",2003);
  Livre L4("titre4","auteur4",2004);
  Livre L5("titre5","auteur5",2005);
  Livre L6("titre6","auteur6",2006);

  L6.setSucc(&L5);
  L5.setSucc(&L4);
  L4.setSucc(&L3);
  L3.setSucc(&L2);
  L2.setSucc(&L1);
  
  
  return 0;
}
