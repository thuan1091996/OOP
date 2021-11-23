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
/**
 * This constant is
 */


/******************************************************************************
* Configuration Constants
*******************************************************************************/
#define			NUMB_LOG_SUBSYSTEM				5

/******************************************************************************
* Macros
*******************************************************************************/



/******************************************************************************
* Typedefs
*******************************************************************************/
typedef enum
{
	Loglevel_debug=0,
	Loglevel_warn,
	Loglevel_err,
	Loglevel_fatal,
	Loglevel_none
}eLogLevel_t;

typedef enum
{
	Logsystem_comm=0,
	Logsystem_app,
	Logsystem_task,
	Logsystem_periph,
	Logsystem_device
}eLogSubSystem_t;			//TODO: Where to use

struct Log_vtable_t;				/* Forward declaration */
typedef struct
{
	struct vtable* const 	p_vtb;
	bool 					b_log_on;
	eLogLevel_t				cur_level;
	eLogLevel_t 			Loglevel[NUMB_LOG_SUBSYSTEM];
}LogObj_t;

typedef struct {
	bool (*Log_output)(LogObj_t* p_me, char* msg);
}Log_vtable_t;	/* Virtual table */

/******************************************************************************
* Variables
*******************************************************************************/


/******************************************************************************
* Function Prototypes
*******************************************************************************/
bool LogMsg(LogObj_t* p_logger, char *msg);
void LogSetOutputLevel(LogObj_t* p_logger, eLogSubSystem_t sys, eLogLevel_t level);
void LogGlobalOn(LogObj_t* p_logger);
void LogGlobalOff(LogObj_t* p_logger);
void LogCtor(LogObj_t* p_logger, bool on_off, eLogLevel_t log_level);


#endif /* LIB_LOGGER_H_ */
