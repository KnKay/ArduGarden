#ifndef SERVO_ACTOR_H
#define SERVO_ACTOR_H

#include <value_pin.h>
#include <Arduino.h>
#include <Servo.h>

namespace actors{
    //A Servo is dead simply. It can take a valu and set the oputput
    class servo_actor: public hal::value::value_output{
        public:
           servo_actor(byte a_pin);
        protected:
           virtual void trigger(int value) override; 
            Servo myservo; 
    };
};

#endif