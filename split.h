/**************************************************************************/
/*! 
  @file     split.h
  @author   lisper (lisper.li@dfrobot.com)
  @license  LGPLv3 (see license.txt) 
  
	build command string cmdstr
	
	Copyright (C) DFRobot - www.dfrobot.com
*/
/**************************************************************************/

#include <Arduino.h>

#define ARGV_SIZE	8
#define CMD_BUF_SIZE	64

extern uint8_t argc;
extern char cmdBuf[CMD_BUF_SIZE];
extern char *argv[ARGV_SIZE];

//
void serialReadCmd (HardwareSerial);

//split str to cmdstr by space
int split (char **cmdstr, char *str, int leng); 

//split str to cmdstr by space and delimiter
int splitc (uint8_t **cmdstr, uint8_t *str, char delimiter, int leng); 

