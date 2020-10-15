#include <Arduino.h>
#include <config.h>

#include <automated.h>


void setup() {
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  automated::inputString.reserve(200);
  init_config();
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
  heart = slots[0];
  heart->trigger(100);
}

