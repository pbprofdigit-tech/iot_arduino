#include "WiFiS3.h"

char ssid[] = "TIM-45796875";        // your network SSID (name)
char pass[] = "c3KGfuCQPY4Gp7cARdkZXA7Q";    // your network password (use for WPA, or use as key for WEP)


void setup(){
  Serial.begin(9600);

  IPAddress local_IP(192, 168, 1, 150);
  WiFi.config(local_IP);

  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnesso!");
  Serial.print("IP Arduino: ");
  delay(3000);
  Serial.println(WiFi.localIP());

}

void loop(){

}
