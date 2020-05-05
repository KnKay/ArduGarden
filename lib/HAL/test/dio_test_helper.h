#ifndef HALTESTHELPER
#define HALTESTHELPER
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
        }; // End digital input

        class digital_output: public hal::slot<bool>{
            public:
                digital_output(int pin){};
                void toggle(void);
                virtual bool read() override {return state;};
                bool state;
                virtual void trigger(bool val) override {state = val;};
            protected: 
                int pin;
        }; //End digital outpu
    
        class int_input: public hal::signal<int> {
             public:
                virtual void update(){                
                    int temp = sig_read();
                    a_slot->trigger(temp);
                }      
                int state = 0;           
            protected:
                virtual int sig_read(void) override {return state;};                
        }; //End byte input

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
                    value_output(int pin);
                    void toggle(void);
                    virtual int read() override;
                    virtual void trigger(int) override;
                protected: 
                    int pin;
            };
    }

}

#endif