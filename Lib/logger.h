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

#ifndef LIB_LOGGER_H_
#define LIB_LOGGER_H_

/******************************************************************************
* Includes
*******************************************************************************/
#include "stdbool.h"
#include "stdio.h"
#include "stdint.h"
#include "driverlib/debug.h"
/******************************************************************************
* Preprocessor Constants
*******************************************************************************/


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
	LOGLEVEL_DEBUG=0,
	LOGLEVEL_WARN,
	LOGLEVEL_ERR,
	LOGLEVEL_FATAL,
	LOGLEVEL_NONE,
}eLogLevel_t;

typedef enum
{
	LOGSYSTEM_COMM=0,
	LOGSYSTEM_APP,
	LOGSYSTEM_TASK,
	LOGSYSTEM_PERIPH,
	LOGSYSTEM_DEVICE,
	LOGSYSTEM_MAX
}eLogSubSystem_t;			//TODO: Where to use


typedef struct
{
	struct Log_vtable_t const 	*p_vtb;
	bool 						b_log_on;			/* If == 0, will not log message */
	eLogLevel_t					e_cur_log_level;	/* Which subsystem has lower level than current level will not be logged out */
	eLogLevel_t 				e_log_list[LOGSYSTEM_MAX];
}LogObj_t;

struct Log_vtable_t{
	bool (*Log_SendMsg)(LogObj_t* p_me, char* msg, uint32_t msg_len);
};	/* Virtual table */

/******************************************************************************
* Variables
*******************************************************************************/


/******************************************************************************
* Function Prototypes
*******************************************************************************/
void Log_GlobalOn(LogObj_t* const p_logger);
void Log_GlobalOff(LogObj_t* const p_logger);
void Log_Ctor(LogObj_t* const p_logger, bool is_on, eLogLevel_t default_log_level);
bool Log_Sendmsg(LogObj_t* const p_logger, char *msg, uint32_t msg_len);
bool Log_Msg(LogObj_t* const p_logger, eLogSubSystem_t sys, char *msg, uint32_t msg_len);
void Log_SetOutputLevel(LogObj_t* const p_logger, eLogSubSystem_t sys, eLogLevel_t level);


#endif /* LIB_LOGGER_H_ */
