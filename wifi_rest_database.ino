#include <WiFiS3.h>

// Credenziali WiFi
const char* ssid = "TIM-45796875";
const char* pass = "c3KGfuCQPY4Gp7cARdkZXA7Q";


char server[] = "www.publisun.it"; // Host
int port = 80;

WiFiClient client;

void setup() {
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

  if (client.connect(server, port)) {
    // Variabile che contiene i dati in json
    const char* body = "{\"n1\":\"64\",\"n2\":\"79\"}";
    Serial.println("Connesso al server!");
    // Invia richiesta HTTP POST
    client.println("POST /rest/database_json.php HTTP/1.1");
    client.println("Host: www.publisun.it");
    client.println("Content-Type: application/json");
    client.print("Content-Length: ");
    client.println(strlen(body));
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
// nessun codice


}