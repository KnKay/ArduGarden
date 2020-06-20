#include <servo_actor.h>


actors::servo_actor::servo_actor(byte a_pin):value_output(a_pin)
{
    myservo.attach(a_pin);
}

void actors::servo_actor::trigger(int value){
    myservo.write(value);
}