/*
 * USART.c
 *
 *  Created on: Jul 5, 2022
 *      Author: ENG TAREK
 */

#include"USART.h"

u32 Prescalar_Arr[8] = {2,4,8,16,64,128,256,512};
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
u32 RCC_GetPCLK2Value(void){
	u32 pclk2,SystemClock;
	u8 clksrc,temp,ahb,apb2;
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
	temp = ((RCC->CFGR>>13) & 0x7);
		if(temp<4){
		apb2=1;
		}
		else{
		apb2=Prescalar_Arr[temp-4];
		}
	}

pclk2 = (SystemClock/ahb)/apb2;
return pclk2;}



void USART_PeriClockControl(USART_RegDef_t *pUSARTx,u8 EnOrDi){
	if(EnOrDi == DISABLE){
		CLR_BIT(pUSARTx->USART_CR[0],13);
			if(pUSARTx == USART1){
				USART1_PCLK_DI();
			}
			else if(pUSARTx == USART2){
				USART2_PCLK_DI();
			}
			else if(pUSARTx == USART3){
				USART3_PCLK_DI();
			}
			else if(pUSARTx == UART4){
				UART4_PCLK_DI();
			}
			else if(pUSARTx == UART5){
				UART5_PCLK_DI();
			}
			else if(pUSARTx == USART6){
				USART6_PCLK_DI();
			}
		}
		else if(EnOrDi == ENABLE){
			SET_BIT(pUSARTx->USART_CR[0],13);
			if(pUSARTx == USART1){
				USART1_PCLK_EN();
			}
			else if(pUSARTx == USART2){
				USART2_PCLK_EN();
			}
			else if(pUSARTx == USART3){
				USART3_PCLK_EN();
			}
			else if(pUSARTx == UART4){
				UART4_PCLK_EN();
			}
			else if(pUSARTx == UART5){
				UART5_PCLK_EN();
			}
			else if(pUSARTx == USART6){
				USART6_PCLK_EN();
			}
		}
}

