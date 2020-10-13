#ifndef CONFIG_H
#define CONFIG_H

#include <hal.h>
#include <digital_pin.h>
#include <value_pin.h>
#include <pwm_pin.h>
#include <connectors/basic_converter.h>
#include <connectors/basic_digital.h>
#include <connectors/basic_connector.h>

//define signals
extern hal::signal_base *signals[6];

//define slots
extern hal::digital::digital_output heartbeat;
extern hal::slot_base *slots[6];

//We need to set the vars. This need to be in an internal, to avoid multiple declaratrion of messages! 
inline void set_vars(void){
    hal::digital::digital_output heartbeat = hal::digital::digital_output(LED_BUILTIN);
}

#endif