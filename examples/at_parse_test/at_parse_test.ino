/**************************************************************************
 *	dfrobot AT command parse library example V0.2
 *
 *	you can input:
 *	+++		:without crlf to into AT mode
 *	AT+MODE=?	or 	AT+MODE=CLIENT or SERVER
 *	AT+NAME=?	or	AT+NAME=hello
 *	AT+SPEED=?	or	AT+SPEED=12
 *	quit		: to quit AT mode
 *
 * 	template:
 *	at_template at_tmp[] = {
 *	{ cmd_string1, func1 }, 
 *	{ cmd_string2, func2 }, 
 *	{ cmd_string3, func3 }, 
 *	{ "", NULL},
 *	};
 *	
 *	func template:
 *	void func (char *param) {
 *		if (param == NULL) {	// is '?' command
 *			//show value
 *		} else {
 *			//write param as value
 *			//such as: speed = atoi (param);
 *			//such as: at_string_write (name, param, sizeof (name));
 *		}
 *	}
 *
 *************************************************************************/

/*************************************************************************
 *	DFRobot_utility offer function: 
 *	serialReads ();
 *
 *	DF_AT_parse offer function: 
 *	at_string_write (char *dest, char *src, int length);
 *	parse_at_string (char *buf, at_template at_temp);
 *	at_template struct
 *************************************************************************/

#include <DFRobot_utility.h>
#include <utility/DF_AT_parse.h>

#define BUF_MAX	36

#define SERVER 0
#define CLIENT 1

char at_string[BUF_MAX];

int mode = SERVER;
int speed = 10;
char name [10]= "DFRobot";

//
void mode_func (char *param) {
	if (param == NULL) {
		Serial.print ("mode=");
		Serial.println (mode ? "CLIENT" : "SERVER");
	} else {
		if (strcmp (param, "SERVER") == 0) {
			mode = SERVER;
			Serial.println ("ok");
		} else if (strcmp (param, "CLIENT") == 0) {
			mode = CLIENT; 
			Serial.println ("ok");
		} else {
			Serial.println ("error, no this mode");
		}
	}
}

//
void name_func (char *param) {
	if (param == NULL) {
		Serial.print ("name=");
		Serial.println (name);
	} else {
		at_string_write (name, param, sizeof (name));
		if (strlen (param) >= sizeof (name)) {
			Serial.println ("error: name too long, will cut");
			Serial.print ("name=");
			Serial.println (name);
		}
		Serial.println ("ok");

	}
}

//
void speed_func (char *param) {
	if (param == NULL) {
		Serial.print ("speed=");
		Serial.println (speed);
	} else {
		speed = atoi (param);
		Serial.println ("ok");
	}
}

//at template struct
at_template at_tmp[] = {
	{"MODE", mode_func}, 
	{"NAME", name_func}, 
	{"SPEED", speed_func}, 
	{"", NULL},
};


boolean isLogin = false;

//
void setup () {
	Serial.begin (115200);
}

//
void loop () {
	int leng = serialReads (Serial, (uint8_t*)at_string, BUF_MAX, 5);
	if (leng) {
		if (isLogin) {
			if (strncmp (at_string, "quit", 4) == 0) {
				isLogin = false;
				Serial.println ("quit AT mode");
			} else {
				parse_at_string (at_string, at_tmp);
			}
		} else {
			if (strcmp (at_string, "+++") == 0) {
				isLogin = true;
				Serial.println ("into AT mode");
			} else {
				Serial.print (strlen (at_string));
				Serial.print(":");
				Serial.println (at_string);
			}
		}
	}
}