void USART_Init(USART_Handler_t *pUSARTHandler)
{

	//Temporary variable
	u32 tempreg=0;

/******************************** Configuration of CR1******************************************/


	//Enable USART Tx and Rx engines according to the USART_Mode configuration item
	if ( pUSARTHandler->USART_Config.USART_Mode == USART_MODE_ONLY_RX)
	{
		//Enables the Receiver bit field
		SET_BIT(tempreg,2);
	}else if (pUSARTHandler->USART_Config.USART_Mode == USART_MODE_ONLY_TX)
	{
		//Enables the Transmitter bit field
		SET_BIT(tempreg,3);

	}else if (pUSARTHandler->USART_Config.USART_Mode == USART_MODE_TXRX)
	{
		//Enables the both Transmitter and Receiver bit fields
		SET_BIT(tempreg,2);
		SET_BIT(tempreg,3);
	}

    //Configuring word length
	if(pUSARTHandler->USART_Config.USART_WordLength == USART_WORDLEN_9BITS){
		SET_BIT(tempreg,12);
	}
	else if(pUSARTHandler->USART_Config.USART_WordLength == USART_WORDLEN_8BITS){
		CLR_BIT(tempreg,12);
		}



    //Configuration of parity control bit fields
	if ( pUSARTHandler->USART_Config.USART_ParityControl == USART_PARITY_EN_EVEN)
	{
		//Enables the parity control
		SET_BIT(tempreg,10);

		//Enables EVEN parity
		CLR_BIT(tempreg,9);

	}else if (pUSARTHandler->USART_Config.USART_ParityControl == USART_PARITY_EN_ODD )
	{
		//Enables the parity control
	    SET_BIT(tempreg,10);

	    //Enables ODD parity
	    SET_BIT(tempreg,9);

	}

   //Program the CR1 register
	pUSARTHandler->pUSARTx->USART_CR[0] = tempreg;

/******************************** Configuration of CR2******************************************/

	tempreg=0;

	//Configuring the number of stop bits inserted during USART frame transmission
	switch(pUSARTHandler->USART_Config.USART_NoOfStopBits){
	case USART_STOPBITS_1: CLR_BIT(tempreg,12);CLR_BIT(tempreg,13);break;
	case USART_STOPBITS_0_5: SET_BIT(tempreg,12);CLR_BIT(tempreg,13);break;
	case USART_STOPBITS_2: SET_BIT(tempreg,13);CLR_BIT(tempreg,12);break;
	case USART_STOPBITS_1_5: SET_BIT(tempreg,12);SET_BIT(tempreg,13);break;
	default:CLR_BIT(tempreg,12);CLR_BIT(tempreg,13);break;
	}


	//Program the CR2 register
	pUSARTHandler->pUSARTx->USART_CR[1] = tempreg;

/******************************** Configuration of CR3******************************************/

	tempreg=0;

	//Configuration of USART hardware flow control
	if ( pUSARTHandler->USART_Config.USART_HWFlowControl == USART_HW_FLOW_CTRL_CTS)
	{
		SET_BIT(tempreg,9);

	}
	else if (pUSARTHandler->USART_Config.USART_HWFlowControl == USART_HW_FLOW_CTRL_RTS)
	{
		//Enables RTS flow control
		SET_BIT(tempreg,8);

	}
	else if (pUSARTHandler->USART_Config.USART_HWFlowControl == USART_HW_FLOW_CTRL_CTS_RTS)
	{
		//Enables both CTS and RTS Flow control
		SET_BIT(tempreg,9);SET_BIT(tempreg,8);
	}


	pUSARTHandler->pUSARTx->USART_CR[3] = tempreg;
	//void USART_SetBaudRate(pUSARTHandler->pUSARTx , pUSARTHandler->USART_Config.USART_Baud);
}
void USART_SendData(USART_Handler_t *pUSARTHandle, u8 *pTxBuffer, u32 Len)
{

	u16 *pdata;
   //Loop over until "Len" number of bytes are transferred
	for(u32 i = 0 ; i < Len; i++)
	{
		//Wait until TXE flag is set in the SR
		while(! GET_BIT(pUSARTHandle->pUSARTx->USART_SR ,USART_FLAG_TXE));

         //Check the USART_WordLength item for 9BIT or 8BIT in a frame
		if(pUSARTHandle->USART_Config.USART_WordLength == USART_WORDLEN_9BITS)
		{
			//if 9BIT, load the DR with 2bytes masking the bits other than first 9 bits
			pdata = (u16*) pTxBuffer;
			pUSARTHandle->pUSARTx->USART_DR  = (*pdata & (u16)0x01FF);//111111111

			//check for USART_ParityControl
			if(pUSARTHandle->USART_Config.USART_ParityControl == USART_PARITY_DISABLE)
			{
				//No parity is used in this transfer. so, 9bits of user data will be sent
				//Increment pTxBuffer twice
				pTxBuffer++;
				pTxBuffer++;
			}
			else
			{
				//Parity bit is used in this transfer . so , 8bits of user data will be sent
				//The 9th bit will be replaced by parity bit by the hardware
				pTxBuffer++;
			}
		}
		else
		{
			//This is 8bit data transfer
			pUSARTHandle->pUSARTx->USART_DR = (*pTxBuffer  & (u8)0xFF); //11111111

			//Implement the code to increment the buffer address
			pTxBuffer++;
		}
	}

	//Implement the code to wait till TC flag is set in the SR
	while( ! USART_GetFlagStatus(pUSARTHandle->pUSARTx,USART_FLAG_TC));
}


/*********************************************************************
 * @fn      		  - USART_ReceiveData
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */

