DELETE FROM jouer;
DELETE FROM film;
DELETE FROM acteur;
DELETE FROM genre;
DELETE FROM realisateur;

INSERT INTO acteur VALUES (1, 'Lamouchi', 'Ambre', 'francaise');
INSERT INTO acteur VALUES (2, 'Do', 'John', 'suisse');
INSERT INTO acteur VALUES (3, 'Jackson', 'Mickeal', 'americaine');

INSERT INTO realisateur VALUES (11, 'Tarantino', 'Quentin', 'americaine');
INSERT INTO realisateur VALUES (12, 'Bardin', 'Melvin', 'francaise');
INSERT INTO realisateur VALUES (13, 'Lin', 'Malika', 'anglaise');

INSERT INTO genre VALUES (111, 'action');
INSERT INTO genre VALUES (112, 'comedie');
INSERT INTO genre VALUES (113, 'policier');
INSERT INTO genre VALUES (114, 'fantastique');

INSERT INTO film VALUES (1111, 'Pulp Fiction', 1994, 'Etats-Unis', 1234, 11, 111);
INSERT INTO film VALUES (1112, 'La Cite de la Peur', 2000, 'France', 71874, 12, 112);
INSERT INTO film VALUES (1113, 'Da Vinci Code', 1945, 'Italie', 4794, 13, 113);

INSERT INTO jouer VALUES (1, 1111, 42);
INSERT INTO jouer VALUES (2, 1112, 666);
INSERT INTO jouer VALUES (1, 1112, 44);
INSERT INTO jouer VALUES (2, 1113, 486);
