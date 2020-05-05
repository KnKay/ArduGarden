#ifndef HAL_CONNECTORS_BASICDIGITAL
#define HAL_CONNECTORS_BASICDIGITAL

#include <hal.h>
/*
    


*/ 
namespace hal {namespace connectors {
    namespace basic_digital{
       
        class inverter:public converter<bool, bool>{
            public:
                inverter (signal<bool>* a_source, slot<bool>* a_target):converter(a_source, a_target){};
                virtual void trigger(bool value)override
                {                    
                    a_slot->trigger(!value);
                };
                virtual bool read() override {return false;}            
        }; //end inverter
        

    }//end namespace 
}}

#endif