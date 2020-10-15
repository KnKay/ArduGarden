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
extern hal::signal_base *signals[1];

//define slots
extern hal::slot_base *slots[1];

//the method that will init
void init_config ();

#endif