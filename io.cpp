/**************************************************************************/
/*! 
	@file     io.cpp
	@author   lisper (lisper.li@dfrobot.com)
	@license  LGPLv3 (see license.txt) 
  
	provide some useful function make it easy to control io

	Copyright (C) 2014 DFRobot
*/

#include <Arduino.h>
#include "io.h"


digitalOut::digitalOut (uint8_t thePin) {
	pin = thePin;
	pinMode (thePin, OUTPUT);
}

void digitalOut:: write (uint8_t value) {
	digitalWrite (pin, value);
}


digitalIn::digitalIn (uint8_t thePin) {
	pin = thePin;
	pinMode (pin, INPUT);
}

uint8_t digitalIn::read () {
	return digitalRead (pin);
}

analogOut::analogOut (uint8_t thePin) {
	pin = thePin;
	pinMode (pin, OUTPUT);
}

void analogOut::write (uint8_t value) {
	analogWrite (pin, value);
}

analogIn::analogIn (uint8_t thePin) {
	pin = thePin;
	pinMode (pin, INPUT);
}

uint16_t analogIn::read () {
	return analogRead (pin);
}

