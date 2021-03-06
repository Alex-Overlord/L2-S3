-- ALTER SESSION SET NLS_DATE_FORMAT = 'DD/MM/YY';
-- exemple: SELECT TO_CHAR(dateNaiss, 'DD') FROM personnes;


-- TP 2 -- Séance 3
-- Exercice 1

-- 1. Le nombre de films qui ont été tournés chaque année :

SELECT annee, COUNT(*) AS nbFilms
       FROM film
       GROUP BY annee;


-- 2. Pour chaque année, le nombre maximum de spectateurs qui ont vu un film :

SELECT annee, MAX(nbSpectateurs) AS maxNbSpectateurs
       FROM film
       GROUP BY annee;

-- 3. Depuis 1990, le nombre de films par année :

SELECT annee, COUNT(*) AS nbFilms
       FROM film
       WHERE annee >= 1990
       GROUP BY annee;


-- 4. Pour chaque année, afficher le nombre de films pour les années où chacun des films a eu plus de 1000000 spectateurs :

SELECT F1.annee, COUNT(*) AS nbFilms
       FROM film F1
       WHERE F1.nbSpectateurs ANY NOT IN
       	     (SELECT F2.nbSpectateurs FROM film F2 WHERE F2.nbSpectateurs <= 1000000)
       GROUP BY annee;	   


-- Exercice 2
