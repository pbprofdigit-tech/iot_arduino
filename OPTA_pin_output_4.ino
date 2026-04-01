void setup() {
  pinMode(RELAY1,OUTPUT);
  pinMode(RELAY1,OUTPUT);
  pinMode(RELAY1,OUTPUT);
  pinMode(RELAY1,OUTPUT);

  digitalWrite(RELAY1,LOW);
  digitalWrite(RELAY1,LOW);
  digitalWrite(RELAY1,LOW);
  digitalWrite(RELAY1,LOW);
}

void loop() {
  digitalWrite(RELAY4,LOW);
  digitalWrite(RELAY1,HIGH);
  delay(2000);
  digitalWrite(RELAY1,LOW);
  digitalWrite(RELAY2,HIGH);
  delay(2000);
  digitalWrite(RELAY2,LOW);
  digitalWrite(RELAY3,HIGH);
  delay(2000);
  digitalWrite(RELAY3,LOW);
  digitalWrite(RELAY4,HIGH);
  delay(2000);
}
