#ifndef CLI_H
#define CLI_H

#include <Arduino.h>

//We need some namespace to get the cli stuff sorted out of the normal functions
namespace cli {
    //We set int values, as we need to kn
    void set_val( String name, int val );
    //void set_bin( String name, int val );
    void get( void );
}


#endif