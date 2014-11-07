/**************************************************************************/
/*! 
  @file     read_serial.cpp
  @author   lisper (lisper.li@dfrobot.com)
  @license  LGPLv3 (see license.txt) 
  
	provide some useful function make it easy to read many data from serial
	
	Copyright (C) DFRobot - www.dfrobot.com
*/
/**************************************************************************/

#include <Arduino.h>

//call like : read_serial_with_timeout (Serial1, buffer, 12, 5)
uint8_t serialRead (HardwareSerial the_serial, 
		uint8_t *buf, uint8_t leng, uint8_t timeout) {
	int sub;
	if (the_serial.available ()) {
		for (sub=0; sub<leng; sub++) {
			uint32_t start_time = millis ();
			while (!the_serial.available ()) {
				if (millis () - start_time > timeout)
					return sub;
			}
			buf[sub] = the_serial.read ();
		}
		return sub;
	}
	return 0;
}

uint8_t serialReads (HardwareSerial the_serial, 
		uint8_t *buf, uint8_t leng, uint8_t timeout) {
	int sub;
	if (the_serial.available ()) {
		for (sub=0; sub<leng; sub++) {
			uint32_t start_time = millis ();
			while (!the_serial.available ()) {
				if (millis () - start_time > timeout)
					return sub;
			}
			buf[sub] = the_serial.read ();
		}
		buf[sub] = '\0';
		return sub;
	}
	return 0;
}

#if defined(__AVR_ATmega32U4__)

//call like : read_serial_with_timeout (Serial, buffer, 12, 5)
uint8_t serialRead (Serial_ the_serial, 
		uint8_t *buf, uint8_t leng, uint8_t timeout) {
	int sub;
	if (the_serial.available ()) {
		for (sub=0; sub<leng; sub++) {
			uint32_t start_time = millis ();
			while (!the_serial.available ()) {
				if (millis () - start_time > timeout)
					return sub;
			}
			buf[sub] = the_serial.read ();
		}
		return sub;
	}
	return 0;
}

uint8_t serialReads (Serial_ the_serial, 
		uint8_t *buf, uint8_t leng, uint8_t timeout) {
	int sub;
	if (the_serial.available ()) {
		for (sub=0; sub<leng; sub++) {
			uint32_t start_time = millis ();
			while (!the_serial.available ()) {
				if (millis () - start_time > timeout)
					return sub;
			}
			buf[sub] = the_serial.read ();
		}
		buf[sub] = '\0';
		return sub;
	}
	return 0;
}

#endif


#if defined(__AVR_ATmega32U4__)

uint8_t serial1Read (uint8_t *buf, uint8_t leng) {
	int sub;
	if (Serial1.available ()) {
		for (sub=0; sub<leng; sub++) {
			buf[sub] = Serial1.read ();
		}
		return sub;
	}
	return 0;
}


//send data to serial1
void serial1Write (uint8_t *buf, uint8_t leng) {
	for (int i=0; i<leng; i++) {
		Serial1.write (buf[i]);
	}
}

#endif

#if defined(__AVR_ATmega2560__)

//send data to serial2
void serial2Write (uint8_t *theBuf, uint8_t leng) {
	for (int i=0; i<leng; i++) {
		Serial2.write (theBuf[i]);
	}
}

#endif

//print data to PC in hex for test
void printHex (uint8_t *thebuf, uint8_t leng) {
	Serial.print (leng);
	Serial.print (":");
	for (int i=0; i<leng; i++) {
		Serial.print (thebuf[i], HEX);
		Serial.print (" ");
	}
	Serial.println ();
}


//
void pauseSerial (uint16_t delayTime) {
	uint32_t nowTime = millis (); 
	Serial.println ("input anything to start:");
	while ((millis () - nowTime < delayTime) && !Serial.available ());
	Serial.println ("start running...");
}

//
void pauseSerial () {
	Serial.println ("input anything to start:");
	while (!Serial.available ());
	Serial.println ("start running...");
}

