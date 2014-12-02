#include "DFRobot_utility.h"
#include <utility/DFTimer.h>

void blink_func ();
void func1s ();
void func4s (void *args);

DFTimer blink_timer = DFTimer (blink_func, 1000);
DFTimer timer1s = DFTimer (func1s, 1000);
DFTimer timer4s = DFTimer (func4s, 4000, (void*)"4s");

void setup () {
	pinMode  (13, OUTPUT);
	Serial.begin (9600);
}

void loop () {
	blink_timer.check ();
	timer1s.check ();
	timer4s.check ();
}

void blink_func () {
	static boolean ledstate = true;
	ledstate = !ledstate;
	digitalWrite (13 , ledstate);
}

void func1s () {
	Serial.println ("hello, 1s");
}

void func4s (void *args) {
	Serial.println ((char*)args);
}


