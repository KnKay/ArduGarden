#ifndef MOISTURESENSOR_C
#define MOISTURESENSOR_C


#include <ADC_sensor.h>

namespace adc_sensor{
    //A DHT has 2 channels. This means we need to have 2 signals
    class moisture_sensor: public adc_sensor{
            public:
                moisture_sensor(byte a_pin);//{};            
        protected:            

    }; //END DHT
}
#endif