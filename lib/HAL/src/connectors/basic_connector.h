#ifndef HAL_CONNECTORS_BASIC_CONNECTOR
#define HAL_CONNECTORS_BASIC_CONNECTOR

#include <hal.h>
/*
    


*/ 

namespace hal {namespace connectors {
    
    namespace basic_connector{        
        class digital_splitter: public hal::splitter<bool>{
            public:
                digital_splitter(signal<bool>* a_source, slot<bool>* a_target, slot<bool>* b_target):splitter(a_source, a_target, b_target){};
                virtual bool read() override{return false;};
        }; //End splitter
     
        class value_splitter: public hal::splitter<int>{
            public:
                value_splitter(signal<int>* a_source, slot<int>* a_target, slot<int>* b_target):splitter(a_source, a_target, b_target){};
                virtual int read() override{return 100;};
        }; //End splitter
    }

}}//end namespace

#endif