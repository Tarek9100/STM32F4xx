

#ifndef I2C_H
#define I2C_H

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "stm32f407xx.h"
#include "I2C_Private.h"
#include "I2C_Config.h"
typedef struct
{
	I2C_RegDef_t *pI2Cx;
	I2C_Pin_Config_t I2C_Config;

}I2C_Handler;

void I2C_PerClockControl(I2C_RegDef_t *pI2Cx, u8 EnorDi);
void I2C_Init(I2C_Handler  *pI2CHandle);
void I2C_DeInit(I2C_RegDef_t *pI2Cx);

void I2C_SendData(I2C_RegDef_t *pI2Cx, u8 *pTxBuffer,u32 Len);
void I2C_ReceiveData(I2C_RegDef_t *pI2Cx,u8 *pRxBuffer,u32 Len);

void I2C_SendDataIT(I2C_Handler  *pI2CHandle, u8 *pTxBuffer,u32 Len);
void I2C_ReceiveDataIT(I2C_Handler  *pI2CHandle, u8 *pRxBuffer,u32 Len);


#endif
