/**************************************************************************/
/*! 
	@file     iic.h
	@author   lisper (lisper.li@dfrobot.com)
	@license  LGPLv3 (see license.txt) 
  
	provide some useful function make it easy to read/write by iic
	
	Copyright (C) 2014 DFRobot
*/

#include <Arduino.h>
#include "Wire.h"


//i2c master send data to slaver
void iicWrite (uint8_t theSlave, uint8_t *theBuf, uint8_t theLeng); 

//i2c slave send data to master
void iicWrite (uint8_t *theBuf, uint8_t theLeng); 

//iic read data from theSlave to theBuf
int iicRead (uint8_t theSlave, uint8_t *theBuf, uint8_t theLeng); 

//iic read data from master to theBuf
int iicRead (uint8_t *theBuf, uint8_t theLeng); 
