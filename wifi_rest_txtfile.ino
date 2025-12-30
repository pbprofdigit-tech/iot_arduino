#include <WiFiS3.h>
#include "DHT.h"

// Credenziali WiFi
const char* ssid = "****";
const char* pass = "****";

char server[] = "www.miosito.it"; // Host
int port = 80;

WiFiClient client;

#define DHTPIN 8     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(A0,INPUT);

  dht.begin();
  Serial.begin(9600);
  while (!Serial);

  // Connessione WiFi
  Serial.print("Connessione a ");
  Serial.println(ssid);

 
  while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("\nConnesso al WiFi!");
  Serial.print("IP locale: ");
  delay(3000);
  Serial.println(WiFi.localIP());

  Serial.print("Connessione a ");
  Serial.println(server);

}

void loop() {

  int p1,p2,p3;
  float temp;

  if (client.connect(server, port)) {

    String body = "", s1="Spento",s2="Spento";
    p1=digitalRead(6);
    p2=digitalRead(7);
    p3=analogRead(A0);

    temp = dht.readTemperature();

    if(p1==1) { s1="Acceso"; }
    if(p2==1) { s2="Acceso"; }

    temp = dht.readTemperature();

    // Variabile che contiene i dati in json
    body = "{\"temperatura\":"+String(temp)+ ",\"potenziometro\":"+String(p3)+",\"pulsante1\":\""+s1+"\",\"pulsante2\":\""+s2+"\"}";

    Serial.println("Connesso al server!");
    // Invia richiesta HTTP POST
    client.println("POST /rest/txt_json.php HTTP/1.1");
    client.println("Host: www. miosito.it");
    client.println("Content-Type: application/json");
    client.print("Content-Length: ");
    client.println(body.length());
    client.println("Connection: close");
    client.println();
    client.println(body);

  } else {
    Serial.println("Connessione fallita!");
  }

  delay(1000);
  
  // Leggi e stampa la risposta
  while (client.available()) {
    char c = client.read();
    Serial.write(c);
  }

  if (!client.connected()) {
    Serial.println("\nDisconnesso dal server.");
    client.stop();
    //while (true); // Ferma il programma
  }

  delay(5000);

}


