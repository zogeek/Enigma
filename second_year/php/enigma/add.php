<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<?php
echo "<h1>Que souhaitez vous faire?</h1>"
?>
<body>
    <h2>Ajouter un utilisateur</h2>
    <form method="POST" action="traitement.php">
        Nom : <input type="text" name="name"><br>
        Email : <input type="text" name="email"><br>
        <input type="submit" value="Envoyer">
    </form>
    <h2>Afficher tout les utilisateurs</h2>
    <a href="display.php">
    <button>Afficher les utilisateurs</button>
    </a>
</body>
</html>