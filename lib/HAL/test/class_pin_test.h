#ifndef CLASSPINTEST_H
#define CLASSPINTEST_H

#include <class_pin.h>

#include <Arduino.h>
#include <unity.h>
#include <digital_pin.h>
#include "dio_test_helper.h"
#include <value_pin.h>

namespace hal {

    void classpin_test(){
        class_out_pin<int>* dut = new class_out_pin<int>();
        hal::value::value_output* helper = new hal::value::value_output(0);
        dut->a_slot = helper;         
        dut->state = 50;
        dut->update();
        TEST_ASSERT_EQUAL(50, dut->state); 
        TEST_ASSERT_EQUAL(50,helper->read() ); 
    }
    
    void stateless_classpin_test(){
        stateless_out_pin<int>* dut = new stateless_out_pin<int>();
        hal::value::value_output* helper = new hal::value::value_output(0);
        dut->a_slot = helper;                 
        dut->update(100);
        
        TEST_ASSERT_EQUAL(100,helper->read() ); 
    }
}

#endif