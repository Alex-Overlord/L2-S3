#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv, char** env)
{
  float moy = 0;
  for(int i=2; i<argc; i++){
    moy += atoi(argv[i]);
  }
  moy /= argc-2;

  printf("La moyenne des %d nombres flottants est : %f \n"
	 , argc-2, moy);
    
  return 0;
}
