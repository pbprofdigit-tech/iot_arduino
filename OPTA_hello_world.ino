#include <Ethernet.h>
byte mac[] = {  
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,1,101);
EthernetServer server(80);   // Porta TCP in ascolto (modificabile)
int n;
char c;
String comando;

void setup() {
  Serial.begin(9600);
  Serial.println("Connessione alla rete...");
  Ethernet.begin(mac, ip);
  delay(1000);
  server.begin();
}

void loop() {
  EthernetClient client = server.available();
  if (client) {
    bool currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        // recupera parametri get
        comando="";
        for(n=1;n<=30;n++) {
          c=client.read();
          comando=comando+c;
        }
        // send a standard http response header
        client.println("HTTP/1.1 200 OK");
        client.println("Content-Type: text/html");
        client.println("Connection: close");  // the connection will be closed after completion of the response
        client.println();
        client.println("<!DOCTYPE HTML>");
        client.println("<html><body>");
        // output the value of each analog input pin
        client.println("<h1>HELLO WORLD !!!</h1>");
        client.println("</body></html>");
        break;
      }
    }
    delay(1);
    client.stop();
  }
}
