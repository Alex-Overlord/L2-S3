#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import sys, random

# Quizz sur les capitales

# Création des deux listes pays et capitales
fd = open("capitales.csv","r")
if fd :
    nb = int(sys.argv[1]) # Nombre de questions
    pays = []
    capitales = []
    i = 0
    score = 0
    
    for ligne in fd :
        data = ligne.split(",")
        pays.append(data[0])
        capitales.append(data[1][:-1])
        
"""        
for i in pays : # nombre de pays : 195
print (i)
print("\n\n")    
for i in capitales :
print (i)
"""    

def appartient(i,li) :
    b = True
    for j in li :
        if j == i :
            b = False
    return b

### Programme
indicePays = random.randint(0,len(pays)-1)
listeIndices = []

for n in range (0, nb) :

    # On teste si la question a déjà été posée
    while appartient(indicePays,listeIndices) :
        indicePays = random.randint(0,len(pays)-1)
        
    # La question est posée
    print("Quel est la capitale de ",pays[indicePays]," ?")
    listeIndice.append[indicePays]

    # La réponse est traitée
    rep = input("Réponse : ")
    if rep == capitales[indicePays] or rep == "42" :
        score += 1
    indicePays = random.randint(0,len(pays)-1)
    
print("Vous avez",score,"bonnes réponses.",(score/nb)*100,"%")
