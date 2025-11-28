#include <SPI.h>
#include <WiFiS3.h>


const char* ssid     = "TIM-45796875";
const char* pass = "c3KGfuCQPY4Gp7cARdkZXA7Q";

int keyIndex = 0;                 // your network key Index number (needed only for WEP)

int status = WL_IDLE_STATUS;

WiFiServer server(80);

int n;
char c;
String comando;

void setup() {

  //Initialize serial and wait for port to open:

  Serial.begin(9600);

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
        client.println("HELLO WORLD !!!");

        // verifica la presenza ed elabora i parametri get
        if(comando.indexOf("99")>0) {
          client.println("<br>99<br>");
        }
        if(comando.indexOf("199")>0) {
          client.println("<br>199<br>");
        }
        // fine get

        client.println("</body></html>");
        break;
      }

    }

    delay(1);

    client.stop();


  }
}

