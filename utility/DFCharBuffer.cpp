/**************************************************************************/
/*! 
  @file     DFCharBuffer.cpp
  @author   lisper (leyapin@gmail.com)
  @license  LGPLv3 (see license.txt) 

  queue, stack, ring buffer for character based on array

  Copyright (C) DFRobot - www.dfrobot.com
 */
/**************************************************************************/

#include <Arduino.h>
#include <DFCharBuffer.h>

DFCharBuffer::DFCharBuffer (uint16_t theSize, boolean theMode) {
	buffer = new char [size];
	size = theSize;
	head = 1;
	tail = 0;
	isOverMode = theMode;
};
void DFCharBuffer::setMode (boolean theMode) {
	isOverMode = theMode;
};
DFCharBuffer::~DFCharBuffer () {
	delete [] buffer;
};

//
int DFCharBuffer::writeFromHead (char data) {
	uint16_t temp = head;
	INDEX_FOR (temp, size);
	if (temp == tail) {
		if (isOverMode) {
			buffer[head] = data;
			head = temp;
			INDEX_FOR (tail, size);
		} else {
			return -1;
		}
	} else {
		buffer[head] = data;
		head = temp;
	}
	return 0;
};

//
int DFCharBuffer::writeFromTail (char data) {
	uint16_t temp = tail;
	INDEX_BACK (temp, size);
	if (temp == head) {
		if (isOverMode) {
			buffer[tail] = data;
			tail = temp;
			INDEX_BACK (head, size);
		} else {
			return -1;
		}
	} else {
		buffer[tail] = data;
		tail = temp;
	}
	return 0;
};

//
int DFCharBuffer::readFromHead () {
	uint16_t temp = head;
	INDEX_BACK (temp, size);

	if (temp == tail) {
		return -1;
	} else {
		head = temp;
		return buffer[head];
	}
};

//
int DFCharBuffer::readFromTail () {
	uint16_t temp = tail;
	INDEX_FOR (temp, size);
	if (temp == head) {
		return -1;
	} else {
		tail = temp;
		return  buffer[tail];
	}
};

