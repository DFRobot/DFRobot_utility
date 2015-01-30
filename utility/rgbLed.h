/**************************************************************************/
/*! 
  @file     rbgLed.h
  @author   lisper (leyapin@gmail.com)
  @license  LGPLv3 (see license.txt) 

  rgb led library

  Copyright (C) DFRobot - www.dfrobot.com
 */
/**************************************************************************/

#ifndef _DF_RGBLED
#define _DF_RGBLED

class rgbLed {
	public:
		uint8_t rPin;
		uint8_t gPin;
		uint8_t bPin;
		rgbLed (uint8_t rPin, uint8_t gPin, uint8_t bPin); 
		void setColorRGB (uint8_t rV, uint8_t gV, uint8_t bV); 
		void setColor (uint16_t color); 
		void setColor (uint16_t color, float s, float b); 
};

#endif
