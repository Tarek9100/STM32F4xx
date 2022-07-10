/***********************************************************************************/
/*                              Name : Tarek Wael                                  */
/*									ARL                                            */
/*                              SWC : GPIO                                         */
/***********************************************************************************/

#ifndef GPIO_Config_H
#define GPIO_Config_H

/*Configuration of modes of Pins */
/*Options: 1-GPIO_MODE_IN    2-GPIO_MODE_OUT  */ /* GPIO_MODE_ALTFN & GPIO_MODE_ANALOG options must be set separately */
#define GPIO_PA0_MODE 	   GPIO_MODE_IN
#define GPIO_PA1_MODE 	   GPIO_MODE_IN
#define GPIO_PA2_MODE 	   GPIO_MODE_IN
#define GPIO_PA3_MODE 	   GPIO_MODE_IN
#define GPIO_PA4_MODE      GPIO_MODE_IN
#define GPIO_PA5_MODE      GPIO_MODE_IN
#define GPIO_PA6_MODE      GPIO_MODE_IN
#define GPIO_PA7_MODE      GPIO_MODE_IN
#define GPIO_PA8_MODE 	   GPIO_MODE_IN
#define GPIO_PA9_MODE 	   GPIO_MODE_IN
#define GPIO_PA10_MODE 	   GPIO_MODE_IN
#define GPIO_PA11_MODE 	   GPIO_MODE_IN
#define GPIO_PA12_MODE     GPIO_MODE_IN
#define GPIO_PA13_MODE     GPIO_MODE_IN
#define GPIO_PA14_MODE     GPIO_MODE_IN
#define GPIO_PA15_MODE     GPIO_MODE_IN

#define GPIO_PB0_MODE 	   GPIO_MODE_IN
#define GPIO_PB1_MODE 	   GPIO_MODE_IN
#define GPIO_PB2_MODE 	   GPIO_MODE_IN
#define GPIO_PB3_MODE 	   GPIO_MODE_IN
#define GPIO_PB4_MODE      GPIO_MODE_IN
#define GPIO_PB5_MODE      GPIO_MODE_IN
#define GPIO_PB6_MODE      GPIO_MODE_IN
#define GPIO_PB7_MODE      GPIO_MODE_IN
#define GPIO_PB8_MODE 	   GPIO_MODE_IN
#define GPIO_PB9_MODE 	   GPIO_MODE_IN
#define GPIO_PB10_MODE 	   GPIO_MODE_IN
#define GPIO_PB11_MODE 	   GPIO_MODE_IN
#define GPIO_PB12_MODE     GPIO_MODE_IN
#define GPIO_PB13_MODE     GPIO_MODE_IN
#define GPIO_PB14_MODE     GPIO_MODE_IN
#define GPIO_PB15_MODE     GPIO_MODE_IN

#define GPIO_PC0_MODE 	   GPIO_MODE_IN
#define GPIO_PC1_MODE 	   GPIO_MODE_IN
#define GPIO_PC2_MODE 	   GPIO_MODE_IN
#define GPIO_PC3_MODE 	   GPIO_MODE_IN
#define GPIO_PC4_MODE      GPIO_MODE_IN
#define GPIO_PC5_MODE      GPIO_MODE_IN
#define GPIO_PC6_MODE      GPIO_MODE_IN
#define GPIO_PC7_MODE      GPIO_MODE_IN
#define GPIO_PC8_MODE 	   GPIO_MODE_IN
#define GPIO_PC9_MODE 	   GPIO_MODE_IN
#define GPIO_PC10_MODE 	   GPIO_MODE_IN
#define GPIO_PC11_MODE 	   GPIO_MODE_IN
#define GPIO_PC12_MODE     GPIO_MODE_IN
#define GPIO_PC13_MODE     GPIO_MODE_IN
#define GPIO_PC14_MODE     GPIO_MODE_IN
#define GPIO_PC15_MODE     GPIO_MODE_IN

#define GPIO_PD0_MODE 	   GPIO_MODE_IN
#define GPIO_PD1_MODE 	   GPIO_MODE_IN
#define GPIO_PD2_MODE 	   GPIO_MODE_IN
#define GPIO_PD3_MODE 	   GPIO_MODE_IN
#define GPIO_PD4_MODE      GPIO_MODE_IN
#define GPIO_PD5_MODE      GPIO_MODE_IN
#define GPIO_PD6_MODE      GPIO_MODE_IN
#define GPIO_PD7_MODE      GPIO_MODE_IN
#define GPIO_PD8_MODE 	   GPIO_MODE_IN
#define GPIO_PD9_MODE 	   GPIO_MODE_IN
#define GPIO_PD10_MODE 	   GPIO_MODE_IN
#define GPIO_PD11_MODE 	   GPIO_MODE_IN
#define GPIO_PD12_MODE     GPIO_MODE_OUT
#define GPIO_PD13_MODE     GPIO_MODE_OUT
#define GPIO_PD14_MODE     GPIO_MODE_OUT
#define GPIO_PD15_MODE     GPIO_MODE_OUT
/*Options : 1-GPIO_NO_PUPD
  			2-GPIO_PIN_PU   */                     /*PD option must be  set separately */
