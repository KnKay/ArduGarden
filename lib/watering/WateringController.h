#ifndef WATERING_CONTROLLER_H
#define WATERING_CONTROLLER_H

#include <Arduino.h>
#include <hal.h>
#include <connectors/basic_converter.h>
#include <connectors/basic_connector.h>
#include <SoilMoist.h>
#include <Valve.h>

namespace Watering{
    //The controller will take care of some steps. It will not actually controll all the stuff. 
    //The simple signal slot stuff will be directly connected! 
    class Controller: public hal::signal_base{
        public:
            Controller(byte Soil_pin, byte Valve_pin, int a_on);        
            Watering::SoilMostSensor *Soil;
            Watering::Valve *Valve;
            virtual void update() override{
                Soil->update();
            };   
            class ValveTrigger: public hal::connectors::basic_converter::schmidt_trigger{
                public: 
                    ValveTrigger(hal::signal<int>* a_source, slot<bool>* a_target, int a_on, int a_off = 0):hal::connectors::basic_converter::schmidt_trigger(a_source, a_target, a_on, a_off){};
                    virtual void trigger(int value) override;
            };
            ValveTrigger *trigger1; 
        protected:
            
    };    
   
}//Watering


#endif