#include <Ethernet.h>

Ethernet server(5000);   // Porta TCP in ascolto (modificabile)
EthernetClient client;


void setup() {
  pinMode(D0,OUTPUT);
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  pinMode(D3,OUTPUT);

  digitalWrite(D0,HIGH);
  digitalWrite(D1,HIGH);
  digitalWrite(D2,HIGH);
  digitalWrite(D3,HIGH);

  Serial.begin(9600);
  delay(1000);


  Serial.println("Connessione alla rete...");
  Ethernet.begin(mac, ip);
  delay(1000);

  Serial.println("\nConnesso!");
  Serial.print("IP Arduino: ");
  delay(3000);
  Serial.println(Ethernet.localIP());

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

    if(incoming.indexOf("lp1=on")>=0){ 
      digitalWrite(D0,HIGH);
    }
    if(incoming.indexOf("lp1=off")>=0){ 
      digitalWrite(D0,LOW);
    }
    if(incoming.indexOf("lp2=on")>=0){ 
      digitalWrite(D1,HIGH);
    }
    if(incoming.indexOf("lp2=off")>=0){ 
      digitalWrite(D1,LOW);
    }
    if(incoming.indexOf("lp3=on")>=0){ 
      digitalWrite(D2,HIGH);
    }
    if(incoming.indexOf("lp3=off")>=0){ 
      digitalWrite(D2,LOW);
    }
    if(incoming.indexOf("lp4=on")>=0){ 
      digitalWrite(D3,HIGH);
    }
    if(incoming.indexOf("lp4=off")>=0){ 
      digitalWrite(D3,LOW);
    }


  }
}