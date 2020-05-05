#include <Arduino.h>
#include <unity.h>
#include <digital_pin.h>
#include <value_pin.h>
#include <connectors/basic_digital.h>
#include <connectors/basic_connector.h>
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
        } //End inverter

        void test_connector_y(void){
            dio_helper::digital_output * out = new dio_helper::digital_output(0);
            dio_helper::digital_output * out2 = new dio_helper::digital_output(0);
            dio_helper::digital_input * in = new dio_helper::digital_input(0);
            in->state = true;
            out->state = false;   
            out2->state = false;     
            TEST_ASSERT_EQUAL(false, out->state);
            TEST_ASSERT_EQUAL(false, out2->state);
            //hal::connectors::basic_digital::inverter*dut = 
            new hal::connectors::basic_connector::digital_splitter(in, out, out2);            
            in->update();
            TEST_ASSERT_EQUAL(true, out->state);
            TEST_ASSERT_EQUAL(true, out2->state);
        }
    }
    
    namespace value{
            void test_connector_y(void){
            hal::value::value_output * out = new hal::value::value_output(0);
            hal::value::value_output * out2 = new hal::value::value_output(0);
            dio_helper::int_input * in = new dio_helper::int_input();
            in->state = 23;
            out->trigger(100);
            out2->trigger(100);  
            TEST_ASSERT_EQUAL(100, out->read());
            TEST_ASSERT_EQUAL(100, out2->read());   
            //hal::connectors::basic_digital::inverter*dut = 
            new hal::connectors::basic_connector::value_splitter(in, out, out2);            
            in->update();
            TEST_ASSERT_EQUAL(23, out->read());
            TEST_ASSERT_EQUAL(23, out2->read());
        }

    }
    
}