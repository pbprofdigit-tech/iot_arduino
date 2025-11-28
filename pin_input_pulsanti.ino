void setup() {

  // Imposta il pin digitale 6 come ingresso.
  // Questo pin leggerà lo stato logico di un pulsante o sensore.
  pinMode(6,INPUT);

  // Imposta il pin digitale 7 come ingresso.
  // Anche questo è dedicato alla lettura di un pulsante o sensore.
  pinMode(7,INPUT);

  // Inizializza la comunicazione seriale a 9600 baud.
  // Serve per inviare i valori letti al PC tramite Monitor Seriale.
  Serial.begin(9600);
}

void loop() {
  
  int p1, p2;   // Variabili per memorizzare lo stato dei pin 6 e 7
  
  // Legge lo stato del pin 6.
  // Restituisce 0 (LOW) o 1 (HIGH) a seconda della tensione presente sul pin.
  p1 = digitalRead(6);

  // Legge lo stato del pin 7.
  p2 = digitalRead(7);

  // Stampa i valori letti sul Monitor Seriale.
  // La sintassi unisce testo e valori trasformati in stringa.
  Serial.println("P1=" + String(p1) + "      P2=" + String(p2));

  // Attende 1 secondo prima di eseguire la prossima lettura.
  delay(1000);
}