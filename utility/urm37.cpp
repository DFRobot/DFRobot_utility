/**************************************************************************/
/*! 
  @file     urm37.cpp
  @author   lisper (lisper.li@dfrobot.com)
  @license  LGPLv3 (see license.txt) 

  urm37 library use serial

  Copyright (C) DFRobot - www.dfrobot.com
 */
/**************************************************************************/

#include <DFRobot_utility.h>
#include <Arduino.h>
#include "urm37.h"


uint8_t distCmd[4] = {
	0x22, 0x00, 0x00, 0x22};
uint8_t dataBuf[4];

uint16_t urm37GetDist () {
	for (int i=0; i<4; i++) {
		Serial.write (distCmd[i]);
	}
	int leng = serialRead (Serial, dataBuf, 4, 4);
	if (leng) {
		//printHex (dataBuf, leng);
		if (dataBuf[0] == 0xff) {
			//Serial.println ("error!");
			return 0;
		} else {
			uint16_t dist = dataBuf[1]*255+dataBuf[2];
			//Serial.print ("==");
			//Serial.println (dist);
			return (dist);
		}        
	}
	return 0;
}

