<?php
$servername = "localhost";
$username = "root";
$password = "";

try {
    $conn = new PDO("mysql:host=$servername;dbname=cours_php", $username, $password);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
} catch(PDOException $e) {
    echo "Connection failed: " . $e->getMessage();
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $id = $_GET['id'];
    $name = $_POST['name'];
    $email = trim($_POST['email']);

    // Initialisation d'un tableau pour stocker les erreurs
    $errors = [];

    // Fonction pour vérifier si une chaîne ne contient pas que des chiffres
    function contientUniquementDesChiffres($chaine) {
        return ctype_digit($chaine);
    }


    if (empty($name)) {
        $errors[] = "Le nom est obligatoire.";
    } elseif (contientUniquementDesChiffres($name)) {
        $errors[] = "Le nom ne doit pas contenir uniquement des chiffres.";
    }

    // Validation de l'email
    if (empty($email)) {
        $errors[] = "L'email est obligatoire.";
    } elseif (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
        $errors[] = "L'email n'est pas valide.";
    }

    // Si aucune erreur, traitement de l'inscription
    if (empty($errors)) {
        //INSERTION EN BDD
        $sql = "UPDATE users SET name = :name, email = :email WHERE id = $id";
        $stmt = $conn ->prepare($sql);
        $stmt->execute(['name' => $name,'email'=> $email]);

        echo "<h2>Modification réussie</h2>";

    } else {
        // Affichage des erreurs
        echo "<h2>Des erreurs ont été trouvées :</h2>";
        echo "<ul>";
        foreach ($errors as $error) {
            echo "<li>" . htmlspecialchars($error) . "</li>";
        }
        echo "</ul>";
    }
}
?>

<!DOCTYPE html>
<html>
    <body>
        <a href="display.php"><button>Retour a l'acceuil</button></a>
    </body>
</html>