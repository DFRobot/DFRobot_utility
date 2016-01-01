/**************************************************************************/
/*! 
  @file     DF_GPS.cpp
  @author   lisper (leyapin@gmail.com, lisper.li@dfrobot.com)
  @license  LGPLv3 (see license.txt) 

  parse gps gpgga protocol

  Copyright (C) DFRobot - www.dfrobot.com
 */
/**************************************************************************/

#include <Arduino.h>
#include <DF_GPS.h>
#include <DFCommon.h>

#define _debug


DFGPS::DFGPS (Stream &theSerial) {
	_mySerial = &theSerial;
}

// check sum using xor
uint8_t DFGPS::gpsCalcChecksum (char *array) {
	uint8_t sum = array[1];
	for (uint8_t i=2; array[i] != '*'; i++) {
		sum ^= array[i];
	}
	return sum;
}

//get gga checksum
uint8_t DFGPS::gpsReadChecksum (char **the_str) {
	char *temp = the_str[14];
	if (temp[0] != '*') {
		//printf ("error no *");
		return 0;
	}
	uint8_t sum = hexToInt2 (temp+1);
	return sum;
}

//
void DFGPS::gps_print_gpgga (gpgga_s *my_gpgga) {
	printf ("now time =	%d:%d:%d\n", my_gpgga->utc.hour, my_gpgga->utc.minute, my_gpgga->utc.second);
	printf ("%c : %f\n", my_gpgga->ns, my_gpgga->latitude);
	printf ("%c : %f\n", my_gpgga->ew, my_gpgga->longitude);
	printf ("fix =	%d\nnum = %d\n", my_gpgga->fix, my_gpgga->num);
	printf ("hdop =	%f\n", my_gpgga->hdop);
	printf ("altitude =	%f %c\n", my_gpgga->altitude, my_gpgga->a_units);
	printf ("level =	%f %c\n", my_gpgga->level, my_gpgga->l_units);
}

//
void DFGPS::gpgga (gpgga_s *gpgga_data) {
	///////////////////////////////////
	gpgga_data->utc.hour = decToInt2 (gpsp[1]);
	gpgga_data->utc.minute = decToInt2 (gpsp[1]+2);
	gpgga_data->utc.second = decToInt2 (gpsp[1]+4);
	///////////////////////////////////
	gpgga_data->latitude= atof (gpsp[2]);
	gpgga_data->ns = gpsp[3][0];
	gpgga_data->longitude= atof (gpsp[4]);
	gpgga_data->ew = gpsp[5][0];
	///////////////////////////////////
	gpgga_data->fix = atoi (gpsp[6]);
	gpgga_data->num = atoi (gpsp[7]);
	gpgga_data->hdop = atof (gpsp[8]);
	gpgga_data->altitude = atof (gpsp[9]);
	gpgga_data->a_units = gpsp[10][0];
	gpgga_data->level = atof (gpsp[11]);
	gpgga_data->l_units = gpsp[12][0];
}

//
int DFGPS::parse () {
	delete_crlf (gps_buffer);
	uint8_t sum = gpsCalcChecksum (gps_buffer);
	wordNum = split_by_comma (gps_buffer, gpsp, sizeof (gpsp)/sizeof (char*));
	uint8_t check_result = gpsReadChecksum (gpsp);
	if (check_result != sum) {
		return 0;
	} else
		return 1;
}

void DFGPS::printGPGGA () {
	for (int i=0; i<wordNum; i++) {
		Serial.print (i);
		Serial.print (": ");
		Serial.println (gpsp[i]);
	}
}

int DFGPS::read () {
	if (_mySerial->available ()) {
		if (_mySerial->read () == '$') {
			gps_buffer[0] = '$';
			while (_mySerial->available () == 0);
			_mySerial->readBytes (gps_buffer+1, 5);
			if (strncmp (gps_buffer+1, "GPGGA", 5) == 0) {
				while (_mySerial->available () == 0);
				_mySerial->readBytesUntil ('$', gps_buffer+6, 100-6);
#ifdef _debug
				Serial.println (gps_buffer);
#endif
				////////////////////////////////////
				parse ();
				return 1;
			}
		}
	}
	return 0;
}

char DFGPS::fixc () {
	return gpsp[6][0];
}

uint8_t DFGPS::fix () {
	if (gpsp[6][0])
		return gpsp[6][0]-'0';
	else 
		return 0;
}

boolean DFGPS::gpsAvailable () {
	if (fixc () == '1')
	       return true;
	else 
	return false;
}

boolean DFGPS::timeAvailable () {
	if (gpsp[1] != '\0')
		return true;
	else
		return false;
}

uint8_t DFGPS::getHour () {
	if (gpsp[1][0])
		return decToInt2 (gpsp[1]);
	else 
		return 0;
}

char *DFGPS::getTime () {
	return gpsp[1];
}

uint8_t DFGPS::getMinute () {
	if (gpsp[1][0])
		return decToInt2 (gpsp[1]+2);
	else 
		return 0;
}


uint8_t DFGPS::getSecond () {
	if (gpsp[1][0])
		return decToInt2 (gpsp[1]+4);
	else 
		return 0;
}


double DFGPS::getLatitude () {
	double lat = (double)decToInt (gpsp[2], 2);
	return lat + atof (gpsp[2]+2) / 60.0;
}

char *DFGPS::getLatitudeStr () {
	return gpsp[2];
}

double DFGPS::getLongitude () {
	double lon = (double)decToInt (gpsp[4], 3);
	return lon + atof (gpsp[4]+3) / 60.0;
}

char *DFGPS::getLongitudeStr () {
	return gpsp[4];
}

char DFGPS::getNS () {
	return gpsp[3][0];
}

char DFGPS::getEW () {
	return gpsp[5][0];
}

uint8_t DFGPS::getNum () {
	return atoi (gpsp[7]);
}

char *DFGPS::getNumStr () {
	return gpsp[7];
}

char *DFGPS::getHDOPStr () {
	return gpsp[8];
}

double DFGPS::getHDOP () {
	return atof (gpsp[8]);
}

char *DFGPS::getAltidudeStr () {
	return gpsp[9];
}

double DFGPS::getAltidude () {
	return atof (gpsp[9]);
}

char DFGPS::getAunits () {
	return gpsp[10][0];
}

char *DFGPS::getLevelStr () {
	return gpsp[11];
}

double DFGPS::getLevel () {
	return atof (gpsp[11]);
}

char DFGPS::getLunits () {
	return gpsp[12][0];
}

