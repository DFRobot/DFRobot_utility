/**************************************************************************/
/*! 
  @file     SerialProtocol.h
  @author   lisper (lisper.li@dfrobot.com)
  @license  LGPLv3 (see license.txt) 

  serial protocol with checksum

  Copyright (C) DFRobot - www.dfrobot.com
 */
/**************************************************************************/

#ifndef _SERIAL_PROTOCOL
#define _SERIAL_PROTOCOL

#include <Arduino.h>

//
void sendData (void *theData, uint8_t ); 

//
int readData (void *theData, uint8_t); 

#endif
