//  #include <DFRobot_utility.h>
#include <Arduino.h>

//  struct healthcup_dat_s {
//  	uint8_t cmd;
//  	uint8_t data;
//  };

//  
//  struct healthcup_pro_s {
//          uint8_t head;
//          //      uint8_t leng;
//          struct healthcup_dat_s body;
//          uint8_t sum;
//  };
//  
//  #define DAT_SIZE (sizeof(struct healthcup_dat_s))
//  
//  #define PRO_SIZE (sizeof(struct healthcup_pro_s))
//  
//  boolean isLogin = false;
//  boolean isBind = false;
//  
//

//uint32_t readTemperature ();

//
//uint32_t readTDS (); 

//
//uint32_t readPower (); 

//
//uint32_t readADXL345 (); 

//
//void parseData (struct healthcup_dat_s * theData); 

//
//boolean checksum (uint8_t *theData, uint8_t leng); 

//
//void bleSend (uint8_t *theData, uint8_t leng); 

//
void sendData (void *theData, uint8_t ); 

//
int readData (void *theData, uint8_t); 

