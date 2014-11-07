/**************************************************************************/
/*! 
	@file     DFRobotCar.h
	@author   lisper (lisper.li@dfrobot.com)
	@license  LGPLv3 (see license.txt) 
  
	provide some useful function make it easy to control two DC car
	
	Copyright (C) 2014 DFRobot
*/

#include <Arduino.h>

class DFRobotCar {
	private:
		bool _left_advance;// = LOW;
		bool _left_back;// = HIGH;
		bool _right_advance;// = HIGH;
		bool _right_back;// = LOW;

		uint8_t _left_en;// = 4;
		uint8_t _left_pwm;// = 5;
		uint8_t _right_en;// = 7;
		uint8_t _right_pwm;// = 6;

	public:
		DFRobotCar (uint8_t left_en, uint8_t left_pwm, uint8_t right_en, uint8_t right_pwm);

		void changeDir (bool left, bool right);

		void control (int16_t left, int16_t right); 
};

