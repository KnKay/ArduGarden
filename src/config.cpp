#include <config.h>

hal::slot_base *slots[1] = {0};


void init_config(){
    slots[0] = new hal::digital::digital_output(LED_BUILTIN);
}
