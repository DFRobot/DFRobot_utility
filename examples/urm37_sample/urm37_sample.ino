/**************************************************************************/
/*! 
 @file     urm37_sample.ino
 @author   lisper (lisper.li@dfrobot.com)
 @license  LGPLv3 (see license.txt) 
 
 	test urm37 on Uno
 	
 	Copyright (C) DFRobot - www.dfrobot.com
 */
/**************************************************************************/

#include <DFRobot_utility.h>
#include <utility/urm37.h>

void setup () {
        Serial.begin (9600);
}

void loop () {
        uint16_t dist = urm37GetDist ();
        if (dist) {
                Serial.println (dist);
        }
        delay (20);
}