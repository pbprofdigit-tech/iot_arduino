void setup(){
  // Inizializza la seriale impostando la velocità
  Serial.begin(9600);
  Serial.println("HELLO WORLD !!!");
}

void loop(){
  int i;
  for(i=0;i<=10;i++){
    Serial.println("Numero: "+String(i));
    delay(1000);
  }
}
