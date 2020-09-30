#include <Arduino.h>
#include <unity.h>
#include <DHT_sensor.h>
#include "../lib/arduinohal/src/value_pin.h"

namespace sensors_test {
    int dht_pin = 9; 
    void set_pin(int pin){
        dht_pin = pin;
    }

    int dht_type= 22; 
    void set_type(int pin){
        dht_pin = pin;
    }

    void test_dht(void){
        dhtsensor::dht_sensor * dut = new dhtsensor::dht_sensor(dht_pin, dht_type);
        hal::value::value_output * temp = new hal::value::value_output(0);
        hal::value::value_output * hum = new hal::value::value_output(0);
        //Connect
        dut->humidity->a_slot = hum;
        dut->temperature->a_slot = temp;
        temp->trigger(123);
        hum->trigger(123);
        TEST_ASSERT_EQUAL(123, temp->read());
        TEST_ASSERT_EQUAL(123, hum->read());
        //Update the values
        dut->update();
        //test if the temp is plausible
        TEST_ASSERT_TRUE(temp->read()<40);
        TEST_ASSERT_TRUE(temp->read()>10);
        TEST_ASSERT_TRUE(hum->read()<90);
        TEST_ASSERT_TRUE(hum->read()>50);

    }
}