/**************************************************************************/
/*! 
  @file     SerialProtocol.cpp
  @author   lisper (lisper.li@dfrobot.com)
  @license  LGPLv3 (see license.txt) 

  serial protocol with checksum

  Copyright (C) DFRobot - www.dfrobot.com
 */
/**************************************************************************/

#include <DFRobot_utility.h>
#include <Arduino.h>
#include "SerialProtocol.h"

#define PRO_MAX 19	//max data length

//#define _debug	//send error message to Serial

//
uint8_t getChecksum (uint8_t *theData, uint8_t leng) {
	uint8_t sum = 0;
	for (uint8_t i=0; i<leng; i++) {
		sum += theData[i];
	}
	return sum;
}

//
boolean checksum (void *theData, uint8_t leng) {
	if (getChecksum ((uint8_t*) theData, leng-1) == ((uint8_t*)theData)[leng-1])
		return true;
	else 
		return false;
}

//
void bleSend (uint8_t *theData, uint8_t leng) {
	Serial.write (theData, leng);
}


//
void sendData (void *theData, uint8_t theLeng) {
	uint8_t pro_size = theLeng+3;
	uint8_t buffer[pro_size];
	buffer[0]= 0xff;
	buffer[1] = theLeng;
	memcpy ((void*)(buffer+2), theData, theLeng);
	buffer[pro_size-1] = getChecksum ((uint8_t*)theData, pro_size-1);
#ifdef _debug
	printHex (buffer, pro_size);
#endif
	bleSend ((uint8_t*)(buffer), pro_size);
}

//
int readData (void *theData, uint8_t theLeng) {
	if (theLeng > PRO_MAX)
		return -1;
	uint8_t pro_size = theLeng+3;
	uint8_t buffer[pro_size];
	int leng = serialRead (Serial, buffer, pro_size, 4);
	if (leng == 0) {
		return 0;
	}


	if (leng != pro_size) {
#ifdef _debug
		Serial.print ("data leng error:");
		printHex (buffer, leng);
#endif
		return -2;        
	}
	if (!checksum (buffer, leng)) {
#ifdef _debug
		Serial.println ("checksum error");
		printHex (buffer, leng);
		Serial.print ("checksum is:");
		Serial.println (getChecksum (buffer, leng-1), HEX);
#endif
		return -3; 
	}
	memcpy ((void*)theData, (void*)(buffer+2), theLeng);
}


