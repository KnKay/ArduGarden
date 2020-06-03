#ifndef HAL_SENSOR_HUMIDITY_H
#define HAL_SENSOR_HUMIDITY_H

#include <hal.h>



namespace hal {
    namespace sensors{
        class humidity: public hal::signal<int>{
            protected:
                 virtual int sig_read() override {return 0;};
        };
    }
}


#endif