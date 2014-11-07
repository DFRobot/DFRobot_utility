/**************************************************************************/
/*! 
	@file     DFRobotCar.cpp
	@author   lisper (lisper.li@dfrobot.com)
	@license  LGPLv3 (see license.txt) 
  
	provide some useful function make it easy to control two DC car

	Copyright (C) 2014 DFRobot
*/

#include <Arduino.h>
#include "DFRobotCar.h"

//DFRobotCar mycar (4,5,7,6);
DFRobotCar::DFRobotCar (uint8_t left_en, uint8_t left_pwm, uint8_t right_en, uint8_t right_pwm) {
	_left_en = left_en;
	_left_pwm = left_pwm;
	_right_en = right_en;
	_right_pwm = right_pwm;
	pinMode (_left_en, OUTPUT);
	pinMode (_left_pwm, OUTPUT);
	pinMode (_right_en, OUTPUT);
	pinMode (_right_pwm, OUTPUT);

	_left_advance = LOW;
	_left_back = HIGH;
	_right_advance = HIGH;
	_right_back = LOW;
}

//
void DFRobotCar::changeDir (bool left, bool right) {
	if (left) {
		_left_advance = !_left_advance;
		_left_back = !_left_back;
	}
	if (right) {
		_right_advance = !_right_advance;
		_right_back = !_right_back;
	}

}

//
void DFRobotCar::control (int16_t left_speed, int16_t right_speed) {
	if (left_speed < 0) {
		left_speed = -left_speed;
		digitalWrite (_left_en, _left_back); 
	} else {
		digitalWrite (_left_en, _left_advance);
	}
	if (right_speed < 0) {
		right_speed = -right_speed;
		digitalWrite (_right_en, _right_back); 
	} else {
		digitalWrite (_right_en, _right_advance);
	}
	if (left_speed > 255) 
		left_speed = 255;
	if (right_speed > 255) 
		right_speed = 255;
	analogWrite (_left_pwm, left_speed);
	analogWrite (_right_pwm, right_speed);
}


