#ifndef ADCSENSOR_C
#define ADCSENSOR_C


#include <hal.h>
#include <Arduino.h>


namespace adc_sensor{
    //A DHT has 2 channels. This means we need to have 2 signals
    class adc_sensor: public hal::signal<int>{
            public:
                adc_sensor(byte a_pin);//{};
            protected:
                virtual int sig_read() override; //This is the only part we need to overwrite
                byte pin;
        protected:            

    }; //END DHT
}
#endif