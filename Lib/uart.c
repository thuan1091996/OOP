/****************************************************************************
* Title                 :   Logger
* Filename              :   logger.h
* Author                :   Itachi
* Origin Date           :   Nov 22, 2021
* Version               :   1.0.0
* Compiler              :   TI
* Target                :   TM4C123
* Notes                 :   None
*****************************************************************************/

/*************** INTERFACE CHANGE LIST **************************************
*
*    Date       Software Version    Initials        Description
*  Nov 22, 2021    XXXXXXXXXXX      Itachi      Interface Created.
*
*****************************************************************************/
/** \file XXX.c
 * \brief This module contains the
 */
/******************************************************************************
* Includes

*******************************************************************************/
#include "uart.h"
#include "uartstdio.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "inc/hw_memmap.h"
/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/
#define RX0_PIN          GPIO_PIN_0
#define TX0_PIN          GPIO_PIN_1
/******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/

/******************************************************************************
* Module Typedefs
*******************************************************************************/

/******************************************************************************
* Module Variable Definitions
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Static Function Definitions
*******************************************************************************/
void uart0_mspinit(void)
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
	GPIOPinConfigure(GPIO_PA0_U0RX);            //PIN mux for UART
	GPIOPinConfigure(GPIO_PA1_U0TX);            //PIN mux for UART
	GPIOPinTypeUART(GPIO_PORTA_BASE, RX0_PIN |TX0_PIN);
}

/******************************************************************************
* Function Definitions
*******************************************************************************/
void UART_Ctor(uart_t* me, uint8_t instace, uart_config_t* p_config)
{
	me->instance		= instace;
	me->config.baudrate = p_config->baudrate;
	me->config.datalen	= p_config->datalen;
	me->config.parity	= p_config->parity;
	me->config.stop_bit	= p_config->stop_bit;
	UART_Init(me);
}

bool UART_Init(uart_t* me)
{
	UARTStdioConfig(me->instance, me->config.baudrate, SysCtlClockGet() );
	switch (me->instance)
	{
		case UART0_INSTANCE:
		{
			uart0_mspinit();
		}
			break;
		case UART1_INSTANCE:
			break;
		case UART2_INSTANCE:
			break;
		default:
			break;
	}
	return true;
}

bool UART_Send(uart_t* p_uart,  const uint8_t* p_data, uint32_t len)
{
	UARTwrite((const char*)p_data, len);
	return true;
}

bool UART_Recv(uart_t* p_uart,  uint8_t* p_buffer, uint32_t len)
{
	UARTgets((char*)p_buffer, len);
	return true;
}

/*************** END OF FUNCTIONS ***************************************************************************/
