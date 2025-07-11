#include "main.h"
#ifndef INC_DISPLAY7SEG_H_
#define INC_DISPLAY7SEG_H_

extern int led_buffer[4];
void display7SEG(int num);
void led7seg_run();
void update7SEG(int index);
void setBuffer(int led0, int led1);
void countAgain();
#endif /* INC_DISPLAY7SEG_H_ */
