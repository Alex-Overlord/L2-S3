-- TP 3 -- Séance 4

-- acteur(idA, nom, prenom, nationalite)
-- film(idF, titre, annee, pays, nbSpectateurs, idRealisateur, idGenre)
-- jouer(idActeur, idFilm, salaire)
-- realisateur(idR, nom prénom, nationalite)
-- genre(idG, description)

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
