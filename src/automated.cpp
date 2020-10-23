#include <automated.h>
#include <cli.h>

String automated::inputString = "";         // a String to hold incoming data
bool automated::stringComplete = false;
bool automated::manual_mode = false;

//On Timer will be called... On Timer...
/*    
    - We need to trigger all SIGNALS! -> This will start what ever need to be done on the slots
*/
void automated::OnTimer(){
    //Signal triggering
/*    
    unsigned int signal_count  = sizeof(config::signals)/sizeof(config::signals[0]);
    for(int i = 0; i < signal_count; i++) {
        config::signals[i]->update();
    }
*/    

}



/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/
void serialEvent() {
  //ToDo: Disable Interrupt
    while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    automated::inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      //We make our string lower case and start what we need to do      
      automated::inputString.toLowerCase();
      if (automated::inputString.startsWith("set val")){
        //We explode the string

        
        //sscanf sollte hier genutzt werden        
      }
      if (automated::inputString.startsWith("get")){
        //we start on printing out what we know!
        cli::get();
      }

      automated::stringComplete = true;
    }
  }
  //ToDo: Enable Interrupt! 
}
