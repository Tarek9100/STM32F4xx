/*
 * I2C.c
 *
 *  Created on: May 13, 2022
 *      Author: ENG TAREK
 */
#include "I2C.h"

/*u32 Prescalar_Arr[8] = {2,4,8,16,64,128,256,512};
u32 RCC_GetPCLK1Value(void){
	u32 pclk1,SystemClock;
	u8 clksrc,temp,ahb,apb1;
	clksrc = ((RCC->CFGR>>2) & 0x3);
	switch(clksrc){
	case 0:SystemClock = 16000000;break; //HSI
	case 1:SystemClock = 8000000;break;  //HSE
	case 2:temp = ((RCC->CFGR>>4) & 0xF);
	if(temp<8){
	ahb=1;
	}
	else{
	ahb=Prescalar_Arr[temp-8];
	}
	temp = ((RCC->CFGR>>10) & 0x7);
		if(temp<4){
		apb1=1;
		}
		else{
		apb1=Prescalar_Arr[temp-4];
		}
	}

pclk1 = (SystemClock/ahb)/apb1;
return pclk1;}
*/
void I2C_PerClockControl(I2C_RegDef_t *pI2Cx, u8 EnorDi){
	if(EnorDi == DISABLE){
		CLR_BIT(pI2Cx->CR1,0);
		if(pI2Cx == I2C1){
			I2C1_PCLK_DI();
		}
		else if(pI2Cx == I2C2){
			I2C2_PCLK_DI();
		}
		else if(pI2Cx == I2C3){
			I2C3_PCLK_DI();
		}
	}
	else{
		SET_BIT(pI2Cx->CR1,0);
		if(pI2Cx == I2C1){
			I2C1_PCLK_EN();
		}
		else if(pI2Cx == I2C2){
			I2C2_PCLK_EN();
		}
		else if(pI2Cx == I2C3){
			I2C3_PCLK_EN();
		}
	}
}

void I2C_Init(I2C_Handler  *pI2CHandle){
	u32 tempreg = 0;
	//Ack Control bit
	tempreg |= pI2CHandle->I2C_Config.I2C_ACKControl << 10;
	pI2CHandle->pI2Cx->CR1 = tempreg;
	//Configure the FREQ field of CR2
	tempreg = 0;
	tempreg |= RCC_GetPCLK1Value()/1000000U;
	pI2CHandle->pI2Cx->CR2 = (tempreg & 0x3F);
	//Program the device own address
	tempreg |= pI2CHandle->I2C_Config.I2C_DeviceAddress <<1;
	tempreg |= (1<<14);
	pI2CHandle->pI2Cx->OAR1 = tempreg;
	//CCR Calculations
	u16 ccr_val = 0;
	tempreg = 0;
	if(pI2CHandle->I2C_Config.I2C_SCLSpeed <= I2C_SCL_SPEED_SM){
	//Standard Mode
	ccr_val = (RCC_GetPCLK1Value()/(2*pI2CHandle->I2C_Config.I2C_SCLSpeed));
	tempreg |= (ccr_val & 0xFFF);
	}
	else{
	//Fast Mode
	tempreg |= (1<<15);
	tempreg |= (pI2CHandle->I2C_Config.I2C_FMDutyCycle << 14);
	if(pI2CHandle->I2C_Config.I2C_FMDutyCycle == I2C_FM_DUTY_2){
		ccr_val = (RCC_GetPCLK1Value()/(3*pI2CHandle->I2C_Config.I2C_SCLSpeed));
	}
	else if(pI2CHandle->I2C_Config.I2C_FMDutyCycle == I2C_FM_DUTY_16){
		ccr_val = (RCC_GetPCLK1Value()/(25*pI2CHandle->I2C_Config.I2C_SCLSpeed));
	}
	tempreg |= (ccr_val & 0xFFF);
	}
	pI2CHandle->pI2Cx->CCR = tempreg;
}
void I2C_DeInit(I2C_RegDef_t *pI2Cx){

}
