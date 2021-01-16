#include <Arduino.h>
#include  <config.h>
#include <WateringController.h>


#include <DHT_sensor.h>
DHT dht(2, DHT22);


bool hal::manual = false; 
Watering::Controller *Controller; 


#include <Ethernet.h>
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
byte ip[] = {192, 168, 1, 201};
IPAddress dns(192, 168, 1, 1);
EthernetClient net; 
MQTTClient client;

const char MQTT_server[] = "garden-lc.fritz.box";
String location = "/Garden/Beet1";


void messageReceived(String &topic, String &payload) {
  Serial.println("incoming: " + topic + " - " + payload);

  // Note: Do not use the client in the callback to publish, subscribe or
  // unsubscribe as it may cause deadlocks when other things arrive while
  // sending and receiving acknowledgments. Instead, change a global variable,
  // or push to a queue and handle it in the loop after calling `client.loop()`.
}

void connect() {
  Serial.print("connecting...");
  while (!client.connect("arduino", "public", "public")) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("\nconnected!");

  client.subscribe("/hello");
  client.subscribe("/Garden/Control");
  // client.unsubscribe("/hello");
}


void setup() {
  Serial.begin(9600);
  Serial.println("---- Init ----");
  Ethernet.begin(mac, ip, dns);
  client.begin(MQTT_server, net);
  client.onMessage(messageReceived);
  connect();
  Controller = new Watering::Controller(A0, 8, 500, 0, &client);
  Controller->name = location;
  Serial.println("---- Starting Main ----");
}


unsigned long lastMillis = 0;
void loop() {
  
  
  client.loop();

  if (!client.connected()) {
    connect();
  }

  // publish a message roughly every second.
  if (millis() - lastMillis > 1000) {
    lastMillis = millis();
    client.publish("/hello", "world");
    Controller->update();  
  } 
}