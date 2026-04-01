void setup() {
  pinMode(RELAY4,OUTPUT);
}

void loop() {
  digitalWrite(RELAY4,HIGH);
  delay(2000);
  digitalWrite(RELAY4,LOW);
  delay(2000);
}
