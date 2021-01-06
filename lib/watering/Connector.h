#ifndef WATERING_Connector_H
#define WATERING_Connector_H

#include <Arduino.h>
#include <MQTT.h>
#include <Ethernet.h>

extern const char location[];

namespace Watering{
    class Connector{
        public: 
            bool begin(const char server[], EthernetClient a_net);
            void report(String topic, String value);
            void report(String topic, int value){report(topic, String(value));};
        
        private:
            EthernetClient net; 
            MQTTClient client;
            bool connect();
           

    }; //Connector
}


#endif //WATERING_Connector_H