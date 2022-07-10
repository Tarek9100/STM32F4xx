/***********************************************************************************/
/*                              Name : Tarek Wael                                  */
/*									ARL                                            */
/*                              SWC : GPIO                                         */
/***********************************************************************************/


#include "GPIO.h"



void GPIO_All_Init(void){
GPIOA->MODER=PRIVATE_u32_CONC(GPIO_PA15_MODE,GPIO_PA14_MODE,GPIO_PA13_MODE,GPIO_PA12_MODE,GPIO_PA11_MODE,GPIO_PA10_MODE,
		GPIO_PA9_MODE,GPIO_PA8_MODE,GPIO_PA7_MODE,GPIO_PA6_MODE,GPIO_PA5_MODE,GPIO_PA4_MODE,
		GPIO_PA3_MODE,GPIO_PA2_MODE,GPIO_PA1_MODE,GPIO_PA0_MODE);

GPIOB->MODER=PRIVATE_u32_CONC(GPIO_PB15_MODE,GPIO_PB14_MODE,GPIO_PB13_MODE,GPIO_PB12_MODE,GPIO_PB11_MODE,GPIO_PB10_MODE,
		GPIO_PB9_MODE,GPIO_PB8_MODE,GPIO_PB7_MODE,GPIO_PB6_MODE,GPIO_PB5_MODE,GPIO_PB4_MODE,
		GPIO_PB3_MODE,GPIO_PB2_MODE,GPIO_PB1_MODE,GPIO_PB0_MODE);

GPIOC->MODER=PRIVATE_u32_CONC(GPIO_PC15_MODE,GPIO_PC14_MODE,GPIO_PC13_MODE,GPIO_PC12_MODE,GPIO_PC11_MODE,GPIO_PC10_MODE,
		GPIO_PC9_MODE,GPIO_PC8_MODE,GPIO_PC7_MODE,GPIO_PC6_MODE,GPIO_PC5_MODE,GPIO_PC4_MODE,
		GPIO_PC3_MODE,GPIO_PC2_MODE,GPIO_PC1_MODE,GPIO_PC0_MODE);

GPIOD->MODER=PRIVATE_u32_CONC(GPIO_PD15_MODE,GPIO_PD14_MODE,GPIO_PD13_MODE,GPIO_PD12_MODE,GPIO_PD11_MODE,GPIO_PD10_MODE,
		GPIO_PD9_MODE,GPIO_PD8_MODE,GPIO_PD7_MODE,GPIO_PD6_MODE,GPIO_PD5_MODE,GPIO_PD4_MODE,
		GPIO_PD3_MODE,GPIO_PD2_MODE,GPIO_PD1_MODE,GPIO_PD0_MODE);

GPIOA->PUPDR=PRIVATE_u32_CONC(GPIO_PA15_RESISTOR,GPIO_PA14_RESISTOR,GPIO_PA13_RESISTOR,GPIO_PA12_RESISTOR,GPIO_PA11_RESISTOR,GPIO_PA10_RESISTOR,
		GPIO_PA9_RESISTOR,GPIO_PA8_RESISTOR,GPIO_PA7_RESISTOR,GPIO_PA6_RESISTOR,GPIO_PA5_RESISTOR,GPIO_PA4_RESISTOR,
		GPIO_PA3_RESISTOR,GPIO_PA2_RESISTOR,GPIO_PA1_RESISTOR,GPIO_PA0_RESISTOR);

GPIOB->PUPDR=PRIVATE_u32_CONC(GPIO_PB15_RESISTOR,GPIO_PB14_RESISTOR,GPIO_PB13_RESISTOR,GPIO_PB12_RESISTOR,GPIO_PB11_RESISTOR,GPIO_PB10_RESISTOR,
		GPIO_PB9_RESISTOR,GPIO_PB8_RESISTOR,GPIO_PB7_RESISTOR,GPIO_PB6_RESISTOR,GPIO_PB5_RESISTOR,GPIO_PB4_RESISTOR,
		GPIO_PB3_RESISTOR,GPIO_PB2_RESISTOR,GPIO_PB1_RESISTOR,GPIO_PB0_RESISTOR);

GPIOC->PUPDR=PRIVATE_u32_CONC(GPIO_PC15_RESISTOR,GPIO_PC14_RESISTOR,GPIO_PC13_RESISTOR,GPIO_PC12_RESISTOR,GPIO_PC11_RESISTOR,GPIO_PC10_RESISTOR,
		GPIO_PC9_RESISTOR,GPIO_PC8_RESISTOR,GPIO_PC7_RESISTOR,GPIO_PC6_RESISTOR,GPIO_PC5_RESISTOR,GPIO_PC4_RESISTOR,
		GPIO_PC3_RESISTOR,GPIO_PC2_RESISTOR,GPIO_PC1_RESISTOR,GPIO_PC0_RESISTOR);

GPIOD->PUPDR=PRIVATE_u32_CONC(GPIO_PD15_RESISTOR,GPIO_PD14_RESISTOR,GPIO_PD13_RESISTOR,GPIO_PD12_RESISTOR,GPIO_PD11_RESISTOR,GPIO_PD10_RESISTOR,
		GPIO_PD9_RESISTOR,GPIO_PD8_RESISTOR,GPIO_PD7_RESISTOR,GPIO_PD6_RESISTOR,GPIO_PD5_RESISTOR,GPIO_PD4_RESISTOR,
		GPIO_PD3_RESISTOR,GPIO_PD2_RESISTOR,GPIO_PD1_RESISTOR,GPIO_PD0_RESISTOR);

}


