/**************************************************************************/
/*! 
  @file     checksum.h
  @author   lisper (lisper.li@dfrobot.com)
  @license  LGPLv3 (see license.txt) 

  provide some useful function make it easy to get checksum

  Copyright (C) DFRobot - www.dfrobot.com
 */
/**************************************************************************/
uint8_t checksum_add (uint8_t *data, uint8_t leng); 

uint8_t checksum_nadd (uint8_t *data, uint8_t leng); 

uint8_t checksum_xor (uint8_t *data, uint8_t leng); 

uint8_t checksum_add_n (uint8_t *data, uint8_t left, uint8_t right); 

uint8_t checksum_nadd_n (uint8_t *data, uint8_t left, uint8_t right); 

uint8_t checksum_xor_n (uint8_t *data, uint8_t left, uint8_t right); 

