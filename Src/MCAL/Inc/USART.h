#ifndef USART_H
#define USART_H

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "stm32f407xx.h"
#include "USART_Private.h"
#include "USART_Config.h"

typedef struct{
	USART_RegDef_t *pUSARTx;
	USART_Pin_Config_t USART_Config;
}USART_Handler_t;



/*
 * Peripheral Clock setup
 */
void USART_PeriClockControl(USART_RegDef_t *pUSARTx, u8 EnorDi);

/*
 * Init and De-init
 */
void USART_Init(USART_Handler_t *pUSARTHandle);
void USART_DeInit(USART_RegDef_t *pUSARTx);


/*
 * Data Send and Receive
 */
void USART_SendData(USART_Handler_t *pUSARTHandle,u8 *pTxBuffer, u32 Len);
void USART_ReceiveData(USART_Handler_t *pUSARTHandle, u8 *pRxBuffer, u32 Len);
u8 USART_SendDataIT(USART_Handler_t *pUSARTHandle,u8 *pTxBuffer, u32 Len);
u8 USART_ReceiveDataIT(USART_Handler_t *pUSARTHandle, u8 *pRxBuffer, u32 Len);
void USART_SetBaudRate(USART_RegDef_t *pUSARTx, u32 BaudRate);
/*
 * IRQ Configuration and ISR handling
 */
void USART_IRQInterruptConfig(u8 IRQNumber, u8 EnorDi);
void USART_IRQPriorityConfig(u8 IRQNumber, u32 IRQPriority);
void USART_IRQHandling(USART_Handler_t *pHandle);

/*
 * Other Peripheral Control APIs
 */
u8 USART_GetFlagStatus(USART_RegDef_t *pUSARTx , u32 FlagName);
void USART_ClearFlag(USART_RegDef_t *pUSARTx, u16 StatusFlagName);

/*
 * Application callback
 */
void USART_ApplicationEventCallback(USART_Handler_t *pUSARTHandle,u8 AppEv);

















#endif
