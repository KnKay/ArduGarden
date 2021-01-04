#include <SoilMoist.h>

int Watering::SoilMostSensor::sig_read(){
    int retval = 0; 
    retval = analogRead(this->pin);    
    return retval;
}