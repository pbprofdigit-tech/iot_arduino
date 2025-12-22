#include <SPI.h>
#include <WiFiS3.h>

const char* ssid = "****";
const char* pass = "****";

int keyIndex = 0;

int status = WL_IDLE_STATUS;

WiFiServer server(80);

int n;
char c;
String comando;

void setup() {

  //Initialize serial and wait for port to open:

  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);

  while (!Serial) {

    ; // wait for serial port to connect. Needed for native USB port only

  }

  // check for the presence of the shield:

  if (WiFi.status() == WL_NO_SHIELD) {

    Serial.println("WiFi shield not present");

    // don't continue:

    while (true);

  }


  // attempt to connect to Wifi network:

  while (status != WL_CONNECTED) {

    Serial.print("Attempting to connect to SSID: ");

    Serial.println(ssid);

    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:

    IPAddress local_IP(192, 168, 1, 18);  
    WiFi.config(local_IP);

    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:

    delay(3000);
    Serial.println(WiFi.localIP());
  }

  server.begin();

  // you're connected now, so print out the status:

}

void loop() {

  // listen for incoming clients

  WiFiClient client = server.available();

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
        client.println("<center><h1>CONTROL LED</h1></center><br><br>");

        // verifica la presenza ed elabora i parametri get/post
        if(comando.indexOf("led1=on")>=0) {
          digitalWrite(2,HIGH);
        }
        if(comando.indexOf("led1=off")>=0) {
          digitalWrite(2,LOW);
        }

        if(comando.indexOf("led2=on")>=0) {
          digitalWrite(3,HIGH);
        }
        if(comando.indexOf("led2=off")>=0) {
          digitalWrite(3,LOW);
        }
        
        if(comando.indexOf("led3=on")>=0) {
          digitalWrite(4,HIGH);
        }
        if(comando.indexOf("led3=off")>=0) {
          digitalWrite(4,LOW);
        }
        
        if(comando.indexOf("led4=on")>=0) {
          digitalWrite(5,HIGH);
        }
        if(comando.indexOf("led4=off")>=0) {
          digitalWrite(5,LOW);
        }
        
        // fine comandi

        // stampa valore aggiornato pin
        int legge1,legge2,legge3,legge4;
        legge1=digitalRead(2);
        legge2=digitalRead(3);
        legge2=digitalRead(4);
        legge2=digitalRead(5);

        client.println("<table width=\"50%\" align=\"center\"><tr>");
        
        if(legge1==0) {
            client.println("<td align=center><form action=\"led1=on\" metdoh=\"post\">");
            client.println("<input type=\"image\" src=\"https://www.ecovision.live/rest/verde_off.jpg\" alt=\"Submit\" width=\"120\">");
            client.println("</form></td>");
        } else {
            client.println("<td align=center><form action=\"led1=off\" metdoh=\"post\">");
            client.println("<input type=\"image\" src=\"https://www.ecovision.live/rest/verde_on.jpg\" alt=\"Submit\" width=\"120\">");
            client.println("</form></td>"); 
        }

        if(legge2==0) {
            client.println("<td align=center><form action=\"led2=on\" metdoh=\"get\">");
            client.println("<input type=\"image\" src=\"https://www.ecovision.live/rest/rosa_off.jpg\" alt=\"Submit\" width=\"120\">");
            client.println("</form></td>");
        } else {
            client.println("<td align=center><form action=\"led2=off\" metdoh=\"get\">");
            client.println("<input type=\"image\" src=\"https://www.ecovision.live/rest/rosa_on.jpg\" alt=\"Submit\" width=\"120\">");
            client.println("</form></td>");
        }

        if(legge3==0) {
            client.println("<td align=center><form action=\"led3=on\" metdoh=\"get\">");
            client.println("<input type=\"image\" src=\"https://www.ecovision.live/rest/bianco_off.jpg\" alt=\"Submit\" width=\"120\">");
            client.println("</form></td>");
        } else {
            client.println("<td align=center><form action=\"led3=off\" metdoh=\"get\">");
            client.println("<input type=\"image\" src=\"https://www.ecovision.live/rest/bianco_on.jpg\" alt=\"Submit\" width=\"120\">");
            client.println("</form></td>");
        }

        if(legge4==0) {
            client.println("<td align=center><form action=\"led4=on\" metdoh=\"get\">");
            client.println("<input type=\"image\" src=\"https://www.ecovision.live/rest/giallo_off.jpg\" alt=\"Submit\" width=\"120\">");
            client.println("</form></td>");
        } else {
            client.println("<td align=center><form action=\"led4=off\" metdoh=\"get\">");
            client.println("<input type=\"image\" src=\"https://www.ecovision.live/rest/giallo_on.jpg\" alt=\"Submit\" width=\"120\">");
            client.println("</form></td>");
        }

        client.println("</tr><tr><td align=center><h2>1</h2></td><td align=center><h2>2</h2></td><td align=center><h2>3</h2></td><td align=center><h2>4</h2></td></tr></table></body></html>");
        break;
      }
    }

    delay(100);

    client.stop();


  }
}


