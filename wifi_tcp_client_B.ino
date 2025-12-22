#include <WiFiS3.h>

// Credenziali WiFi
const char* ssid = "****";
const char* password = "****";

// IP del server nella LAN
const char* serverIP = "192.168.1.27";  
// Porta del server TCP
const int serverPort = 5000;

WiFiClient client;

void setup() {
  // inizializzazione della seriale
  Serial.begin(9600);
  delay(1000);

  Serial.println("Connessione alla rete WiFi...");
  WiFi.begin(ssid, password);

  // Attesa connessione
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // stampa ip assegnato al dispositivo
  Serial.println("\nConnesso!");
  Serial.print("IP ottenuto: ");
  delay(3000);
  Serial.println(WiFi.localIP());

  Serial.println("Connessione al server TCP...");

  // stabilisce una connessione con il server
  if (client.connect(serverIP, serverPort)) {
    Serial.println("Connesso al server!");
  } else {
    Serial.println("Connessione fallita!");
  }
}

void loop() {
  if (client.connected()) {
    String message = "Ciao dalla R4 WiFi!";
    // invia il messaggio al server
    client.println(message);
    Serial.println("Inviato: " + message);
  } else {
    Serial.println("Connessione persa, riconnessione...");

    if (client.connect(serverIP, serverPort)) {
      Serial.println("Riconnesso al server.");
    } else {
      Serial.println("Riconnessione fallita.");
    }
  }

  // invia ogni 2 secondi
  delay(2000);   
}
