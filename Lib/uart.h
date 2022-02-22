/****************************************************************************
* Title                 :   ADC Application
* Filename              :   adc_app.h
* Author                :   Itachi
* Origin Date           :   06/07/2012
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
/** \file tsk.h
 *  \brief This module contains continuous tasks.
 *
 *  This is the header file for the definition for tasks that are continuous
 *  and should be ran as often as possible.
 */
#ifndef UART_H
#define UART_H

/******************************************************************************
* Includes
*******************************************************************************/
#include "stdbool.h"
#include "stdint.h"
/******************************************************************************
* Preprocessor Constants
*******************************************************************************/
#define	UART0_INSTANCE		0
#define	UART1_INSTANCE		1
#define	UART2_INSTANCE		2


/******************************************************************************
* Configuration Constants
*******************************************************************************/


/******************************************************************************
* Macros
*******************************************************************************/



/******************************************************************************
* Typedefs
*******************************************************************************/
typedef enum
{
	DATA_LEN_7B = 0,
	DATA_LEN_8B,
	DATA_LEN_9B
}eUART_data_len_t;

typedef enum
{
	STOP_BIT_NONE = 0,
	STOP_BIT_1B,
	STOP_BIT_2B
}eUART_stop_bit_t;


typedef enum
{
	PARITY_NONE =0,
	PARITY_EVEN,
	PARITY_ODD
}eUART_parity_t;

typedef enum
{
	STATUS_RESET=0,
	STATUS_RDY,
	STATUS_BUSY,
	STATUS_ERR
}eUART_status_t;

typedef struct
{
	eUART_data_len_t		datalen;
	eUART_stop_bit_t		stop_bit;
	eUART_parity_t			parity;
	uint32_t				baudrate;
}uart_config_t;


typedef struct
{
	uint8_t 				instance;
	eUART_status_t			status;
	uart_config_t  			config;
}uart_t;

/******************************************************************************
* Variables
*******************************************************************************/


/******************************************************************************
* Function Prototypes
*******************************************************************************/
void UART_Ctor(uart_t* p_uart, uint8_t instace, uart_config_t* p_config);
bool UART_Init(uart_t* p_uart);
bool UART_Send(uart_t* p_uart, const uint8_t* p_data, uint32_t len);
bool UART_Recv(uart_t* p_uart, uint8_t* p_buffer, uint32_t len);

#endif /*UART_H*/

/*** End of File **************************************************************/
