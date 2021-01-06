#include <Connector.h>

bool Watering::Connector::begin(const char server[], EthernetClient a_net){
    net = a_net;   
    client.begin(server, a_net);
    connect();
    return false;
}

bool Watering::Connector::connect(){
    Serial.print("connecting...");
    for (int i = 0; i < 5; i++){
        if (!client.connect("arduino")){
            Serial.print(".");
            delay(1000);
        }
        else {
            Serial.println("\nconnected!");
            return true;
        }
    }    
    return false;
}

void Watering::Connector::report(String topic, String value){
    client.publish(location+topic, value);
}