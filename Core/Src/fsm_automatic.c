#include "fsm_automatic.h"
#include "fsm_settings.h"
#include "fsm_manual.h"
#include "string.h"

int count0, count1;
int led_buffer[4];
int second = 0;

void setCount (int index, int value) {
	if (index == 0) count0 = value;
	if (index == 1)	count1 = value;
}
void minusCount(){
	count0--;
	count1--;
}
int getCount (int index) {
	if (index ==0) return count0;
	if (index ==1) return count1;
	return -1;
}

void fsm_INIT() {
	status = MODE0;
	set_off0_off1();
	count0 = RedTime();
	count1 = GreenTime();
	setBuffer(RedTime(), GreenTime());
	if (second < 1) {
		SCH_Add_Task(fsm_INIT, 250, 0);
		second++;
	}
	else {
		second = 0;
		SCH_Add_Task(fsm_AUTO_RED_GREEN, 250, 0);
	}
}

void fsm_AUTO_RED_GREEN () {
	if (status == MAN_RED_GREEN) lcd_clear_display();
	set_red0_green1();

	char buffer[16];
	lcd_goto_XY(0, 1);
	lcd_goto_XY(1, 0);
	if (count0 < 10) {
		sprintf(buffer,"TrafficX: 0%d", count0);
	}
	else {
		sprintf(buffer,"TrafficX: %d", count0);
	}
	lcd_send_string(buffer);
	if (count0 < 10) {
		sprintf(buffer,"TrafficY: 0%d", count1);
	}
	else {
		sprintf(buffer,"TrafficY: %d", count1);
	}
	lcd_goto_XY(0, 1);
	lcd_send_string(buffer);

	status = AUTO_RED_GREEN;
	if (second < 3) {
			SCH_Add_Task(fsm_AUTO_RED_GREEN, 250, 0);
			second++;
	}
	else {
		second = 0;
		minusCount();
		setBuffer(count0, count1);
		if (count1 == 0) {
			SCH_Add_Task(fsm_AUTO_RED_YELLOW, 250, 0);
			count1 = AmberTime();
			count0 = AmberTime();
			setBuffer(count0, count1);
		}
		else {
			SCH_Add_Task(fsm_AUTO_RED_GREEN, 250, 0);
		}
	}
}

void fsm_AUTO_RED_YELLOW () {
	if (status == MAN_RED_YELLOW) lcd_clear_display();
	set_red0_amber1();

	char buffer[16];
	lcd_goto_XY(0, 1);
	lcd_goto_XY(1, 0);
	if (count0 < 10) {
		sprintf(buffer,"TrafficX: 0%d", count0);
	}
	else {
		sprintf(buffer,"TrafficX: %d", count0);
	}
	lcd_send_string(buffer);
	if (count0 < 10) {
		sprintf(buffer,"TrafficY: 0%d", count1);
	}
	else {
		sprintf(buffer,"TrafficY: %d", count1);
	}
	lcd_goto_XY(0, 1);
	lcd_send_string(buffer);

	status = AUTO_RED_YELLOW;
	if (second < 3) {
			SCH_Add_Task(fsm_AUTO_RED_YELLOW, 250, 0);
			second++;
	}
	else {
		second = 0;
		minusCount();
		setBuffer(count0, count1);
		if (count1 == 0) {
			SCH_Add_Task(fsm_AUTO_GREEN_RED, 250, 0);
			count0 = GreenTime();
			count1 = RedTime();
			setBuffer(count0, count1);

		}
		else {
			SCH_Add_Task(fsm_AUTO_RED_YELLOW, 250, 0);

		}
	}
}

void fsm_AUTO_GREEN_RED () {
	if (status == MAN_GREEN_RED) lcd_clear_display();
	set_green0_red1();

	char buffer[16];
	lcd_goto_XY(0, 1);
	lcd_goto_XY(1, 0);
	if (count0 < 10) {
		sprintf(buffer,"TrafficX: 0%d", count0);
	}
	else {
		sprintf(buffer,"TrafficX: %d", count0);
	}
	lcd_send_string(buffer);
	if (count0 < 10) {
		sprintf(buffer,"TrafficY: 0%d", count1);
	}
	else {
		sprintf(buffer,"TrafficY: %d", count1);
	}
	lcd_goto_XY(0, 1);
	lcd_send_string(buffer);

	status = AUTO_GREEN_RED;
	if (second < 3) {
			SCH_Add_Task(fsm_AUTO_GREEN_RED, 250, 0);
			second++;
	}
	else {
		second = 0;
		minusCount();
		setBuffer(count0, count1);
		if (count0 == 0) {
			SCH_Add_Task(fsm_AUTO_YELLOW_RED, 250, 0);
			count0 = AmberTime();
			count1 = AmberTime();
			setBuffer(count0, count1);
		}
		else {
			SCH_Add_Task(fsm_AUTO_GREEN_RED, 250, 0);
		}
	}
}

void fsm_AUTO_YELLOW_RED () {
	if (status == MAN_YELLOW_RED) lcd_clear_display();
	set_amber0_red1();

	char buffer[16];
	lcd_goto_XY(0, 1);
	lcd_goto_XY(1, 0);
	if (count0 < 10) {
		sprintf(buffer,"TrafficX: 0%d", count0);
	}
	else {
		sprintf(buffer,"TrafficX: %d", count0);
	}
	lcd_send_string(buffer);
	if (count0 < 10) {
		sprintf(buffer,"TrafficY: 0%d", count1);
	}
	else {
		sprintf(buffer,"TrafficY: %d", count1);
	}
	lcd_goto_XY(0, 1);
	lcd_send_string(buffer);

	status = AUTO_YELLOW_RED;
	if (second < 3) {
			SCH_Add_Task(fsm_AUTO_YELLOW_RED, 250, 0);
			second++;
	}
	else {
		second = 0;
		minusCount();
		setBuffer(count0, count1);
		if (count0 == 0) {
			SCH_Add_Task(fsm_AUTO_RED_GREEN, 250, 0);
			count0 = RedTime();
			count1 = GreenTime();
			setBuffer(count0, count1);
		}
		else {
			SCH_Add_Task(fsm_AUTO_YELLOW_RED, 250, 0);
		}
	}
}



