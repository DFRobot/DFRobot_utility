/**************************************************************************/
/*! 
 @file     read_serial_test.ino
 @author   lisper (lisper.li@dfrobot.com)
 @license  LGPLv3 (see license.txt) 
 
 	test split string on Uno
 	
 	Copyright (C) DFRobot - www.dfrobot.com
 */
/**************************************************************************/
#include "DFRobot_utility.h"

#define BUF_SIZE 64
#define CMD_SIZE 8

char buf[BUF_SIZE];
char *cmdbuf[CMD_SIZE];

void setup () {
        Serial.begin (9600);
}

void loop () {
        int leng = serialReads (Serial, (uint8_t*)buf, BUF_SIZE, 10);
        if (leng) {
                Serial.print ("get ");
                Serial.print (leng);
                Serial.println (" byte:");
                printHex ((uint8_t*)buf, leng);
                int cmdleng = split (cmdbuf, buf, CMD_SIZE);
                Serial.print ("get ");
                Serial.print (cmdleng);
                Serial.println (" string:");
                for (int i=0; i<cmdleng; i++) {
                        Serial.print (i);
                        Serial.print (" = ");
                        Serial.println (cmdbuf[i]);
                }
        }
}

