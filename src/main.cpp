#include <Arduino.h>
#include  <config.h>
#include <WateringController.h>


bool hal::manual = false; 
Watering::Controller *Controller; 

#include <Ethernet.h>
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
byte ip[] = {192, 168, 1, 201};
IPAddress dns(192, 168, 1, 1);
EthernetClient net; 
const char MQTT_server[] = "garden-lc.fritz.box";

void setup() {
  Serial.begin(9600);
  Serial.println("---- Init ----");
  Ethernet.begin(mac, ip, dns);
  Controller = new Watering::Controller(A0, 8, 500);
  Serial.println("---- Starting Main ----");
}

void loop() {
  Controller->update();  
  delay(500);  
}