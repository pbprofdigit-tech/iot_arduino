void setup() {

  // put your setup code here, to run once:
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);

  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);

  digitalWrite(8,LOW);
  digitalWrite(9,LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  int p2,p3,p4;
  int y;
  // Tabella di verità [righe][colonne]
  // colonne: 3 di input, 2 di output
  byte tabella[8][5] = {
    { 0, 0, 0,   1, 1},
    { 0, 0, 1,   1, 0},
    { 0, 1, 0,   0, 1},
    { 0, 1, 1,   0, 0},
    { 1, 0, 0,   1, 0},
    { 1, 0, 1,   1, 1},
    { 1, 1, 0,   0, 1},
    { 1, 1, 1,   1, 0}
  };

  for(y=0;y<=7;y++)
  {
    p2=digitalRead(2);
    p3=digitalRead(3);
    p4=digitalRead(4);

    if(tabella[y][0]==p4 && tabella[y][1]==p3 && tabella[y][2]==p2) { digitalWrite(9,tabella[y][3]); digitalWrite(8,tabella[y][4]);}
  }

  delay(100);
}
