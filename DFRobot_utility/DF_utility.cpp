#include "Arduino.h"
//
void fill_uint16_bigend (uint8_t *thebuf, uint16_t data) {
	*thebuf =	(uint8_t)(data>>8);
	*(thebuf+1) =	(uint8_t)data;
}


//
void fill_uint16 (uint8_t *thebuf, uint16_t data) {
        *(uint16_t*)(thebuf) = data;
}
