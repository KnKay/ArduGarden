#include <Arduino.h>
#include <unity.h>

#include <../lib/HAL/test/dio_test.h>
#include <../lib/HAL/test/dio_cons_test.h>
#include <../lib/HAL/test/basic_converter_test.h>
#include <../lib/HAL/test/class_pin_test.h>
#include <../lib/sensors/test/DHT_sensor_test.h>

void setup() {
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    delay(2000);

    UNITY_BEGIN();    // IMPORTANT LINE!
  //  RUN_TEST(hal::test_led_state_high);

    //pinMode(LED_BUILTIN, OUTPUT);
}

uint8_t i = 0;


void loop() {
    if (i < 1)
    {
        RUN_TEST(hal::digital::test_output_read);
        delay(50);
        RUN_TEST(hal::digital::test_output_trigger_toggle);
        delay(50);
        RUN_TEST(hal::digital::test_input);
        delay(50);
        RUN_TEST(hal::digital::test_connector_inverter);
        delay(50);
        RUN_TEST(hal::connectors::test_basic_converter::schmidt_trigger);
        delay(50);
        RUN_TEST(hal::digital::test_connector_y);
        delay(50);
        RUN_TEST(hal::value::test_connector_y);
        delay(50);
        RUN_TEST(hal::classpin_test);
        delay(50);
        RUN_TEST(hal::stateless_classpin_test);
        delay(50);
        RUN_TEST(sensors_test::test_dht);
        i++;
    }
    else if (i == 1) {
      UNITY_END(); // stop unit testing
    }
}