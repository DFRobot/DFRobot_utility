#include <Arduino.h>

//
uint8_t decToInt2 (char *the_buf); 

//
uint8_t hexToInt2 (char *the_buf); 

//
uint8_t split_by_char (char *the_src, char the_char, char **the_des, uint8_t the_siz); 

//
uint8_t split_by_comma (char *the_src, char **the_des, uint8_t the_siz); 

//
uint8_t delete_crlf (char *the_buf); 
