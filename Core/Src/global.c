/*
 * global.c
 *
 *  Created on: Oct 30, 2024
 *      Author: My Laptop
 */

#include <global.h>

int status = 0;
int status_command = WAIT_INIT;
int status_uart = WAIT_RST;

uint8_t cursor = 0;
uint8_t buffer_flag = 0;

uint8_t command[MAX_BUFFER_SIZE];
uint8_t command_index = 0;
uint8_t command_flag = 0;

uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t index_buffer = 0;

char str[50];
uint32_t ADC_value = 0;

int btn1 = 0;
int btn2 = 0;
int btn3 = 0;
