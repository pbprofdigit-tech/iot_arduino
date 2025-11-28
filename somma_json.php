<?php

// Recupera i dati inviati con la richiesta
$input_data = file_get_contents("php://input");
$input_data2 = json_decode($input_data);

$n1=$input_data2->n1;
$n2=$input_data2->n2;

$somma=$n1+$n2;

echo('{"risultato:"'.$somma.'}');

?>

