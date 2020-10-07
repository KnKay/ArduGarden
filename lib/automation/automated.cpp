#include <automated.h>
    String automated::inputString = "";         // a String to hold incoming data
    bool automated::stringComplete = false;

//On Timer will be called... On Timer...
/*    
    - We need to trigger all SIGNALS! -> This will start what ever need to be done on the slots
*/
void automated::OnTimer(){
    //Signal triggering
    /*
    unsigned int signal_count  = sizeof(signals)/sizeof(signals[0]);
    for(int i = 0; i < signal_count; i++) {
        signals[i]->update();
    }
    */
}


/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/
void serialEvent() {

    while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    automated::inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      automated::stringComplete = true;
    }
  }

}

