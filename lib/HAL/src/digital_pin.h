#ifndef HAL_DIGITAL_IN
#define HAL_DIGITAL_IN
#include <hal.h>
/*
    We define a digital input. This will mostly be a switch or relay circuit. 

*/

//namespcae hal::digital { //This would be better to read but it is not compiling.
namespace hal { namespace digital {
    
    class digital_input: public hal::signal<bool>{};

    class digital_output: public hal::slot<bool>{};
    
}}

#endif