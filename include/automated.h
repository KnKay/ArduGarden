#ifndef AUTOMATED_H
#define AUTOMATED_H
#include <Arduino.h>
#include <config.h>
//We need some bool to be able to go into hand mode

namespace automated{
    void OnTimer( void );
    extern String inputString;         // a String to hold incoming data
    extern bool stringComplete;  // whether the string is complete
    extern bool manual_mode; 
}

#endif