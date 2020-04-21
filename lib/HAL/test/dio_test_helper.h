#include <digital_pin.h>
#include <hal.h>

namespace hal {


    namespace dio_helper{
        class digital_input: public hal::signal<bool>{
        public:
            virtual void update(){
             
                bool temp = sig_read();
                a_slot->trigger(temp);
            }
            digital_input(byte a_pin){                
            }  
            bool state = false;
        protected:
            virtual bool sig_read(void) override {return state;};
            byte pin;
    };

    class digital_output: public hal::slot<bool>{
        public:
            digital_output(int pin){};
            void toggle(void);
            virtual bool read() override {return state;};
            bool state;
            virtual void trigger(bool val) override {state = val;};
        protected: 
            int pin;
    };

    }

}