/*
 * uart_com.c
 *
 *  Created on: Dec 11, 2024
 *      Author: My Laptop
 */

#include <uart_com.h>
#include <main.h>
void uart_com_fsm(UART_HandleTypeDef huart2) {
	switch(status_uart) {
		case WAIT_RST:
			// If command has completed and command = "RST" -> status = SEND_ADC, update ADC_Value, flag = 0 and setTimer
			if (command_flag == 1) {
				command_flag = 0;
				status_uart = SEND_ADC;
//				uint8_t data3[5] ="out";
//				HAL_UART_Transmit(&huart2, data3, sizeof(data3), 50);
			}
			break;

		case SEND_ADC:
			// Display ADC Value console, status = WAIT_OK
			if (command[0]=='1') {
				btn1 = 1;
				uint8_t data3[5] ="btn1";
				HAL_UART_Transmit(&huart2, data3, sizeof(data3), 50);
				status_uart = WAIT_RST;
			}
			if (command[0] =='2') {
				btn2 = 1;
				uint8_t data3[5] ="btn2";
				HAL_UART_Transmit(&huart2, data3, sizeof(data3), 50);
				status_uart = WAIT_RST;
			}
			if (command[0] == '3') {
				btn3 = 1;
				uint8_t data3[5] ="btn3";
				HAL_UART_Transmit(&huart2, data3, sizeof(data3), 50);
				status_uart = WAIT_RST;
			}

			break;
		default:
			break;
		}
}
