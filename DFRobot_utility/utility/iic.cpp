/**************************************************************************/
/*! 
	@file     iic.cpp
	@author   lisper (lisper.li@dfrobot.com)
	@license  LGPLv3 (see license.txt) 
  
	provide some useful function make it easy to read/write by iic
	
	Copyright (C) 2014 DFRobot
*/

#include <Arduino.h>
#include "Wire.h"

//iic master send data to slave
void iicWrite (uint8_t theSlave, uint8_t *theBuf, uint8_t theLeng) {
	Wire.beginTransmission(theSlave);
	Wire.write(theBuf, theLeng);
	Wire.endTransmission();
}

//iic slave send data to master
void iicWrite (uint8_t *theBuf, uint8_t theLeng) {
	Wire.write(theBuf, theLeng);
}

//iic read data from theSlave to theBuf
int iicRead (uint8_t theSlave, uint8_t *theBuf, uint8_t theLeng) {
	Wire.requestFrom(theSlave, theLeng);
	int leng = Wire.available ();  
	if (leng <= 0)
		return 0;
        if (leng != theLeng)
                return -1;
	for (int i=0; i<leng; i++) {
		theBuf[i] = Wire.read ();
	}
	return leng;
}

//iic read data from master to theBuf
int iicRead (uint8_t *theBuf, uint8_t theLeng) {
	int leng = Wire.available ();  
	if (leng <= 0)
		return 0;
        if (leng != theLeng)
                return -1;
	for (int i=0; i<leng; i++) {
		theBuf[i] = Wire.read ();
	}
	return leng;
}

