#ifndef CLASSPIN_H
#define CLASSPIN_H

#include <hal.h>
/*
    A Class pin can be triggered by a capsulating class. 
    This will be useful once we have a sensor implementing more than one channel

*/
namespace hal{
    template<class T>
    class class_out_pin: public hal::signal<T> {
        public:                        
            virtual void update(){                               
                this->a_slot->trigger(state);
            }
            T state = 0;
        protected:
            virtual int sig_read(void) override {return state;};                
    };

    template<class T>
    class stateless_out_pin: public hal::signal<T> {
        public:                        
            virtual void update(){                               
              //  this->a_slot->trigger(state);
            }
            //T state = 0;
        protected:
            virtual int sig_read(void) override {return 0;};                
    };
}
#endif