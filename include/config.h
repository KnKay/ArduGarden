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
hal::signal_base *signals[6];

//define slots
hal::digital::digital_output outi = hal::digital::digital_output(LED_BUILTIN);


#endif