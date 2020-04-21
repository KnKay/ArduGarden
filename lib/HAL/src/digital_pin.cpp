#include <digital_pin.h>
#include <Arduino.h>

namespace hal { namespace digital {

    digital_output::digital_output(int a_pin)
    {    
        //Need to adopt once we differ in framework
        pinMode(a_pin, OUTPUT);
        pin = a_pin;            
    }

    bool digital_output::read()
    {                   
       return (digitalRead(pin) == HIGH);        
    }

    void digital_output::trigger(bool high)
    {
        if (high == true)
            digitalWrite(pin, HIGH);
        else
            digitalWrite(pin, LOW);
    }

    void digital_output::toggle()
    {
        trigger(!read());
    }
     
    bool digital_input::read(){       
        return (digitalRead(pin) == HIGH); 
    }

}} //End namespace shit