#include <WiFiS3.h> 
#include <WiFiUdp.h>

// Credenziali WiFi
const char* ssid     = "TIM-45796875";
const char* password = "c3KGfuCQPY4Gp7cARdkZXA7Q";

// Indirizzo e porta del destinatario
const char* udpAddress = "192.168.1.27";  
const int udpPort = 5000;

WiFiUDP udp;

void setup() {
  Serial.begin(9600);

  // Connessione WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connessione a WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnesso!");

  udp.begin(udpPort);  // opzionale per ricevere
}

void loop() {
  const char* message = "Ciao da Arduino via UDP!";

  udp.beginPacket(udpAddress, udpPort);  
  udp.write((uint8_t*)message, strlen(message));
  udp.endPacket();

  Serial.println("Messaggio inviato");

  delay(2000);
}