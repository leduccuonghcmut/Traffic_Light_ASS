#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include <software_interrupt.h>
#include <button.h>
#include <main.h>
#include <led7_segment.h>
#include "traffic_light.h"
#include <scheduler.h>
#include <i2c_lcd.h>
#include "stdio.h"
#include "stdlib.h"
#include "global.h"
#include "string.h"
#include "math.h"
extern int status;

#define MODE0 1

#define MAN_RED_GREEN 6
#define MAN_RED_YELLOW 7
#define MAN_GREEN_RED 8
#define MAN_YELLOW_RED 9


#define AUTO_RED_GREEN 10
#define AUTO_RED_YELLOW 11
#define AUTO_GREEN_RED 12
#define AUTO_YELLOW_RED 13

#define SET_REDTIME 14
#define SET_AMBERTIME 15
#define SET_GREENTIME 16

#define WAIT_INIT 		0
#define WAIT_END		1

// Status UART communication
#define WAIT_RST 		10
#define SEND_ADC		11
#define WAIT_OK 		12

#define MAX_BUFFER_SIZE 30

extern int status_command;
extern int status_uart;

// Variables to read data
extern uint8_t cursor;
extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t index_buffer;
extern uint8_t buffer_flag;

// Variables to read command
extern uint8_t command_flag;
extern uint8_t command[MAX_BUFFER_SIZE];
extern uint8_t command_index;

// String to display console
extern char str[50];


extern int btn1;
extern int btn2;
extern int btn3;


#endif /* INC_GLOBAL_H_ */


