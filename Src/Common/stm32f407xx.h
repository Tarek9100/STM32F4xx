/*
 * stm32f407xx.h
 *
 *  Created on: May 8, 2022
 *      Author: ENG TAREK
 */

#ifndef STM_ADDRESSES_H
#define STM_ADDRESSES_H


/*********************************************Processor Specific Details*************************************************/

#define NVIC_ISER0						((volatile u32*)0xE000E100)
#define NVIC_ISER1						((volatile u32*)0xE000E104)
#define NVIC_ISER2						((volatile u32*)0xE000E108)
#define NVIC_ISER3						((volatile u32*)0xE000E10C)

#define NVIC_ICER0						((volatile u32*)0xE000E180)
#define NVIC_ICER1						((volatile u32*)0xE000E184)
#define NVIC_ICER2						((volatile u32*)0xE000E188)
#define NVIC_ICER3						((volatile u32*)0xE000E18C)

#define NVIC_PR_BASEADDR				((volatile u32*)0xE000E400)

#define NO_PR_BITS_IMPLEMENTED			4
/*
 * base addresses of Flash and SRAM memories
 */

#define FLASH_BASEADDR						0x08000000U
#define SRAM1_BASEADDR						0x20000000U
#define SRAM2_BASEADDR						0x2001C000U
#define ROM_BASEADDR						0x1FFF0000U
#define SRAM 								SRAM1_BASEADDR


/*
 * AHBx and APBx Bus Peripheral base addresses
 */

#define PERIPH_BASEADDR 						0x40000000U
#define APB1PERIPH_BASEADDR						PERIPH_BASEADDR
#define APB2PERIPH_BASEADDR						0x40010000U
#define AHB1PERIPH_BASEADDR						0x40020000U
#define AHB2PERIPH_BASEADDR						0x50000000U



#define GPIOA_BASEADDR                  (AHB1PERIPH_BASEADDR + 0x0000)
#define GPIOB_BASEADDR                  (AHB1PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR 					(AHB1PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR 					(AHB1PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR 					(AHB1PERIPH_BASEADDR + 0x1000)
#define GPIOF_BASEADDR 					(AHB1PERIPH_BASEADDR + 0x1400)
#define GPIOG_BASEADDR 					(AHB1PERIPH_BASEADDR + 0x1800)
#define GPIOH_BASEADDR 					(AHB1PERIPH_BASEADDR + 0x1C00)
#define GPIOI_BASEADDR 					(AHB1PERIPH_BASEADDR + 0x2000)

#define RCC_BASEADDR                    (AHB1PERIPH_BASEADDR + 0x3800)
#define EXTI_BASEADDR					(APB2PERIPH_BASEADDR + 0x3C00)
#define SYSCFG_BASEADDR					(APB2PERIPH_BASEADDR + 0x3800)

#define SPI1_BASEADDR					(APB2PERIPH_BASEADDR + 0x3000)
#define SPI2_BASEADDR					(APB1PERIPH_BASEADDR + 0x3800)
#define SPI3_BASEADDR					(APB1PERIPH_BASEADDR + 0x3C00)
#define SPI4_BASEADDR					(APB2PERIPH_BASEADDR + 0x3400)

#define I2C1_BASEADDR					(APB1PERIPH_BASEADDR + 0x5400)
#define I2C2_BASEADDR					(APB1PERIPH_BASEADDR + 0x5800)
#define I2C3_BASEADDR					(APB1PERIPH_BASEADDR + 0x5C00)

#define USART1_BASEADDR					(APB2PERIPH_BASEADDR + 0x1000)
#define USART2_BASEADDR					(APB1PERIPH_BASEADDR + 0x4400)
#define USART3_BASEADDR					(APB1PERIPH_BASEADDR + 0x4800)
#define UART4_BASEADDR					(APB1PERIPH_BASEADDR + 0x4C00)
#define UART5_BASEADDR					(APB1PERIPH_BASEADDR + 0x5000)
#define USART6_BASEADDR					(APB2PERIPH_BASEADDR + 0x1400)
/*
 * peripheral definitions ( Peripheral base addresses typecasted to xxx_RegDef_t)
 */

 typedef struct
{
	volatile u32 MODER;                        /*!< GPIO port mode register,      Address offset: 0x00      */
	volatile u32 OTYPER;                       /*!<     						  Address offset: 0x04      */
	volatile u32 OSPEEDR;
	volatile u32 PUPDR;
	volatile u32 IDR;
	volatile u32 ODR;
	volatile u32 BSRR;
	volatile u32 LCKR;
	volatile u32 AFR[2];					 /*!< AFR[0] : GPIO alternate function low register, AF[1] : GPIO alternate function high register    		Address offset: 0x20-0x24 */
}GPIO_RegDef_t;

