/**************************************************************************/
/*! 
  @file     read_serial.h
  @author   lisper (lisper.li@dfrobot.com)
  @license  LGPLv3 (see license.txt) 

  provide some useful function make it easy to read many data from serial

  Copyright (C) DFRobot - www.dfrobot.com
 */
/**************************************************************************/

#include <Arduino.h>

//call like : read_serial_with_timeout (Serial1, buffer, 12, 5)
uint8_t serialRead (HardwareSerial the_serial, 
		uint8_t *buf, uint8_t leng, uint8_t timeout);

uint8_t serialReads (HardwareSerial the_serial, 
		uint8_t *buf, uint8_t leng, uint8_t timeout);

#if defined(__AVR_ATmega32U4__)
//call like : read_serial_with_timeout (Serial, buffer, 12, 5)
uint8_t serialRead (Serial_ the_serial, 
		uint8_t *buf, uint8_t leng, uint8_t timeout); 

uint8_t serialReads (Serial_ the_serial, 
		uint8_t *buf, uint8_t leng, uint8_t timeout); 
#endif


#if defined(__AVR_ATmega32U4__)
uint8_t serial1Read (uint8_t *buf, uint8_t leng); 
//send data to serial1
void serial1Write (uint8_t *buf, uint8_t leng);
#endif

#if defined(__AVR_ATmega2560__)
//send data to serial2
void serial2Write (uint8_t *theBuf, uint8_t leng);
#endif

//print data to PC in hex for test
void printHex (uint8_t *thebuf, uint8_t leng);

//
void pauseSerial (uint16_t delayTime);
//
void pauseSerial ();

#if defined(__AVR_ATmega32U4__)
void pauseSerial (Serial_ the_serial, uint16_t delayTime);
#endif

void pauseSerial (HardwareSerial the_serial, uint16_t delayTime);


