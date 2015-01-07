/**************************************************************************/
/*! 
  @file     split.cpp
  @author   lisper (lisper.li@dfrobot.com)
  @license  LGPLv3 (see license.txt) 
  
	build command string cmdstr
	
	Copyright (C) DFRobot - www.dfrobot.com
*/
/**************************************************************************/

#include <Arduino.h>
#include <DFRobot_utility.h>
#include "split.h"

//#define ARGV_SIZE	8
//#define CMD_BUF_SIZE	32

uint8_t argc;
char cmdBuf[CMD_BUF_SIZE];
char *argv[ARGV_SIZE];

//
void serialReadCmd (HardwareSerial theSerial) {
	int leng = serialReads (theSerial, (uint8_t*)cmdBuf, CMD_BUF_SIZE, 4);
	if (leng) {
		argc = split (argv, cmdBuf, ARGV_SIZE);
	} else {
		argc = 0;
	}
}

//split str to cmdstr by space
int split (char **cmdstr, char *str, int leng) {
	int i;
	for (i=0; *str && i<leng; i++) {
		while (isspace (*str))
			*str++='\0';
		if (*str == '\0')
			break;
		cmdstr[i] = str;
		while (isgraph (*str))
			str++;
	}
	//*str = '\0';
	//cmdstr[i] = '\0';
	return i;
}

//split str to cmdstr by space and delimiter
int splitc (uint8_t **cmdstr, uint8_t *str, char delimiter, int leng) {
	int i;
	for (i=0; *str && i<leng-1; i++) {
		while (*str == delimiter || isspace (*str))
			*str++='\0';
		if (*str == '\0')
			break;
		cmdstr[i] = str;
		while (*str != delimiter)
			str++;
	}
	cmdstr[i] = '\0';
	return i;
}


