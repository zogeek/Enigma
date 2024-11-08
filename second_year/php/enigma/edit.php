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
    $sql = "SELECT * FROM `users` WHERE id = :id";
    $stmt = $db->prepare($sql);
    $stmt->execute(['id' => $id]);
    $user = $stmt->fetch();
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Edit Page</title>
</head>
<body>
    <form method="POST" action="traitement-edit.php?id=<?php echo $user['id'];?>">
        Nom : <input type="text" name="name"value=<?php echo $user['name'];?>><br>
        Email : <input type="text" name="email" value=<?php echo $user['email'];?>><br>
        <input type="submit" value="Envoyer">
    </form>
</body>
</html>