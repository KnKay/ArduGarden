#ifndef VALVE_H
#define VALVE_H

#include <Arduino.h>
#include <digital_pin.h>

//We define a one minute threshhold
#define VALVE_THR 60LL*1000LL

namespace Watering{
    //We use the base class. We need to overwrite the actual implementation to water for only a specific time! 
    class Valve : public hal::digital::digital_output {
        public:
            Valve(byte a_pin): hal::digital::digital_output(a_pin){};
            virtual void trigger(bool) override;
        protected:
            long last_on = -1*VALVE_THR; 
    };
} // Watering


#endif