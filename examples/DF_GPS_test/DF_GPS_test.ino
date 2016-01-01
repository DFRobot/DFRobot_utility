/**************************************************************************/
/*! 
  @file     DF_GPS_test.ino
  @author   lisper (leyapin@gmail.com, lisper.li@dfrobot.com)
  @license  LGPLv3 (see license.txt) 
  test on uno or leonardo
  Copyright (C) DFRobot - www.dfrobot.com
  */
/**************************************************************************/
#include <DFRobot_utility.h>
#include <utility/DF_GPS.h>

//gpgga_s gpgga_data;

DFGPS gps (Serial);
//DFGPS gps (Serial1);        if use leonardo and Serial1

void setup () {
	Serial.begin (9600);
	//Serial1.begin (9600);        if use leonardo and Serial1
	//while (! Serial1);
}

//
void loop () {
	int res = gps.read ();
	if (res) {
		if (gps.fix() == 1) {
			//gps.gpgga (&gpgga_data);
			Serial.println ("fixed");
			Serial.print ("latitude=");
			Serial.println (gps.getLatitude ());
			Serial.print ("longitude=");
			Serial.println (gps.getLongitude());
			print_gps_data ();
		}
		gps.printGPGGA ();	//will always print
	}
}

//
void print_gps_data () {
	Serial.print ("getTime:        ");
	Serial.println (gps.getTime ());
	Serial.print ("getLatitude:        ");
	Serial.println (gps.getLatitude (), 6);
	Serial.print ("getLongitude:        ");
	Serial.println (gps.getLongitude (), 5);
	Serial.print ("fixc:        ");
	Serial.println (gps.fixc ());
	Serial.print ("getNum:        ");
	Serial.println (gps.getNum ());
	Serial.print ("getHDOP:        ");
	Serial.println (gps.getHDOP ());
	Serial.print ("getAltidude:        ");
	Serial.print (gps.getAltidude ());
	Serial.println (gps.getAunits ());

	Serial.print ("getLevel:        ");
	Serial.print (gps.getLevelStr ());
	Serial.println (gps.getLunits ());
	Serial.println ();

}

//typedef struct {
//	//int id;
//	struct utc{	//1:UTC time
//		int hour;
//		int minutes;
//		int second;
//	}utc;
//	double latitude;	//2:
//	char ns;		//3:
//	double longtitude;	//4:
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







