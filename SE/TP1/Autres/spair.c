#include <stdlib.h>
#include <stdio.h>
#include "p.h"
#include "i.h"

int main(int argc, char** argv)
{
  int n = atoi(argv[2]);

  if (n >= 0) {
    if (pair(n)) {
      printf("%d est pair\n", n);
    } else {
      printf("%d est impair\n", n);
    }
  }
  
  return;
}
