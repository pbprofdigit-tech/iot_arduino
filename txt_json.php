<?php
// Recupera i dati inviati con la richiesta
$input_data = file_get_contents("php://input");
$input_data2 = json_decode($input_data);

$temperatura=$input_data2->temperatura;
$potenziometro=$input_data2->potenziometro;
$pulsante1=$input_data2->pulsante1;
$pulsante2=$input_data2->pulsante2;


$temperatura=1;
$potenziometro=2;
$pulsante1=3;
$pulsante2=4;


$myfile = fopen("newfile.txt", "a") or die("Unable to open file!");
$txt = "Temperatura: $temperatura Potenziometro: $potenziometro Pulsante 1: $pulsante1 Pulsante 2: $pulsante2\n";

fwrite($myfile, $txt);

fclose($myfile);
echo('{"result":"Write"}');

?>

