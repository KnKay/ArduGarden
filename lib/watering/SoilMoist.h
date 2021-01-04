#ifndef SOILMOST_H
#define SOILMOST_H

#include <value_pin.h>

namespace Watering {
    // We define our SoilMost Sensor. This piece will give us the inforamtion about the soil. 
    class SoilMostSensor: public hal::value::value_input{
        public:
            SoilMostSensor(byte a_pin): hal::value::value_input(a_pin){};
        protected: 
            virtual int sig_read();
    };
} // namespace Watering

#endif