void USART_ReceiveData(USART_Handler_t *pUSARTHandle, u8 *pRxBuffer, u32 Len)
{
   //Loop over until "Len" number of bytes are transferred
	for(u32 i = 0 ; i < Len; i++)
	{
		//Implement the code to wait until RXNE flag is set in the SR
		while(!(GET_BIT(pUSARTHandle->pUSARTx->USART_SR ,USART_FLAG_RXNE)));

		//Check the USART_WordLength to decide whether we are going to receive 9bit of data in a frame or 8 bit
		if(pUSARTHandle->USART_Config.USART_WordLength == USART_WORDLEN_9BITS)
		{
			//We are going to receive 9bit data in a frame

			//Check are we using USART_ParityControl control or not
			if(pUSARTHandle->USART_Config.USART_ParityControl == USART_PARITY_DISABLE)
			{
				//No parity is used. so, all 9bits will be of user data

				//read only first 9 bits. so, mask the DR with 0x01FF
				*((u16*) pRxBuffer) = (pUSARTHandle->pUSARTx->USART_DR & (u16)0x01FF);

				//Now increment the pRxBuffer two times
				pRxBuffer+=2;
			}
			else
			{
				//Parity is used, so, 8bits will be of user data and 1 bit is parity
				 *pRxBuffer = (pUSARTHandle->pUSARTx->USART_DR  & (u8)0xFF);

				 //Increment the pRxBuffer
				 pRxBuffer++;
			}
		}
		else
		{
			//We are going to receive 8bit data in a frame

			//check are we using USART_ParityControl control or not
			if(pUSARTHandle->USART_Config.USART_ParityControl == USART_PARITY_DISABLE)
			{
				//No parity is used , so all 8bits will be of user data

				//read 8 bits from DR
				 *pRxBuffer = pUSARTHandle->pUSARTx->USART_DR;
			}

			else
			{
				//Parity is used, so , 7 bits will be of user data and 1 bit is parity

				//read only 7 bits , hence mask the DR with 0X7F
				 *pRxBuffer = (u8)(pUSARTHandle->pUSARTx->USART_DR  & (u8)0x7F);

			}

			//Increment the pRxBuffer
			pRxBuffer++;
		}
	}

}

void USART_SetBaudRate(USART_RegDef_t *pUSARTx, u32 BaudRate)
{

	//Variable to hold the APB clock
	u32 PCLKx;

	u32 usartdiv;

	//variables to hold Mantissa and Fraction values
	u32 M_part,F_part;

  u32 tempreg=0;

  //Get the value of APB bus clock in to the variable PCLKx
  if(pUSARTx == USART1 || pUSARTx == USART6)
  {
	   //USART1 and USART6 are hanging on APB2 bus
	   PCLKx = RCC_GetPCLK2Value();
  }
  else
  {
	   PCLKx = RCC_GetPCLK1Value();
  }

  //Check for OVER8 configuration bit
  if(GET_BIT(pUSARTx->USART_CR[0],15))
  {
	   //OVER8 = 1 , over sampling by 8
	   usartdiv = ((25 * PCLKx) / (2 *BaudRate));
  }else
  {
	   //over sampling by 16
	  usartdiv = ((25 * PCLKx) / (4 *BaudRate));
  }

  //Calculate the Mantissa part
  M_part = usartdiv/100;

  //Place the Mantissa part in appropriate bit position . refer USART_BRR
  tempreg |= M_part << 4;

  //Extract the fraction part
  F_part = (usartdiv - (M_part * 100));

  //Calculate the final fractional
  if(GET_BIT(pUSARTx->USART_CR[0],USART_CR1_OVER8))
   {
	  //OVER8 = 1 , over sampling by 8
	  F_part = ((( F_part * 8)+ 50) / 100)& ((u8)0x07); //Adding 50 to round up number

   }else
   {
	   //over sampling by 16
	   F_part = ((( F_part * 16)+ 50) / 100) & ((u8)0x0F);

   }

  //Place the fractional part in appropriate bit position . refer USART_BRR
  tempreg |= F_part;

  //copy the value of tempreg in to BRR register
  pUSARTx->USART_BRR = tempreg;
}

/*********************************************************************
 * @fn      		  - USART_SendDataWithIT
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              - Resolve all the TODOs

 */
/*u8 USART_SendDataIT(USART_Handler_t *pUSARTHandle,u8 *pTxBuffer, u32 Len)
{
	u8 txstate = pUSARTHandle->TODO;

	if(txstate != USART_BUSY_IN_TX)
	{
		pUSARTHandle->TODO = Len;
		pUSARTHandle->pTxBuffer = TODO;
		pUSARTHandle->TxBusyState = TODO;

		//Implement the code to enable interrupt for TXE
		TODO


		//Implement the code to enable interrupt for TC
		TODO


	}

	return txstate;

}


/*********************************************************************
 * @fn      		  - USART_ReceiveDataIT
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              - Resolve all the TODOs

 */
/*u8 USART_ReceiveDataIT(USART_Handler_t *pUSARTHandle,u8 *pRxBuffer, u32 Len)
{
	u8 rxstate = pUSARTHandle->TODO;

	if(rxstate != TODO)
	{
		pUSARTHandle->RxLen = Len;
		pUSARTHandle->pRxBuffer = TODO;
		pUSARTHandle->RxBusyState = TODO;

		//Implement the code to enable interrupt for RXNE
		TODO

	}

	return rxstate;

}
*/
