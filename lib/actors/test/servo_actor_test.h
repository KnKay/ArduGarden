#include <Arduino.h>
#include <unity.h>
#include <servo_actor.h>


namespace actors_test {
    int servo_pin = 9; 
    void set_pin(int pin){
        servo_pin = pin;
    }



    void test_dht(void){
        actors::servo_actor *dut = new actors::servo_actor(servo_pin);        
    }
}