void GPIO_PerClockControl(GPIO_RegDef_t *pGPIO_x,u8 EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if(pGPIO_x == GPIOA){
			GPIOA_PCLK_EN();
		}else if(pGPIO_x == GPIOB)
		{
			GPIOB_PCLK_EN();
		}else if(pGPIO_x == GPIOC)
		{
			GPIOC_PCLK_EN();
		}else if(pGPIO_x == GPIOD)
		{
			GPIOD_PCLK_EN();
		}
		else if(pGPIO_x == GPIOE)
		{
			GPIOE_PCLK_EN();
		}
	}else{

		if(pGPIO_x == GPIOA){
					GPIOA_PCLK_DI();
				}else if(pGPIO_x == GPIOB)
				{
					GPIOB_PCLK_DI();
				}else if(pGPIO_x == GPIOC)
				{
					GPIOC_PCLK_DI();
				}else if(pGPIO_x == GPIOD)
				{
					GPIOD_PCLK_DI();
				}
				else if(pGPIO_x == GPIOD)
				{
					GPIOE_PCLK_DI();
				}
		}
}

void GPIO_Initialize(GPIO_Handler * pGPIO_Handle)
{
	//1. Configure the mode of GPIO pin
if(pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Mode<= GPIO_MODE_ANALOG){
	pGPIO_Handle-> pGPIO_x->MODER &= ~( 0x3 << ( 2 * pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number)); // Clearing pre-set Mode bits before changing configuration
	pGPIO_Handle->pGPIO_x->MODER |=(pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Mode <<(2*pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number));// x2 as each pin takes 2 bit-fields
}
else{
//interrupt mode
if(pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Mode == GPIO_MODE_IT_FALLING){

	SET_BIT(EXTI->FTSR,pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number);
	CLR_BIT(EXTI->RTSR,pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number);
}
else if(pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Mode == GPIO_MODE_IT_RISING){

	SET_BIT(EXTI->RTSR,pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number);
	CLR_BIT(EXTI->FTSR,pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number);
}
else if(pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Mode == GPIO_MODE_IT_CHANGE){

	SET_BIT(EXTI->FTSR,pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number);
	SET_BIT(EXTI->RTSR,pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number);
}
u8 PortCode = GPIO_BASEADDR_TO_CODE(pGPIO_Handle ->pGPIO_x);
SYSCFG_PCLK_EN();
SYSCFG->EXTICR[pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number/4]	= PortCode <<(4*(pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number%4));

SET_BIT(EXTI->IMR,pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number);
}
	//2.Configure the speed

	pGPIO_Handle->pGPIO_x->OSPEEDR &= ~( 0x3 << ( 2 * pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number));
	pGPIO_Handle->pGPIO_x->OSPEEDR |=(pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Speed <<(2*pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number));

	//3. Configure the pull-up & pull-down configuration settings

	pGPIO_Handle->pGPIO_x->PUPDR &= ~( 0x3 << ( 2 * pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number));
	pGPIO_Handle->pGPIO_x->PUPDR |=(pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Pu_PdCTRL <<(2*pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number));

	//4. Configure the output type

	pGPIO_Handle->pGPIO_x->OTYPER &= ~( 1 << (pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number));
	pGPIO_Handle->pGPIO_x->OTYPER |=(pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Output_Type << pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number);

	//5. configure the alt functionality

	if(pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Mode == GPIO_MODE_ALTFN)
	{
		u8 temp1,temp2;
		temp1 = pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number/8; // Determine AFRL or AFRH
		temp2 = pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number%8; // Determine Pin number
		pGPIO_Handle->pGPIO_x->AFR[temp1] &= ~(0xF << (4*temp2));
		pGPIO_Handle ->pGPIO_x->AFR[temp1] |= (pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Alt_Function <<(4*temp2));
	}

}


