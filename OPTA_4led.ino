void setup() {
  pinMode(LED_RELAY1,OUTPUT);
  pinMode(LED_RELAY2,OUTPUT);
  pinMode(LED_RELAY3,OUTPUT);
  pinMode(LED_RELAY4,OUTPUT);

  digitalWrite(LED_RELAY1,LOW);
  digitalWrite(LED_RELAY2,LOW);
  digitalWrite(LED_RELAY3,LOW);
  digitalWrite(LED_RELAY4,LOW);
}

void loop() {
  digitalWrite(LED_RELAY1,HIGH);
  digitalWrite(LED_RELAY4,LOW);
  delay(1000);
  digitalWrite(LED_RELAY2,HIGH);
  digitalWrite(LED_RELAY1,LOW);
  delay(1000);
  digitalWrite(LED_RELAY3,HIGH);
  digitalWrite(LED_RELAY2,LOW);
  delay(1000);
  digitalWrite(LED_RELAY4,HIGH);
  digitalWrite(LED_RELAY3,LOW);
  delay(1000);
}
