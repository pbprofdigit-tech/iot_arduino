#include <WiFiS3.h>
#include "ArduinoGraphics.h" 
#include "Arduino_LED_Matrix.h"

// Credenziali WiFi
const char* ssid = "****";
const char* password = "****";

WiFiServer server(5000);   // Porta TCP in ascolto (modificabile)
WiFiClient client;
ArduinoLEDMatrix matrix;

void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);

  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);

  Serial.begin(9600);
  delay(1000);

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

    if(incoming.indexOf("L1=on")>=0){ 
      digitalWrite(2,HIGH);
    }
    if(incoming.indexOf("L1=off")>=0){ 
      digitalWrite(2,LOW);
    }
    if(incoming.indexOf("L2=on")>=0){ 
      digitalWrite(3,HIGH);
    }
    if(incoming.indexOf("L2=off")>=0){ 
      digitalWrite(3,LOW);
    }
    if(incoming.indexOf("L3=on")>=0){ 
      digitalWrite(4,HIGH);
    }
    if(incoming.indexOf("L3=off")>=0){ 
      digitalWrite(4,LOW);
    }
    if(incoming.indexOf("L4=on")>=0){ 
      digitalWrite(5,HIGH);
    }
    if(incoming.indexOf("L4=off")>=0){ 
      digitalWrite(5,LOW);
    }


  }
}
