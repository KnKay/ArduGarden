#include <Arduino.h>
#include <unity.h>
#include <digital_pin.h>

namespace hal {

    void test_led_state_high(void) {
        digitalWrite(LED_BUILTIN, HIGH);
        TEST_ASSERT_EQUAL(HIGH, digitalRead(LED_BUILTIN));
    }

    void test_led_state_low(void) {
        digitalWrite(LED_BUILTIN, LOW);
        TEST_ASSERT_EQUAL(LOW, digitalRead(LED_BUILTIN));
    }    

    namespace digital{
        //We test the output by setting the pin as out, triggere it and see the result
        void test_output_read(void){
            digital_output* dut = new digital_output(LED_BUILTIN);
            digitalWrite(LED_BUILTIN, HIGH);                        
            TEST_ASSERT_EQUAL(true, dut->read());            
            digitalWrite(LED_BUILTIN, LOW);
            TEST_ASSERT_EQUAL(false, dut->read());             
        }

        void test_output_trigger_toggle(void){
            digital_output* dut = new digital_output(LED_BUILTIN);
            dut->trigger(true);                      
            TEST_ASSERT_EQUAL(true, dut->read());            
            dut->trigger(false);
            TEST_ASSERT_EQUAL(false, dut->read());             
            dut->toggle();
            TEST_ASSERT_EQUAL(true, dut->read());                        
        }

        //This test is not the most trustworthy thing! 
        void test_input(void)
        {
            digital_input* dut = new digital_input(LED_BUILTIN);
            digitalWrite(LED_BUILTIN, HIGH); 
            digital_output* help = new digital_output(14);            
            dut->a_slot = help;
            pinMode(LED_BUILTIN, OUTPUT);
            digitalWrite(LED_BUILTIN, HIGH);          
            dut->update();
            TEST_ASSERT_EQUAL(true, help->read());  
            digitalWrite(LED_BUILTIN, LOW);
            TEST_ASSERT_EQUAL(LOW, digitalRead(LED_BUILTIN));
            dut->update();
            TEST_ASSERT_EQUAL(false, help->read());  
        }
        

    }

    

}
