/**************************************************************************/
/*! 
  @file     DFRobotCar_test.ino
  @author   lisper (lisper.li@dfrobot.com)
  @license  LGPLv3 (see license.txt) 

  test code for DFRobotCar library

  Copyright (C) 2014 DFRobot
 */
/**************************************************************************/

#include <DFRobot_utility.h>

DFRobotCar mycar (7, 6, 4, 5);

void setup () {
	mycar.changeDir (true, true);
	pinMode (13, OUTPUT);
}


void loop () {
	mycar.control (100, 0);
	digitalWrite (13, HIGH);
	delay (1000);

	mycar.control (100, 100);
	digitalWrite (13, LOW);
	delay (1000);

	mycar.control (0, 0);
	delay (2000);
}


/*
 *	
 *	DFRobotCar (uint8_t left_en, uint8_t left_pwm, uint8_t right_en, uint8_t right_pwm);
 *	
 *	//switch left and right side direction
 *	void changeDir (boolean left, boolean right);
 *	
 *	//specify left and right side's speed, round is (-255 ~ 255)        
 *	void control (int16_t left, int16_t right); 
 *	
 */
