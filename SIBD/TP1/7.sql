-- 7 - Requêtes de consultation

-- 1. Les acteurs ayant joué dans les comédies ou des films policiers :

SELECT nom, prenom
       FROM acteur, genre, film, jouer
       WHERE idA = idActeur AND idG = idGenre AND idF = idFilm
       AND (description = 'comedie' OR description = 'policier');

-- 2. Les films tournés par Daroussin depuis 2000 :

SELECT titre
       FROM film, realisateur
       WHERE idF = idFilm
       AND nom = 'Daroussin' AND annee >= 2000;

-- 3. Les couples (réalisateurs, acteurs) par ordre réalisateurs, acteurs :

SELECT DISTINCT realisateur.nom, realisateur.prenom, acteur.nom, acteur.prenom
       FROM realisateur, acteur, jouer, film
       WHERE idR = idRealisateur AND idA = idActeur AND idF = idFilm 
       GROUP BY realisateur.nom, realisateur.prenom, acteur.nom, acteur.prenom;

-- 4. Les genres des films dans lesquels a joué Al Pacino :

SELECT description
       FROM genre, acteur, jouer, film
       WHERE idG = idGenre AND idA = idActeur AND idF = idFilm
       AND nom = 'Al Pacino';

-- 5. Les réalisateurs de comédies musicales par ordre chonologique :

SELECT nom, prenom
       FROM realisateur, film, genre
       WHERE idR = idRealisateur AND idG = idGenre
       AND description = 'comedie musicale'
       GROUP BY nom, prenom, annee;
