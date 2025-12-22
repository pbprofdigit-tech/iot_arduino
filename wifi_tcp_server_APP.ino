#include <WiFiS3.h>

// Credenziali WiFi
const char* ssid = "****";
const char* password = "****";

WiFiServer server(5000);   // Porta TCP in ascolto (modificabile)
WiFiClient client;

void setup() {
  Serial.begin(9600);
  delay(1000);

  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);

  IPAddress local_IP(192, 168, 1, 216);
  WiFi.config(local_IP);

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

 
    if(incoming=="P1on"){ 
      digitalWrite(2,HIGH);
    }
    if(incoming=="P2on"){ 
      digitalWrite(3,HIGH);
    }
    if(incoming=="P3on"){ 
      digitalWrite(4,HIGH);
    }
    if(incoming=="P4on"){ 
      digitalWrite(5,HIGH);
    }

    if(incoming=="P1off"){ 
      digitalWrite(2,LOW);
    }
    if(incoming=="P2off"){ 
      digitalWrite(3,LOW);
    }
    if(incoming=="P3off"){ 
      digitalWrite(4,LOW);
    }
    if(incoming=="P4off"){ 
      digitalWrite(5,LOW);
    }

  }
}
