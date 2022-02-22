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


/******************************************************************************
* Includes
*******************************************************************************/
#include "log_uart.h"

/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/
#define LOG_UART_BAUDRATE		9600
#define LOG_UART_DATALEN		DATA_LEN_8B
#define LOG_UART_PARITY			PARITY_NONE
#define LOG_UART_STOPBIT		STOP_BIT_1B
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
* Function Definitions
*******************************************************************************/
void LogUART_Ctor(LogUART_t* me)
{
	/* Base class constructor */
	Log_Ctor(&me->super, 0, LOGLEVEL_DEBUG); /* Log all */

	/* UART's side constructor */
	static uart_config_t config_def =
	{
		.baudrate 	= LOG_UART_BAUDRATE,
		.datalen	= LOG_UART_DATALEN,
		.parity		= LOG_UART_PARITY,
		.stop_bit	= LOG_UART_STOPBIT
	};

	static uart_t uart0_obj;
	me->p_uart_driver = &uart0_obj;
	uart0_obj.instance = UART0_INSTANCE;
	UART_Ctor(&uart0_obj, uart0_obj.instance, &config_def);
	/* Usage of polymorphism overwrite  */
	static struct Log_vtable_t const LogUART_vtable =
	{
		&LogUART_Send,
	};
	me->super.p_vtb = &LogUART_vtable;
}

bool LogUART_Send(LogUART_t* me, uint8_t* p_msg, uint32_t msg_len)
{
	return UART_Send(me->p_uart_driver, p_msg, msg_len);
}
/*************** END OF FUNCTIONS ***************************************************************************/
