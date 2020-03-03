-- TP 4 -- Séance 5

-- personne(id, nom, prenom)
-- voiture(immat, marque, annee, prix, idProp) (prix > 0)

-- 1. Nombre total de personnes.
SELECT COUNT(*) FROM personne;

-- 2. Nombre de personnes dont le prénom est inconnu.
SELECT COUNT(*) FROM personne WHERE prenom IS NULL;

-- 3. Afficher le nombre de voitures par identifiant de propriétaire.
SELECT idProp, COUNT(*) FROM voiture GROUP BY idProp;

-- 4. Afficher le capital de chaque propriétaire désigné par son nom et son prénom.
SELECT nom, prenom, SUM(prix) AS capital FROM personne, voiture WHERE id = idProp GROUP BY nom, prenom, id;

-- 5. Afficher le prix moyen par marque.
SELECT marque, AVG(prix) FROM voiture GROUP BY marque;

-- 6. Afficher le nombre de voitures de plus de 20 000 euros pour chaque propriétaire désigné par son nom et prénom.
SELECT nom, prenom, COUNT(*) AS nombre_voitures FROM personne, voiture WHERE id = idProp AND prix > 20000 GROUP BY nom, prenom, id;

-- 7. Afficher le capital et l'identifiant des propriétaires dont le capital est supérieur à 50 000 euros.
SELECT idProp, SUM(prix) FROM voiture GROUP BY idProp HAVING SUM(prix) > 50000;

-- 8. Capital de chaque propriétaire par année (afficher l'identifiant du propriétaire, l'année et le capital).
SELECT idProp, annee, SUM(prix) FROM voiture GROUP BY idProp, annee;

-- 9. Idem, mais afficher le nom et le prénom à la place de l'identifiant.
SELECT nom, prenom, annee, SUM(prix) FROM voiture, personne WHERE id = idProp GROUP BY nom, prenom, annee;


--------------------------------------------------------------------------------------------
-- 1. Titre des films dont la fréquentation dépasse la moyenne.

SELECT titre FROM film WHERE nbSpectateurs > (SELECT AVG(nbSpectateurs) FROM film);

-- 2. Nom et prénom des réalisateurs dont au moins un film dépasse la fréquentation moyenne.

SELECT nom, prenom FROM film, realisateur WHERE idR = idRealisateur AND nbSpectateurs > (SELECT AVG(nbSpectateurs) FROM film);

-- 3. Nom et prénom des acteurs participant au film ayant eu le plus de succès.

SELECT nom, prenom FROM acteur, jouer, film WHERE idA = idActeur AND idF = idFilm AND nbSpectateurs = (SELECT MAX(nbSpectateurs) FROM film);

-- 4. Nom et prénom des acteurs n’ayant joué dans aucun film.

SELECT nom, prenom FROM acteur WHERE idA NOT IN (SELECT idActeur FROM jouer);

-- 5. Description des genres jamais utilisés.

SELECT DISTINCT description FROM genre WHERE description NOT IN (SELECT description FROM genre, film WHERE idG = idGenre);

-- 6. Nom et prénom des réalisateurs qui n’ont rien tourné depuis 2002.

SELECT nom, prenom FROM realisateur WHERE idR NOT IN (SELECT idRealisateur FROM film WHERE annee > 2002);

-- 7. Description des genres dont la fréquentation est toujours supérieure à 50000.

SELECT DISTINCT description FROM genre, film WHERE idG = idGenre AND nbSpectateurs > 50000;

-- 8. Description des genres dont la fréquentation est toujours supérieure à 50000 et dont les réalisateurs sont tous américains.

SELECT description FROM genre, film, realisateur WHERE idG = idGenre AND idR = idRealisateur AND nbSpectateurs > 50000 AND (nationalite = 'americaine');

SELECT description FROM genre, film WHERE idG = idGenre AND nbSpectateurs > 50000 AND idRealisateur IN (SELECT idR FROM realisateur WHERE nationalite = 'americaine');
