#ifndef DHTSENSOR_C
#define DHTSENSOR_C


#include <hal.h>
#include <sensors/temperature.h>
#include <sensors/humidity.h>
#include <DHT.h>

namespace dhtsensor{
    //A DHT has 2 channels. This means we need to have 2 signals
    class dht_sensor: public hal::multi_signal{
        public: 
            dht_sensor(byte pin, byte type);
            virtual void update() override;
            hal::sensors::temperature * temperature; 
            hal::sensors::humidity * humidity;         
        
        protected:
            DHT * sensor = 0; 

    }; //END DHT
}

#endif