<?php
$servername = "localhost";
$username = "root";
$password = "";

try {
    $db = new PDO("mysql:host=$servername;dbname=cours_php", $username, $password);
    $db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
} catch(PDOException $e) {
    echo "Connection failed: " . $e->getMessage();
}

    $id=$_GET['id'];

    // Initialisation d'un tableau pour stocker les erreurs
    $errors = [];

    if (empty($id)) {
        $errors[] = "L'id  est obligatoire.";
    }
    if(empty($errors)){

        $sql = "DELETE FROM users WHERE id =(:id)";
        $stmt = $db ->prepare($sql);
        $stmt->execute(['id' => $id]);
        // Préparer la requête pour vérifier si l'utilisateur existe
        $sql2 = "SELECT * FROM `users` WHERE id = :id";
        $stmt = $db->prepare($sql2);
        $stmt->execute(['id' => $id]);

        // Vérifier si l'utilisateur existe
        if ($stmt->rowCount() > 0) {
            echo "L'utilisateur existe toujours.";

        } else {
            echo "La suppression de la ligne a l'id". $id." est un succés."."<br>";
        }
        

    }else {
        // Affichage des erreurs
        echo "<h2>Des erreurs ont été trouvées :</h2>";
        echo "<ul>";
        foreach ($errors as $error) {
            echo "<li>" . htmlspecialchars($error) . "</li>";
        }
        echo "</ul>";
    }
?>
<!DOCTYPE html>
<html>
    <body>
        <a href="display.php"><button>Retour a l'acceuil</button></a>
    </body>
</html>