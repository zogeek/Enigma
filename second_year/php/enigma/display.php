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
$sql = "SELECT * FROM users";
$stmt = $db->query($sql);

$sql2 ="SELECT u.name AS username, o.name AS objectname, u.id AS id FROM userobjectrelation uor JOIN users u ON uor.userid = u.id JOIN objects o ON uor.objectid = o.id;";
$stmt2 = $db->query($sql2);


$row2 = $stmt2->fetch(PDO::FETCH_ASSOC);

?>



<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <h2>Utilisateur enregistrés</h2>
    <table border="1">
    <tr>
        <th>ID</th>
        <th>Nom d'utilisateur</th>
        <th>Email</th>
        <th>Objets</th>
        <th>Actions</th>
    </tr>
    <?php while ($row = $stmt->fetch()) : ?>
    <?php ?>
    <tr>
        <td> <?php echo $row['id'];  ?> </td>
        <td> <?php echo $row['name'];  ?> </td>
        <td> <?php echo $row['email'];  ?> </td>
         <td>
             <?php echo $row2['objectname'];  ?>
         </td>
        <td>
            <a href="edit.php?id=<?php echo $row['id']; ?>">Modifier</a>
            <a href="remove.php?id=<?php echo $row['id']; ?>" onclick="return confirm('Êtes-vous sur de vouloir supprimer cet utilisateur ?');">Supprimer</a>
        </td>
    </tr>
    <?php endwhile; ?>
        
    </table>
    <h2>Ajouter un utilisateur</h2>
    <a href="add.php"><button>Ajouter un utilisateur</button></a>


    
</body>
</html>
