#include <DFRobot_utility.h>
#include <utility/SerialProtocol.h>

//
struct mytype {
	uint8_t cmd;
	uint32_t data;
};

//
struct mytype receiveCmd;

//
void setup () {
	Serial.begin (115200);
}

//
void loop () {
	int result = readData (&receiveCmd, sizeof (receiveCmd));
	if (result> 0) {
		parseData (&receiveCmd);
	}
}

//
void parseData (struct mytype *theData) {
	mytype sendCmd;
	switch(theData->cmd) {
		case 0x01:	//say "hello"
			Serial.println ("hello");
			break;
		case 0x02:	//return the same data
			sendCmd.cmd = theData->cmd | 0x80;
			sendCmd.data = theData->data;
			sendData ((void*)&sendCmd, sizeof (sendCmd));
			break;
		case 0x03:	//print the command and data
			Serial.println (theData->cmd, HEX);
			Serial.println (theData->data, HEX);
			break;
		default:
			Serial.println ("error! no this command!");
	}
}


