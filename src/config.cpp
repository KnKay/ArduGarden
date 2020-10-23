#include <config.h>

hal::slot_base *config::slots[1] = {0};


void config::init(){
    config::slots[0] = new hal::digital::digital_output(LED_BUILTIN);
    config::slots[0]->name = "test";
}

//We iterate until we find a slot
//ToDo: Make this more abstract and coming from hal
hal::hal_base* config::get_hal(String name, bool slot){
    if (slot){
        int count  = sizeof(config::slots)/sizeof(config::slots[0]);
        for(int i = 0; i < count; i++) {
            if (name == config::slots[i]->name ){
                return config::slots[i];
            }            
        }
    }else {
        int signal_count  = sizeof(config::signals)/sizeof(config::signals[0]);
        for(int i = 0; i < signal_count; i++) {
            if (name == config::signals[i]->name ){
                return config::signals[i];
            }            
        }
    }
    return 0;
}

