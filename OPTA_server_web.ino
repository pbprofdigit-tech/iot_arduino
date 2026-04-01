#include <Ethernet.h>

byte mac[] = {  
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,1,150);
EthernetServer server(80);   // Porta TCP in ascolto (modificabile)
int n;
char c;
String comando;

void setup() {
  pinMode(D0,OUTPUT);
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  pinMode(D3,OUTPUT);

  Serial.begin(9600);
  Serial.println("Connessione alla rete...");
  Ethernet.begin(mac, ip);
  delay(1000);
  server.begin();
}

void loop() {
  // listen for incoming clients
  EthernetClient client = server.available();
  if (client) {
    bool currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        // recupera parametri get/post dal body della request
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
        client.println("<h2>CONTROL LED 1 - 2 - 3 - 4</h2>");

        // verifica la presenza ed elabora i parametri get/post
        if(comando.indexOf("led1=on")>=0) {
          digitalWrite(D0,HIGH);
        }
        if(comando.indexOf("led1=off")>=0) {
          digitalWrite(D0,LOW);
        }

        if(comando.indexOf("led2=on")>=0) {
          digitalWrite(D1,HIGH);
        }
        if(comando.indexOf("led2=off")>=0) {
          digitalWrite(D1,LOW);
        }
       
        if(comando.indexOf("led3=on")>=0) {
          digitalWrite(D2,HIGH);
        }
        if(comando.indexOf("led3=off")>=0) {
          digitalWrite(D2,LOW);
        }
       
        if(comando.indexOf("led4=on")>=0) {
          digitalWrite(D3,HIGH);
        }
        if(comando.indexOf("led4=off")>=0) {
          digitalWrite(D3,LOW);
        }
        // fine verifica

        // stampa valore aggiornato pin
        int legge1,legge2,legge3,legge4;
        legge1=digitalRead(D0);
        Serial.println(legge1);
        client.println("Led1 = "+String(legge1));
        client.println("<br>");
        legge2=digitalRead(D1);
        client.println("Led2 = "+String(legge2));
        client.println("<br>");
        legge3=digitalRead(D2);
        client.println("Led3 = "+String(legge3));
        client.println("<br>");
        legge4=digitalRead(D3);
        client.println("Led4 = "+String(legge4));
        client.println("<br>");
        client.println("<br>");
        // fine stampa

        // inizio form
        client.println("<form action=\"led1=on\" metdoh=\"post\">");
        client.println("<input type=\"submit\" value=\"LED 1 ON\">");
        client.println("</form> ");
        client.println("<form action=\"led1=off\" metdoh=\"post\">");
        client.println("<input type=\"submit\" value=\"LED 1 OFF\">");
        client.println("</form><br>");

        client.println("<form action=\"led2=on\" metdoh=\"get\">");
        client.println("<input type=\"submit\" value=\"LED 2 ON\">");
        client.println("</form> ");
        client.println("<form action=\"led2=off\" metdoh=\"get\">");
        client.println("<input type=\"submit\" value=\"LED 2 OFF\">");
        client.println("</form><br>");

        client.println("<form action=\"led3=on\" metdoh=\"get\">");
        client.println("<input type=\"submit\" value=\"LED 3 ON\">");
        client.println("</form> ");
        client.println("<form action=\"led3=off\" metdoh=\"get\">");
        client.println("<input type=\"submit\" value=\"LED 3 OFF\">");
        client.println("</form><br>");

        client.println("<form action=\"led4=on\" metdoh=\"get\">");
        client.println("<input type=\"submit\" value=\"LED 4 ON\">");
        client.println("</form> ");
        client.println("<form action=\"led4=off\" metdoh=\"get\">");
        client.println("<input type=\"submit\" value=\"LED 4 OFF\">");
        client.println("</form><br>");
        // fine form

        client.println("</body></html>");
        break;
      }

    }
    delay(1);
    client.stop();
  }
}
