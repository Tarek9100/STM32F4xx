/***********************************************************************************/
/*                              Name : Tarek Wael                                  */
/*									ARL                                            */
/*                              SWC : GPIO                                         */
/***********************************************************************************/
#ifndef GPIO_H
#define GPIO_H


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "stm32f407xx.h"
#include "GPIO_Private.h"
#include "GPIO_Config.h"

/* Peripheral Clock setup*/
void GPIO_PerClockControl(GPIO_RegDef_t *pGPIOx,u8 EnorDi);

/*Initializing/De-initializing GPIO*/
void GPIO_All_Init(void); // User Initializing from config header file
void GPIO_Initialize(GPIO_Handler * pGPIO_Handle);
void GPIO_Deinit(GPIO_RegDef_t *pGPIOx);


u8 GPIO_ReadPin(GPIO_RegDef_t  *pGPIO_x,u8 Pin_Number);
u16 GPIO_ReadPort(GPIO_RegDef_t  *pGPIO_x);
void GPIO_WritePin(GPIO_RegDef_t  *pGPIO_x,u8 Pin_Number,u8 Value);
void GPIO_WritePort(GPIO_RegDef_t  *pGPIO_x,u16 Value);
void GPIO_TogglePin(GPIO_RegDef_t  *pGPIO_x,u8 Pin_Number);
void GPIO_IRQInterruptConfig(u8 IRQNumber, u8 EnorDi);
void GPIO_IRQPriorityConfig(u8 IRQNumber, u32 IRQPriority);
void GPIO_IRQHandling(u8 PinNumber);
#endif
