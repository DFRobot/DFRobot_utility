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

//
uint8_t decToInt2 (char *the_buf) {
	uint8_t value = 0;
	value += (the_buf[0]-'0') *10;
	value += (the_buf[1]-'0');
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

// check sum using xor
uint8_t gps_checksum (char *array) {
	uint8_t sum = array[1];
	for (uint8_t i=2; array[i] != '*'; i++) {
		sum ^= array[i];
	}
	return sum;
}

//get gga checksum
uint8_t gps_read_checksum (char **the_str) {
	char *temp = the_str[14];
	if (temp[0] != '*') {
		printf ("error no *");
		return 0;
	}
	uint8_t sum = hexToInt2 (temp+1);
	return sum;
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

//
void gps_print_debug (char **the_strp, uint8_t the_leng) {
	for (uint8_t i=0; i<the_leng; i++) {
		printf ("%d:%d = %s\n", i, strlen (the_strp[i]), the_strp[i]);
	}
	printf ("----------------------\n");
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

/*
void gps_print_gpgga (gpgga_s *my_gpgga) {
	printf ("now time =	%d:%d:%d\n", my_gpgga->utc.hour, my_gpgga->utc.minutes, my_gpgga->utc.second);
	printf ("%c : %f\n", my_gpgga->ns, my_gpgga->longitude);
	printf ("%c : %f\n", my_gpgga->ew, my_gpgga->satellites);
	printf ("fix =	%d\nnum = %d\n", my_gpgga->fix, my_gpgga->num);
	printf ("hdop =	%f\n", my_gpgga->hdop);
	printf ("altitude =	%f %c\n", my_gpgga->altitude, my_gpgga->a_units);
	printf ("level =	%f %c\n", my_gpgga->level, my_gpgga->l_units);
}

*/

//
int gps_gpgga_parse (char* gps_string, gpgga_s *gpgga_data) {
	uint8_t gps_length = strlen (gps_string);
	char *gps_temp = (char*)malloc (gps_length + 1);
	strcpy (gps_temp, gps_string);
	gps_temp[gps_length] = '\0';
	char *strp[15];
	delete_crlf (gps_temp);
	uint8_t sum = gps_checksum (gps_temp);
	split_by_comma (gps_temp, strp, sizeof (strp)/sizeof (char*));
	//split_by_comma (gps_temp, strp, sizeof (strp)/4);	//!!! bug
	uint8_t check_result = gps_read_checksum (strp);
	if (check_result != sum) {
		return -1;
	}

	///////////////////////////////////
	gpgga_data->utc.hour = decToInt2 (strp[1]) + 8;
	gpgga_data->utc.minute = decToInt2 (strp[1]+2);
	gpgga_data->utc.second = decToInt2 (strp[1]+4);
	///////////////////////////////////
	gpgga_data->longitude = atof (strp[2]);
	gpgga_data->ns = strp[3][0];
	gpgga_data->satellites = atof (strp[4]);
	gpgga_data->ew = strp[5][0];
	///////////////////////////////////
	gpgga_data->fix = atoi (strp[6]);
	gpgga_data->num = atoi (strp[7]);
	gpgga_data->hdop = atof (strp[8]);
	gpgga_data->altitude = atof (strp[9]);
	gpgga_data->a_units = strp[10][0];
	gpgga_data->level = atof (strp[11]);
	gpgga_data->l_units = strp[12][0];
	free (gps_temp);
	//gps_print_gpgga (gpgga_data);
}


