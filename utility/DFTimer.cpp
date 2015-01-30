/**************************************************************************/
/*! 
  @file     DFTimer.cpp
  @author   lisper (leyapin@gmail.com)
  @license  LGPLv3 (see license.txt) 

  timer library use millis ()

  Copyright (C) DFRobot - www.dfrobot.com
 */
/**************************************************************************/

#include <Arduino.h>
#include "DFTimer.h"

//
DFTimer::DFTimer (void (*theTimeHandler)(), uint32_t theDelayTime) {
	isFirst = false; 
	isRun = true;
	nowTime = millis ();
	timeHandlern = theTimeHandler;
	delayTime = theDelayTime;
}

//
DFTimer::DFTimer (void (*theTimeHandler)(), uint32_t theDelayTime, uint32_t theStartTime) { 
	isFirst = true;
	isRun = true;
	nowTime = millis ();
	timeHandlern = theTimeHandler;
	delayTime = theDelayTime;
	startTime = theStartTime;
}

//
DFTimer::DFTimer (void (*theTimeHandler)(void*), uint32_t theDelayTime,  void *theArgs) { 
	isFirst = true;
	isRun = true;
	nowTime = millis ();
	timeHandler = theTimeHandler;
	delayTime = theDelayTime;
	args = theArgs;
}

//
DFTimer::DFTimer (void (*theTimeHandler)(void*), uint32_t theDelayTime, uint32_t theStartTime,  void *theArgs) { 
	isFirst = true;
	isRun = true;
	nowTime = millis ();
	timeHandler = theTimeHandler;
	delayTime = theDelayTime;
	startTime = theStartTime;
	args = theArgs;
}

//
void DFTimer::check () {
	if (!isRun)
		return;
	uint32_t divTime = millis () - nowTime;
	if (isFirst ? (divTime > startTime) : (divTime > delayTime)) {
		isFirst = false;
		nowTime = millis (); 
		if (args)
			timeHandler (args);
		else 
			timeHandlern ();
	}
}

//
void DFTimer::stop () {
	isRun = false;
}

//
void DFTimer::start () {
	isRun = true;
	nowTime = millis ();
}