#define GPIO_PA0_RESISTOR			 GPIO_NO_PUPD
#define GPIO_PA1_RESISTOR			 GPIO_NO_PUPD
#define GPIO_PA2_RESISTOR			 GPIO_NO_PUPD
#define GPIO_PA3_RESISTOR			 GPIO_NO_PUPD
#define GPIO_PA4_RESISTOR            GPIO_NO_PUPD
#define GPIO_PA5_RESISTOR            GPIO_NO_PUPD
#define GPIO_PA6_RESISTOR            GPIO_NO_PUPD
#define GPIO_PA7_RESISTOR            GPIO_NO_PUPD
#define GPIO_PA8_RESISTOR            GPIO_NO_PUPD
#define GPIO_PA9_RESISTOR 	         GPIO_NO_PUPD
#define GPIO_PA10_RESISTOR           GPIO_NO_PUPD
#define GPIO_PA11_RESISTOR        	 GPIO_NO_PUPD
#define GPIO_PA12_RESISTOR        	 GPIO_NO_PUPD
#define GPIO_PA13_RESISTOR        	 GPIO_NO_PUPD
#define GPIO_PA14_RESISTOR           GPIO_NO_PUPD
#define GPIO_PA15_RESISTOR 			 GPIO_NO_PUPD

#define GPIO_PB0_RESISTOR			 GPIO_NO_PUPD
#define GPIO_PB1_RESISTOR			 GPIO_NO_PUPD
#define GPIO_PB2_RESISTOR			 GPIO_NO_PUPD
#define GPIO_PB3_RESISTOR			 GPIO_NO_PUPD
#define GPIO_PB4_RESISTOR            GPIO_NO_PUPD
#define GPIO_PB5_RESISTOR            GPIO_NO_PUPD
#define GPIO_PB6_RESISTOR            GPIO_NO_PUPD
#define GPIO_PB7_RESISTOR            GPIO_NO_PUPD
#define GPIO_PB8_RESISTOR            GPIO_NO_PUPD
#define GPIO_PB9_RESISTOR 	         GPIO_NO_PUPD
#define GPIO_PB10_RESISTOR           GPIO_NO_PUPD
#define GPIO_PB11_RESISTOR        	 GPIO_NO_PUPD
#define GPIO_PB12_RESISTOR        	 GPIO_NO_PUPD
#define GPIO_PB13_RESISTOR        	 GPIO_NO_PUPD
#define GPIO_PB14_RESISTOR           GPIO_NO_PUPD
#define GPIO_PB15_RESISTOR 			 GPIO_NO_PUPD

#define GPIO_PC0_RESISTOR			 GPIO_NO_PUPD
#define GPIO_PC1_RESISTOR			 GPIO_NO_PUPD
#define GPIO_PC2_RESISTOR			 GPIO_NO_PUPD
#define GPIO_PC3_RESISTOR			 GPIO_NO_PUPD
#define GPIO_PC4_RESISTOR            GPIO_NO_PUPD
#define GPIO_PC5_RESISTOR            GPIO_NO_PUPD
#define GPIO_PC6_RESISTOR            GPIO_NO_PUPD
#define GPIO_PC7_RESISTOR            GPIO_NO_PUPD
#define GPIO_PC8_RESISTOR            GPIO_NO_PUPD
#define GPIO_PC9_RESISTOR 	         GPIO_NO_PUPD
#define GPIO_PC10_RESISTOR           GPIO_NO_PUPD
#define GPIO_PC11_RESISTOR        	 GPIO_NO_PUPD
#define GPIO_PC12_RESISTOR        	 GPIO_NO_PUPD
#define GPIO_PC13_RESISTOR        	 GPIO_NO_PUPD
#define GPIO_PC14_RESISTOR           GPIO_NO_PUPD
#define GPIO_PC15_RESISTOR 			 GPIO_NO_PUPD

#define GPIO_PD0_RESISTOR			 GPIO_NO_PUPD
#define GPIO_PD1_RESISTOR			 GPIO_NO_PUPD
#define GPIO_PD2_RESISTOR			 GPIO_NO_PUPD
#define GPIO_PD3_RESISTOR			 GPIO_NO_PUPD
#define GPIO_PD4_RESISTOR            GPIO_NO_PUPD
#define GPIO_PD5_RESISTOR            GPIO_NO_PUPD
#define GPIO_PD6_RESISTOR            GPIO_NO_PUPD
#define GPIO_PD7_RESISTOR            GPIO_NO_PUPD
#define GPIO_PD8_RESISTOR            GPIO_NO_PUPD
#define GPIO_PD9_RESISTOR 	         GPIO_NO_PUPD
#define GPIO_PD10_RESISTOR           GPIO_NO_PUPD
#define GPIO_PD11_RESISTOR        	 GPIO_NO_PUPD
#define GPIO_PD12_RESISTOR        	 GPIO_NO_PUPD
#define GPIO_PD13_RESISTOR        	 GPIO_NO_PUPD
#define GPIO_PD14_RESISTOR           GPIO_NO_PUPD
#define GPIO_PD15_RESISTOR 			 GPIO_NO_PUPD

#endif
