#include <ADC_sensor.h>

/*
    We need to setup the pin mode and stuff like that! 

*/ 
adc_sensor::adc_sensor::adc_sensor(byte a_pin):pin(a_pin){

};


/*
    We simply read the input of out
    pin assigned ADC. There will not happen any conversation? 

*/
int adc_sensor::adc_sensor::sig_read(){
    return analogRead(pin);
};