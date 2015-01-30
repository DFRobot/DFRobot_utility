/**************************************************************************/
/*! 
  @file     rbgLed.cpp
  @author   lisper (leyapin@gmail.com)
  @license  LGPLv3 (see license.txt) 

  rgb led library

  Copyright (C) DFRobot - www.dfrobot.com
 */
/**************************************************************************/

#include <DFRobot_utility.h>
#include <rgbLed.h>


rgbLed::rgbLed (uint8_t rPin, uint8_t gPin, uint8_t bPin) {
	rPin = rPin;
	gPin = gPin;
	bPin = bPin;
	pinMode (rPin, OUTPUT);
	pinMode (gPin, OUTPUT);
	pinMode (bPin, OUTPUT);
}

void rgbLed::setColorRGB (uint8_t rV, uint8_t gV, uint8_t bV) {
	analogWrite (rPin, rV);
	analogWrite (gPin, gV);
	analogWrite (bPin, bV);
}

void rgbLed::setColor (uint16_t color) {
	float hsb[3] = {(float)color, 1, 1};
	uint8_t rgb[3];
	HSB2RGB (hsb, rgb);
	setColorRGB (rgb[0], rgb[1], rgb[2]);	

}

void rgbLed::setColor (uint16_t color, float s, float b) {
	float hsb[3] = {color, s, b};
	uint8_t rgb[3];
	HSB2RGB (hsb, rgb);
	setColorRGB (rgb[0], rgb[1], rgb[2]);	
}
