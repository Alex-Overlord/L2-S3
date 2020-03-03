#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import sys

### Afficher les n premiers nombres premiers

def estPremier(n) :
    b = True
    for i in range (2, n) :
        if n%i==0 :
            b = False
    return b

def nPremierNbrPremier(n) :
    li = []
    x = 2
    while n > 0 :
        if estPremier(x) :
            li.append(x)
            n-=1
        x+=1
    return li

print(nPremierNbrPremier(int(sys.argv[1])))
