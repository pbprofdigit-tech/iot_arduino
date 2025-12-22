#include "WiFiS3.h"

char ssid[] = "****";        // your network SSID (name)
char pass[] = "****";    // your network password (use for WPA, or use as key for WEP)

// Si imposta un ip fisso da richiamare dal browser
IPAddress local_IP(192, 168, 1, 150); 

WiFiServer server(80);
int n=0;

void setup() {
  WiFi.config(local_IP);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  server.begin();
}

void loop()
{
  WiFiClient client = server.available();
  if (client) {
    while (client.connected()) {
      if (client.available()) {
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html><body>");
          // inizio contenuto pagina web 
          client.println("<h1>HELLO WORLD!!!</h1>");
          // fine contenuto pagina web 
          client.println("</body></html>");
          client.stop();
      }
    }
  }
}
