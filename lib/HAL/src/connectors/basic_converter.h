#ifndef HAL_CONNECTORS_BASIC_CONVERTER
#define HAL_CONNECTORS_BASIC_CONVERTER

#include <hal.h>
/*
    


*/ 

namespace hal {namespace connectors {
    
    namespace basic_converter{
        template<class T1,class T2>
        class schmidt_trigger:public converter<float, bool>
        {
            public:
                schmidt_trigger(T1* a_source,slot<T2>* a_target, int on, int off = 0):on(on), off(off), converter(a_source, a_target){};                                
                virtual void trigger(T1 value)override
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
            private:
                int on, off;
                
        };                
    }
}}

#endif