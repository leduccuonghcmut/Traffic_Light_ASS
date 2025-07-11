#include <led7_segment.h>
#include <global.h>

const int MAX_LED = 4;
int index_led = 0;

void display7SEG(int num)
{
	//
}

void update7SEG (int index)
{
	//
}

void led7seg_run() 
{
	if (index_led > 3) {
			index_led = 0;
		}
		update7SEG(index_led++);
}

void setBuffer(int led0, int led1) 
{
	led_buffer[0] = led0/10;
	led_buffer[1] = led0%10;
	led_buffer[2] = led1/10;
	led_buffer[3] = led1%10;
}

void countAgain() {
	index_led = 0;
}

