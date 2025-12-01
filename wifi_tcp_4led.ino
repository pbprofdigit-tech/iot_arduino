#include <WiFiS3.h>

// Credenziali WiFi
const char* ssid = "****";
const char* password = "****";

WiFiServer server(5000);   // Porta TCP in ascolto (modificabile)
WiFiClient client;
IPAddress local_IP(192, 168, 1, 150); // Your Desired Static IP Address

void setup() {
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);

  // Inizializzazione seriale
  Serial.begin(9600);
  delay(1000);
  WiFi.config(local_IP);

  // Connessione alla rete WiFi 
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

  // Avvia server TCP
  server.begin(); 
  Serial.println("Server TCP in ascolto sulla porta 5000...");
}

void loop() {
  // Accettazione del client
  if (!client || !client.connected()) {
    client = server.available();
    if (client) {
      Serial.println("Client connesso!");
    }
    return;
  }

  // Ricezione dati
  if (client.available()) {
    String incoming = client.readStringUntil('\n'); 
    Serial.print("Ricevuto: ");
    Serial.println(incoming);

    // In base alla stringa ricevuta imposta lo stato dei pin
    if(indexOf("L1=on")>0){ 
      digitalWrite(1,HIGH);
    }
    if(indexOf("L1=off")>0){ 
      digitalWrite(1,HIGH);
    }
    if(indexOf("L2=on")>0){ 
      digitalWrite(2,HIGH);
    }
    if(indexOf("L2=off")>0){ 
      digitalWrite(2,HIGH);
    }
    if(indexOf("L3=on")>0){ 
      digitalWrite(3,HIGH);
    }
    if(indexOf("L3=off")>0){ 
      digitalWrite(3,HIGH);
    }
    if(indexOf("L4=on")>0){ 
      digitalWrite(4,HIGH);
    }
    if(indexOf("L4=off")>0){ 
      digitalWrite(4,HIGH);
    }
  }
}