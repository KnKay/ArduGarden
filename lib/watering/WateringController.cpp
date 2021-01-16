#include <WateringController.h>


Watering::Controller::Controller(byte Soil_pin, byte Valve_pin, int a_on, int a_off = 0, MQTTClient *a_connector = 0){
    Valve = new Watering::Valve(Valve_pin);
    Valve->name = "Ventil";
    mqtt = a_connector;
    Soil = new Watering::SoilMostSensor(Soil_pin);
    Soil->name = "Soil1";
    trigger1 = new Watering::Controller::ValveTrigger(Soil, Valve, a_on,0, mqtt);
    trigger1->name = &name;
}   

void Watering::Controller::ValveTrigger::trigger(int value){
    //ToDo: Report this 
    Serial.print("Soil1: ");
    Serial.println(value);
    if (mqtt != 0){    
        String test = *name;
        mqtt->publish(test+"/Soil", String(value));
        mqtt->publish(test+"/Valve", String(a_slot->read()));
        mqtt->publish(test+"/ManualMode", String(hal::manual));
        
    }
    hal::connectors::basic_converter::schmidt_trigger::trigger(value);
}