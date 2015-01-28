/**************************************************************************/
/*! 
 @file     DF_GPS_test.ino
 @author   lisper (leyapin@gmail.com, lisper.li@dfrobot.com)
 @license  LGPLv3 (see license.txt) 
 
 parse gps gpgga protocol example
 
 Copyright (C) DFRobot - www.dfrobot.com
 */
/**************************************************************************/
#include <DFRobot_utility.h>
#include <utility/DF_GPS.h>

gpgga_s gpgga_data;

char gps_buffer[100] = {
        0};

void setup () {
        Serial.begin (9600);
        Serial1.begin (9600);
        while (! Serial1);
        //delay (100);
}

void loop () {
        if (Serial1.available ()) {
                if (Serial1.read () == '$') {
                        gps_buffer[0] = '$';
                        while (Serial1.available () == 0);
                        Serial1.readBytes (gps_buffer+1, 5);
                        if (strncmp (gps_buffer+1, "GPGGA", 5) == 0) {
                                while (Serial1.available () == 0);
                                Serial1.readBytesUntil ('\r', gps_buffer+6, 100-6);
                                gps_gpgga_parse (gps_buffer, &gpgga_data);
                                Serial.println (gps_buffer);
                                if (gpgga_data.fix == 1) {
                                        print_gps_gpgga(&gpgga_data);
                                } else {
                                        print_utc_time (&gpgga_data);
                                }  
                        }
                }
        }
}

void print_utc_time (gpgga_s *my_gpgga) {
        char tmp_buf[50];
        sprintf (tmp_buf, "time =\t%d:%d:%d",my_gpgga->utc.hour, my_gpgga->utc.minute, my_gpgga->utc.second);
        Serial.println (tmp_buf);
}
//
void print_gps_gpgga (gpgga_s *my_gpgga) {
        char tmp_buf[50];
        char float_buf[20];
        print_utc_time (my_gpgga);
        sprintf (tmp_buf, "longitude =\t%c:%s",my_gpgga->ns, dtostrf (my_gpgga->longitude, 10, 5, float_buf));
        Serial.println (tmp_buf);
        sprintf (tmp_buf, "satellites =\t%c:%s",my_gpgga->ew, dtostrf (my_gpgga->satellites, 10, 5, float_buf));
        Serial.println (tmp_buf);
        sprintf (tmp_buf, "fix =\t%d:%d", my_gpgga->fix,  my_gpgga->num);
        Serial.println (tmp_buf);
        sprintf (tmp_buf, "hdop =\t%s", dtostrf (my_gpgga->hdop, 10, 5, float_buf));
        Serial.println (tmp_buf);
        sprintf (tmp_buf, "altitude =\t%s %c", dtostrf (my_gpgga->altitude, 10, 5, float_buf), my_gpgga->a_units);
        Serial.println (tmp_buf);
        sprintf (tmp_buf, "level =\t%s %c", dtostrf (my_gpgga->level, 10, 5, float_buf), my_gpgga->l_units);
        Serial.println (tmp_buf);
}

//typedef struct {
//	//int id;
//	struct utc{	//1:UTC time
//		int hour;
//		int minutes;
//		int second;
//	}utc;
//	double longitude;	//2:
//	char ns;		//3:
//	double satellites;	//4:
//	char ew;		//5:
//	int fix;	//6:gps status 0 1 2 3 4 5 6 7 8 9
//	int num;	//7:
//	double hdop;	//8:水平精度
//	double altitude;	//9:海拔高度
//	char a_units;	//10:单位M
//	double level;	//11:大地水准面高度
//	char l_units;	//12:单位M
//	double diff_time;	13
//	int diff_id;	//14
//} gpgga_s;




