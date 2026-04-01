#include <Ethernet.h>

byte mac[] = {  
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,1,101);

const char* serverIP = "192.168.1.100";
// Porta del server TCP
const int serverPort = 5000;

EthernetClient client;

void setup() {

  pinMode(PIN_A3,INPUT);
  pinMode(PIN_A5,INPUT);

  // inizializzazione della seriale
  Serial.begin(9600);
  delay(1000);

  Serial.println("Connessione alla rete...");
  Ethernet.begin(mac, ip);

  // stampa ip assegnato al dispositivo
  Serial.println("Connesso!");
  Serial.print("IP ottenuto: ");
  delay(3000);
  Serial.println(Ethernet.localIP());

  Serial.println("Connessione al server TCP...");

  // stabilisce una connessione con il server
  if (client.connect(serverIP, serverPort)) {
    Serial.println("Connesso al server!");
  } else {
    Serial.println("Connessione fallita!");
  }
}

void loop() {
  int p1,p2;
  if (client.connected()) {
    String message = "";
    p1=analogRead(PIN_A3);
    p2=analogRead(PIN_A5);

    message="P1="+String(p1)+" P2="+String(p2);

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
