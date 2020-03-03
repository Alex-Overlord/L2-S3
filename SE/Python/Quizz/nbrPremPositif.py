#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import sys

### Affiche les nombres premiers contenus dans les n premiers entiers positifs

def estPremier(n) :
    b = True
    for i in range (2, n) :
        if n%i==0 :
            b = False
    return b
        

def nbrPremPositif(n) :
    li = []
    for x in range (2, n+1) :
        if estPremier(x) :
            li.append(x)
    return li

print(nbrPremPositif(int(sys.argv[1])))
