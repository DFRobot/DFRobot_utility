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
uint8_t read_serial_with_timeout (HardwareSerial the_serial, 
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

#if defined(__AVR_ATmega32U4__)

//call like : read_serial_with_timeout (Serial, buffer, 12, 5)
uint8_t read_serial_with_timeout (Serial_ the_serial, 
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

#endif

//
uint8_t serial_reads (uint8_t *buf, uint8_t leng) {
	int sub;
	if (Serial.available ()) {
		for (sub=0; Serial.available () && sub<leng; sub++) {
			buf[sub] = Serial.read ();
		}
		return sub;
	}
	return 0;
}


#if defined(__AVR_ATmega32U4__)

uint8_t serial1_reads (uint8_t *buf, uint8_t leng) {
	int sub;
	if (Serial1.available ()) {
		for (sub=0; sub<leng; sub++) {
			buf[sub] = Serial1.read ();
		}
		return sub;
	}
	return 0;
}

#endif

//send to PC
void print_hex (uint8_t *buf, uint8_t leng) {
	for (uint8_t i=0; i<leng; i++) {
		Serial.print (buf[i], HEX);
		Serial.print (" ");
	}
	Serial.println ();
}

/*
   void serial_transmit (HardwareSerail serial1, HardwareSerail serial2) {
   int value = serial1.read ();
   if (value != -1)
   serial2.write (value);
   }
 */
