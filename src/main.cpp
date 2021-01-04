#include <Arduino.h>
#include  <config.h>
#include <WateringController.h>

bool hal::manual = false; 
Watering::Controller *Controller; 

void setup() {
  Serial.begin(9600);
  Serial.println("---- Init ----");
  Controller = new Watering::Controller(A0, 8, 500);
  Serial.println("---- Starting Main ----");
}

void loop() {
  Controller->update();
  delay(500);  
}