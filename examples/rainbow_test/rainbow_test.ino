/*
	@file     rainbow_test.ino
	@author   lisper (lisper.li@dfrobot.com)
	@license  LGPLv3 (see license.txt) 

	Copyright (C) 2014 DFRobot
*/

#include <Adafruit_NeoPixel.h>
#include <DFRobot_utility.h>

#define PIN 9
#define LED_LENG 7


// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_RGB     Pixels are wired for RGB bitstream
//   NEO_GRB     Pixels are wired for GRB bitstream
//   NEO_KHZ400  400 KHz bitstream (e.g. FLORA pixels)
//   NEO_KHZ800  800 KHz bitstream (e.g. High Density LED strip)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_LENG, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
	Serial.begin (9600);
	strip.begin();
	strip.show(); // Initialize all pixels to 'off'
}


//
void loop () {
	static float add = 0;
	add += 0.01;
	float h = add;
	for (int i=0; i<LED_LENG; i++) {
		h -= 0.4;
		strip.setPixelColor (i, hsbToColor (360*((sin(h)+1)/2.0), 1,1));
	}
	strip.show(); 
}


