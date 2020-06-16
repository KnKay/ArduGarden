#ifndef HAL_VALUE_IN
#define HAL_VALUE_IN
#include <hal.h>
#include <Arduino.h>
/*
    We define a digital input. This will mostly be a switch or relay circuit. 

*/

//namespcae hal::digital { //This would be better to read but it is not compiling.
namespace hal { namespace value {
    
    class value_input: public hal::signal<int>{
        public:
            virtual void update(){a_slot->trigger(sig_read());}
            value_input(byte a_pin){
                //Need to adopt once we differ in framework
                pinMode(a_pin, INPUT);
                pin = a_pin;
            }  
        protected:
            virtual int sig_read(void) override;
            byte pin;
    };

    class value_output: public hal::slot<int>{
        public:
            value_output(byte a_pin){pin = a_pin;};
            void toggle(void);
            virtual int read() override{return state;};
            virtual void trigger(int value) override{state=value;};
        protected: 
            byte pin;
            int state;
    };


    
}}

#endif