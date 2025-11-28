#include <WiFiS3.h>
#include "DHT.h"

// Credenziali WiFi
const char* ssid     = "TIM-45796875";
const char* password = "c3KGfuCQPY4Gp7cARdkZXA7Q";


// IP del server nella LAN
const char* serverIP = "192.168.1.27";
// Porta del server TCP
const int serverPort = 5000;

#define DHTPIN 8 // Digital pin connected to the DHT sensor
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

DHT dht(DHTPIN, DHTTYPE);

WiFiClient client;

void setup() {

  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(A0,INPUT);

  // inizializzazione della seriale
  Serial.begin(9600);
  delay(1000);

  dht.begin();

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
  
  int p1,p2,p3;
  float temp;
  if (client.connected()) {
    String message = "", s1="Spento",s2="Spento";
    p1=digitalRead(6);
    p2=digitalRead(7);
    p3=analogRead(A0);
    temp = dht.readTemperature();

    if(p1==1) { s1="Acceso"; }
    if(p2==1) { s2="Acceso"; }

    message="P1="+s1+" P2="+s2+" Temp:"+String(temp)+"°    Valore potenziometro: "+String(p3)+"  ";

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

  delay(2000);   // invia ogni 2 secondi
}

