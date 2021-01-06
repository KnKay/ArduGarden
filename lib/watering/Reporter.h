#ifndef WATERING_REPORTER_H
#define WATERING_REPORTER_H

#include <Arduino.h>
#include <MQTT.h>
#include <Ethernet.h>

namespace Watering{
    class Reporter{
        public: 
            bool begin(const char server[], EthernetClient a_net);
            void report(String topic, String value);
            void report(String topic, int value){report(topic, String(value));};
        
        private:
            EthernetClient net; 
            MQTTClient client;
            bool connect();

    }; //Reporter
}


#endif //WATERING_REPORTER_H