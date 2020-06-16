
#include <Arduino.h>
#include <unity.h>
#include <ADC_sensor.h>
#include "../lib/HAL/src/value_pin.h"

namespace sensors_test {
    int adc_pin = 9; 
    void set_pin(int pin){
        adc_pin = pin;
    }

    /*ToDo: got some stuff to produce a well known value*/

    void test_dht(void){        
        adc_sensor::adc_sensor *dut = new adc_sensor::adc_sensor(adc_pin);
        hal::value::value_output * hum = new hal::value::value_output(0);
        //Connect
        dut->a_slot = hum;                
        hum->trigger(123);        
        TEST_ASSERT_EQUAL(123, hum->read());
        //Update the values
        dut->update();
        //test if the temp is plausible
        TEST_ASSERT_TRUE(hum->read()<80);
        TEST_ASSERT_TRUE(hum->read()>50);

    }
}