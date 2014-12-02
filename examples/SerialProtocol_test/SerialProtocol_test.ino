#include <DFRobot_utility.h>
#include <utility/SerialProtocol.h>

//
struct mytype {
        uint8_t cmd;
        uint8_t data;
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
        switch(theData->cmd) {
        case 0x01:
                break;
        case 0x02:
                break;
        case 0x03:
                break;
        default:
                ;        
        }
}


