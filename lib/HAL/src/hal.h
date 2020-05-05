#ifndef HAL
#define HAL

/*
We define some basic stuff that is needed in order to make the 
code we create as reusable as possible. This will be nice once we see 
any thing is getting too big an the ESP shout replace the arduino itself. 
*/

namespace hal{
    
    //A slot can be informad about the update of a signal
    template <class T>
    class slot{
        public:
            virtual void trigger(T value); //We get treiggered from the signal. It has the value value
            virtual T read(void);
    };

    //A signal can update the slot it is connected to
    template <class T>
    class signal{        
        public:
            slot<T>* a_slot;
            virtual void update() {a_slot->trigger(sig_read());} //We trigger the slot with our update

        protected: 
            virtual T sig_read();// = 0;
            
    };
    
    //We convert from T1 into T2
    template<class T1, class T2>
    class converter: public slot<T1>{        
        public:
            converter (signal<T1>* a_source, slot<T2>* a_target){
                a_source->a_slot = this;                
                a_slot = a_target;
            };
        protected:
            slot<T2>* a_slot;           
    }; //end converter

    //We split one signal and publish it to 2 slots. 
    template<class T1>
    class splitter: public slot<T1>{
        public:
            splitter(signal<T1>* a_source, slot<T1>* a_target, slot<T1>* b_target):target_1(a_target), target_2(b_target)
            {
                a_source->a_slot = this; 
            }
            virtual void trigger(T1 value)override{
                target_1->trigger(value);
                target_2->trigger(value);
            }

        private:
            slot<T1>* target_1;
            slot<T1>* target_2;
    }; //End splitter
    


}



#endif