<?php
// Recupera i dati inviati con la richiesta
$input_data = file_get_contents("php://input");
$input_data2 = json_decode($input_data);

$temperatura=$input_data2->temperatura;
$potenziometro=$input_data2->potenziometro;
$pulsante1=$input_data2->pulsante1;
$pulsante2=$input_data2->pulsante2;

// Si connette al database
$servername = "31.11.39.40";
$username = "Sql1663447";
$password = "ITIS-arezzo-123";
$dbname = "Sql1663447_1";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

// Inserisce i dati nel database
$sql="INSERT INTO valori_arduino (temperatura,potenziometro,pulsante1,pulsante2) VALUES ($temperatura,$potenziometro,$pulsante1,$pulsante2)";
$res=mysqli_query($conn, $sql);

echo('{"result:"'.$res.'}');
$mysqli->close();

?>

