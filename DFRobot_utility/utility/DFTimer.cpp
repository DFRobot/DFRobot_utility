#include <Arduino.h>
#include "DFTimer.h"

//
DFTimer::DFTimer (void (*theTimeHandler)(), uint32_t theDelayTime) {
	isBegin = false; 
	nowTime = millis ();
	timeHandlern = theTimeHandler;
	delayTime = theDelayTime;
}

//
DFTimer::DFTimer (void (*theTimeHandler)(), uint32_t theDelayTime, uint32_t theStartTime) { 
	isBegin = true;
	nowTime = millis ();
	timeHandlern = theTimeHandler;
	delayTime = theDelayTime;
	startTime = theStartTime;
}

//
DFTimer::DFTimer (void (*theTimeHandler)(void*), uint32_t theDelayTime,  void *theArgs) { 
	isBegin = true;
	nowTime = millis ();
	timeHandler = theTimeHandler;
	delayTime = theDelayTime;
	args = theArgs;
}

//
DFTimer::DFTimer (void (*theTimeHandler)(void*), uint32_t theDelayTime, uint32_t theStartTime,  void *theArgs) { 
	isBegin = true;
	nowTime = millis ();
	timeHandler = theTimeHandler;
	delayTime = theDelayTime;
	startTime = theStartTime;
	args = theArgs;
}

//
void DFTimer::check () {
	uint32_t divTime = millis () - nowTime;
	if (isBegin ? (divTime > startTime) : (divTime > delayTime)) {
		isBegin = false;
		nowTime = millis (); 
		if (args)
			timeHandler (args);
		else 
			timeHandlern ();
	}
}

