void setup() {
  pinMode(A3,INPUT);
  pinMode(A5,INPUT);

  Serial.begin(9600);
}

void loop() {
  int p1,p2;
    p1=analogRead(A3);
    p2=analogRead(A5);

    Serial.println(p1);
    Serial.println(p2);
    Serial.println("----");
  delay(2000);  
}
