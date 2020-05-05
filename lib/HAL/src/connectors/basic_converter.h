#ifndef HAL_CONNECTORS_BASIC_CONVERTER
#define HAL_CONNECTORS_BASIC_CONVERTER

#include <hal.h>
/*
    


*/ 

namespace hal {namespace connectors {
    
    namespace basic_converter{
        class schmidt_trigger:public converter<int, bool>
        {
            public:
                schmidt_trigger(signal<int>* a_source, slot<bool>* a_target, int a_on, int a_off = 0): converter(a_source, a_target), on(a_on), off(a_off){
                     if (a_off == 0)
                        off=a_on; //We have no hysteresis
                };                                
                virtual void trigger(int value)override
                {
                    if(value > on)
                    {
                        a_slot->trigger(true);
                    }
                    if(value < off)
                    {
                        a_slot->trigger(false);
                    }
                };
                virtual int read() override {return 0;} //Das noch nicht so elegant
            private:
                int on;
                int off;
                
        };                        
    }
}}

#endif