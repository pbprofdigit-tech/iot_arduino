#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;

void setup() {

  // Inizializza la matrice di led
  matrix.begin();

  matrix.beginDraw();
  matrix.stroke(0x00000000);


  // Imposta lo scorrimento del testo alla velocità 50
  matrix.textScrollSpeed(50);

}

void loop() {
  matrix.textFont(Font_5x7);
  matrix.beginText(0, 1, 0xFFFFFF);

  // Stampa testo scorrevole
  matrix.println("Hello World !!!");
  matrix.endText(SCROLL_LEFT);
  matrix.endDraw();
  delay(1000);

  // Stampa matrice di punti
  byte frame[8][12] = {
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1 },
    { 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1 },
    { 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1 },
    { 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
  };

  matrix.renderBitmap(frame, 8, 12);
  delay(1000);
}