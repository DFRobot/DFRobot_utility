/**************************************************************************/
/*! 
  @file     DF_AT_parse.cpp
  @author   lisper (leyapin@gmail.com)
  @license  LGPLv3 (see license.txt) 

  AT command parse library

  Copyright (C) DFRobot - www.dfrobot.com
 */
/**************************************************************************/


#include <Arduino.h>
#include "DF_AT_parse.h"

//
int startWithAT (char* theBuf) {
	if (strncmp (theBuf, "AT+", 3) == 0) {
		return 1;
	} else {
		return 0;
	}
}

//
int findChar (char* theBuf, char c) {
	for (uint8_t i=0; theBuf[i] != '\0'; i++) {
		if (theBuf[i] == c) {
			return i;
		}
	}
	return -1;
}

int endWithCRLF (char *theBuf) {
	for (int i=1; theBuf[i] != '\0'; i++) {
		if (theBuf[i-1] == '\r' && theBuf[i] == '\n') {
			return i-1;
		}
	}
	return -1;
}

void at_string_write (char *theBuf, char *cmd, int length) {
	strncpy (theBuf, cmd, length - 1);
	theBuf [length-1] = '\0';
}


//
void parse_command (char *theBuf, char *param, at_template *at_tmp) {
	for (uint8_t i=0; (at_tmp[i].cmd) != '\0'; i++) {
		if (strcmp (theBuf, at_tmp[i].cmd) == 0) {
			if (strncmp (param, "?", 1) == 0) {
				at_tmp[i].func (NULL);
			} else {
				at_tmp[i].func (param);
			}
			return;
		}
	}
	Serial.println ("no this command");
}

//
void parse_at_string (char *theBuf, at_template *at_tmp) {
	if (! startWithAT (theBuf)) {
		Serial.println ("not AT command");
		return;
	}	//
	int crlf_flag = endWithCRLF (theBuf);
	if (crlf_flag == -1) {
		Serial.println ("error, no crlf");
		return ;
	} 	//
	theBuf[crlf_flag] = '\0';
	theBuf += 3;
	int sub_eq = findChar (theBuf, '=');
	if (sub_eq == -1) {
		Serial.println ("error, lose \'=\'");
		return ;
	} else if (sub_eq == 0) {
		Serial.println ("error, no command");
		return ;
	}
	theBuf[sub_eq] = '\0';
	char *param = theBuf+sub_eq+1;
	if (*param == '\0') {
		Serial.println ("error, no param");
		return ;
	}	//
	parse_command (theBuf, param, at_tmp);
}


