#!/usr/bin/env python3
# -*- coding: utf-8 -*-

''' 
	Parcours récursif du SF
- Faire tourner la fonction récursive (afficher juste les noms des répertoires)
- Extraire l'extension des fichiers et l'afficher
- Mettre en place la mémorisation dans un dictionnaire
	-> initialisé à vide hormis l'entrée (la clef) 'sans extension'
'''

import os, sys, re

if len(sys.argv) != 2 :
	print("Le script doit avoir un paramètre :")
	print("Par exemple pour le répertoire toto : ./comptages.py toto")
	exit()

dict_ext = {}
def parcours(rep) :
    ext = ""
    sum_ext = 0
    # print("-> "+rep)
    list_dir = os.listdir(rep)
    for f in list_dir :
        if os.path.isdir(rep+'/'+f):
            parcours(rep+'/'+f)
            # print(rep+'/'+f)
        else :
        	# print(rep+'/'+f)
        	ext = re.findall(".+\.(.+)", f)
        	if ext[0] in dict_ext :
        		dict_ext[ext[0]] += 1
        	else :
        		dict_ext[ext[0]] = 1
        	sum_ext += 1
    # for e in dict_ext :
    # 	print('.'+e, " : ", dict_ext[e])
    dict_ext["Total : "] = sum_ext
    return dict_ext

        	# if ext : 
        	# 	print('.'+ext.group(1))# in dict_ext :
  	      		# dict_ext.append(ext)# dict_ext[ext]
        	# else :
        		# dict_ext[ext] = 1 # dict_ext.append(re.search(".\.([^.]+)$", f)
    # print(dict_ext)


# dict_ext = {}
# def parcours(rep) :
# 	print(rep)
# 	list_dir = os.listdir(rep)
# 	for f in list_dir :
# 		if os.path.isdir(rep+'/'+f) : 
# 			parcours(f)
# 		else :
# 			print("c'est un fichier")
# 			# Vous devez extraire l'extension
# 			# et avoir ne variable ext
# 			if ext in dict_ext and os.access(rep+"/"+f, os.X_OK):
				
# 			#else :
# 				#dict_ext[ext] = 1		

# def parcours (rep) :
# 	print("Je suis dans "+rep)
# 	liste_dir = os.listdir(rep)
# 	liste_ext = [] #re.findall("\.([^.]+)", liste_dir)
# 	for fichier in liste_dir :		
# 		if os.path.isfile(rep) : # .f+"/"+f
# 			liste_ext.append(re.search(".\.([^.]+)$", fichier)
# 		if os.path.isdir(rep) : # .f+"/"+f
# 			parcours(fichier)

### Main 
print(parcours(sys.argv[1])) # Appel initial de la fonction récursive


