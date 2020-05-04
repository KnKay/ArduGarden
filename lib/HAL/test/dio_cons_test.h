#include <Arduino.h>
#include <unity.h>
#include <digital_pin.h>
#include <connectors/basic_digital.h>
#include "dio_test_helper.h"

namespace hal {

    namespace digital{
        void test_connector_inverter(void){
            dio_helper::digital_output * out = new dio_helper::digital_output(0);
            dio_helper::digital_input * in = new dio_helper::digital_input(0);
            in->state = false;
            out->state = false;       
            //hal::connectors::basic_digital::inverter*dut = 
            new hal::connectors::basic_digital::inverter(in, out);            
            in->update();
            TEST_ASSERT_EQUAL(true, out->state);
        }
    }
}