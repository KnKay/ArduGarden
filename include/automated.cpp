#include <automated.h>

//On Timer will be called... On Timer...
/*    
    - We need to trigger all SIGNALS! -> This will start what ever need to be done on the slots
*/
void automated::OnTimer(){
    //Signal triggering
    unsigned int signal_count  = sizeof(signals)/sizeof(signals[0]);
    for(int i = 0; i < signal_count; i++) {
        signals[i]->update();
    }
}

//This will take care of the serial event management. No more wating in any loop...
/*
    https://www.arduino.cc/en/Tutorial/BuiltInExamples/SerialEvent
    We may need to set some limits, what ever. This will all be done using serial and handled here...

*/
String automated::inputString = "";         // a String to hold incoming data
bool automated::stringComplete = false;  // whether the string is complete

void SerialEvent() {
	while(Serial.available()) {
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