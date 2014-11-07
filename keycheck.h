/**************************************************************************/
/*! 
  @file     keycheck.h
  @author   lisper (lisper.li@dfrobot.com)
  @license  LGPLv3 (see license.txt) 
  
	key check for Arduino
	
	Copyright (C) DFRobot - www.dfrobot.com


	function:	ispressed (uint16_t key, uint16_t state);
				-> for digital pin
			issticked (uint16_t key, uint16_t value); 
				-> for analog pin
			issticked2 (uint16_t key, uint16_t left, uint16_t right);
				-> for analog pin

 */
/**************************************************************************/

#ifdef __KEYCHECK__
#define __KEYCHECK__


uint16_t key_analog_range = 50;
uint16_t key_delay_time = 20;


//digital pin key 0 or 1
boolean ispressed (uint16_t key, uint16_t state); 

//analog pin key 
boolean issticked (uint16_t key, uint16_t range); 

//analog pin key
boolean issticked2 (uint16_t key, uint16_t left, uint16_t right); 


#endif
