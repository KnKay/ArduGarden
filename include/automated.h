#ifndef AUTOMATED_H
#define AUTOMATED_H
#include <Arduino.h>

namespace automated{
    void OnTimer( void );
    extern String inputString;         // a String to hold incoming data
    extern bool stringComplete;  // whether the string is complete
}

#endif