typedef struct
{
	u8 GPIO_Pin_Number;
	u8 GPIO_Pin_Mode;
	u8 GPIO_Pin_Speed;
	u8 GPIO_Pin_Pu_PdCTRL;
	u8 GPIO_Pin_Output_Type;
	u8 GPIO_Pin_Alt_Function;

}GPIO_Pin_Config_t;

/* configration struct */

typedef struct
{
	GPIO_RegDef_t  * pGPIO_x;
	GPIO_Pin_Config_t  GPIO_PinConfig;
}GPIO_Handler;

typedef struct
{
	u32 I2C_SCLSpeed;
	u8 I2C_DeviceAddress;
	u8 I2C_ACKControl;
	u8 I2C_FMDutyCycle;
}I2C_Pin_Config_t;

typedef struct
{
	u8 USART_Mode;
	u32 USART_Baud;
	u8 USART_NoOfStopBits;
	u8 USART_WordLength;
	u8 USART_ParityControl;
	u8 USART_HWFlowControl;

}USART_Pin_Config_t;

typedef struct
{
	volatile u32 SPI_CR1;
	volatile u32 SPI_CR2;
	volatile u32 SPI_SR;
	volatile u32 SPI_DR;
	volatile u32 SPI_CRCPR;
	volatile u32 SPI_RXCRCR;
	volatile u32 SPI_TXCRCR;
	volatile u32 SPI_I2SCFGR;
	volatile u32 SPI_I2SPR;
}SPI_RegDef_t;

typedef struct{
	volatile u32 USART_SR;
	volatile u32 USART_DR;
	volatile u32 USART_BRR;
	volatile u32 USART_CR[3];
	volatile u32 USART_GTPR;

}USART_RegDef_t;
typedef struct
{
	volatile u32 CR;					//RCC clock control register																	Address offset: 0x00
	volatile u32 PLLCFGR;				//RCC PLL configuration register 																Address offset: 0x04
	volatile u32 CFGR;					//RCC clock configuration register																Address offset: 0x08
	volatile u32 CIR;					//RCC clock u32errupt register																	Address offset: 0x0C
	volatile u32 AHB1RSTR;				//RCC AHB1 peripheral reset register															Address offset: 0x10
	volatile u32 AHB2RSTR;				//RCC AHB2 peripheral reset register															Address offset: 0x14
	volatile u32 AHB3RSTR;				//RCC AHB3 peripheral reset register															Address offset: 0x18
	u32 Reserved0;
	volatile u32 APB1RSTR;				//RCC APB1 peripheral reset register															Address offset: 0x20
	volatile u32 APB2RSTR;				//RCC APB2 peripheral reset register															Address offset: 0x24
	u32 Reserved1[2];
	volatile u32 AHB1ENR;				//RCC AHB1 peripheral clock enable register														Address offset: 0x30
	volatile u32 AHB2ENR;				//RCC AHB2 peripheral clock enable register														Address offset: 0x34
	volatile u32 AHB3ENR;				//RCC AHB3 peripheral clock enable register														Address offset: 0x38
	u32 Reserved2;
	volatile u32 APB1ENR;				//RCC APB1 peripheral clock enable register 													Address offset: 0x40
	volatile u32 APB2ENR;				//RCC APB2 peripheral clock enable register														Address offset: 0x44
	u32 Reserved3[2];
	volatile u32 AHB1LPENR;				//RCC AHB1 peripheral clock enable in low power mode register									Address offset: 0x50
	volatile u32 AHB2LPENR;				//RCC AHB2 peripheral clock enable in low power mode register									Address offset: 0x54
	volatile u32 AHB3LPENR;				//RCC AHB3 peripheral clock enable in low power mode register									Address offset: 0x58
	u32 Reserved4;
	volatile u32 APB1LPENR;				//RCC APB1 peripheral clock enable in low power mode register									Address offset: 0x60
	volatile u32 APB2LPENR;				//RCC APB2 peripheral clock enabled in low power mode register									Address offset: 0x64
	u32 Reserved5[2];
	volatile u32 BDCR;					//RCC Backup domain control register 															Address offset: 0x70
	volatile u32 CSR;					//RCC clock control & status register															Address offset: 0x74
	u32 Reserved6[2];
	volatile u32 SSCGR;					//RCC spread spectrum clock generation register 												Address offset: 0x80
	volatile u32 PLLI2SCFGR;			//RCC PLLI2S configuration register																Address offset: 0x84
	volatile u32 PLLSAICFGR;			//RCC PLLSAI configuration register																Address offset: 0x88
	volatile u32 DCKCFGR;				//RCC DCK configuration register																Address offset: 0x8C
	volatile u32 CKGATENR;				//RCC CKGAT configuration register																Address offset: 0x90
	volatile u32 DCKCFGR2;				//RCC DCK2 Clocks Configuration Register														Address offset: 0x94


}RCC_RegDef_t;

