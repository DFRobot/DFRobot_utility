/**************************************************************************/
/*! 
  @file     checksum.cpp
  @author   lisper (lisper.li@dfrobot.com)
  @license  LGPLv3 (see license.txt) 

  provide some useful function make it easy to get checksum

  Copyright (C) DFRobot - www.dfrobot.com
 */
/**************************************************************************/

#include "Arduino.h"

uint8_t checksum_add (uint8_t *data, uint8_t leng) {
	uint8_t sum = 0;
	for (uint8_t i=0; i<leng; i++)
		sum += data[i];
	return sum;
}

uint8_t checksum_nadd (uint8_t *data, uint8_t leng) {
	uint8_t sum = 0;
	for (uint8_t i=0; i<leng; i++)
		sum += data[i];
	return ~sum;
}

uint8_t checksum_xor (uint8_t *data, uint8_t leng) {
	uint8_t sum = 0;
	for (uint8_t i=0; i<leng; i++)
		sum ^= data[i];
	return sum;
}

uint8_t checksum_add_n (uint8_t *data, uint8_t left, uint8_t right) {
	uint8_t sum = 0;
	for (uint8_t i=left; i<=right; i++)
		sum+= data[i];
	return sum;
}

uint8_t checksum_nadd_n (uint8_t *data, uint8_t left, uint8_t right) {
	uint8_t sum = 0;
	for (uint8_t i=left; i<=right; i++)
		sum += data[i];
	return ~sum;
}

uint8_t checksum_xor_n (uint8_t *data, uint8_t left, uint8_t right) {
	uint8_t sum = 0;
	for (uint8_t i=left; i<=right; i++)
		sum ^= data[i];
	return sum;
}


