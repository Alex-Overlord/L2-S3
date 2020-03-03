#include <stdlib.h>
#include <stdio.h>
#include "i.h"
#include "p.h"

int impair(unsigned int i) {
  return i==0
    ? 0
    : pair(i-1);
}