typedef struct
{
volatile u32 IMR;																/*Address offset: 0x00*/
volatile u32 EMR;																/*Address offset: 0x04*/
volatile u32 RTSR;																/*Address offset: 0x08*/
volatile u32 FTSR;																/*Address offset: 0x0C*/
volatile u32 SWIER;																/*Address offset: 0x10*/
volatile u32 PR;																/*Address offset: 0x14*/
}EXTI_RegDef_t;

typedef struct
{
volatile u32 MEMRMP;																/*Address offset: 0x00*/
volatile u32 PMC;																	/*Address offset: 0x04*/
volatile u32 EXTICR[4];																/*Address offset: 0x08*/
u32 Reserved1[2];
volatile u32 CMPCR;																	/*Address offset: 0x20*/
 u32 Reserved2[2];
volatile u32 CFGR;																	/*Address offset: 0x2C*/

}SYSCFG_RegDef_t;

typedef struct
{
volatile u32 CR1;											/*Address offset: 0x00*/
volatile u32 CR2;											/*Address offset: 0x04*/
volatile u32 OAR1;											/*Address offset: 0x08*/
volatile u32 OAR2;											/*Address offset: 0x0C*/
volatile u32 DR;											/*Address offset: 0x10*/
volatile u32 SR1;											/*Address offset: 0x14*/
volatile u32 SR2;											/*Address offset: 0x18*/
volatile u32 CCR;											/*Address offset: 0x1C*/
volatile u32 TRISE;											/*Address offset: 0x20*/
volatile u32 FLTR;											/*Address offset: 0x24*/
}I2C_RegDef_t;

#define GPIOA  				((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB  				((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC  				((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD  				((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE  				((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF  				((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG  				((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH  				((GPIO_RegDef_t*)GPIOH_BASEADDR)
#define GPIOI  				((GPIO_RegDef_t*)GPIOI_BASEADDR)

#define RCC 				((RCC_RegDef_t*)RCC_BASEADDR)
#define SYSCFG				((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)
#define EXTI 				((EXTI_RegDef_t*)EXTI_BASEADDR)

#define SPI1				((SPI_RegDef_t*)SPI1_BASEADDR)
#define SPI2                ((SPI_RegDef_t*)SPI2_BASEADDR)
#define SPI3                ((SPI_RegDef_t*)SPI3_BASEADDR)
#define SPI4                ((SPI_RegDef_t*)SPI4_BASEADDR)

#define I2C1				((I2C_RegDef_t*)I2C1_BASEADDR)
#define I2C2				((I2C_RegDef_t*)I2C2_BASEADDR)
#define I2C3				((I2C_RegDef_t*)I2C3_BASEADDR)


#define USART1               ((USART_RegDef_t*)USART1_BASEADDR)
#define USART2               ((USART_RegDef_t*)USART2_BASEADDR)
#define USART3               ((USART_RegDef_t*)USART3_BASEADDR)
#define UART4              	 ((USART_RegDef_t*)UART4_BASEADDR)
#define UART5              	 ((USART_RegDef_t*)UART5_BASEADDR)
#define USART6               ((USART_RegDef_t*)USART6_BASEADDR)

/*
 * Clock Enable Macros for SYSCFG peripheral
 */

#define SYSCFG_PCLK_EN() (RCC->APB2ENR |= (1 << 14))

/*
 * Clock Enable Macros for GPIOx peripherals
 */
