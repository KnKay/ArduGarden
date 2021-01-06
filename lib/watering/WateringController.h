#ifndef WATERING_CONTROLLER_H
#define WATERING_CONTROLLER_H

#include <Arduino.h>
#include <hal.h>
#include <connectors/basic_converter.h>
#include <connectors/basic_connector.h>
#include <SoilMoist.h>
#include <Valve.h>
#include <Connector.h>
#include <Ethernet.h>

extern EthernetClient net; 
extern const char MQTT_server[];
extern const char location[];

namespace Watering{
    //The controller will take care of some steps. It will not actually controll all the stuff. 
    //The simple signal slot stuff will be directly connected! 
    class Controller: public hal::signal_base{
        public:
            Controller(byte Soil_pin, byte Valve_pin, int a_on, int a_off = 0);  
            Watering::SoilMostSensor *Soil;
            Watering::Valve *Valve;
            virtual void update() override{
                Soil->update();
            };   
            class ValveTrigger: public hal::connectors::basic_converter::schmidt_trigger{
                public: 
                    ValveTrigger(hal::signal<int>* a_source, slot<bool>* a_target, int a_on, int a_off = 0, Watering::Connector *a_mqtt = 0 ):hal::connectors::basic_converter::schmidt_trigger(a_source, a_target, a_on, a_off),mqtt(a_mqtt){};
                    virtual void trigger(int value) override;
                    Watering::Connector *mqtt = 0;
            };
            ValveTrigger *trigger1; 
        protected:
            
        private:
            Watering::Connector mqtt;
    };    
   
}//Watering


#endif