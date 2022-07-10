/***********************************************************************************/
/*                              Name : Tarek Wael                                  */
/*									ARL                                            */
/*                              SWC : GPIO                                         */
/***********************************************************************************/
#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

#define ENABLE						1
#define DISABLE						0

#define HIGH 						1
#define LOW							0

#define GPIO_PIN_NO_0					0
#define GPIO_PIN_NO_1					1
#define GPIO_PIN_NO_2					2
#define GPIO_PIN_NO_3					3
#define GPIO_PIN_NO_4					4
#define GPIO_PIN_NO_5					5
#define GPIO_PIN_NO_6					6
#define GPIO_PIN_NO_7					7
#define GPIO_PIN_NO_8					8
#define GPIO_PIN_NO_9					9
#define GPIO_PIN_NO_10					10
#define GPIO_PIN_NO_11					11
#define GPIO_PIN_NO_12					12
#define GPIO_PIN_NO_13					13
#define GPIO_PIN_NO_14					14
#define GPIO_PIN_NO_15					15

/*
 * GPIO_PIN_MODES
 * GPIO pin possible modes
 */
#define GPIO_MODE_IN					0
#define GPIO_MODE_OUT					1
#define GPIO_MODE_ALTFN					2
#define GPIO_MODE_ANALOG				3
#define GPIO_MODE_IT_FALLING			4
#define GPIO_MODE_IT_RISING				5
#define GPIO_MODE_IT_CHANGE				6

/*
 * GPIO pin possible output types
 */
#define GPIO_OP_TYPE_PP				0	// Push-Pull
#define GPIO_OP_TYPE_OD				1   //Open Drain

/*
 *  GPIO_PIN_SPEED
 * GPIO pin possible output speeds
 */
#define GPIO_SPEED_LOW 				0
#define GPIO_SPEED_MEDIUM			1
#define GPIO_SPEED_FAST 			2
#define GPIO_SPEED_HIGH				3


/* GPIO pin pull up and pull down configuration macros*/
#define GPIO_NO_PUPD				0
#define GPIO_PIN_PU					1
#define GPIO_PIN_PD					2

/*
	this enum represent Alternative function in lower register
	AFRLy: Alternate function selection for port x bit y (y = 0..7)
	These bits are written by software to configure alternate function I/Os
	AFRLy selection:
	0000: AF0
	0001: AF1
	0010: AF2
	0011: AF3
	0100: AF4
	0110: AF6
	0111: AF7
	1000: AF8
	1001: AF9
	1010: AF10
	1011: AF11
	1100: AF12
	1101: AF13
	1110: AF14
	1111: AF15
*/

typedef enum
{
	AF0,AF1,AF2,AF3,AF4,AF5,AF6,AF7,AF8,AF9,AF10,AF11,AF12,AF13,AF14,AF15
}Alt_FunctionL;



#define GPIOA_REG_RESET()					do{ (RCC->AHB1RSTR |=(1<<0));	(RCC->AHB1RSTR &=~(1<<0));} while(0)
#define GPIOB_REG_RESET()					do{ (RCC->AHB1RSTR |=(1<<1));	(RCC->AHB1RSTR &=~(1<<1));} while(0)
#define GPIOC_REG_RESET()					do{ (RCC->AHB1RSTR |=(1<<2));	(RCC->AHB1RSTR &=~(1<<2));} while(0)
#define GPIOD_REG_RESET()					do{ (RCC->AHB1RSTR |=(1<<3));	(RCC->AHB1RSTR &=~(1<<3));} while(0)
#define GPIOE_REG_RESET()					do{ (RCC->AHB1RSTR |=(1<<4));	(RCC->AHB1RSTR &=~(1<<4));} while(0)

/* do while is used to execute multiple statements in using only one micro */

/* Concatenation Function*/


#define PRIVATE_u32_CONC(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0)			PRIVATE_u32_CONC_HELP(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0)
#define PRIVATE_u32_CONC_HELP(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0)	0b##0##b15##0##b14##0##b13##0##b12##0##b11##0##b10##0##b9##0##b8##0##b7##0##b6##0##b5##0##b4##0##b3##0##b2##0##b1##0##b0

#endif /* GPIO_PRIVATE_H_ */
