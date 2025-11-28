#include <WiFiS3.h>
#include "ArduinoGraphics.h" 
#include "Arduino_LED_Matrix.h"

// Credenziali WiFi
const char* ssid     = "TIM-45796875";
const char* password = "c3KGfuCQPY4Gp7cARdkZXA7Q";

WiFiServer server(5000);   // Porta TCP in ascolto (modificabile)
WiFiClient client;
ArduinoLEDMatrix matrix;

void setup() {
  Serial.begin(9600);
  delay(1000);

  IPAddress local_IP(192, 168, 1, 216);
  WiFi.config(local_IP);

  matrix.begin();

  matrix.beginDraw();
  matrix.stroke(0xFFFFFFFF);

  Serial.println("Connessione alla rete WiFi...");
  WiFi.begin(ssid, password);

  // Attesa connessione
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnesso!");
  Serial.print("IP Arduino: ");
  delay(3000);
  Serial.println(WiFi.localIP());

  server.begin();  // Avvia server TCP
  Serial.println("Server TCP in ascolto sulla porta 5000...");
}

void loop() {
  // Se non abbiamo un client collegato, proviamo ad accettarne uno
  if (!client || !client.connected()) {
    client = server.available();
    if (client) {
      Serial.println("Client connesso!");
    }
    return; // Evita di leggere se non c’è client
  }

  // Ricezione dati
  if (client.available()) {
    String incoming = client.readStringUntil('\n');  // Legge fino a newline
    Serial.print("Ricevuto: ");
    Serial.println(incoming);

    matrix.beginDraw();
    matrix.stroke(0xFFFFFFFF);
    matrix.textScrollSpeed(50);

    if(incoming=="Aon"){ 
      const char text[] = "AAA-";
      matrix.textFont(Font_5x7);
      matrix.beginText(0, 1, 0xFFFFFF);
      matrix.println(text);
      matrix.endText(SCROLL_LEFT);
      matrix.endDraw();
    }
    if(incoming=="Bon"){ 
      const char text[] = "BBB-";
      matrix.textFont(Font_5x7);
      matrix.beginText(0, 1, 0xFFFFFF);
      matrix.println(text);
      matrix.endText(SCROLL_LEFT);
      matrix.endDraw();
    }
  }
}