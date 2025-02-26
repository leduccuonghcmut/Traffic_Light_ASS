/*
 * traffic_light.c
 *
 *  Created on: Oct 30, 2024
 *      Author: My Laptop
 */

#include <traffic_light.h>
#include <led7_segment.h>
// - ways
void set_off0_off1(){
	HAL_GPIO_WritePin(D9_LED0_GPIO_Port, D9_LED0_Pin, RESET);
	HAL_GPIO_WritePin(D10_LED1_GPIO_Port, D10_LED1_Pin, RESET);
	HAL_GPIO_WritePin(D3_LED0_GPIO_Port, D3_LED0_Pin, RESET);
	HAL_GPIO_WritePin(D4_LED1_GPIO_Port, D4_LED1_Pin, RESET);
}

void set_red0_green1(){
	HAL_GPIO_WritePin(D10_LED1_GPIO_Port, D10_LED1_Pin, SET);
	HAL_GPIO_WritePin(D9_LED0_GPIO_Port, D9_LED0_Pin, SET);
	HAL_GPIO_WritePin(D4_LED1_GPIO_Port, D4_LED1_Pin, RESET);
	HAL_GPIO_WritePin(D3_LED0_GPIO_Port, D3_LED0_Pin, SET);

}
void set_red0_amber1() {
	HAL_GPIO_WritePin(D10_LED1_GPIO_Port, D10_LED1_Pin, SET);
	HAL_GPIO_WritePin(D9_LED0_GPIO_Port, D9_LED0_Pin, SET);
	HAL_GPIO_WritePin(D4_LED1_GPIO_Port, D4_LED1_Pin, SET);
	HAL_GPIO_WritePin(D3_LED0_GPIO_Port, D3_LED0_Pin, RESET);
}
void set_green0_red1() {
	HAL_GPIO_WritePin(D10_LED1_GPIO_Port, D10_LED1_Pin, RESET);
	HAL_GPIO_WritePin(D9_LED0_GPIO_Port, D9_LED0_Pin, SET);
	HAL_GPIO_WritePin(D4_LED1_GPIO_Port, D4_LED1_Pin, SET);
	HAL_GPIO_WritePin(D3_LED0_GPIO_Port, D3_LED0_Pin, SET);
}
void set_amber0_red1()
{
	HAL_GPIO_WritePin(D10_LED1_GPIO_Port, D10_LED1_Pin, SET);
	HAL_GPIO_WritePin(D9_LED0_GPIO_Port, D9_LED0_Pin, RESET);
	HAL_GPIO_WritePin(D4_LED1_GPIO_Port, D4_LED1_Pin, SET);
	HAL_GPIO_WritePin(D3_LED0_GPIO_Port, D3_LED0_Pin, SET);
}

void setallRed() {
	HAL_GPIO_WritePin(D10_LED1_GPIO_Port, D10_LED1_Pin, SET);
	HAL_GPIO_WritePin(D9_LED0_GPIO_Port, D9_LED0_Pin, SET);
	HAL_GPIO_WritePin(D4_LED1_GPIO_Port, D4_LED1_Pin, SET);
	HAL_GPIO_WritePin(D3_LED0_GPIO_Port, D3_LED0_Pin, SET);
}
void setallGreen() {
	HAL_GPIO_WritePin(D10_LED1_GPIO_Port, D10_LED1_Pin, RESET);
	HAL_GPIO_WritePin(D9_LED0_GPIO_Port, D9_LED0_Pin, SET);
	HAL_GPIO_WritePin(D4_LED1_GPIO_Port, D4_LED1_Pin, RESET);
	HAL_GPIO_WritePin(D3_LED0_GPIO_Port, D3_LED0_Pin, SET);
}
void setallAmber() {
	HAL_GPIO_WritePin(D10_LED1_GPIO_Port, D10_LED1_Pin, SET);
	HAL_GPIO_WritePin(D9_LED0_GPIO_Port, D9_LED0_Pin, RESET);
	HAL_GPIO_WritePin(D4_LED1_GPIO_Port, D4_LED1_Pin, SET);
	HAL_GPIO_WritePin(D3_LED0_GPIO_Port, D3_LED0_Pin, RESET);
}
void setallOff() {
	HAL_GPIO_WritePin(D9_LED0_GPIO_Port, D9_LED0_Pin, RESET);
	HAL_GPIO_WritePin(D10_LED1_GPIO_Port, D10_LED1_Pin, RESET);
	HAL_GPIO_WritePin(D3_LED0_GPIO_Port, D3_LED0_Pin, RESET);
	HAL_GPIO_WritePin(D4_LED1_GPIO_Port, D4_LED1_Pin, RESET);
}
