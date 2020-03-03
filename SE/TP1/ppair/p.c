#include <stdlib.h>
#include <stdio.h>
#include "p.h"
#include "i.h"

int pair(size_t i) {
  return i==0
    ? 1
    : impair(i-1);
}
