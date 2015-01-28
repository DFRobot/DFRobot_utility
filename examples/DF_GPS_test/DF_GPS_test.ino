/**************************************************************************/
/*! 
 @file     DF_GPS_test.ino
 @author   lisper (leyapin@gmail.com, lisper.li@gmail.com)
 @license  LGPLv3 (see license.txt) 
 
 parse gps gpgga protocol example
 
 Copyright (C) DFRobot - www.dfrobot.com
 */
/**************************************************************************/
#include <DFRobot_utility.h>
#include <utility/DF_GPS.h>

gpgga_s gpgga_data;

char gps_buffer[100] = "$GPGGA,004512.00,3111.46395,N,12137.44897,E,1,07,1.38,11.1,M,10.2,M,,*6E\r\n";

void setup () {
        Serial.begin (9600);
}

void loop () {
        gps_gpgga_parse (gps_buffer, &gpgga_data);
        Serial.println (gps_buffer);
        print_gps_gpgga(&gpgga_data);
        delay (2000);
}

void print_gps_gpgga (gpgga_s *my_gpgga) {
        Serial.print ("utc time        ");
        Serial.print (my_gpgga->utc.hour);
        Serial.print (":");
        Serial.print (my_gpgga->utc.minute);
        Serial.print (":");
        Serial.println (my_gpgga->utc.second);
        Serial.print ("longitude        ");
        Serial.print (my_gpgga->ns);
        Serial.print (":");
        Serial.println (my_gpgga->longitude);
        Serial.print ("satellites        ");
        Serial.print (my_gpgga->ew);
        Serial.print (":");
        Serial.println (my_gpgga->satellites);
        Serial.print ("fix        ");
        Serial.print (my_gpgga->fix);
        Serial.print (":");
        Serial.println ( my_gpgga->num);
        Serial.print ("hdop        ");
        Serial.println (my_gpgga->hdop);
        Serial.print ("altitude        ");
        Serial.print (my_gpgga->altitude);
        Serial.print (" ");
        Serial.println (my_gpgga->a_units);
        Serial.print ("level        ");
        Serial.print (my_gpgga->level);
        Serial.print (" ");
        Serial.println (my_gpgga->l_units);
        Serial.println ();
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


