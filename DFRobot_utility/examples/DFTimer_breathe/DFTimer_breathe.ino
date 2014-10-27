#include "DFRobot_utility.h"
#include <utility/DFTimer.h>

DFTimer breathe_timer = DFTimer (breathe_func, 1, 3000);

//
void setup () {
	pinMode  (13, OUTPUT);
	Serial.begin (9600);
}

//
void loop () {
	breathe_timer.check ();
}

//
void breathe_func () {
	static int16_t ledValue = 0;
	static boolean dir = true;
	if (dir)
		ledValue ++;
	else 
		ledValue --;
	if (ledValue < 0) {
		dir = true;
		ledValue = 0;
	} 
	else if (ledValue > 255) {
		dir = false;
		ledValue = 255;
	}
	analogWrite (13 , ledValue);
	// Serial.println (ledValue);
}


