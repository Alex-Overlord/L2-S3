#include <stdlib.h>
#include <stdio.h>
#include "p.h"
#include "i.h"

int impair(int i) {
  return i==0
    ? 0
    : pair(i-1);
}
int pair(int i) {
  return i==0
    ? 1
    : impair(i-1);
}

int main(int argc, char** argv)
{
  int n = atoi(argv[1]);

  if (n >= 0) {
    if (pair(n)) {
      printf("%d est pair\n", n);
    } else {
      printf("%d est impair\n", n);
    }
  }

  return 0;
}
