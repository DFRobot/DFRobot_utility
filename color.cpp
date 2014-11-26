
/*! 
	@file     color.cpp
	@author   lisper (lisper.li@dfrobot.com)
	@license  LGPLv3 (see license.txt) 
  
	function is hsb to rgb

	Copyright (C) 2014 DFRobot
*/

#include "Arduino.h"
#include "color.h"

// hsb to rgb
void HSB2RGB (float *hsb, uint8_t *rgb) {
	for(int offset=240,i=0; i<3; i++,offset -= 120) { 
		float x = fabs (((int)(hsb[0]+offset)) % 360 - 240.0);
		if(x<=60) 
			rgb[i] = 255;
		else if(60<x && x<120) 
			rgb[i] = ((1-(x-60)/60)*255);
		else 
			rgb[i] = 0;
	}
	for(int i=0; i<3; i++)
		rgb[i] += (255-rgb[i]) * (1-hsb[1]);
	for(int i=0; i<3; i++)
		rgb[i] *= hsb[2];
}

//
uint32_t hsbToColor (float h, float s, float b) {
	//return color:0x00rrggbb
	//h=>(0~360), s=>(0~1.0) add=>(0~1.0)
	float hsb[3] = { 
		h, s, b};
	uint8_t rgb[3];
	HSB2RGB (hsb, rgb);
	return ((uint32_t)rgb[0] << 16) | ((uint32_t)rgb[1] <<  8) | (uint32_t)rgb[2];
}

#ifdef colorCircle
uint32_t hbToColor (uint16_t h, float b) {
	//return color:0x00rrggbb, very fast, note: s always is 1.0
	//h=>(0~360), b=>(0~1.0)
	uint32_t color = color_array[h];
	uint8_t r = (uint8_t)color * b;
	uint8_t g = (uint8_t)(color>>8) * b;
	uint8_t add = (uint8_t)(color>>16) * b;
	return ((uint32_t)r << 16) | ((uint32_t)g <<  8) | (uint32_t)add;
}

void setColorCircle (uint32_t *array, uint32_t length, float s, float add) {
	//array length is 360
	for (int i=0; i<length; i++) {
		array[i] = get_color_from_hsb (i, s, add);
	}
}
#endif

