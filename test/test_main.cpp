#include <Arduino.h>
#include <unity.h>
#include <../lib/HAL/test/dio_test.h>

void setup() {
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    delay(2000);

    UNITY_BEGIN();    // IMPORTANT LINE!
    //RUN_TEST(hal::test_led_state_high);

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
        i++;
    }
    else if (i == 1) {
      UNITY_END(); // stop unit testing
    }
}