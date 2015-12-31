/**************************************************************************/
/*! 
  @file     DF_GPS.h
  @author   lisper (leyapin@gmail.com, lisper.li@dfrobot.com)
  @license  LGPLv3 (see license.txt) 

  serial GPS library

  Copyright (C) DFRobot - www.dfrobot.com
 */
/**************************************************************************/

#ifndef _DF_GPS
#define _DF_GPS

#include <Arduino.h>


typedef struct {
	struct utc{	//1:UTC time
		uint8_t hour;
		uint8_t minute;
		uint8_t second;
	}utc;
	double latitude;	//2:
	char ns;		//3:
	double longitude;	//4:
	char ew;		//5:
	uint8_t fix;	//6:gps status 0 1 2 3 4 5 6 7 8 9
	uint8_t num;	//7:
	double hdop;	//8:水平精度
	double altitude;	//9:海拔高度
	char a_units;	//10:单位M
	double level;	//11:大地水准面高度
	char l_units;	//12:单位M
	double diff_time;	//13:差分GPS数据期限(RTCM SC-104)，最后设立RTCM传送的秒数量，如不是差分定位则为空
	uint8_t diff_id;	//14:差分参考基站标号
} gpgga_s;

#define GPS_BUF_SIZE 101
#define GPSP_SIZE 15


class DFGPS {
	private:
		Stream *_mySerial;

		// check sum using xor
		uint8_t gpsCalcChecksum (char *array); 

		//get gga checksum
		uint8_t gpsReadChecksum (char **the_str); 
		//
		void gps_print_gpgga (gpgga_s *my_gpgga); 
		int parse ();
		uint8_t wordNum;

	public :
		DFGPS (Stream & mySerial);
		char gps_buffer[GPS_BUF_SIZE];
		char *gpsp[GPSP_SIZE];
		int read ();
		void printGPGGA ();
		void gpgga (gpgga_s *gpgga_data); 

		boolean gpsAvailable (); 
		boolean timeAvailable ();
		uint8_t getHour (); 

		char *getTime ();
		uint8_t getMinute (); 

		uint8_t getSecond (); 

		double getLatitude (); 
		char *getLatitudeStr (); 
		double getLongitude (); 
		char *getLongitudeStr (); 

		char getNS (); 

		char getEW (); 

		char fixc ();
		uint8_t fix ();
		uint8_t getNum (); 
		char *getNumStr (); 

		char *getHDOPStr (); 
		double getHDOP (); 
		char *getAltidudeStr (); 
		double getAltidude (); 

		char getAunits (); 

		char *getLevelStr (); 
		double getLevel (); 

		char getLunits (); 


};

#endif
