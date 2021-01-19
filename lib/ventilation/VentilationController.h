#ifndef VENTILATION_CONTROLLER_H
#define VENTILATION_CONTROLLER_H

#include <hal.h> 
#include <MQTT.h>
#include <DHT_sensor.h>

namespace Ventilation {
    class VentilationController :  public hal::signal_base{

        public: 
            class TempTrigger : public hal::slot<int>{
                public: 
                    virtual void trigger(int value) override {
                        Serial.print("Temp: ");
                        Serial.println(value);
                        if (mqtt != 0){    
                            String test = *name;
                            mqtt->publish(test+"/Temp", String(value));                                                        
                        }
                    };
                    virtual int read(void) override {return 0;};
                    MQTTClient *mqtt;
                    String *name; 
            }; //Temptrigger
            class HumTrigger : public hal::slot<int>{
                public: 
                    virtual void trigger(int value) override {
                        Serial.print("Hum: ");
                        Serial.println(value);
                        if (mqtt != 0){    
                            String test = *name;
                            mqtt->publish(test+"/Humidity", String(value));                                                        
                        }
                    };
                    virtual int read(void) override {return 0;};
                    MQTTClient *mqtt;
                    String *name; 
            }; //Temptrigger
            VentilationController( byte pin, byte type, MQTTClient *mqtt = 0){
                dht = new dhtsensor::dht_sensor(pin, type);
                hum = new Ventilation::VentilationController::HumTrigger();
                hum->mqtt = mqtt;
                hum->name = &name;
                temp = new Ventilation::VentilationController::TempTrigger();
                temp->mqtt = mqtt;
                temp->name = &name;
                dht->temperature->a_slot = temp;
                dht->humidity->a_slot = hum;
                
            };
            void update(){
                dht->update();
            }
            dhtsensor::dht_sensor *dht;
            String name;    
            TempTrigger *temp; 
            HumTrigger *hum;
    }; //Controller

}


#endif //VENTILATION_CONTROLLER_H