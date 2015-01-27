/**************************************************************************/
/*! 
  @file     iic_slave.ino
  @author   lisper (lisper.li@dfrobot.com)
  @license  LGPLv3 (see license.txt) 


  Copyright (C) DFRobot - www.dfrobot.com
 */
/**************************************************************************/
#include "Wire.h"
#include "DFRobot_utility.h"
#include "utility/iic.h"

#define BUF_SIZE 6

uint8_t buf[BUF_SIZE] = {1, 2, 3, 4, 5, 6};

void setup () {
	Wire.begin (10);
	Wire.onRequest (requestEvent);
	Wire.onReceive (receiveEvent);
}

void loop () {
}

void receiveEvent (int HowMany) {
}

void requestEvent () {
         iicWrite (buf, BUF_SIZE);
}

