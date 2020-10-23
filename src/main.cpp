#include <Arduino.h>
#include <config.h>
#include <automated.h>




void setup() {
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  automated::inputString.reserve(200);
  config::init();
}

void loop() {
  // print the string when a newline arrives:
  if (automated::stringComplete) {
    Serial.println(automated::inputString);
    // clear the string:
    automated::inputString = "";
    automated::stringComplete = false;

  }
  hal::digital::digital_output *heart;
  heart = config::slots[0];
  heart->trigger(100);
  delay(500);
  heart = config::get_hal("test");
  heart->trigger(0);
   delay(500);
}

