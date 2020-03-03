#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import sys

### Calcule en itératif la factorielle de n
def fact(n) :
    f = 1
    for i in range (1,n+1) :
        f = f*i
    return f

print(fact(int(sys.argv[1])))

### Calcule en récursif la factorielle de n
def fact(n) :
    if n == 0 :
        return 1
    return n * fact(n-1)
print(fact(int(sys.argv[1])))
