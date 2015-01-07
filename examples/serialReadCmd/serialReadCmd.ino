/**************************************************************************/
/*! 
 @file     serialReadCmd.ino
 @author   lisper (lisper.li@dfrobot.com)
 @license  LGPLv3 (see license.txt) 
 
 	test read cmd from serial and get argc/argv
 	
 	Copyright (C) DFRobot - www.dfrobot.com
 */
/**************************************************************************/
#include "DFRobot_utility.h"

void setup () {
        Serial.begin (9600);
}

void loop () {
        serialReadCmd (Serial);
        if (argc > 0) {
                Serial.print ("cmd num is: ");
                Serial.println (argc);
                for (int i=0; i<argc; i++) {
                        Serial.print ("cmd");
                        Serial.print(i);
                        Serial.print (" is: ");
                        Serial.println (argv[i]);        // is string
                }
        }
}

// you will get argc and argv like the main function :int main (int argc, char *argv[]) in PC 

