#include <WateringController.h>


Watering::Controller::Controller(byte Soil_pin, byte Valve_pin, int a_on){
    Valve = new Watering::Valve(Valve_pin);
    Soil = new Watering::SoilMostSensor(Soil_pin);
    trigger1 = new Watering::Controller::ValveTrigger(Soil, Valve, a_on);
    
}   

void Watering::Controller::ValveTrigger::trigger(int value){
    //ToDo: Report this 
    Serial.print("Soil1: ");
    Serial.println(value);
    hal::connectors::basic_converter::schmidt_trigger::trigger(value);
}