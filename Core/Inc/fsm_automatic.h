#ifndef INC_FSM_AUTOMATIC_H_
#define INC_FSM_AUTOMATIC_H_

#include <global.h>

void minusCount();
void fsm_AUTO_RED_YELLOW();
void fsm_AUTO_GREEN_RED();
void fsm_AUTO_YELLOW_RED();
void fsm_AUTO_RED_GREEN();
void fsm_INIT();
void setCount (int index, int value);
int getCount (int index);

#endif 
