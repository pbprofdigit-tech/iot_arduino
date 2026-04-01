void setup() {
  // Si inizializza LED_BUILTIN come output
  pinMode(LED_BUILTIN, OUTPUT);
  // Si inizializza BTN_USER come input
  pinMode(BTN_USER,INPUT);
}

void loop() {
  int k=digitalRead(BTN_USER);
  if(k==0) {
    digitalWrite(LED_BUILTIN,HIGH);
  } else {
    digitalWrite(LED_BUILTIN,LOW);
  }
}
