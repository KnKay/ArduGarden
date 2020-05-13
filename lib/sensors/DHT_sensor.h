#ifndef DHTSENSOR_C
#define DHTSENSOR_C


#include <hal.h>

namespace dhtsensor{
    //A DHT has 2 channels. This means we need to have 2 signals
    class dht_sensor: public hal::multi_signal{
        public: 
            virtual void update() override;

    }; //END DHT
}

#endif