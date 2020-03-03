<!doctype html>
<html lang="fr">
	<head>
		<title> Réponses </title>
		<meta charset="UTF8"/>
		<link rel="stylesheet" href="styles.css"/>
	</head>
	<body>
		<p>
			Vos réponses sont donc :
		
		</p>
		<?php
			$total = 0;
			foreach($_GET as $numero=>$reponse) {
				echo "<li>" , " - " , $numero, " : ", $reponse, "</li>";

				$total += $reponse;


			}
			echo " Score : " , $total;
		?>
		<a href="http://localhost/~acantonconde/quizz_dynamique.html"> Quizz Dynamique </a>
	</body>
</html>