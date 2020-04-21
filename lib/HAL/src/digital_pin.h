#ifndef HAL_DIGITAL_IN
#define HAL_DIGITAL_IN
#include <hal.h>
#include <Arduino.h>
/*
    We define a digital input. This will mostly be a switch or relay circuit. 

*/

//namespcae hal::digital { //This would be better to read but it is not compiling.
namespace hal { namespace digital {
    
    class digital_input: public hal::signal<bool>{
        public:
            virtual void update(){a_slot->trigger(sig_read());}
            digital_input(byte a_pin){
                //Need to adopt once we differ in framework
                pinMode(a_pin, INPUT);
                pin = a_pin;
            }  
        protected:
            virtual bool sig_read(void) override;
            byte pin;
    };

    class digital_output: public hal::slot<bool>{
        public:
            digital_output(int pin);
            void toggle(void);
            virtual bool read() override;
            virtual void trigger(bool) override;
        protected: 
            int pin;
    };


    
}}

#endif