void GPIO_Deinit(GPIO_RegDef_t *pGPIOx)
{
	if(pGPIOx == GPIOA){
		GPIOA_REG_RESET();
	}else if(pGPIOx == GPIOB)
	{
		GPIOB_REG_RESET();
	}else if(pGPIOx == GPIOC)
	{
		GPIOC_REG_RESET();
	}else if(pGPIOx == GPIOD)
	{
		GPIOD_REG_RESET();
	}
	else if(pGPIOx == GPIOE)
	{
		GPIOE_REG_RESET();
	}

}

u8 GPIO_ReadPin(GPIO_RegDef_t  * pGPIO_x,u8 Pin_Number)
{
	return  ((u8)(pGPIO_x ->IDR >> Pin_Number) & 0x00000001);
}

void GPIO_WritePin(GPIO_RegDef_t  *pGPIO_x,u8 Pin_Number,u8 Value)
{
	if (Value != LOW)
	{
	//Write 1 to the output data register at the bit
	SET_BIT(pGPIO_x->ODR,Pin_Number);

	}
	else
	{
	CLR_BIT(pGPIO_x->ODR,Pin_Number);
	}

}
u16 GPIO_ReadPort(GPIO_RegDef_t  * pGPIO_x)
{
	return ((u16) pGPIO_x->IDR);
}


void GPIO_WritePort(GPIO_RegDef_t  *pGPIO_x,u16 Value)
{

	pGPIO_x->ODR = Value;

}

void GPIO_TogglePin(GPIO_RegDef_t  *pGPIO_x,u8 Pin_Number){
	TOG_BIT(pGPIO_x->ODR,Pin_Number);
}

void GPIO_IRQInterruptConfig(u8 IRQNumber, u8 EnorDi){

	if(EnorDi==ENABLE){
		if(IRQNumber < 31){									//program ISER0
		SET_BIT(*NVIC_ISER0,IRQNumber);
		}
		else if((31 <IRQNumber) && (IRQNumber < 64)){		//program ISER1
		SET_BIT(*NVIC_ISER1,(IRQNumber%32));
		}
		else if((64 < IRQNumber) && (IRQNumber < 96)){			//program ISER2
		SET_BIT(*NVIC_ISER2,(IRQNumber%64));
		}
	}else{
		if(IRQNumber < 31){									//program ISER0
		SET_BIT(*NVIC_ICER0,IRQNumber);
		}
		else if((31 <IRQNumber) && (IRQNumber < 64)){		//program ISER1
		SET_BIT(*NVIC_ICER1,(IRQNumber%32));
		}
		else if((64 < IRQNumber) && (IRQNumber < 96)){			//program ISER2
		SET_BIT(*NVIC_ICER2,(IRQNumber%64));
		}
		}

	}
void GPIO_IRQPriorityConfig( u8 IRQNumber, u32 IRQPriority){
u8 shift_amount	= (8*(IRQNumber%4)) + (8 - NO_PR_BITS_IMPLEMENTED) ;
SET_BIT(*(NVIC_PR_BASEADDR + (IRQNumber/4)),(IRQPriority << shift_amount));
}

void GPIO_IRQHandling(u8 PinNumber){

if(EXTI->PR & (1 << PinNumber)){
	SET_BIT(EXTI->PR,(1 << PinNumber)); //clear PR Register
}

}
