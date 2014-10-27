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
#define BUF_SIZE 32

uint8_t buf[BUF_SIZE];

void setup () {
	Serial.begin (9600);
}

void loop () {
	int leng = serialRead (Serial, buf, BUF_SIZE, 5);
	if (leng)
		printHex (buf, leng);
}


// read bytes data from the_serial
// uint8_t serialRead (HardwareSerial the_serial, 
// 		uint8_t *buf, uint8_t leng, uint8_t timeout);
// 
// uint8_t serialRead (Serial_ the_serial, 
// 		uint8_t *buf, uint8_t leng, uint8_t timeout); 
// 
// read bytes from Serial1
// uint8_t serial1_reads (uint8_t *buf, uint8_t leng); 
// 
// send by Serial to PC
// void print_hex (uint8_t *buf, uint8_t leng); 
// 
