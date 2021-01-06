#include <WateringController.h>


Watering::Controller::Controller(byte Soil_pin, byte Valve_pin, int a_on, int a_off = 0){
    Valve = new Watering::Valve(Valve_pin);
    Soil = new Watering::SoilMostSensor(Soil_pin);
    trigger1 = new Watering::Controller::ValveTrigger(Soil, Valve, a_on);
    //We initialize our Reporter
    mqtt.begin(MQTT_server, net);
    trigger1->mqtt = &mqtt;
}   

void Watering::Controller::ValveTrigger::trigger(int value){
    //ToDo: Report this 
    Serial.print("Soil1: ");
    Serial.println(value);
    if (mqtt != 0){
        mqtt->report("/Soil1", value);
    }
    hal::connectors::basic_converter::schmidt_trigger::trigger(value);
}