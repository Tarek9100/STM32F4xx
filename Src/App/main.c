/*
 * main.c
 *
 *  Created on: May 11, 2022
 *      Author: ENG TAREK
 */

#include "GPIO.h"

void delay(void){
	u32 i=0;
	while(i<200000){
		i++;
	}
}
int main(){

	GPIO_Handler GPIO_LED,GPIOBtn;
	GPIO_LED.pGPIO_x= GPIOD;
	GPIO_LED.GPIO_PinConfig.GPIO_Pin_Number = GPIO_PIN_NO_12;
	GPIO_LED.GPIO_PinConfig.GPIO_Pin_Mode = GPIO_MODE_OUT;
	GPIO_LED.GPIO_PinConfig.GPIO_Pin_Speed =GPIO_SPEED_HIGH;
	GPIO_LED.GPIO_PinConfig.GPIO_Pin_Output_Type = GPIO_OP_TYPE_PP;
	GPIO_LED.GPIO_PinConfig.GPIO_Pin_Pu_PdCTRL = GPIO_NO_PUPD;
	GPIO_PerClockControl(GPIOD,ENABLE);
	GPIO_Initialize(&GPIO_LED);

	GPIOBtn.pGPIO_x= GPIOA;
	GPIOBtn.GPIO_PinConfig.GPIO_Pin_Number = GPIO_PIN_NO_0;
	GPIOBtn.GPIO_PinConfig.GPIO_Pin_Mode = GPIO_MODE_IN;
	GPIOBtn.GPIO_PinConfig.GPIO_Pin_Speed =GPIO_SPEED_HIGH;
	GPIOBtn.GPIO_PinConfig.GPIO_Pin_Pu_PdCTRL = GPIO_PIN_PU;
	GPIO_PerClockControl(GPIOA,ENABLE);
	GPIO_Initialize(&GPIOBtn);

	USART_Handler_t USART3_H;
	USART3_H.pUSARTx = USART3;
	USART3_H.USART_Config.USART_Baud = USART_STD_BAUD_9600;
	USART3_H.USART_Config.USART_NoOfStopBits = USART_STOPBITS_1;
	USART3_H.USART_Config.USART_HWFlowControl = USART_HW_FLOW_CTRL_NONE;
	USART3_H.USART_Config.USART_Mode = USART_MODE_TXRX;
	USART3_H.USART_Config.USART_WordLength = USART_WORDLEN_8BITS;
	USART3_H.USART_Config.USART_ParityControl = USART_PARITY_DISABLE;
	USART_Init(&USART_Handler_t);



//	GPIO_IRQPriorityConfig(IRQ_NO_EXTI0,15);
//	GPIO_IRQInterruptConfig(IRQ_NO_EXTI0,ENABLE);


while(1){


}
return 0;
}



