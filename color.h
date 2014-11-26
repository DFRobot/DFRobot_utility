/*! 
	@file     color.h
	@author   lisper (lisper.li@dfrobot.com)
	@license  LGPLv3 (see license.txt) 
  
	function is hsb to rgb

	Copyright (C) 2014 DFRobot
*/

#include "Arduino.h"

// hsb to rgb
void HSB2RGB (float *hsb, uint8_t *rgb); 

//return color:0x00rrggbb
//h=>(0~360), s=>(0~1.0) add=>(0~1.0)
uint32_t hsbToColor (float h, float s, float b); 

#ifdef colorCircle
uint32_t hbToColor (uint16_t h, float b); 
	//return color:0x00rrggbb, very fast, note: s always is 1.0
	//h=>(0~360), b=>(0~1.0)

void setColorCircle (uint32_t *array, uint16_t length, float s, float add); 
	//array length is 360
#endif

