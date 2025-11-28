#include <Ethernet.h>

byte mac[] = {  
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,1,3);

EthernetServer server(80);

void setup() {
  pinMode(21,INPUT);
  Ethernet.begin(mac, ip);

}

void loop()
{

}
