#ifndef AUTOMATED_H
#define AUTOMATED_H

#include <config.h>

namespace automated{
    void OnTimer( void );
    String inputString = "";         // a String to hold incoming data
    bool stringComplete = false;  // whether the string is complete
}

#endif