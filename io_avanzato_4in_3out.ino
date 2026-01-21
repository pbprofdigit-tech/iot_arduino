void setup() {

  // put your setup code here, to run once:
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);

  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);

  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  int p2,p3,p4,p5;
  int y;
  // Tabella di verità [righe][colonne]
  // colonne: 3 di input, 2 di output
  byte tabella[16][7] = {
    { 0, 0, 0, 0,   1, 1, 0},
    { 0, 0, 0, 1,   1, 0, 1},
    { 0, 0, 1, 0,   0, 1, 0},
    { 0, 0, 1, 1,   0, 0, 0},
    { 0, 1, 0, 0,   1, 0, 1},
    { 0, 1, 0, 1,   1, 1, 1},
    { 0, 1, 1, 0,   0, 1, 0},
    { 0, 1, 1, 1,   1, 0, 1},
    { 1, 0, 0, 0,   1, 1, 1},
    { 1, 0, 0, 1,   1, 0, 0},
    { 1, 0, 1, 0,   0, 1, 1},
    { 1, 0, 1, 1,   0, 0, 1},
    { 1, 1, 0, 0,   1, 0, 0},
    { 1, 1, 0, 1,   1, 1, 0},
    { 1, 1, 1, 0,   0, 1, 1},
    { 1, 1, 1, 1,   1, 0, 1}
  };

  for(y=0;y<=15;y++)
  {
    p2=digitalRead(2);
    p3=digitalRead(3);
    p4=digitalRead(4);
    p5=digitalRead(5);

    if(tabella[y][0]==p5 && tabella[y][1]==p4 && tabella[y][2]==p3 && tabella[y][3]==p2) { digitalWrite(10,tabella[y][4]); digitalWrite(9,tabella[y][5]); digitalWrite(8,tabella[y][6]);}
  }

  delay(100);
}
