#include <Valve.h>

void Watering::Valve::trigger(bool set){
    long now = millis();
    long next_on = last_on + VALVE_THR;
    //Serial.println("---- Called Set ----"); 
    //If we are on manual we can not make any stuf
    if (hal::manual){
        return;
    }
    //We only want to set the valve active if this has not been made in the last x minutes! 
    if (set){
        if ((last_on + VALVE_THR) > now){            
            return; 
        }                
    }else{
        if (read()){
            last_on = now;
        }
    }
    hal::digital::digital_output::trigger(set);
}