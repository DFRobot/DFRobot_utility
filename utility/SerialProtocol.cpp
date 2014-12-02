#include <DFRobot_utility.h>
#include <Arduino.h>
#include "SerialProtocol.h"

#define PRO_MAX 19

//
uint8_t getChecksum (uint8_t *theData, uint8_t leng) {
	uint8_t sum = 0;
	for (uint8_t i=0; i<leng-1; i++) {
		sum += theData[i];
	}
	return sum;
}

//
boolean checksum (void *theData, uint8_t leng) {
	if (getChecksum ((uint8_t*) theData, leng) == ((uint8_t*)theData)[leng])
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
	buffer[pro_size] = getChecksum ((uint8_t*)theData, pro_size);
	bleSend ((uint8_t*)(buffer), pro_size);
}

//
int readData (void *theData, uint8_t theLeng) {
	if (theLeng > PRO_MAX)
		return -10;
	uint8_t pro_size = theLeng+3;
	uint8_t buffer[pro_size];
	int leng = serialRead (Serial, buffer, pro_size, 4);
	if (leng == 0) {
		return 0;
	}
	if (leng != pro_size) {
		Serial.print ("data leng error:");
		Serial.println (leng);   
		return -1;        
	}
	if (!checksum (buffer, leng)) {
		Serial.println ("checksum error");
		return -2; 
	}
	printHex (buffer, leng);
	memcpy ((void*)theData, (void*)(buffer+2), theLeng);
}


