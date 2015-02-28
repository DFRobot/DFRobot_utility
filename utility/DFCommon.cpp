/**************************************************************************/
/*! 
  @file     DFCommon.cpp
  @author   lisper (leyapin@gmail.com)
  @license  LGPLv3 (see license.txt) 

  some usefull function

  Copyright (C) DFRobot - www.dfrobot.com
 */
/**************************************************************************/

#include <Arduino.h>


//
uint8_t decToInt2 (char *the_buf) {
	uint8_t value = 0;
	value += (the_buf[0]-'0') *10;
	value += (the_buf[1]-'0');
	return value;
}

//
uint16_t decToInt (char *theBuf, uint8_t theSize) {
	uint16_t value = 0;
	for (int i = 0; i<theSize; i++) {
		value *= 10;
		value += (theBuf[i]-'0');
	}
	return value;
}

//
uint8_t hexToInt2 (char *the_buf) {
	uint8_t value = 0; 
	if (the_buf[0] >= '0' && the_buf[0] <= '9') {
		value += (the_buf[0] - '0') * 16;
	} else {
		value += (the_buf[0] - 'A' + 10) * 16;
	}

	if (the_buf[1] >= '0' && the_buf[1] <= '9') {
		value += (the_buf[1] - '0');
	} else {
		value += (the_buf[1] - 'A' + 10);
	}
	return value; 
}


//
uint8_t split_by_char (char *the_src, char the_char, char **the_des, uint8_t the_siz) {
	uint8_t src_len = strlen (the_src);
	uint8_t di=0;
	the_des[di++] = the_src;
	for (uint8_t si=0; si<src_len && di < the_siz; si++) {
		if (the_src[si] == the_char) {
			the_des[di++] = the_src+si+1;
			the_src[si] = '\0';
		}
	}
	return di;
}

//
uint8_t split_by_comma (char *the_src, char **the_des, uint8_t the_siz) {
	return split_by_char (the_src, ',', the_des, the_siz);
}



uint8_t delete_crlf (char *the_buf) {
	uint8_t leng = strlen (the_buf);
	for (uint8_t i=0; i<leng-1; i++) {
		if (the_buf[i] == '\r' && the_buf[i+1] == '\n') {
			the_buf[i] = '\0';
			return 1;
		}
	}
	return 0;
}
