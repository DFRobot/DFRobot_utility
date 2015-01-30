/**************************************************************************/
/*! 
  @file     DFCharBuffer.h
  @author   lisper (leyapin@gmail.com)
  @license  LGPLv3 (see license.txt) 

  ring, queue, stack buffer for character based on array

  Copyright (C) DFRobot - www.dfrobot.com
 */
/**************************************************************************/

#ifndef _DF_CHAR_BUFFER
#define _DF_CHAR_BUFFER

#include <Arduino.h>

#define INDEX_FOR(x, max) (x = (x+1)%max)
#define INDEX_BACK(x, max) (x==0 ? x = max-1 : x--)

class DFCharBuffer {
	private:
		char *buffer;
		uint16_t head;
		uint16_t size;
		uint16_t tail;
		boolean isOverMode;
	public:
		DFCharBuffer (uint16_t theSize, boolean theMode = true) ;
		void setMode (boolean theMode) ;
		~DFCharBuffer () ;
		//
		int writeFromHead (char data) ;

		//
		int writeFromTail (char data) ;

		//
		int readFromHead ();

		//
		int readFromTail (); 
};
#endif
