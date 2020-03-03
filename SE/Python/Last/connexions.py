#!/usr/bin/env python3
# -*- coding: utf-8 -*-

### Reporting de la commande last
'''
- Récupérer le résultat de la commande last dans le script.
- Extraire le login et l'afficher.
- Etendre la reg_exp pour extraire la date et l'afficher
- Etendre la reg_exp pour extraire (calculer) le temps de connexion.
- Créez le dico de nombre de connexions, 
puis le dicos de nombre de connexions par dates

last = os.popen("last")
for ligne in last :
	print(ligne)

connexions = {}
---------------------------
connexions[login] = {}
connexions[login][date] = 1
---------------------------
connexions[login][date] = [1, tps]

---- Version final -----
if login in connexions :
	if date in connexions[login]:
		...
	else : # date inconnue pour le login
else : # login pas connu
	connexions[login] = {}
	connexions[login][date] = [1, tps]
------------------------
'''	
# for ligne in last :
# 	print(ligne, end = '')

import sys, os, re

connexions = {}
dico_date = {}
login = ""
date = ""
heures = ""
minutes = ""
last = os.popen("last")

for ligne in last :

	res = re.search("^([^ ]+)", ligne) # récupère le login
	if res :
		login = res.group(1)
		print("Login :", login, " ", end='')

		if login != "reboot" and login != "wtmp" :
			if login not in connexions :
				connexions[login] = dico_date
			#else :
			#	connexions[login] = 1

			res = re.search(".+([A-Z][a-z]+ +[0-9]+)", ligne) # récupère la date
			if res :
				date = res.group(1)
				print("Date :", date, " ", end='')
				if date in connexions[login] :
					connexions[login] = date
				# if date in connexions[login]:
				# 	# ...
				# else : # date inconnue pour le login
				# connexions[login] = {}
				# connexions[login][date] = [1, tps]

			res = re.search(".+\(([0-9][0-9])", ligne) # récupère le nombre d'heures
			if res :
				heures = res.group(1)
				print("Heures :", heures, " ", end='')

			res = re.search("[0-9]\:([0-9][0-9])\)", ligne) # récupère le nombre de minutes
			if res :
				minutes = res.group(1)
				print("Minutes :", minutes, " ")

print(connexions)