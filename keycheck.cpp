/*
 *	created:	2013-09-24
 *	by:		lisper (leyapin@gmail.com)
 *	description:	key check
 *	function:	ispressed (uint16_t key, uint16_t state);
 *				-> for digital pin
 *			issticked (uint16_t key, uint16_t value); 
 *				-> for analog pin
 *			issticked2 (uint16_t key, uint16_t left, uint16_t right);
 *				-> for analog pin
 *
 */

#include "Arduino.h"

extern uint16_t key_analog_range;
extern uint16_t key_delay_time;


//digital pin key 0 or 1
boolean ispressed (uint16_t key, uint16_t state) {
	if (digitalRead (key) == state) {
		delay (key_delay_time);
		if (digitalRead (key) == state)
			return true;
	}
	return false;
}


//analog pin key 
boolean issticked (uint16_t key, uint16_t range) {
	if (abs (analogRead (key) - range) < key_analog_range) {
		delay (key_delay_time);
		if (abs (analogRead (key) - range) < key_analog_range)
			return true;
	}
	return false;
}

//analog pin key
boolean issticked2 (uint16_t key, uint16_t left, uint16_t right) {
	uint16_t value = analogRead (key);
	if (value >= left && value < right) {
		delay (key_delay_time);
		value = analogRead (key);
		if (value >= left && value < right) 
			return true;
	}
	return false;
}