#define GPIOA_PCLK_EN()			(RCC->AHB1ENR |=(1<<0))
#define GPIOB_PCLK_EN()			(RCC->AHB1ENR |=(1<<1))
#define GPIOC_PCLK_EN()			(RCC->AHB1ENR |=(1<<2))
#define GPIOD_PCLK_EN()			(RCC->AHB1ENR |=(1<<3))
#define GPIOE_PCLK_EN()			(RCC->AHB1ENR |=(1<<4))
#define GPIOH_PCLK_EN()			(RCC->AHB1ENR |=(1<<7))


/*
 * Clock Disable Macros for GPIOx peripherals
 */
#define GPIOA_PCLK_DI()			(RCC->AHB1ENR &= ~(1<<0))
#define GPIOB_PCLK_DI()			(RCC->AHB1ENR &= ~(1<<1))
#define GPIOC_PCLK_DI()			(RCC->AHB1ENR &= ~(1<<2))
#define GPIOD_PCLK_DI()			(RCC->AHB1ENR &= ~(1<<3))
#define GPIOE_PCLK_DI()			(RCC->AHB1ENR &= ~(1<<4))
#define GPIOH_PCLK_DI()			(RCC->AHB1ENR &= ~(1<<7))

/* Clock Enable/Disable for SPIx peripherals */

#define SPI1_PCLK_EN()			(RCC->APB2ENR |= (1<<12))
#define SPI1_PCLK_DI()			(RCC->APB2ENR &= ~(1<<12))

#define SPI2_PCLK_EN()			(RCC->APB1ENR |= (1<<14))
#define SPI2_PCLK_DI()			(RCC->APB1ENR &= ~(1<<14))

#define SPI3_PCLK_EN()			(RCC->APB1ENR |= (1<<15))
#define SPI3_PCLK_DI()			(RCC->APB1ENR &= ~(1<<15))

#define SPI4_PCLK_EN()			(RCC->APB2ENR |= (1<<13))
#define SPI4_PCLK_DI()			(RCC->APB2ENR &= ~(1<<13))

/* Clock Enable/Disable for USARTx peripherals */

#define USART1_PCLK_EN()		(RCC->APB2ENR |= (1<<4))
#define USART1_PCLK_DI()		(RCC->APB2ENR &= ~(1<<4))

#define USART2_PCLK_EN()		(RCC->APB1ENR |= (1<<17))
#define USART2_PCLK_DI()		(RCC->APB1ENR &= ~(1<<17))

#define USART3_PCLK_EN()		(RCC->APB1ENR |= (1<<18))
#define USART3_PCLK_DI()		(RCC->APB1ENR &= ~(1<<18))

#define USART6_PCLK_EN()		(RCC->APB1ENR |= (1<<5))
#define USART6_PCLK_DI()		(RCC->APB1ENR &= ~(1<<5))

/* Clock Enable/Disable for UARTx peripherals */

#define UART4_PCLK_EN()			(RCC->APB1ENR |= (1<<19))
#define UART4_PCLK_DI()			(RCC->APB1ENR &= ~(1<<19))

#define UART5_PCLK_EN()			(RCC->APB1ENR |= (1<<20))
#define UART5_PCLK_DI()			(RCC->APB1ENR &= ~(1<<20))

/* Clock Enable/Disable for I2Cx peripherals */

#define I2C1_PCLK_EN()			(RCC->APB1ENR |= (1<<21))
#define I2C1_PCLK_DI()			(RCC->APB1ENR &= ~(1<<21))

#define I2C2_PCLK_EN()			(RCC->APB1ENR |= (1<<22))
#define I2C2_PCLK_DI()			(RCC->APB1ENR &= ~(1<<22))

#define I2C3_PCLK_EN()			(RCC->APB1ENR |= (1<<23))
#define I2C3_PCLK_DI()			(RCC->APB1ENR &= ~(1<<23))


#define IRQ_NO_EXTI0			6
#define IRQ_NO_EXTI1			7
#define IRQ_NO_EXTI2			8
#define IRQ_NO_EXTI3			9
#define IRQ_NO_EXTI4			10
#define IRQ_NO_EXTI9_5			23
#define IRQ_NO_EXTI10			40

#define GPIO_BASEADDR_TO_CODE(x)		(	(x==GPIOA)?0:\
											(x==GPIOB)?1:\
											(x==GPIOC)?2:\
											(x==GPIOD)?3:\
											(x==GPIOE)?4:5)
#include "GPIO.h"
#include "I2C.h"
#include "USART.h"

#endif
