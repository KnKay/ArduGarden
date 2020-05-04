#include <Arduino.h>
#include <unity.h>
#include <digital_pin.h>
#include <connectors/basic_converter.h>
#include "dio_test_helper.h"

namespace hal {

    namespace  connectors{ namespace test_basic_converter{
        void schmidt_trigger(void){
            dio_helper::digital_output * out = new dio_helper::digital_output(0);
            dio_helper::int_input * in = new dio_helper::int_input();
            in->state = 100;
            out->state = false;       
            //hal::connectors::basic_digital::inverter*dut = 
            new hal::connectors::basic_converter::schmidt_trigger(in, out, 50);            
            in->update();
            TEST_ASSERT_EQUAL(true, out->state);
            in->state = 40;
            in->update();
            TEST_ASSERT_EQUAL(false, out->state);
            //We connect a new trigger. This should prevent the old from getting used
            new hal::connectors::basic_converter::schmidt_trigger(in, out, 50, 40);            
            TEST_ASSERT_EQUAL(false, out->state);
            in->state = 55;
            in->update();
            TEST_ASSERT_EQUAL(true, out->state);
            in->state = 45;
            in->update();
            TEST_ASSERT_EQUAL(true, out->state);
            in->state = 35;
            in->update();
            TEST_ASSERT_EQUAL(false, out->state);
            
            in->state = 45;
            in->update();
            TEST_ASSERT_EQUAL(false, out->state);
            in->state = 55;
            in->update();
            TEST_ASSERT_EQUAL(true, out->state);

        }
    }}
}