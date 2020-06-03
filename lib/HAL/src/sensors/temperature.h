#ifndef HAL_SENSOR_TEMPERATURE_H
#define HAL_SENSOR_TEMPERATURE_H

#include <hal.h>



namespace hal {
    namespace sensors{
        class temperature: public hal::signal<int>{
            protected:
                 virtual int sig_read() override {return 0;};
        };
    }
}


#endif