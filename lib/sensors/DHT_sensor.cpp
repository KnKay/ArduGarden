#include <DHT_sensor.h>

//We construct the sensor. This means we create 2 simple slots that shout an int to who ever is connected
dhtsensor::dht_sensor::dht_sensor (byte pin, byte type){
    temperature = new hal::sensors::temperature();
    humidity = new hal::sensors::humidity();
    sensor = new DHT(pin, type);
    sensor->begin();
}

/*
We want to perfom a read. This means we: 
- Update the Sensor
- Shout Temp
- Shout Hum
*/
void dhtsensor::dht_sensor::update(){
    sensor->read();
    temperature->a_slot->trigger((int) sensor->readTemperature());
    humidity->a_slot->trigger((int) sensor->readHumidity());
}