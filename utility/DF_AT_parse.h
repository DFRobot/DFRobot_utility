/**************************************************************************/
/*! 
  @file     DF_AT_parse.h
  @author   lisper (leyapin@gmail.com)
  @license  LGPLv3 (see license.txt) 

  AT command parse library

  Copyright (C) DFRobot - www.dfrobot.com
 */
/**************************************************************************/

#ifndef _DF_AT_PARSE
#define _DF_AT_PARSE

#include <Arduino.h>


typedef struct at_template {
	char *cmd;
	void (*func) (char *);
}at_template;


void at_string_write (char* theBuf, char* cmd, int length);
//
void parse_at_string (char *theBuf, at_template *at_tmp); 

#endif
