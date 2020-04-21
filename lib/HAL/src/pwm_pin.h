#ifndef HAL_PWM
#define HAL_PWM
#include <hal.h>

namespace hal{namespace pwm{
    class pwm_output: public hal::slot<int>
    {

    };
}}

#endif