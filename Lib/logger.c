/****************************************************************************
* Title                 :   Logger
* Filename              :   logger.c
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
#include "logger.h"

/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/

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
bool LogMsg(LogObj_t* p_logger, char *msg)
{
	/* purely-virtual function should never be called */
	ASSERT(0);
	return 0U;
};

void LogCtor(LogObj_t* me, bool on_off, eLogLevel_t log_level)
{
	volatile static Log_vtable_t const Log_vtable =
	{
		.Log_output =  &LogMsg,
	};
	me->b_log_on	= on_off;
	me->cur_level	= log_level;
	int idx;
	for(idx=0; idx < NUMB_LOG_SUBSYSTEM; idx++)
		me->Loglevel[idx] = Loglevel_none;
}

void LogSetOutputLevel(LogObj_t* me, eLogSubSystem_t sys, eLogLevel_t level)
{
	me->Loglevel[sys] = level;
}

void LogGlobalOn(LogObj_t* me)
{
	me->b_log_on = true;
}

void LogGlobalOff(LogObj_t* me)
{
	me->b_log_on= false;
}

