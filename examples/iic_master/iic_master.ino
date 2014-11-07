/**************************************************************************/
/*! 
 @file     read_serial_test.ino
 @author   lisper (lisper.li@dfrobot.com)
 @license  LGPLv3 (see license.txt) 
 
 test read_serial_with_timeout ()
 
 Copyright (C) DFRobot - www.dfrobot.com
 */
/**************************************************************************/
#include "DFRobot_utility.h"
#include "utility/iic.h"

#define BUF_SIZE 6

uint8_t buf[BUF_SIZE];

void setup () {
        Wire.begin ();
}

void loop () {
        int num = iicRead (2,buf, BUF_SIZE);
        if (num > 0)
                printHex (buf, num);
        delay (1000);
}


