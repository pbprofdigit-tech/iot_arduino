#include "DHT.h"

#define DHTPIN 8     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

DHT dht(DHTPIN, DHTTYPE);

float leggeTemp(){
  float temp = dht.readTemperature();
  return temp;
}

void setup(){
  dht.begin();
  Serial.begin(9600);
}

void loop(){
  Serial.println("-->"+String(leggeTemp()));
  delay(2000);
}
