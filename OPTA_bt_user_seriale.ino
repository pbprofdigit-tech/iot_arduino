void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN,OUTPUT);
  pinMode(BTN_USER,INPUT);

  digitalWrite(LED_BUILTIN,HIGH);
}

void loop() {
  int k=digitalRead(BTN_USER);
  if(k==0) {
    Serial.println("Pulsante premuto");
  } else {
    Serial.println("Pulsante rilasciato");
  }
  delay(100);
}
